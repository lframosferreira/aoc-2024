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
  vll v[2];
  ll val;

  while (cin >> val)
    v[0].pb(val);

  for (int c = 0; c < 25; c++) {
    ll nd;
    for (auto &e : v[c % 2]) {
      if (e == 0)
        v[(c + 1) % 2].pb(1);
      else if ((nd = num_digits(e)) % 2 == 0) {
        string sn = to_string(e);
        v[(c + 1) % 2].pb(stoll(sn.substr(0, nd / 2)));
        v[(c + 1) % 2].pb(stoll(sn.substr(nd / 2)));
      } else {
        v[(c + 1) % 2].pb(e * 2024);
      }
    }
    v[c % 2].clear();
  }
  cout << sz(v[1]) << endl;
  exit(0);
}
