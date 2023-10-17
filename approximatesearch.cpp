#include <bits/stdc++.h>
using namespace std;

#define f(i,s,e) for(int i=s;i<e;i++)

int find_approximate(int a[], int n, int x) {
    if (x<=a[0]) {
        return a[0];
    } else if (x>=a[n-1]) {
        return a[n-1];
    }

    int l = -1;
    int r = n;

    while (r-l>1) {
        int m = r+l>>1;
        if (a[m]<=x) {
            l = m;
        } else {
            r = m;
        }
    }

    return x-a[l]<=a[r]-x ? a[l] : a[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a[n];
    f(i, 0, n) {
        cin >> a[i];
    }

    int x[k];
    f(i, 0, k) {
        cin >> x[i];
    }

    f(i, 0, k) {
        cout << find_approximate(a, n, x[i]) << '\n';
    }

    return 0;
}