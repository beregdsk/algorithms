#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fori(i,s,e) for(int i=s;i<e;i++)

bool split(ll m, int a[], int n, int k) {
    ll sum = 0;
    int l = 1;
    fori(i,0,n) {
        if (sum+a[i]<=m) {
            sum += a[i];
        } else {
            if (a[i]>m) {
                return false;
            } else {
                sum = a[i];
                ++l;
            }
        }
    }

    return l <= k;
}

ll maxsum(int a[], int n, int k) {
    ll l = 0;
    ll r = 1e14;

    while (r-l>1) {
        ll m = l+r>>1;

        if (split(m, a, n, k)) {
            r = m;
        } else {
            l = m;
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a[n];
    fori(i,0,n) {
        cin >> a[i];
    }

    cout << maxsum(a, n, k) << '\n';

    return 0;
}