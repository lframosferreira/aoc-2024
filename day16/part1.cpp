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
int n, m;

int oob(int x, int y) {
  return x < 1 or x >= n - 1 or y < 1 or y >= m - 1 or mapa[x][y] == '#';
}
static const vector<ii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct pqval {
  int i;
  int j;
  int cost;
  ii dir;

  bool operator<(const pqval &other) const { return cost > other.cost; }
} pqval;

int main() {
  _ string st;
  int ri, rj;
  int fi, fj;
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
  priority_queue<pqval> pq;
  pq.push({ri, rj, 0, {0, 1}});
  vvi vis(n, vi(m));
  while (sz(pq)) {
    auto [ni, nj, cost, dir] = pq.top();
    pq.pop();
    if (ni == fi and nj == fj) {
      cout << cost << endl;
      exit(0);
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
  exit(0);
}
