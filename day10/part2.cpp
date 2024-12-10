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

int cnt, n, m;
vector<vector<bool>> vis;
static const vector<ii> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<string> mapa;
inline bool oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }

void bfs(int x, int y) {

  queue<iii> q;
  q.push({x, y, 0});
  while (sz(q)) {
    auto [nx, ny, val] = q.front();
    q.pop();
    if (val == 9) {
      cnt++;
      continue;
    }
    vis[nx][ny] = true;
    for (auto [dx, dy] : moves) {
      if (oob(nx + dx, ny + dy))
        continue;
      if (mapa[nx + dx][ny + dy] - '0' != val + 1)
        continue;
      q.push({nx + dx, ny + dy, val + 1});
    }
  }
}

int main() {
  _ string st;
  while (cin >> st)
    mapa.pb(st);

  n = sz(mapa);
  m = sz(mapa[0]);
  vis.resize(n);
  for (auto &e : vis)
    e.resize(m);
  int ans = 0;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] != '0')
        continue;
      bfs(i, j);
      ans += cnt;
      cnt = 0;
      for (auto &e1 : vis)
        fill(all(e1), false);
    }
  }
  cout << ans << endl;

  exit(0);
}
