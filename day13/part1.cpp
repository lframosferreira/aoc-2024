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

#define A 3
#define B 1

int main() {
  string ba, bb, prize;
  int ans = 0;
  while (getline(cin, ba)) {
    getline(cin, bb);
    getline(cin, prize);
    int ax, ay, bx, by, px, py;

    ba = ba.substr(ba.find('+') + 1);
    ax = stoi(ba.substr(0, ba.find(',')));
    ay = stoi(ba.substr(ba.find('+') + 1));

    bb = bb.substr(bb.find('+') + 1);
    bx = stoi(bb.substr(0, bb.find(',')));
    by = stoi(bb.substr(bb.find('+') + 1));

    prize = prize.substr(prize.find('=') + 1);
    px = stoi(prize.substr(0, prize.find(',')));
    py = stoi(prize.substr(prize.find('=') + 1));

    // empty line
    string trash;
    getline(cin, trash);

    // a * 94 + b * 22 = 8400
    // a*34 + b * 67 = 5400
    // a*128 + b*89 = 13800

    int det = ax * by - ay * bx;
    if (det == 0)
      continue;

    if ((px * by - py * bx) % det != 0)
      continue;
    if ((ax * py - ay * px) % det != 0)
      continue;
    int aaa = (px * by - py * bx) / det;
    int bbb = (ax * py - ay * px) / det;
    ans += 3 * aaa + bbb;
  }
  cout << ans << endl;
  exit(0);
}
