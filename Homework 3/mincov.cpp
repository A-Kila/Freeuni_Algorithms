#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, l, r, firstl;
    cin >> m;
    pair<int, int> arr[m]; // l, r
    int right[m];
    memset(right, 0, 4 * m);
    while (true) {
        cin >> l >> r;
        if (!(l | r)) break;
        if (l > m || r < 0) continue;
        int i = l;
        if (l < 0) i = 0;
        if (r > right[i]) {
            if (i == 0) firstl = l;
            right[i] = r;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!i) {
            arr[i] = {firstl, right[i]};
            continue;
        }
        if (arr[i - 1].second > right[i])  
            arr[i] = arr[i - 1];
        else arr[i] = {i, right[i]};
    }
    int size = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < m; i = arr[i].second) {
        if (arr[i].second == i) {
            cout << "No solution" << endl;
            return 0;
        }
        size++;
        res.push_back({arr[i].first, arr[i].second});
    }
    cout << size << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
}