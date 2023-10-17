#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int l = 101;
    int m = 10;
    int d = l/m+1;
    int cnt[m] = {0};
    int cnt2[d] = {0};

    int cnum;
    int a[n][2];
    for (int i=0; i<n; ++i) {
        cin >> cnum;
        
        int c = cnum / m;
        int r = cnum % m;
        a[i][0] = c;
        a[i][1] = r;
        cnt[r]++;
        cnt2[c]++;
    }

    int p[m] = {0};
    int p2[d] = {0};

    for (int i=1; i<=m; ++i) {
        p[i] = p[i-1] + cnt[i-1];
    }
    for (int i=1; i<=d; ++i) {
        p2[i] = p2[i-1] + cnt2[i-1];
    }
    
    int a2[n][2];
    for (int i=0; i<n; ++i) {
        int* k = &p[a[i][1]];
        a2[*k][0] = a[i][0];
        a2[*k][1] = a[i][1];
        (*k)++;
    } 
    for (int i=0; i<n; ++i) {
        int* k = &p2[a2[i][0]];
        a[*k][0] = a2[i][0];
        a[*k][1] = a2[i][1];
        (*k)++;
    }

    for (int i=0; i<n; ++i) {
        int number = a[i][0]*m + a[i][1];
        cout << number << ' ';
    }
    cout << '\n';

    return 0;
}
