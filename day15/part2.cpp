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

  if (is_wall(x - 1, y))
    return false;
  if (is_box(x - 1, y)) {
    if (mapa[x - 1][y] == ']')
      return ok_above(x - 1, y) and ok_above(x - 1, y - 1);
    else
      return ok_above(x - 1, y) and ok_above(x - 1, y + 1);
  }
  return true;
}

inline void printm() {
  for (auto &e : mapa)
    cout << e << endl;
  cout << "------------------------------------------------" << endl;
}

void push_up(int x, int y) {
  if (mapa[x - 1][y] == '[') {
    push_up(x - 1, y);
    push_up(x - 1, y + 1);
  } else if (mapa[x - 1][y] == ']') {
    push_up(x - 1, y);
    push_up(x - 1, y - 1);
  } else {
    mapa[x - 1][y] = mapa[x][y];
  }
}

int main() {
  string input = "";
  string inp;
  int i = 0;
  int rx, ry;
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
  m = sz(mapa[0]);
  while (cin >> input)
    movement += input;
  for (auto &c : movement) {
    int idx = -1;
    bool foundbox = false;
    dbg(c);
    printm();
    if (c == 'v')
      exit(0);
    switch (c) {
    case '^':
      if (is_wall(rx - 1, ry))
        break;
      if (!is_box(rx - 1, ry)) {
        mapa[rx][ry] = '.';
        rx--;
        mapa[rx][ry] = '@';
        break;
      }

      if (ok_above(rx, ry)) {
        push_up(rx, ry);
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
      if (is_wall(rx + 1, ry))
        break;
      if (!is_box(rx + 1, ry)) {
        mapa[rx][ry] = '.';
        rx++;
        mapa[rx][ry] = '@';
        break;
      }
      for (int i = rx; i <= n - 2; i++) {
        if (mapa[i][ry] == '#')
          foundbox = true;
        if (mapa[i][ry] == '.' and !foundbox) {
          idx = i;
          break;
        }
      }
      if (idx != -1) {
        mapa[idx][ry] = 'O';
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
  }
  ll ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m - 2; j++) {
      if (mapa[i][j] == 'O') {
        ans += 100 * i + j;
      }
    }
  }
  cout << ans << endl;

  exit(0);
}
