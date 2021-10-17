#include <bits/stdc++.h>
using namespace std;

int getLongestPaliSize(string& s) {
    int arr[s.size() + 1][s.size() + 1];
    for (int i = 0; i <= s.size(); i++) 
        for (int j = 0; j <= s.size(); j++) {
            if (i == 0 || j == 0) 
                arr[i][j] = 0;
            else if (s[i - 1] == s[s.size() - j])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else 
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    return arr[s.size()][s.size()];
}

int main() {
    int n;
    string in;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        int longPaliSize = getLongestPaliSize(in);
        cout << in.size() - longPaliSize << endl;
    }
    return 0;
}