#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

#define fori(i,s,e) for(int i=s;i<e;i++)
#define print(_x) cout << (_x) << '\n'
#define print_double fixed << setprecision(20)
#define print_array(_v) fori(i,0,(_v).size()){cout<<(_v)[i]<<' ';}cout<<'\n';

vector<pair<double, int>> kbest(int n, int k, vector<int> v, vector<int> w) {
    double l = 0;
    double r = 1e9;

    while (r-l>1e-6) {
        double m = (l+r)/2;
        
        vector<double> a(n);
        fori(i,0,n) {
            a[i] = v[i]-m*w[i];
        }

        sort(a.rbegin(), a.rend());

        double sum = 0;
        fori(i,0,k) {
            sum += a[i];
        }

        if (sum>=0) {
            l = m;
        } else {
            r = m;
        }
    }

    vector<pair<double, int>> b(n);
    fori(i,0,n) {
        b[i].first = v[i]-l*w[i];
        b[i].second = i;
    }

    sort(b.rbegin(), b.rend());

    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    vector<int> v(n), w(n);
    fori(i,0,n) {
        cin >> v[i] >> w[i];
    }

    fori(i,0,k) cout<<kbest(n, k, v, w)[i].second+1 << ' ';

    return 0;
}