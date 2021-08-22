int Head[N], Next[M], To[M], ne, u, v, n, m, subtree_size[N], level[N];
ll dis[N];

void dfs(int node, int par = -1) {
  subtree_size[node] = 1;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      level[To[i]] = level[node] + 1;
      dfs(To[i], node);
      subtree_size[node] += subtree_size[To[i]];
    }
}

void reRoot(int node, ll pd, int par = -1) {
  dis[node] = pd;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      reRoot(To[i], pd - subtree_size[To[i]] + (n - subtree_size[To[i]]), node);
    }
}

void get_dis()
{
  dfs(1);
  ll pd = 0;
  for(int i = 1; i <= n; ++i)
    pd += level[i];

  reRoot(1, pd);
  for(int i = 1; i <= n; ++i)
    cout << dis[i] << " \n"[i == n];
}
