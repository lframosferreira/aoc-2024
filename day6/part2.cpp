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

inline int oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }
inline pair<int, char> get_guard_col_and_direction(const string &st) {
  int col = -1;
  char dir = '$';

  if ((col = st.find('^')) != string::npos) {
    dir = '^';
    return mp(col, dir);
  }
  if ((col = st.find('>')) != string::npos) {
    dir = '>';
    return mp(col, dir);
  }
  if ((col = st.find('v')) != string::npos) {
    dir = 'v';
    return mp(col, dir);
  }
  if ((col = st.find('<')) != string::npos) {
    dir = '<';
    return mp(col, dir);
  }

  return mp(col, dir);
}

#define UP '^'
#define RIGHT '>'
#define DOWN 'v'
#define LEFT '<'

vector<string> v;
ii pos;
char dir;
set<tuple<int, int, char>> cj;

const int MAX = 1e3 + 10;

int upv[MAX][MAX];
int downv[MAX][MAX];
int leftv[MAX][MAX];
int rightv[MAX][MAX];

inline void printv() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << rightv[i][j] << " ";
    }
    cout << endl;
  }
  cout << "-----------------------\n";
}

bool has_cycle() {
  memset(upv, 0, sizeof(upv));
  memset(downv, 0, sizeof(upv));
  memset(leftv, 0, sizeof(upv));
  memset(rightv, 0, sizeof(upv));
  while (true) {
    if (oob(pos.f, pos.s))
      return false;
    if (v[pos.f][pos.s] != '#') {
      if (dir == UP) {
        if (upv[pos.f][pos.s] == 1)
          return true;
        upv[pos.f][pos.s] = 1;
      }
      if (dir == DOWN) {
        if (downv[pos.f][pos.s] == 1)
          return true;
        downv[pos.f][pos.s] = 1;
      }
      if (dir == LEFT) {
        if (leftv[pos.f][pos.s] == 1)
          return true;
        leftv[pos.f][pos.s] = 1;
      }
      if (dir == RIGHT) {
        if (rightv[pos.f][pos.s] == 1)
          return true;
        rightv[pos.f][pos.s] = 1;
      }
    }

    if (v[pos.f][pos.s] == '#') {
      if (dir == UP) {
        pos.f++;
        dir = RIGHT;
      } else if (dir == DOWN) {
        pos.f--;
        dir = LEFT;
      } else if (dir == LEFT) {
        pos.s++;
        dir = UP;
      } else if (dir == RIGHT) {
        dir = DOWN;
        pos.s--;
      }
    } else {

      switch (dir) {
      case UP:
        pos.f--;
        break;
      case DOWN:
        pos.f++;
        break;
      case LEFT:
        pos.s--;
        break;
      case RIGHT:
        pos.s++;
        break;
      }
    }
  }
}

int main() {
  string st;
  ii initial_pos;
  while (cin >> st) {
    v.pb(st);
    auto [col, d] = get_guard_col_and_direction(st);
    if (d != '$') {
      initial_pos = mp(n, col);
      dir = d;
    }
    n++;
  }
  m = sz(v[0]);
  int ans = 0;
  char initial_dir = dir;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp(i, j) == initial_pos or v[i][j] == '#')
        continue;
      v[i][j] = '#';
      pos = initial_pos;
      dir = initial_dir;
      ans += (int)has_cycle();
      v[i][j] = '.';
    }
  }
  cout << ans << endl;
  exit(0);
}
