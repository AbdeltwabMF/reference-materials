void DFS(int node, int par = -1) 
{
  visited[node] = true;
  for (int i = Head[node]; i; i = Next[i])
    if(To[i] != par)
      DFS(To[i], node);
}

int main() 
{
  for(int i = 1; i <= n; ++i)
    if(!visited[i])
      ++CCs, DFS(i);
  cout << CCs << endl;
}

