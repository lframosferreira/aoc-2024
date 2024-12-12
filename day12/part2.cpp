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
vector<vector<bool>> vis, vis2;
static const vector<ii> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<string> mapa;
vector<string> mapa2;
inline bool oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }
inline bool oob2(int x, int y) {
  return x < 0 or x >= n + 2 or y < 0 or y >= m + 2;
}
char curr_plant;

// chatgpt made this function, I changed some logic during dev but the base code
// was made by him
int check_corners(int x, int y, char comp) {
  int corners = 0;

  // Iterate through all pairs of moves
  for (size_t i = 0; i < moves.size(); ++i) {
    for (size_t j = i + 1; j < moves.size(); ++j) {
      // Get the two move offsets
      auto [di1, dj1] = moves[i];
      auto [di2, dj2] = moves[j];
      if (di1 == -1 * di2 or dj1 == -1 * dj2)
        continue;

      // Calculate the resulting positions
      int nx1 = x + di1;
      int ny1 = y + dj1;
      int nx2 = x + di2;
      int ny2 = y + dj2;

      // Check if both positions are within bounds and match curr_plant
      if (!oob2(nx1, ny1) && mapa2[nx1][ny1] == comp && !oob2(nx2, ny2) &&
          mapa2[nx2][ny2] == comp) {
        if (comp == '.' and mapa2[x + di1 + di2][y + dj1 + dj2] == curr_plant) {
          continue;
        }
        corners++;
      }
    }
  }

  return corners;
}

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
    mapa2[ni + 1][nj + 1] = curr_plant;
    for (auto [di, dj] : moves) {
      if (oob(ni + di, nj + dj)) {
        mapa2[ni + di + 1][nj + dj + 1] = '.';
      } else if (mapa[ni + di][nj + dj] != curr_plant)
        mapa2[ni + di + 1][nj + dj + 1] = '.';
      else
        q.push({ni + di, nj + dj});
    }
  }
}

int corners_cnt;
ii dir;
void bfs2(int i, int j) {
  auto [di, dj] = dir;
  queue<ii> q;
  q.push(mp(i, j));
  while (sz(q)) {
    auto [ni, nj] = q.front();
    q.pop();
    if (vis2[ni][nj])
      continue;
    vis2[ni][nj] = true;
    corners_cnt += check_corners(ni, nj, curr_plant);
    if (oob2(ni + di, nj + dj))
      continue;
    if (mapa2[ni + di][nj + dj] == '_' or mapa2[ni + di][nj + dj] == curr_plant)
      continue;
    q.push(mp(ni + di, nj + dj));
  }
  dbg(i);
  dbg(j);
  dbg(corners_cnt);
}
void printm() {
  for (auto e : mapa2) {
    cout << e << endl;
  }
}

int main() {
  string st;
  while (cin >> st)
    mapa.pb(st);
  n = sz(mapa);
  m = sz(mapa[0]);
  mapa2.resize(n + 2);
  for (auto &e : mapa2)
    e.resize(m + 2, '_');
  vis.resize(n);
  for (auto &e : vis)
    e.resize(m);
  vis2.resize(n + 2);
  for (auto &e : vis2)
    e.resize(m + 2);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j])
        continue;
      area = 0;
      per = 0;
      curr_plant = mapa[i][j];
      for (auto &e : mapa2)
        fill(all(e), '_');
      bfs(i, j);
      for (auto &e : vis2)
        fill(all(e), false);
      int sides = 0;
      for (int a = 0; a < n + 2; a++) {
        for (int b = 0; b < m + 2; b++) {
          if (mapa2[a][b] == '.') {
            sides += check_corners(a, b, curr_plant);
          } else if (mapa2[a][b] == curr_plant) {
            sides += check_corners(a, b, '.');
          }
        }
      }
      ans += area * (sides);
    }
  }
  cout << ans << endl;

  exit(0);
}
