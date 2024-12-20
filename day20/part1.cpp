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

vector<string> mapa;
int n, m;
int si, sj, fi, fj;
static const vector<ii> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int oob(int x, int y) {
  return x < 0 or x >= n or y < 0 or y >= m or mapa[x][y] == '#';
}
vvi vis;
vvi costs;

void bfs() {
  queue<iii> q;
  q.push({si, sj, 0});
  while (sz(q)) {
    auto [ni, nj, cost] = q.front();
    q.pop();
    costs[ni][nj] = cost;
    if (vis[ni][nj])
      continue;
    vis[ni][nj] = 1;
    for (auto [di, dj] : moves) {
      if (oob(ni + di, nj + dj))
        continue;
      if (vis[ni + di][nj + dj])
        continue;
      q.push({ni + di, nj + dj, cost + 1});
    }
  }
}

int main() {
  _ string st;
  int i = 0;
  while (cin >> st) {
    mapa.pb(st);
    if (st.find('S') != string::npos) {
      si = i;
      sj = st.find('S');
    }
    if (st.find('E') != string::npos) {
      fi = i;
      fj = st.find('E');
    }
    i++;
  }
  n = sz(mapa);
  m = sz(mapa[0]);
  vis.resize(n);
  for (auto &e : vis)
    e.resize(m);
  costs.resize(n);
  for (auto &e : costs)
    e.resize(m);

  bfs();
  int total = costs[fi][fj];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] != '#') {
        for (auto [di, dj] : moves) {
          if (oob(i + 2 * di, j + 2 * dj))
            continue;
          int new_cost =
              costs[i][j] + 2 + (total - costs[i + 2 * di][j + 2 * dj]);
          int save = total - new_cost;

          if (save <= 0)
            continue;
          if (save >= 100)
            ans++;
        }
      }
    }
  }
  cout << ans << endl;
  exit(0);
}
