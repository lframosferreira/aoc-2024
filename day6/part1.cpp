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
      cout << e2 << " ";
    }
    cout << endl;
  }
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
  m = sz(v[0]);
  vvi cnt(n, vi(m));
  while (1) {
    switch (dir) {
    case '^':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = 1;
        pos.f--;
      }
      if (oob(pos.f, pos.s)) {
        cout << get_ans(cnt) << endl;
        exit(0);
      }
      dir = '>';
      pos.f++;
      break;
    case '>':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = 1;
        pos.s++;
      }
      if (oob(pos.f, pos.s)) {
        cout << get_ans(cnt) << endl;
        exit(0);
      }
      dir = 'v';
      pos.s--;
      break;
    case 'v':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = 1;
        pos.f++;
      }
      if (oob(pos.f, pos.s)) {
        cout << get_ans(cnt) << endl;
        exit(0);
      }
      dir = '<';
      pos.f--;
      break;
    case '<':
      while (!oob(pos.f, pos.s) and v[pos.f][pos.s] != '#') {
        cnt[pos.f][pos.s] = 1;
        pos.s--;
      }
      if (oob(pos.f, pos.s)) {
        cout << get_ans(cnt) << endl;
        exit(0);
      }
      pos.s++;
      dir = '^';

      break;
    default:
      cout << "should't be here" << endl;
      exit(1);
    }
  }
  exit(0);
}
