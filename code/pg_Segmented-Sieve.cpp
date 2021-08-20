int lp[N];
int Primes[664580], pnx; /** size of Primes = n / (ln(n) - 1.08) */
bool isPrime[N];

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

vector<ll> segmented_sieve(ll l, ll r) {
  l += l == 1;
  int limit = r - l + 1;
  vector<ll> ret;
  memset(isPrime, true, sizeof(isPrime));

  ll p;
  for (int i = 0; i < pnx && (p = Primes[i], true); ++i) {
    for (ll j = max(p * p, (l + p - 1) / p * p); j <= r; j += p)
      isPrime[j - l] = false;
  }

  for (int i = 0; i < limit; ++i)
    if (isPrime[i])
      ret.emplace_back(i + l);
  return ret;
}
