vector <int> kahn(int n)
{
  vector <int> ready, ret;

  for(int i = 1; i <= n; ++i)
    if(!in[i])
      ready.push_back(i);

  int node;
  while(!ready.empty())
    {
      node = ready.back(); ready.pop_back();
      ret.push_back(node);

      for(int i = Head[node]; i; i = Next[i])
	if(--in[To[i]] == 0)
	  ready.push_back(To[i]);
    }
  return ret;
}

int main() {
  vector <int> v = kahn(n);
  if((int)v.size() == n)
    for(int i : v)
      cout << i << ' ';
  else
    cout << "not a DAG!" << endl;
}

