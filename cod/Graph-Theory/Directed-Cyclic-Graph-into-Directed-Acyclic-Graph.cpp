int HeadDAG[N], ToDAG[M], NextDAG[M], CostDAG[M], neDAG, Head[N], To[M], Next[M], Cost[M], dfs_num[N], dfs_low[N], out[N], Stack[N], compID[N], compSize[N], ne, n, m, u, v, w. dfs_timer, top, ID;
bool in_stack[N];

void addEdge(int from, int to, int cost = 0) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  Cost[ne] = cost;
  To[ne] = to;
}

void addEdgeDAG(int from, int to, int cost = 0) {
  NextDAG[++neDAG] = HeadDAG[from];
  HeadDAG[from] = neDAG;
  CostDAG[ne] = cost;
  ToDAG[neDAG] = to;
  ++out[from];
}

void _clear() {
  memset(Head,     0, sizeof(Head[0])     * (n + 2));
  memset(dfs_num,  0, sizeof(dfs_num[0])  * (n + 2));
  memset(compID,   0, sizeof(compID[0])   * (n + 2));
  memset(compSize, 0, sizeof(compSize[0]) * (n + 2));
  memset(HeadDAG,  0, sizeof(HeadDAG[0])  * (n + 2));
  memset(out,      0, sizeof(out[0])      * (n + 2));
  ne = dfs_timer = top = neDAG = ID = 0;
}

void Tarjan(int node)
{
  dfs_num[node] = dfs_low[node] = ++dfs_timer;
  in_stack[Stack[top++] = node] = true;

  for(int i = Head[node]; i; i = Next[i]) {
    if(dfs_num[To[i]] == 0)
      Tarjan(To[i]);

    if(in_stack[To[i]])
      dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);
  }

  if(dfs_num[node] == dfs_low[node]) {
    ++ID;
    for(int cur = -1; cur ^ node;) {
      in_stack[cur = Stack[--top]] = false;
      compID[cur] = ID;
      ++compSize[ID];
    }
  }
}

void Tarjan() {
  for(int i = 1; i <= n; ++i)
    if(dfs_num[i] == 0)
      Tarjan(i);
}

void DFS(int node)
{
  dfs_num[node] = 1;
  for(int i = Head[node]; i; i = Next[i]) {
      if(compID[node] != compID[To[i]])
	addEdgeDAG(compID[node], compID[To[i]]);
      if(dfs_num[To[i]] == 0)
	DFS(To[i]);
    }
}

void construct_dag() {
  memset(dfs_num, 0, sizeof(dfs_num[0]) * (n + 2));

  for(int i = 1; i <= n; ++i)
    if(dfs_num[i] == 0)
      DFS(i);
}

