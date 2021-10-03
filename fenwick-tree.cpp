#include "bits/stdc++.h"
using namespace std;

const int mxn = 1e5+10;
int arr[mxn];
int tree[mxn];

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int idx, int x, int n) {
    while(idx <= n) {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}


void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    int x, a, b;
    while(q--) {
        cin >> x;
        if(x == 1) {
            cin >> a;
            a++;
            cout << arr[a] << "\n";
            update(a, -arr[a], n);
            arr[a] = 0;
        } else if(x == 2) {
            cin >> a >> b;
            a++;
            update(a, b, n);
            arr[a] += b;
        } else {
            cin >> a >> b;
            a++, b++;
            cout << query(b) - query(a-1) << "\n";
        }
    }

}


int main() {
    int t; cin >> t;
    for(int tc=1; tc<=t; tc++) {
        printf("Case %d:\n", tc);
        solve();
    }


    return 0;
}
