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
  _ vector<int> v;
  set<ii> conj;
  string st;
  int ans = 0;
  while (cin >> st) {

    // got to updates
    int pos;
    if ((pos = st.find('|')) == string::npos) {
      int i = 0, j = 0;
      while (1) {
        while (j < sz(st) and st[j] != ',')
          j++;
        v.pb(stoi(st.substr(i, j - i)));
        if (j == sz(st))
          break;
        j++;
        i = j;
      }
      int ok = 1;
      for (int i = 0; i < sz(v); i++) {
        for (int j = i + 1; j < sz(v); j++) {
          if (conj.find(mp(v[j], v[i])) != conj.end())
            ok = 0;
        }
      }
      if (!ok) {
        sort(all(v), [&conj](int a, int b) {
          if (conj.find(mp(a, b)) == conj.end())
            return false;
          return true;
        });
        // for (auto e : v)
        //   cout << e << " ";
        // cout << endl;

        ans += v[(sz(v) - 1) / 2];
      }

      v.clear();
      continue;
    }
    int x = stoi(st.substr(0, pos));
    int y = stoi(st.substr(pos + 1));
    conj.insert(mp(x, y));
  }
  cout << ans << endl;
  exit(0);
}
