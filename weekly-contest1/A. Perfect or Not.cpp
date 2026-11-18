// Author: takias452 | Created: 2026-10-26 11:00
#include <bits/stdc++.h>
#include <numeric>
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
    int n;
    cin >> n;
    vector<int> temp;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            temp.push_back(i);
            if ((n / i) != i) {
                temp.push_back(n / i);
            }
        }
    }
    dbg(temp);
    sort(temp.begin(), temp.end());
    LL sum = 0;
    for (int i = 0; i < temp.size() - 1; i++) {
        sum += temp[i];
    }
    if (sum == n)
        cout << "Perfect\n";
    else if (sum > n)
        cout << "Abundant\n";
    else
        cout << "Deficient\n";
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
