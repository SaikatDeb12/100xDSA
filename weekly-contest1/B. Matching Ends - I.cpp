#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the function below.
    Return the number of pairs (l, r) with 0 <= l <= r < n and
    colours[l] == colours[r]. A piece made of a single bead counts.
*/
typedef long long LL;
long long countPrettyPieces(vector<int> &a) {
    int n = a.size();
    map<int, vector<int>> t;
    for (int i = 0; i < n; i++) {
        t[a[i]].push_back(i);
    }
    LL cnt = 0;
    LL ans = 0;
    for (auto [i, j] : t) {
        LL m = j.size();
        // cout << m << " ";
        cnt += ((m * (m + 1) / 2));
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> colours(n);
    for (int i = 0; i < n; i++)
        cin >> colours[i];

    cout << countPrettyPieces(colours) << '\n';

    return 0;
}
