void DFS(int node) 
{
  vis[node] = true;
  for(int i = Head[node]; i; i = Next[i])
    if(!vis[To[i]])
      DFS(To[i]);
}
