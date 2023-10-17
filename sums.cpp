#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fori(i,s,e) for(int i=s;i<e;i++)
#define print(_x) cout << (_x) << '\n'
#define print_double fixed << setprecision(20)
#define print_array(_v) fori(i,0,(_v).size()){cout<<(_v)[i]<<' ';}cout<<'\n';

ll counti(int a[], int b[], ll n, ll i, ll x) {
    ll l = -1;
    ll r = n+1;

    while (r-l>1) {
        ll m = l+r>>1;

        if (a[i]+b[m]<x) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

ll findk(int a[], int b[], ll n, ll k) {
    ll l = min(*min_element(a, a+n), *min_element(b, b+n))-1;
    ll r = *max_element(a, a+n)+*max_element(b, b+n)+1;

    while (r-l>1) {
        ll m = l+r>>1;

        ll count = 0;
        for(ll i=0; i<n; ++i) {
            ll c = counti(a, b, n, i, m);
            
            if (c==0) break;
            count += c;
            if (count>k) break;
        }

        if (count<k) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    int a[n];
    fori(i,0,n) {
        cin >> a[i];
    }
    sort(a, a+n);

    int b[n];
    fori(i,0,n) {
        cin >> b[i];
    }
    sort(b, b+n);

    cout << findk(a, b, n, k) << '\n';

    return 0;
}