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

int n, m, area, per;
vector<vector<bool>> vis;
static const vector<ii> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<string> mapa;
inline bool oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }
char curr_plant;

void bfs(int i, int j) {
  queue<ii> q;
  q.push({i, j});
  while (sz(q)) {
    auto [ni, nj] = q.front();
    q.pop();
    if (vis[ni][nj])
      continue;
    area++;
    vis[ni][nj] = true;
    for (auto [di, dj] : moves) {
      if (oob(ni + di, nj + dj))
        per++;
      else if (mapa[ni + di][nj + dj] != curr_plant)
        per++;
      else
        q.push({ni + di, nj + dj});
    }
  }
}

int main() {
  string st;
  while (cin >> st)
    mapa.pb(st);
  n = sz(mapa);
  m = sz(mapa[0]);
  vis.resize(n);
  for (auto &e : vis)
    e.resize(m);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j])
        continue;
      area = 0;
      per = 0;
      curr_plant = mapa[i][j];
      bfs(i, j);
      ans += area * per;
      // dbg(per);
      // dbg(area);
    }
  }
  cout << ans << endl;

  exit(0);
}
