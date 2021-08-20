void BFS(int src) 
{
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));
    
  queue <int> q;
  q.push(src);
  dis[src] = 0;

  int u;
  while(q.size()) 
    {
      u = q.front(); q.pop();
      for(int i = Head[u]; i; i = Next[i]) if(dis[To[i]] == oo) {
	  dis[To[i]] = dis[u] + 1;
	  Par[To[i]] = u;
	  q.push(To[i]);
        }
    }
}
