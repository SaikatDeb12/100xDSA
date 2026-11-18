#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the function below.
    Positions are numbered 1 to n: a[i - 1] is the element at position i.
    The element at position i (1 < i < n) is a critical point if it is greater
    than both of its neighbours or smaller than both of them.
    queries[k] = [L, R] asks how many critical points are at positions i with
    L < i < R. Return the answer for every query, in order.
*/
typedef long long LL;
vector<int> countCriticalPoints(vector<int> &a, vector<vector<int>> &q) {
    int n = a.size();
    vector<pair<int, int>> b(n); // max, min
    for (int i = 0; i < n; i++) {
        if (i > 0 and i < n - 1 and a[i] > a[i - 1] and a[i] > a[i + 1]) {
            b[i].first = 1;
        }
        if (i > 0 and i < n - 1 and a[i] < a[i - 1] and a[i] < a[i + 1]) {
            b[i].second = 1;
        }
    }

    LL sum = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i].first;
        sum2 += b[i].second;
        b[i].first = sum;
        b[i].second = sum2;
    }
    // for (auto [i, j] : b) {
    //     cout << i << " " << j << "\n";
    // }

    int m = q.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        int l = q[i][0] - 1;
        int r = q[i][1] - 1;
        if (l == r) {
            ans.push_back(0);
            continue;
        }
        r = r - 1;
        l = l + 1;
        // if (l == r) {
        //     ans.push_back(0);
        //     continue;
        // }
        // r = r - 1;
        // l = l + 1;

        int mx = b[r].first - b[l - 1].first;
        int mn = b[r].second - b[l - 1].second;
        ans.push_back(mx + mn);
        // ans.push_back(b[r] - b[l - 1]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> queries(q, vector<int>(2));
    for (int k = 0; k < q; k++)
        cin >> queries[k][0] >> queries[k][1];

    vector<int> answer = countCriticalPoints(a, queries);
    for (int x : answer)
        cout << x << '\n';

    return 0;
}
