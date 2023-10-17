#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define fori(i,s,e) for(int i=s;i<e;i++)

double f(double x, int v1, int v2, double a) {
    return sqrt(pow(a,2)+pow(1-x,2))/v1 + sqrt(pow(1-a,2)+pow(x,2))/v2;
}

double find_h(int v1, int v2, double a) {
    double l = 0;
    double r = 1;

    while (r-l>1e-9) {
        double m1 = (2*l+r)/3;
        double m2 = (l+2*r)/3;
        if (f(m1, v1, v2, a)>=f(m2, v1, v2, a)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v1, v2;
    cin >> v1 >> v2;

    double a;
    cin >> a;

    cout << find_h(v1,  v2, a) << '\n';

    return 0;
}