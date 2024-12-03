// pescoço pra baixo é canela

#include <bits/stdc++.h>
#include <regex>

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

ll ans;
inline void parse_mul(const string &st) {
  int a, b;
  // s começa com mul com ctz ent pulamos as tres primeiras
  regex re("mul\\(\\d{1,3},\\d{1,3}\\)|don't\\(\\)|do\\(\\)");
  sregex_iterator begin(st.begin(), st.end(), re);
  sregex_iterator end;
  int ok = 1;
  for (auto it = begin; it != end; it++) {
    int pos = (*it).position();
    if (st[pos] == 'd' and st[pos + 2] == 'n' and st[pos + 3] == '\'' and
        st[pos + 4] == 't') {
      ok = 0;
      continue;
    }
    if (st[pos] == 'd') {
      ok = 1;
      continue;
    }
    pos += 4;
    string n;
    while (st[pos] != ',') {
      n.pb(st[pos]);
      pos++;
    }
    pos++;
    a = stoi(n);
    n.clear();
    while (st[pos] != ')') {
      n.pb(st[pos]);
      pos++;
    }
    b = stoi(n);
    if (ok)
      ans += (ll)a * (ll)b;
  }
}

int main() {
  _ string st((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
  ans = 0;
  parse_mul(st);
  cout << ans << endl;
  exit(0);
}
