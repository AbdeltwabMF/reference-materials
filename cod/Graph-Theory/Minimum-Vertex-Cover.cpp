bool DFS(int node, int par = -1) {

  bool black = false;
  for(int e = Head[node]; e; e = Next[e])
    if(To[e] != par)
      black |= DFS(To[e], node);

  MVC += black;
  return !black;
}
