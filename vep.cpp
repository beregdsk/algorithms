#include <bits/stdc++.h>
using namespace std;
 
#define f(i,s,e) for(int i=s;i<e;i++)
 
int print_time(int n, int x, int y) {
    int l = -1;
    int r = (n+1)*y;
 
    while(r-l>1) {
        int m = r+l>>1;
        if (m/x + m/y<n) {
            l = m;
        } else {
            r = m;
        }
    }
 
    return r+x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, x, y;
    cin >> n >> x >> y;
 
    if (x>y) swap(x, y);
 
    cout << print_time(n-1, x, y) << '\n';
 
    return 0;
}