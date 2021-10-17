#include <bits/stdc++.h>
using namespace std;

struct data {
    int maxSize, ones, zeros;
};

data* segTree, *invTree;
bool* lazyTree;


void build(vector<bool>& arr, int s, int tl, int tr) {
    lazyTree[s] = 0;
    if (tl == tr) {
        segTree[s].maxSize = 1;
        invTree[s].maxSize = 1;
        if (arr[tl]) {
            segTree[s].ones = 1;
            segTree[s].zeros = 0;
        } else {
            segTree[s].ones = 0;
            segTree[s].zeros = 1;
        }
        invTree[s].ones = segTree[s].zeros;
        invTree[s].zeros = segTree[s].ones;
        lazyTree[s] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(arr, s * 2, tl, tm);
    build(arr, s * 2 + 1, tm + 1, tr);
    segTree[s].ones = segTree[s * 2].ones + segTree[s * 2 + 1].ones;
    segTree[s].zeros = segTree[s * 2].zeros + segTree[s * 2 + 1].zeros;
    invTree[s].ones = invTree[s * 2].ones + invTree[s * 2 + 1].ones;
    invTree[s].zeros = invTree[s * 2].zeros + invTree[s * 2 + 1].zeros;
    segTree[s].maxSize = max(segTree[s * 2].maxSize + segTree[s * 2 + 1].ones, 
                              segTree[s * 2].zeros + segTree[s * 2 + 1].maxSize);
    invTree[s].maxSize = max(invTree[s * 2].maxSize + invTree[s * 2 + 1].ones, 
                              invTree[s * 2].zeros + invTree[s * 2 + 1].maxSize);
}

void update(vector<bool>& arr, int s, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r) {
        swap(segTree[s], invTree[s]);
        lazyTree[s] = !lazyTree[s];
        return;
    }
    if (lazyTree[s]) {
        swap(segTree[s * 2], invTree[s * 2]);
        lazyTree[s * 2] = !lazyTree[s * 2];
        swap(segTree[s * 2 + 1], invTree[s * 2 + 1]);
        lazyTree[s * 2 + 1] = !lazyTree[s * 2 + 1];
        lazyTree[s] = 0;
    }
    int tm = (tl + tr) / 2;
    if (tm >= l)
        update(arr, s * 2, tl, tm, l, r);
    if (tm < r)
        update(arr, s * 2 + 1, tm + 1, tr, l, r);
    segTree[s].ones = segTree[s * 2].ones + segTree[s * 2 + 1].ones;
    segTree[s].zeros = segTree[s * 2].zeros + segTree[s * 2 + 1].zeros;
    invTree[s].ones = invTree[s * 2].ones + invTree[s * 2 + 1].ones;
    invTree[s].zeros = invTree[s * 2].zeros + invTree[s * 2 + 1].zeros;
    segTree[s].maxSize = max(segTree[s * 2].maxSize + segTree[s * 2 + 1].ones, 
                              segTree[s * 2].zeros + segTree[s * 2 + 1].maxSize);
    invTree[s].maxSize = max(invTree[s * 2].maxSize + invTree[s * 2 + 1].ones, 
                              invTree[s * 2].zeros + invTree[s * 2 + 1].maxSize);
}

int main() {
    int size, q;    
    cin >> size >> q;
    vector<bool> arr;
    data tree[4 * size];
    data inverse[4 * size];
    bool lazy[4 * size];
    segTree = tree;
    invTree = inverse;
    lazyTree = lazy;
    for (int i = 0; i < size; i++) {
        char a;
        cin >> a;
        arr.push_back(a - '0');
    }
    build(arr, 1, 0, size - 1);
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r;
            cin >> l >> r;
            update(arr, 1, 0, size - 1, l - 1, r - 1);

        } else {
            cout << segTree[1].maxSize << endl;
        }
    }
}