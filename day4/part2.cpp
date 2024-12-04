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

static vector<ii> moves = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

int n, m;
inline bool oob(int i, int j) { return i < 0 or i >= n or j < 0 or j >= m; }

inline int check_for_xmas(const vector<string> &v, int i, int j) {
  int cnt[2] = {0, 0};
  for (const auto &move : moves) {
    int a = move.f;
    int b = move.s;
    if (oob(i + a, j + b))
      return 0;
    cnt[0] += (v[i + a][j + b] == 'S');
    cnt[1] += (v[i + a][j + b] == 'M');
  }
  if (cnt[0] == 2 and cnt[1] == 2) {
    return v[i - 1][j + 1] != v[i + 1][j - 1];
  }
  return 0;
}

int main() {
  _ vector<string> v;
  string st;
  while (cin >> st)
    v.pb(st);
  n = sz(v);
  m = sz(v[0]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'A') {
        ans += check_for_xmas(v, i, j);
      }
    }
  }
  cout << ans << endl;
  exit(0);
}
