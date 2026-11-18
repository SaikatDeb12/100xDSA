// Author: takias452 | Created: 2026-11-10 15:12
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
    LL n, x;
    cin >> n >> x;
    vector<LL> a(n);
    for (auto &i : a)
        cin >> i;

    LL l = 1, r = 10000000000;
    while (l <= r) {
        LL h = l + (r - l) / 2;
        LL water = 0;
        for (auto &i : a) {
            water += max(0LL, h - i);
        }

        if (water > x)
            r = h - 1;
        else
            l = h + 1;
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    int test = 1;
    cin >> test;
    while (test--)
        solve();
    return 0;
}
