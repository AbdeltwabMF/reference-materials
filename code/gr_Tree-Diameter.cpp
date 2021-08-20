int Head[N], Next[M], To[M], Par[N], toLeaf[N], maxLength[N], ne, n, m, u, v, w;

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  memset(Par, -1, sizeof(Par[0])  * (n + 2));
  ne = 0;
}

void dfs_toLeaf(int node, int par = -1)
{
  toLeaf[node] = 0;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      dfs_toLeaf(To[i], node);
      if(toLeaf[To[i]] + 1 > toLeaf[node])
	toLeaf[node] = toLeaf[To[i]] + 1;
    }
}

void dfs_maxLength(int node, int par = -1)
{
  int firstMax = -1;
  int secondMax = -1;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      dfs_maxLength(To[i], node);

      if(toLeaf[To[i]] > firstMax) {
	if(firstMax > secondMax)
	  secondMax = firstMax;
	firstMax = toLeaf[To[i]];
      } else if(toLeaf[To[i]] > secondMax)
	secondMax = toLeaf[To[i]];
    }
  maxLength[node] = firstMax + secondMax + 2;
}

void main()
{
  dfs_toLeaf(1);
  dfs_maxLength(1);

  int diameter = 0;
  for(int i = 1; i <= n; ++i)
    if(maxLength[i] > diameter)
      diameter = maxLength[i];

  cout << diameter << endl;
}
