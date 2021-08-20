void DFS(int node)
{
  if(hasCycle |= visited[node] == 1)
    return; /** Oops\, revisiting active node **/
  visited[node] = 1;                         /** current node legend mode has been activated **/

  for(int i = Head[node]; i; i = Next[i])
    if(visited[To[i]] != 2)
      DFS(To[i]);

  visited[node] = 2;                          /** done with this node and mark it as visited **/
}

int main()
{
  for(int i = 1; i <= n; ++i)
    if(!visited[i])
      DFS(i);
  cout << (hasCycle ? "YES" : "NO") << endl;
}

