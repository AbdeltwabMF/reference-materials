void DFS(int node, int cost, int par = -1) {
  if(cost > diameter) diameter = cost, at = node;
  for (int e = Head[node]; e; e = Next[e]) if(To[e] != par)
					     DFS(To[e], cost + 1, node);
}

int main() {
  DFS(1, 0);
  from = at, diameter = 0;
  DFS(from, 0);
  to = at;
  cout << diameter << " " << from << " " << to << endl;
}

