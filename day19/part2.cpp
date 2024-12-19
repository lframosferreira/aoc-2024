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

// trim functions available at
// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring trim from
// start (in place)
inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

inline void trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

set<string> towels;

int main() {
  string st;
  getline(cin, st);
  int comma;
  while ((comma = st.find(',')) != string::npos) {
    string aux = st.substr(0, comma);
    trim(aux);
    towels.insert(aux);
    st = st.substr(comma + 1);
  }
  trim(st);
  towels.insert(st);
  // for (auto e : towels)
  //   cout << e << endl;
  ll ans = 0;

  while (cin >> st) {
    vector<vector<int>> dp(sz(st) + 1, vector<int>(sz(st) + 1));
    for (int i = 0; i < sz(st) + 1; i++) {
      string aux;
      aux.pb(st[i]);
      dp[i][i] = towels.find(aux) != towels.end();
    }
    for (int j = 1; j < sz(st); j++) {
      for (int i = 0; i < sz(st) - j; i++) {
        string curr = st.substr(i, j + 1);
        dp[i][j + i] = (int)(towels.find(curr) != towels.end());
        for (int k = 0; k < j; k++) {
          dp[i][j + i] |= dp[i][i + k] and dp[i + k + 1][j + i];
        }
      }
    }
    vector<ll> dp2(sz(st) + 1);
    dp2[0] = 1;
    for (int i = 1; i <= sz(st); i++) {
      for (auto &towel : towels) {
        if (i < sz(towel))
          continue;
        if (st.substr(i - sz(towel), sz(towel)) == towel)
          dp2[i] += dp2[i - sz(towel)];
      }
    }

    ll val = dp2[sz(st)];
    ans += val;
  }
  cout << ans << endl;

  exit(0);
}
