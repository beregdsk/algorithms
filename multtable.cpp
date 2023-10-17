#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef long long ll;

#define fori(i,s,e) for(int i=s;i<e;++i)
#define forir(i,s,e) for(int i=e-1;i>=s;--i)
#define print(_x) cout << (_x) << '\n'
#define print_double fixed << setprecision(20)
#define print_array(_v) fori(i,0,(_v).size()){cout<<(_v)[i]<<' ';}cout<<'\n';

int split(vector<int> &a, int l, int r, int xi) {
    int m = l;
    int x = a[xi];
    swap(a[xi], a[r]);
    fori(i,l,r) {
        if (a[i]<x) {
            swap(a[i], a[m]);
            ++m;
        }
    }
    swap(a[r], a[m]);
    return m;
}

int findk(vector<int> &a, int l, int r, int k) {
    if (r-l<=0) return a[l];
    
    int xi = rand()%(r-l+1)+l;
    int m = split(a, l, r, xi);
    if (k==m) return a[k];
    if (k<m) {
        return findk(a, l, m-1, k);
    } else {
        return findk(a, m+1, r, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n*n);
    forir(i,0,n) {
        forir(j,0,n) {
            a[i*n+j] = (i+1)*(j+1);
        }
    }

    cout << findk(a, 0, n*n-1, k-1) << '\n';

    return 0;
}