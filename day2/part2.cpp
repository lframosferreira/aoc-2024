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

int main() {
  _ vvi v;
  string line;
  int i = 0;
  while (getline(cin, line)) {
    v.pb(vi());
    istringstream iss(line);
    int val;
    while (iss >> val) {
      v[i].pb(val);
    }
    i++;
  }
  int ans = 0;
  for (auto &lev : v) {
    for (int i = 0; i < sz(lev); i++) {
      vi level = lev;
      level.erase(level.begin() + i);
      int ok = 1;
      int dec = level[0] > level[1];
      int diff = abs(level[0] - level[1]);
      if (diff < 1 or diff > 3)
        continue;
      for (int i = 1; i < sz(level) - 1; i++) {
        diff = abs(level[i] - level[i + 1]);
        if (diff < 1 or diff > 3) {
          ok = 0;
          break;
        }
        if (level[i] > level[i + 1] != dec) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans += ok;
        break;
      }
    }
  }
  cout << ans << endl;
  exit(0);
}
