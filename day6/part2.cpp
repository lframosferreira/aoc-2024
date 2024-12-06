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

int n, m;

inline int oob(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }

int get_ans(const vvi &cnt) {
  int ans = 0;
  for (auto &e1 : cnt)
    for (auto &e2 : e1)
      ans += e2;
  return ans;
}

inline void printv(const vvi &v) {
  for (auto &e1 : v) {
    for (auto &e2 : e1) {
      cout << (char)e2 << " ";
    }
    cout << endl;
  }
}

inline void printmap(const vector<string> &vm) {
  for (auto &fff : vm)
    cout << fff << endl;
}

int main() {
  _ vector<string> v;
  string st;
  ii pos;
  char dir;
  n = 0;
  while (cin >> st) {
    v.pb(st);
    auto [col, d] = get_guard_col_and_direction(st);
    if (d != '$') {
      pos = mp(n, col);
      dir = d;
    }
    n++;
  }
  ii initial_pos = pos;
  m = sz(v[0]);
  vvi cnt(n, vi(m));
  set<ii> visited;
  int shouldbreak = 0;
  while (1) {
    if (shouldbreak)
      break;
    switch (dir) {
    case '^':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = '^';
        visited.insert(pos);
        pos.f--;
      }
      if (oob(pos.f, pos.s)) {
        shouldbreak = 1;
      }
      dir = '>';
      pos.f++;
      break;
    case '>':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = '>';

        visited.insert(pos);
        pos.s++;
      }
      if (oob(pos.f, pos.s)) {
        shouldbreak = 1;
      }
      dir = 'v';
      pos.s--;
      break;
    case 'v':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = 'v';
        visited.insert(pos);
        pos.f++;
      }
      if (oob(pos.f, pos.s)) {
        shouldbreak = 1;
      }
      dir = '<';
      pos.f--;
      break;
    case '<':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = '<';
        visited.insert(pos);
        pos.s--;
      }
      if (oob(pos.f, pos.s)) {
        shouldbreak = 1;
      }
      pos.s++;
      dir = '^';

      break;
    default:
      cout << "should't be here" << endl;
      exit(1);
    }
  }
  vector<string> v2 = v;
  int ans = 0;
  vector<ii> vis(all(visited));
  char initial_dir = dir;
  for (int i = 0; i < sz(vis); i++) {
    cnt = vvi(n, vi(m));
    cnt[initial_pos.f][initial_pos.s] = initial_dir;
    dir = initial_dir;
    auto &[a, b] = vis[i];
    dbg(a);
    dbg(b);
    if (a == initial_pos.f and b == initial_pos.s)
      continue;
    if (a != 16 or b != 6)
      continue;
    v2[a][b] = '#';
    shouldbreak = 0;
    pos = initial_pos;
    while (1) {
      printv(cnt);
      if (shouldbreak)
        break;
      switch (dir) {
      case '^':
        while (!oob(pos.f, pos.s) and v2[pos.f][pos.s] != '#') {
          if (!oob(pos.f - 1, pos.s) and v2[pos.f - 1][pos.s] == '#' and
              cnt[pos.f][pos.s] == '>') {
            ans++;
            // printmap(v2);
            // cout << "-----------------------\n";
            shouldbreak = 1;
          }
          cnt[pos.f][pos.s] = '^';
          pos.f--;
        }
        if (oob(pos.f, pos.s)) {
          shouldbreak = 1;
        }
        dir = '>';
        pos.f++;
        break;
      case '>':
        while (!oob(pos.f, pos.s) and v2[pos.f][pos.s] != '#') {
          if (!oob(pos.f, pos.s + 1) and v2[pos.f][pos.s + 1] == '#' and
              cnt[pos.f][pos.s] == 'v') {
            ans++;

            // printmap(v2);
            // cout << "-----------------------\n";
            shouldbreak = 1;
          }
          cnt[pos.f][pos.s] = '>';
          pos.s++;
        }
        if (oob(pos.f, pos.s)) {
          shouldbreak = 1;
        }
        dir = 'v';
        pos.s--;
        break;
      case 'v':
        while (!oob(pos.f, pos.s) and v2[pos.f][pos.s] != '#') {
          if (!oob(pos.f + 1, pos.s) and v2[pos.f + 1][pos.s] == '#' and
              cnt[pos.f][pos.s] == '<') {
            ans++;
            shouldbreak = 1;
            // printmap(v2);
            // cout << "-----------------------\n";
          }
          cnt[pos.f][pos.s] = 'v';
          pos.f++;
        }
        if (oob(pos.f, pos.s)) {
          shouldbreak = 1;
        }
        dir = '<';
        pos.f--;
        break;
      case '<':
        while (!oob(pos.f, pos.s) and v2[pos.f][pos.s] != '#') {
          if (!oob(pos.f, pos.s - 1) and v2[pos.f][pos.s - 1] == '#' and
              cnt[pos.f][pos.s] == '^') {
            ans++;
            shouldbreak = 1;
            // printmap(v2);
            // cout << "-----------------------\n";
          }
          cnt[pos.f][pos.s] = '<';
          pos.s--;
        }
        if (oob(pos.f, pos.s)) {
          shouldbreak = 1;
        }
        pos.s++;
        dir = '^';

        break;
      default:
        cout << "should't be here" << endl;
        exit(1);
      }
    }
    // printv(cnt);
    v2[a][b] = '.';
  }
  cout << ans << endl;
  exit(0);
}
