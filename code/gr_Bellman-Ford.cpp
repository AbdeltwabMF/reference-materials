// Bellman Ford Algorithm : In programming contests, the slowness of Bellman Fords and its negative cycle detection feature causes it to be used only to solve the SSSP problem on small graph  which is not guaranteed to be free from negative weight cycle.

bool hasNC() {
  for(int i = 1; i <= n; ++i)
    for(int j = Head[i]; j; j = Next[j])
      if(dis[i] < INF && dis[i] + Cost[j] < dis[To[j]])
	return true;

  return false;
}

bool Bellman_Ford(int src)
{
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  dis[src] = 0;
  bool newRelaxation = true;

  for(int i = 2; i <= n && newRelaxation; ++i) {
    newRelaxation = false;
    for(int i = 1; i <= n; ++i)
      for(int j = Head[i]; j; j = Next[j])
	if(dis[i] < INF && dis[i] + Cost[j] < dis[To[j]]) {
	  dis[To[j]] = dis[i] + Cost[j];
	  Par[To[j]] = i;
	  newRelaxation = true;
	}
  }
  return hasNC();
}
