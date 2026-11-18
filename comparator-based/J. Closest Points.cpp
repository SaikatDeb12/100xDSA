// Author: takias452 | Created: 2026-10-27 01:16
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
static ofstream debug_stream("error.txt");
#endif

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() {
#ifndef ONLINE_JUDGE
    debug_stream << endl;
#endif
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
#ifndef ONLINE_JUDGE
    debug_stream << ' ' << H;
    dbg_out(T...);
#endif
}

#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    debug_stream << '[' << __FILE__ << ':' << __LINE__ << "] ("                \
                 << #__VA_ARGS__ << "):",                                      \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using int128 = __int128_t;
typedef long long LL;
#define inf_p INT_MAX
#define inf_n INT_MIN
#define inf_pll LLONG_MAX
#define inf_nll LLONG_MIN
const LL MOD = 1000000007;
const LL MOD1 = 998244353;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    vector<pair<pair<LL, LL>, LL>> t(n);
    for (int i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        t[i].first = make_pair(l, r);
        LL dx = (l - a) * (l - a);
        LL dy = (r - b) * (r - b);
        t[i].second = dx + dy;
    }

    sort(t.begin(), t.end(), [](const auto &a, const auto &b) {
        if (a.second == b.second) {
            if (a.first.first == b.first.first) {
                return a.first.second < b.first.second;
            }
            return a.first.first < b.first.first;
        }
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << t[i].first.first << " " << t[i].first.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    int test = 1;
    while (test--)
        solve();
    return 0;
}
