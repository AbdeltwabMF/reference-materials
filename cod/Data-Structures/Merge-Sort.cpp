ll inversions;

template <class T>
void merge(T localArr [], int l, int mid, int r)
{
  int l_size = mid - l + 1;
  int r_size = r - mid;

  T L[l_size + 1];
  T R[r_size + 1];

  for(int i = 0; i < l_size; ++i) L[i] = localArr[i + l];
  for(int i = 0; i < r_size; ++i) R[i] = localArr[i + mid + 1];

  T Mx;
  if(sizeof(T) == 4) Mx = INT_MAX;
  else Mx = LONG_MAX;

  L[l_size] = R[r_size] = Mx;

  for(int k = l, i = 0, j = 0; k <= r; ++k)
    if(L[i] <= R[j])
      localArr[k] = L[i], i += (L[i] != Mx);
    else
      localArr[k] = R[j], j += (R[j] != Mx), inversions += l_size - i;
}

template <class T>
void merge_sort(T localArr [], int l, int r)
{
  if(r - l)
    {
      int mid = (l + r) >> 1;
      merge_sort(localArr, l,     mid);
      merge_sort(localArr, mid + 1, r);
      merge(localArr,      l,  mid, r);
    }
}

template <class T>
void merge_sort(T _begin, T _end)
{
  const int sz = _end - _begin;
  __typeof(*_begin) localArray[sz];

  __typeof(_begin) k = _begin;
  for(int i = 0; k != _end; ++i, ++k)
    localArray[i] = *k;

  merge_sort(localArray, 0, sz - 1);

  k = _begin;
  for(int i = 0; k != _end; ++i, ++k)
    *k = localArray[i];
}

