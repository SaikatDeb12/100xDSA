#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the function below.
    s contains only '0' and '1', and its characters are numbered 1 to n.
    queries[k] = [L, R] asks whether the substring from character L to
    character R contains as many zeros as ones.
    For every query, in order, return whether that substring is balanced.
*/
vector<bool> balancedQueries(string &s, vector<vector<int>> &q) {
    int n = s.length();
    vector<pair<int, int>> temp(n);
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zero++;
        else
            one++;
        temp[i].first = zero;
        temp[i].second = one;
    }
    // for (auto [i, j] : temp) {
    //     cout << i << " " << j << "\n";
    // }
    //
    // cout << "\n";
    int m = q.size();
    vector<bool> ans;
    for (int i = 0; i < m; i++) {
        int l = q[i][0] - 1;
        int r = q[i][1] - 1;
        int zero = temp[r].first;
        if (l > 0)
            zero -= temp[l - 1].first;
        int one = temp[r].second;
        if (l > 0)
            one -= temp[l - 1].second;
        // cout << zero << " " << one << "\n";
        if (zero == one)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int k = 0; k < q; k++)
        cin >> queries[k][0] >> queries[k][1];

    vector<bool> answer = balancedQueries(s, queries);
    for (bool ok : answer)
        cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}
