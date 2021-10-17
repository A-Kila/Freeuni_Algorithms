#include <bits/stdc++.h>
using namespace std;

int tree[800001];
bool lazy[800001];

void update(int i, int tl, int tr, int l, int r, int c) {
    if (tl >= l && tr <= r) {
        tree[i] = c;
        lazy[i] = 1;
        return;
    }
    if (lazy[i]) {
        tree[i * 2] = tree[i];
        lazy[i * 2] = 1;
        tree[i * 2 + 1] = tree[i];
        lazy[i * 2 + 1] = 1;
        lazy[i] = 0;
    }
    int tm = (tl + tr) / 2;
    if (tm >= l) update(i * 2, tl, tm, l, r, c);
    if (tm < r) update(i * 2 + 1, tm + 1, tr, l, r, c);
    if (tree[i * 2] == tree[i * 2 + 1])
        tree[i] = tree[i * 2];
    else tree[i] = -1;
}

void printTree(int i, int tl, int tr) {
    if (tl == tr || tree[i] != -1) {
        for (int j = 0; j < tr - tl + 1; j++) 
            cout << tree[i] << endl;
        return;
    }
    int tm = (tl + tr) / 2;
    printTree(i * 2, tl, tm);
    printTree(i * 2 + 1, tm + 1, tr);
}

int main() {
    int n, q;
    cin >> n >> q;
    tree[1] = 0;
    lazy[1] = 0;
    for (int i = 0; i < q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        update(1, 0, n - 1, l - 1, r - 1, c);
    }
    printTree(1, 0, n - 1);
    return 0;
}