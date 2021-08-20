int Head[N], To[M], Next[M], Cost[M], Par[N], ne, n, m, u, v, w, q;
bool vis[N];

void DFS(int node) {
  vis[node] = true;
  for(int i = Head[node]; i; i = Next[i]) if(!vis[To[i]]) {
      Par[To[i]] = node;
      DFS(To[i]);
    }
}

int LCA(int u, int v)
{
  memset(vis, false, sizeof(vis[0]) * (n + 2));

  while(u != -1) {
    vis[u] = true;
    u = Par[u];
  }

  while(!vis[v]) {
    vis[v] = true;
    v = Par[v];
  }

  return v;
}

int main()
{
  DFS(1);
  cin >> q;
  while(q--)
    {
      cin >> u >> v;
      cout <<  LCA(u, v) << endl;
    }
}

