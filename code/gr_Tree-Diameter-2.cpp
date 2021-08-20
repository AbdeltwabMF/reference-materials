int Head[N], Next[M], To[M], Par[N], toLeaf[N], diameter, ne, n, m, u, v, w, f, s;

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  memset(Par, -1, sizeof(Par[0])  * (n + 2));
  ne = 0;
}

void dfs(int node, int par = -1) {
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      dfs(To[i], node);

      diameter = max(toLeaf[node] + 1 + toLeaf[To[i]], diameter);
      toLeaf[node] = max(toLeaf[node], toLeaf[To[i]] + 1);
    }
}

void main()
{
  dfs(1);
  cout << diameter << endl;
}
