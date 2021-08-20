void DFS(int node, long long cost, int par = -1) {
  if(cost > diameter) diameter = cost, at = node;
  for (int e = Head[node]; e; e = Next[e])
    if(To[e] != par)
      DFS(To[e], cost + Cost[e], node);
}

int main() {
  DFS(1, 0ll);
  from = at, diameter = 0;
  DFS(from, 0ll);
  to = at;
  cout << diameter << endl;
}

