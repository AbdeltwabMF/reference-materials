int Head[N], To[M], Next[M], Par[N], up[N][LOG + 1], Log[N], Level[N], ne, n, u, v, q;

void _clear() {
  memset(Head,  0, sizeof(Head[0])   * (n + 2));
  memset(Par,   0, sizeof(Par[0])    * (n + 2));
  memset(Level, 0, sizeof(Level[0])  * (n + 2));
  ne = 0;
}

int lastBit(int a) {
  return (a & -a);
}

void logCalc()
{
  Log[1] = 0;
  for(int i = 2; i < N; ++i)
    Log[i] = Log[i >> 1] + 1;
}

void DFS(int node, int depth = 0)
{
  Level[node] = depth;
  up[node][0] = Par[node];  // Par[root] = root

  for(int i = 1; i <= LOG; ++i) {
    up[node][i] = up[up[node][i - 1]][i - 1];
  }

  for(int i = Head[node]; i; i = Next[i]) if(To[i] != Par[node]) {
      Par[To[i]] = node;
      DFS(To[i], depth + 1);
    }
}

int KthAncestor(int u, int k)
{
  if(k > Level[u]) return -1;

  for(int i = lastBit(k); k; k -= lastBit(k), i = lastBit(k))
    u = up[u][Log[i]];

  return u;
}

int LCA(int u, int v)
{
  if(Level[u] < Level[v]) swap(u, v);
  int k = Level[u] - Level[v];

  u = KthAncestor(u, k);
  if(u == v) return u;

  for(int i = LOG; i >= 0; --i)
    if(up[u][i] ^ up[v][i])
      {
	u = up[u][i];
	v = up[v][i];
      }

  return up[u][0];
}

int main()
{
  logCalc();
  for(int i = 1; i <= n; ++i) if(Par[i] == 0) {
      Par[i] = i;
      DFS(i);
    }

  cin >> q;
  while(q--)
    {
      cin >> u >> v;
      cout << LCA(u, v) << endl;
    }
}

