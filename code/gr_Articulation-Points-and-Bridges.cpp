int Head[N], Next[M], To[M], Cost[M], Par[N], dfs_num[N], dfs_low[N], ne, n, m, u, v, w, root, rootChildren, dfs_timer, bridgeInx;
bool Art[N];
vector < pair <int, int> > bridges(M);

void _clear() {
  memset(Head,    0, sizeof(Head[0])    * (n + 2));
  memset(dfs_num, 0, sizeof(dfs_num[0]) * (n + 2));
  memset(Par,    -1, sizeof(Par[0])     * (n + 2));
  memset(Art,     0, sizeof(Art[0])     * (n + 2));
  ne = dfs_timer = bridgeInx = 0;
}

void Tarjan(int node) {
  dfs_num[node] = dfs_low[node] = ++dfs_timer;
  for(int i = Head[node]; i; i = Next[i]) {
    if(dfs_num[To[i]] == 0) {
      if(node == root) ++rootChildren;
      Par[To[i]] = node;
      Tarjan(To[i]);
      dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);

      if(dfs_low[To[i]] >= dfs_num[node])
	Art[node] = true;

      if(dfs_low[To[i]] > dfs_num[node])
	bridges[bridgeInx++] = make_pair(node, To[i]);
    }
    else if(To[i] != Par[node])
      dfs_low[node] = Min(dfs_low[node], dfs_num[To[i]]);
  }
}

int main() {
  for(int i = 1; i <= n; ++i)
    if(dfs_num[i] == 0) {
      root = i;
      rootChildren = 0;
      Tarjan(i);
      Art[root] = (rootChildren > 1);
    }

  cout << "Art Points :\n";
  for(int i = 1; i <= n; ++i)
    if(Art[i])
      cout << i << " ";

  cout << "\nBridges :\n";
  for(int i = 0; i < bridgeInx; ++i)
    cout << bridges[i].first << " - " << bridges[i].second << endl;
}
