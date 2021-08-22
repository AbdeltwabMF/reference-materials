/** Dijkstra on dense graphs
    complexity : O(n^2 + m)
**/
int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

void Dijkstra(int src, int V)
{
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  vector <bool> mark(V + 1, false);

  dis[src] = 0;
  for(int i = 1; i <= V; ++i) {
    int node = 0;
    for(int j = 1; j <= V; ++j)
      if(!mark[j] && dis[j] < dis[node])
	node = j;

    if(dis[node] == INF) break;
    mark[node] = true;
    for(int i = Head[node]; i; i = Next[i])
      if(dis[node] + Cost[i] < dis[To[i]])
	{
	  dis[To[i]] = dis[node] + Cost[i];
	  Par[To[i]] = node;
	}
  }
}

