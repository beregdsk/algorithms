#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define f(i,s,e) for(int i=s;i<e;i++)

double solve(double c) {
    double l = 0;
    double r = c;

    while (r-l>1e-9) {
        double m = (l+r)/2;
        if (pow(m, 2)+sqrt(m)-c>0) {
            r = m;
        } else {
            l = m;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double c;
    cin >> c;

    cout.setf(ios::fixed);
    cout.precision(20);
    cout << solve(c) << '\n';

    return 0;
}