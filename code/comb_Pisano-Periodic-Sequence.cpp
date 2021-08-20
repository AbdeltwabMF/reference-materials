vector <int> pisano_periodic_sequence(int n) {
  vector <int> period;

  int current = 0, next = 1;
  period.push_back(current);

  if(n < 2) return period;
  current = (next += current) - current;

  while(current != 0 || next != 1) {
    period.push_back(current);
    current = current + next >= n ? (next += current - n) + (n - current) : (next += current) - current;
  }
  return period;
}
