// pescoço pra baixo é canela

#include <bits/stdc++.h>

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

#define PLUS 0
#define TIMES 1

int main() {
  _ string st;
  ull ans = 0;
  while (getline(cin, st)) {
    int pos = st.find(':');
    ll val = stoll(st.substr(0, pos));
    string rest = st.substr(pos + 2);
    vll v;
    string curr;
    int i = 0;
    int ok = 0;
    while (i < sz(rest)) {
      if (rest[i] == ' ') {
        v.pb(stoll(curr));
        curr.clear();
      }
      curr.pb(rest[i++]);
      if (i == sz(rest)) {
        v.pb(stoll(curr));
      }
    }
    int n = sz(v);
    for (ll i = 0; i < (ll)pow(3, n); i++) {
      vi base3;
      ll aux = i;
      do {
        int d = aux % 3;
        base3.pb(d);
        aux = aux / 3;
      } while (aux);
      ll s = v[0];
      for (ll j = 1; j < n; j++) {
        if (base3[j - 1] == PLUS)
          s += v[j];
        else if (base3[j - 1] == TIMES)
          s *= v[j];
        else {
          string t = to_string(s);
          t = t + to_string(v[j]);
          s = stoll(t);
        }
      }
      if (s == val)
        ok = 1;
    }
    ans += ok * val;
  }
  cout << ans << endl;
  exit(0);
}
