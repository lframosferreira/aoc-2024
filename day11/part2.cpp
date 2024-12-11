// pescoço pra baixo é canela

#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

inline ll num_digits(ll n) {
  if (n < 0)
    return 1;
  return (ll)log10((long double)n) + 1;
}

int main() {
  map<ll, ll> hm;
  ll val;

  while (cin >> val)
    hm[val]++;

  for (int c = 0; c < 75; c++) {
    ll nd;
    map<ll, ll> hm2(hm);
    for (auto &[val, cnt] : hm2) {
      if (val == 0) {
        hm[1LL] += cnt;
      } else if ((nd = num_digits(val)) % 2 == 0) {
        string sn = to_string(val);
        ll fh = stoll(sn.substr(0, nd / 2));
        ll sh = stoll(sn.substr(nd / 2));
        hm[fh] += cnt;
        hm[sh] += cnt;
      } else {
        hm[val * 2024] += cnt;
      }
      hm[val] -= cnt;
    }
  }
  ll ans = 0;
  for (auto &[val, cnt] : hm)
    ans += cnt;
  cout << ans << endl;
  exit(0);
}
