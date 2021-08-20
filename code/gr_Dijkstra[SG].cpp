/** Dijkstra on sparse graphs
    - complexity : O(n + m)logn -> O(nlogn + m)
    - Single Source Single Destination Shortest Path Problem
    - Positive Weight Edges only
    Subpaths of shortest paths from u to v are shortest paths!
**/
int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

void Dijkstra(int src, int trg)
{
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  priority_queue <pair <ll, int> > Q;
  dis[src] = 0;
  Q.push({-dis[src], src});

  int node;
  ll cost;
  while(Q.size()) {
    tie(cost, node) = Q.top(); Q.pop();

    if((-cost) > dis[node]) continue; // lazy deletion
    if(node == trg) return;           // cheapest cost in case of positive weight edges

    for(int i = Head[node]; i; i = Next[i])
      if(dis[node] + Cost[i] < dis[To[i]])
	{
	  dis[To[i]] = dis[node] + Cost[i];
	  Q.push({-dis[To[i]], To[i]});
	  Par[To[i]] = node;
	}
  }
}

