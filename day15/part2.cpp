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
string movement;

inline bool is_wall(int x, int y) { return mapa[x][y] == '#'; }

inline bool is_box(int x, int y) {
  return mapa[x][y] == ']' or mapa[x][y] == '[';
}

inline bool is_dot(int x, int y) { return mapa[x][y] == '.'; }

inline int allht(const string &st) {
  for (auto &c : st)
    if (c != '#')
      return 0;
  return 1;
}

set<ii> pos;

bool ok_above(int x, int y) {
  if (is_wall(x, y)) {
    return false;
  }
  if (is_box(x, y)) {
    if (mapa[x][y] == ']') {
      pos.insert(mp(x, y));
      pos.insert(mp(x, y - 1));
      return ok_above(x - 1, y) and ok_above(x - 1, y - 1);
    } else {
      pos.insert(mp(x, y));
      pos.insert(mp(x, y + 1));
      return ok_above(x - 1, y) and ok_above(x - 1, y + 1);
    }
  }
  return true;
}

bool ok_below(int x, int y) {
  if (is_wall(x, y)) {
    return false;
  }
  if (is_box(x, y)) {
    if (mapa[x][y] == ']') {
      pos.insert(mp(x, y));
      pos.insert(mp(x, y - 1));
      return ok_below(x + 1, y) and ok_below(x + 1, y - 1);
    } else {
      pos.insert(mp(x, y));
      pos.insert(mp(x, y + 1));
      return ok_below(x + 1, y) and ok_below(x + 1, y + 1);
    }
  }
  return true;
}

inline void printm() {
  for (auto &e : mapa)
    cout << e << endl;
  cout << "------------------------------------------------" << endl;
}

int rx, ry;

void push_up() {
  for (auto &[a, b] : pos) {
    mapa[a - 1][b] = mapa[a][b];
    mapa[a][b] = '.';
  }
  mapa[rx][ry] = '.';
  rx--;
  mapa[rx][ry] = '@';
}

void push_down() {
  for (auto it = pos.rbegin(); it != pos.rend(); it++) {
    auto &[a, b] = *it;
    mapa[a + 1][b] = mapa[a][b];
    mapa[a][b] = '.';
  }
  mapa[rx][ry] = '.';
  rx++;
  mapa[rx][ry] = '@';
}

int main() {
  string input = "";
  string inp;
  int i = 0;
  while (cin >> inp) {
    for (auto &c : inp) {
      if (c == '@') {
        input += "@.";
      } else if (c == 'O') {
        input += "[]";
      } else {
        input.pb(c);
        input.pb(c);
      }
    }
    mapa.pb(input);
    if (i != 0 and allht(input))
      break;
    if (input.find('@') != string::npos) {
      ry = input.find('@');
      rx = i;
    }
    i++;
    input = "";
  }
  // empty line
  getline(cin, input);
  n = sz(mapa);
  m = sz(mapa[0]);
  while (cin >> input)
    movement += input;
  int contaa = 0;
  for (auto &c : movement) {
    int idx = -1;
    bool foundbox = false;
    pos.clear();
    // if (contaa++ > 250)
    //   exit(0);
    switch (c) {
    case '^':
      if (mapa[rx - 1][ry] == ']') {
        if (ok_above(rx - 1, ry) and ok_above(rx - 1, ry - 1)) {
          push_up();
        }
      } else if (mapa[rx - 1][ry] == '[') {
        if (ok_above(rx - 1, ry) and ok_above(rx - 1, ry + 1)) {
          push_up();
        }
      } else if (mapa[rx - 1][ry] == '.') {
        mapa[rx][ry] = '.';
        rx--;
        mapa[rx][ry] = '@';
      }

      break;
    case '>':
      if (is_wall(rx, ry + 1))
        break;
      if (!is_box(rx, ry + 1)) {
        mapa[rx][ry] = '.';
        ry++;
        mapa[rx][ry] = '@';
        break;
      }
      for (int i = ry; i <= m - 2; i++) {
        if (mapa[rx][i] == '#')
          foundbox = true;
        if (mapa[rx][i] == '.' and !foundbox) {
          idx = i;
          break;
        }
      }
      if (idx != -1) {
        mapa[rx][ry] = '.';
        ry++;
        mapa[rx][ry] = '@';
        mapa[rx][idx] = '[';
        for (int i = ry + 1; i <= idx; i++) {
          if (mapa[rx][i] == ']')
            mapa[rx][i] = '[';
          else
            mapa[rx][i] = ']';
        }
      }
      break;
    case 'v':
      if (mapa[rx + 1][ry] == ']') {
        if (ok_below(rx + 1, ry) and ok_below(rx + 1, ry - 1)) {
          push_down();
        }
      } else if (mapa[rx + 1][ry] == '[') {
        if (ok_below(rx + 1, ry) and ok_below(rx + 1, ry + 1)) {
          push_down();
        }
      } else if (mapa[rx + 1][ry] == '.') {
        mapa[rx][ry] = '.';
        rx++;
        mapa[rx][ry] = '@';
      }

      break;
    case '<':
      if (is_wall(rx, ry - 1))
        break;
      if (!is_box(rx, ry - 1)) {
        mapa[rx][ry] = '.';
        ry--;
        mapa[rx][ry] = '@';
        break;
      }
      for (int i = ry; i >= 1; i--) {
        if (mapa[rx][i] == '#')
          foundbox = true;
        if (mapa[rx][i] == '.' and !foundbox) {
          idx = i;
          break;
        }
      }
      if (idx != -1) {
        mapa[rx][ry] = '.';
        ry--;
        mapa[rx][ry] = '@';
        mapa[rx][idx] = ']';
        for (int i = ry - 1; i >= idx; i--) {
          if (mapa[rx][i] == ']')
            mapa[rx][i] = '[';
          else
            mapa[rx][i] = ']';
        }
      }
      break;
    default:
      break;
    }
    // dbg(c);
    // printm();
  }
  ll ans = 0;
  printm();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] == '[') {
        int d1 = 100 * i + j;
        ans += d1;
      }
    }
  }
  cout << ans << endl;

  exit(0);
}
