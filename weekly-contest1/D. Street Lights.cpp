#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the function below.
    The street has n spots, numbered 0 to n - 1, where n is the length of
    power. If power[i] is 0 there is no lamp at spot i; otherwise the lamp
    lights every spot j with i - power[i] <= j <= i + power[i].
    Return the number of spots that no lamp lights.
*/
typedef long long LL;
int countDarkSpots(vector<int> &a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            // cout << max(0, i - a[i]) << " " << min(n - 1, i + a[i] + 1);
            b[max(0, i - a[i])]++;
            if ((i + a[i] + 1) < n)
                b[i + a[i] + 1]--;
        }
    }

    // for (auto i : b) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    int sum = 0;
    for (auto &i : b) {
        sum += i;
        i = sum;
    }
    // for (auto i : b) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    int cnt = 0;
    for (auto i : b) {
        if (i == 0)
            cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> power(n);
    for (int i = 0; i < n; i++)
        cin >> power[i];

    cout << countDarkSpots(power) << '\n';

    return 0;
}
