int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

void BFS(int src, int trg)
{
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  deque <int> Q;
  Q.push_front(src);
  dis[src] = 0;

  int node;
  while(Q.size()) {
    node = Q.front(); Q.pop_front();
    if(node == trg) return;

    for(int i = Head[node]; i; i = Next[i])
      if(dis[node] + Cost[i] < dis[To[i]]) {
	dis[To[i]] = dis[node] + Cost[i];
	if(Cost[i])
	  Q.push_back(To[i]);
	else
	  Q.push_front(To[i]);
      }
  }
}

