// Author: takias452 | Created: 2026-11-17 20:50
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

const int N = 1e6;
vector<int> spf(N + 1);

void calculateSpf() {
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) { // not filled
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int x;
    cin >> x;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        cout << p << "^" << cnt << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    calculateSpf();
    int test = 1;
    cin >> test;
    while (test--)
        solve();
    return 0;
}
