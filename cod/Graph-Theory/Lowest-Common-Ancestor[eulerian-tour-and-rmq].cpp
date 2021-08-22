int Head[N], To[M], Next[M], Cost[M], ne, n, m, u, v, w, q;
int Last[N], First[N], euler_tour[N << 1], Height[N << 1], euler_timer;

void EulerianTour(int node, int depth = 0)
{
  euler_tour[++euler_timer] = node;
  Height[euler_timer] = depth;
  First[node] = euler_timer;

  for(int i = Head[node]; i; i = Next[i])
    if(First[To[i]] == 0)
      {
	EulerianTour(To[i], depth + Cost[i]);

	euler_tour[++euler_timer] = node;
	Height[euler_timer] = depth;
      }

  Last[node] = euler_timer;
}

int main()
{
  EulerianTour(1);
  SparseTable <int> st(Height + 1, Height + euler_timer + 1, [&](int a, int b) { return a <= b; });

  int l, r; cin >> q;
  while(q--)
    {
      cin >> l >> r;

      int left = Last[l];
      int right = Last[r];
      if(left > right) swap(left, right);

      cout << euler_tour[ st.query(left, right) ] << endl;
    }
}

