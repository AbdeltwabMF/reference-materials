int Head[N], Next[M], To[M], Par[N], sbtree_size[N], ne, n, m, u, v, w;

void dfs(int node, int par = -1) {
  sbtree_size[node] = 1;
  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != par) {
      dfs(To[i], node);
      sbtree_size[node] += sbtree_size[To[i]];
    }
}

int main()
{
  dfs(1);
  for(int i = 1; i <= n; ++i)
    cout << sbtree_size[i] - 1 << " \n"[i == n];
}

