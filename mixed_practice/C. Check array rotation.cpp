// Author: takias452 | Created: 2026-10-13 11:18
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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> ind;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    int l = 0, r = n - 1;
    int mn = INT_MAX;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[l] <= a[mid]) {
            mn = min(mn, a[l]);
            l = mid + 1;
        } else if (a[mid] <= a[r]) {
            mn = min(mn, a[mid]);
            r = mid - 1;
        }
    }
    cout << ind[mn] << "\n";
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

// class Solution {
//   public:
//     int findMin(vector<int> &a) {
//         int n = a.size();
//         int l = 0, r = n - 1;
//         int mn = INT_MAX;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             mn = min(mn, a[mid]);
//             mn = min(mn, a[l]);
//             mn = min(mn, a[r]);
//             if (a[l] <= a[mid] and a[mid] <= a[r]) {
//                 // both side sorted
//                 r = mid - 1;
//             } else if (a[l] <= a[mid]) {
//                 l = mid + 1;
//             } else if (a[mid] <= a[r]) {
//                 r = mid - 1;
//             }
//         }
//         return mn;
//     }
// };

// class Solution {
//   public:
//     bool search(vector<int> &a, int t) {
//         int n = a.size();
//         int l = 0, r = n - 1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (a[l] == a[mid] and a[mid] == a[r]) {
//                 int mid2 = l + (mid - l) / 2;
//                 int mid3 = mid + (r - mid) / 2;
//                 if (a[mid2] != a[mid]) {
//                     r = mid - 1;
//                 } else {
//                     l = mid + 1;
//                 }
//             } else if (a[l] <= a[mid]) {
//                 if (a[l] <= t and t <= a[mid]) {
//                     r = mid - 1;
//                 } else {
//                     l = mid + 1;
//                 }
//             } else if (a[mid] <= a[r]) {
//                 if (a[mid] <= t and t <= a[r]) {
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };

// class Solution {
//   public:
//     int search(vector<int> &a, int t) {
//         int n = a.size();
//         int l = 0, r = n - 1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (a[mid] == t) {
//                 return mid;
//             } else if (a[l] <= a[mid]) {
//                 if (a[l] <= t and a[mid] >= t) {
//                     r = mid - 1;
//                 } else {
//                     l = mid + 1;
//                 }
//             } else if (a[mid] <= a[r]) {
//                 if (a[mid] <= t and a[r] >= t) {
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };
