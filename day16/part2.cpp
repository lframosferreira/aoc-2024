// pescoço pra baixo é canela

#include <bits/stdc++.h>
#include <queue>

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
int n, m, ri, rj, fi, fj;

int oob(int x, int y) {
  return x < 1 or x >= n - 1 or y < 1 or y >= m - 1 or mapa[x][y] == '#';
}
static const vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct pqval {
  int i;
  int j;
  int cost;
  ii dir;
  int pi, pj;

  bool operator<(const pqval &other) const { return cost > other.cost; }
} pqval;

set<ii> seats;
ii glob_dir = {0, 1};
int dijkstra(ii start, ii end) {

  priority_queue<pqval> pq;
  pq.push({start.f, start.s, 0, glob_dir});
  vvi vis(n, vi(m));

  while (sz(pq)) {
    auto [ni, nj, cost, dir, pi, pj] = pq.top();
    pq.pop();
    if (ni == end.f and nj == end.s) {
      glob_dir = dir;
      return cost;
    }
    if (vis[ni][nj])
      continue;
    vis[ni][nj] = 1;
    for (auto &[di, dj] : moves) {
      if (dir.f == di and dir.s == dj) {
        if (!oob(ni + di, nj + dj))
          pq.push({ni + di, nj + dj, cost + 1, dir});
      } else {
        if (!oob(ni + di, nj + dj))
          pq.push({ni + di, nj + dj, cost + 1001, {di, dj}});
      }
    }
  }
  return -1;
}

int main() {
  string st;
  int i = 0;
  while (cin >> st) {
    mapa.pb(st);
    if (st.find('S') != string::npos) {
      rj = st.find('S');
      ri = i;
    };
    if (st.find('E') != string::npos) {
      fj = st.find('E');
      fi = i;
    };
    i++;
  }
  n = sz(mapa);
  m = sz(mapa[0]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] == '.') {
        glob_dir = {0, 1};
        int v1 = dijkstra({ri, rj}, {i, j});
        int v2 = dijkstra({i, j}, {fi, fj});
        if (v1 + v2 == 130536) {
          seats.insert({i, j});
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (seats.find({i, j}) != seats.end())
        cout << 'O';
      else
        cout << mapa[i][j];
    }
    cout << endl;
  }
  cout << ans + 2 << endl;
  exit(0);
}
