void BFS(int src) {
  memset(dis, 0x3f, sizeof dis);
  queue <int> Q;
  Q.push(src);
  dis[src] = 0;

  int node;
  while(Q.size()) {
    node = Q.front();
    Q.pop();
    for(int e = Head[node]; e; e = Next[e]) if(dis[To[e]] == oo) {
	dis[To[e]] = dis[node] + Cost[e];
	Q.push(To[e]);
      }
  }
}

int furthest() {
  long long ret = -1;
  int node = 1;
  for(int i = 1; i <= n; ++i) if(dis[i] != oo && dis[i] > ret)
				ret = dis[i], node = i;

  diameter = ret;
  return node;
}

int main() {
  BFS(1);
  BFS(furthest());
  furthest();
  cout << diameter << endl;
}

