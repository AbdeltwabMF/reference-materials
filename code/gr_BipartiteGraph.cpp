bool checkBiPartite(int node, int par = 0) {
  if(vis[node])
    return color[par] != color[node];

  color[node] = color[par] ^ 1;
  vis[node] = true;
  bool ok = true;
  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != par)
      ok &= checkBiPartite(To[i], node);
  return ok;
}

int main() {
  bool isBiPartite = true;
  for(int i = 1; i <= n; ++i)
    if(!vis[i])
      isBiPartite &= checkBiPartite(i);
  cout << (isBiPartite ? "YES" : "NO") << endl;
}
