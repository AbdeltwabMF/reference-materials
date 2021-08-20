int n, m, u, v, w;
vector < tuple <int, int, int> > edges;
UnionFind uf;

pair < ll, vector < pair <int, int> > > Kruskal()
{
  sort(edges.begin(), edges.end());

  vector < pair <int, int> > mstEdges;
  int from, to, cost;
  ll minWieght = 0;

  for(tuple <int, int, int> edge : edges)
    {
      tie(cost, from, to) = edge;
      if(uf.union_set(from, to))
        {
	  minWieght += cost;
	  mstEdges.push_back(make_pair(from, to));
        }
    }

  if(mstEdges.size() == n - 1)
    return make_pair(minWieght, mstEdges);

  return make_pair(-1, vector < pair <int, int> > ());
}

