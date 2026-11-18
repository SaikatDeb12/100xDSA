// Author: takias452 | Created: 2026-11-17 17:32
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

const int LIMIT = 1e6;
vector<bool> isPrime(LIMIT + 1, true);

void generatePrimes() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIMIT; j += i)
                isPrime[j] = false;
        }
    }
}

void solve() {
    generatePrimes();
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            ans.push_back(i);
    }

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    cout << ans.size() << "\n";
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
