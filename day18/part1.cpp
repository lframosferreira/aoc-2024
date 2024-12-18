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

#define SZ 71

vvi mapa(SZ, vi(SZ));
vvi vis(SZ, vi(SZ));
static const vector<ii> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int oob(int x, int y) {
  return x < 0 or x >= SZ or y < 0 or y >= SZ or mapa[x][y] == 1;
}

void printm() {
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      cout << (mapa[j][i] ? '#' : '.');
    }
    cout << endl;
  }
}

int bfs() {
  queue<iii> q;
  q.push({0, 0, 0});
  while (sz(q)) {
    auto [ni, nj, cost] = q.front();
    q.pop();
    if (ni == SZ - 1 and nj == SZ - 1)
      return cost;
    if (vis[ni][nj])
      continue;
    vis[ni][nj] = 1;
    for (auto [di, dj] : moves) {
      if (oob(ni + di, nj + dj) or vis[ni + di][nj + dj])
        continue;
      q.push({ni + di, nj + dj, cost + 1});
    }
  }
  return -1;
}

int main() {
  _ string st;
  vector<ii> bytes;
  while (cin >> st) {
    int i = stoi(st.substr(0, st.find(',')));
    int j = stoi(st.substr(st.find(',') + 1));
    bytes.pb({i, j});
  }
  for (int i = 0; i < sz(bytes); i++) {
    auto [a, b] = bytes[i];
    mapa[a][b] = 1;
    for (auto &e : vis)
      fill(all(e), 0);
    int ans = bfs();
    if (ans == -1) {
      cout << a << "," << b << endl;
      break;
    }
  }
  exit(0);
}
