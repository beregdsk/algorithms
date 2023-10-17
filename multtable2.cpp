#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fori(i,s,e) for(int i=s;i<e;i++)
#define print(_x) cout << (_x) << '\n'
#define print_double fixed << setprecision(20)
#define print_array(_v) fori(i,0,(_v).size()){cout<<(_v)[i]<<' ';}cout<<'\n';

ll findk(ll n, ll k) {
    ll l = 1;
    ll r = 1LL*n*n+1;

    while (r-l>1) {
        ll m = (l+r)>>1;

        ll sum = 0;
        fori(i, 0, n) {
            sum += min(n, (m-1)/(i+1));
        }

        if (sum<k) {
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

    cout << findk(n, k) << '\n';

    return 0;
}