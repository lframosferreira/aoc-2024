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

inline int modd(int a, int mo) {
  int ret = a % mo;
  return ret < 0 ? mo + ret : ret;
}

typedef struct Robot {
  int px;
  int py;
  int vx;
  int vy;
} Robot;

const int n = 103;
const int m = 101;
vvi mapa = vvi(n, vi(m));
int i;

inline bool borda(int a, int b) {
  return a <= 0 or a == n - 1 or b <= 0 or b == m - 1;
}
static const vector<ii> moves = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

inline void printm() {
  cout << "----------------------------------------" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int skip = 0;
      if (!borda(i, j)) {
        for (auto &[dx, dy] : moves) {
          skip += mapa[i + dx][j + dy];
        }
      }
      cout << (mapa[i][j] and skip != 0 ? '*' : ' ');
    }
    cout << endl;
  }
  cout << "----------------------------------------" << endl;
  dbg(i);
  std::this_thread::sleep_for(std::chrono::milliseconds(400));
  cout << "\033[2J\033[H" << flush;
}

int main() {
  string input;
  int quads[2][2] = {0};
  vector<Robot> robots;
  while (getline(cin, input)) {
    Robot r;
    input = input.substr(input.find('=') + 1);
    string pos = input;
    r.px = stoi(input.substr(0, input.find(',')));
    r.py = stoi(input.substr(input.find(',') + 1, input.find(' ')));
    input = input.substr(input.find('=') + 1);
    r.vx = stoi(input.substr(0, input.find(',')));
    r.vy = stoi(input.substr(input.find(',') + 1));
    mapa[r.py][r.px]++;
    robots.pb(r);
  }
  for (i = 0; i < 7350; i++) {
    for (auto &[px, py, vx, vy] : robots) {
      mapa[py][px]--;
      px = modd(px + vx, m);
      py = modd(py + vy, n);
      mapa[py][px]++;
    }
    if (i == 7137)
      printm();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == n / 2 or j == m / 2)
        continue;
      quads[i < n / 2][j < m / 2] += mapa[i][j];
    }
  }
  int ans = quads[0][0] * quads[0][1] * quads[1][0] * quads[1][1];
  cout << ans << endl;

  exit(0);
}
