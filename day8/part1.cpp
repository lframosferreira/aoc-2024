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

int n, m;
vector<string> mapa;

int oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }

int main() {
  _ string st;
  while (cin >> st)
    mapa.pb(st);
  map<char, vector<ii>> pairs;
  int n = sz(mapa);
  int m = sz(mapa[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ant = mapa[i][j];
      if (ant == '.')
        continue;
      pairs[ant].pb(mp(i, j));
    }
  }
  int ans = 0;
  for (auto &[a, ve] : pairs)
    sort(all(ve));
  for (auto &[ant, ve] : pairs) {
    for (int i = 0; i < sz(ve) - 1; i++) {
      for (int j = i + 1; j < sz(ve); j++) {
        ii p1 = ve[i];
        ii p2 = ve[j];
        ii pos1 = ve[i];
        ii pos2 = ve[j];
        int dx = abs(p1.f - p2.f);
      }
    }
  }
  exit(0);
}
