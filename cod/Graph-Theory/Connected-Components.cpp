void DFS(int node) {
  visited[node] = true;
  for(int e = Head[node]; e; e = Next[e])
    if(!visited[To[e]])
      DFS(To[e]);
}

int main() {
  for(int node = 1; node <= n; ++node)
    if(!visited[node])
      ++CCs, DFS(node);
  cout << CCs << endl;
}

