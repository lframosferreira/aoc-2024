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

inline bool is_box(int x, int y) { return mapa[x][y] == 'O'; }

inline int allht(const string &st) {
  for (auto &c : st)
    if (c != '#')
      return 0;
  return 1;
}

inline void printm() {
  for (auto &e : mapa)
    cout << e << endl;
  cout << "------------------------------------------------" << endl;
}

int main() {
  _ string input;
  int i = 0;
  int rx, ry;
  while (cin >> input) {
    mapa.pb(input);
    if (i != 0 and allht(input))
      break;
    if (input.find('@') != string::npos) {
      ry = input.find('@');
      rx = i;
    }
    i++;
  }
  // empty line
  getline(cin, input);
  n = sz(mapa);
  m = sz(mapa[0]);
  while (cin >> input)
    movement += input;
  for (auto &c : movement) {
    int idx = -1;
    bool foundbox = false;
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

      // is box, have to find out if boxes can be moved
      for (int i = rx; i >= 1; i--) {
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
        mapa[rx][idx] = 'O';
        mapa[rx][ry] = '.';
        ry++;
        mapa[rx][ry] = '@';
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
        mapa[rx][idx] = 'O';
        mapa[rx][ry] = '.';
        ry--;
        mapa[rx][ry] = '@';
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
