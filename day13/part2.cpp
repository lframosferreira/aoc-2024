// pescoço pra baixo é canela

#include <bits/stdc++.h>
#include <numeric>

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

const ull val = 10000000000000;

int main() {
  string ba, bb, prize;
  ll ans = 0;
  while (getline(cin, ba)) {
    getline(cin, bb);
    getline(cin, prize);
    ll ax, ay, bx, by, px, py;

    ba = ba.substr(ba.find('+') + 1);
    ax = stoll(ba.substr(0, ba.find(',')));
    ay = stoll(ba.substr(ba.find('+') + 1));

    bb = bb.substr(bb.find('+') + 1);
    bx = stoll(bb.substr(0, bb.find(',')));
    by = stoll(bb.substr(bb.find('+') + 1));

    prize = prize.substr(prize.find('=') + 1);
    px = val + stoll(prize.substr(0, prize.find(',')));
    py = val + stoll(prize.substr(prize.find('=') + 1));

    // empty line
    string trash;
    getline(cin, trash);

    // a * 94 + b * 22 = 8400
    // a*34 + b * 67 = 5400
    // a*128 + b*89 = 13800

    ll det = ax * by - ay * bx;
    if (det == 0)
      continue;

    if ((px * by - py * bx) % det != 0)
      continue;
    if ((ax * py - ay * px) % det != 0)
      continue;
    ll aaa = (px * by - py * bx) / det;
    ull bbb = (ax * py - ay * px) / det;
    ans += 3 * aaa + bbb;
  }
  cout << ans << endl;
  exit(0);
}
