// Author: takias452 | Created: 2026-10-23 15:03
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
    int n, q;
    cin >> n >> q;
    vector<LL> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> b(n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1])
            b[i + 1] = 1;
    }

    LL sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
        b[i] = sum;
    }

    dbg(b);
    while (q--) {
        LL l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            cout << "0\n";
            continue;
        }
        LL val = b[r] - b[l];
        cout << val << "\n";
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
