void DFS(int node, int parent = -1)
{
  if(hasCycle |= visited[node])
    return;
  visited[node] = true;

  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != parent)
      DFS(To[i], node);
}

int main() {
  for(int i = 1; i <= n; ++i)
    if(!visited[i])
      DFS(i);
  cout << (hasCycle ? "YES" : "NO") << endl;
}
