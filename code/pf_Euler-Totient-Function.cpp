int lp[N], Primes[664580], pnx; /** size of Primes = n / (ln(n) - 1.08) */

void linear_sieve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = Primes[pnx++] = i;
    }
    for (int j = 0, comp; j < pnx && Primes[j] <= lp[i] && (comp = i * Primes[j]) <= n; ++j) {
      lp[comp] = Primes[j];
    }
  }
}

ll Phi(ll a) { // for Queries
  ll ret = a, p;
  for (int i = 0; i < pnx && (p = Primes[i], true); ++i) {
    if (p * p > a) break;
    if (a % p) continue;
    ret -= ret / p;
    while (a % p == 0) a /= p;
  }
  if (a > 1) ret -= ret / a;
  return ret;
}
