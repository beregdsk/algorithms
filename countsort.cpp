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
    
    int m = 101;
    int cnt[m] = {0};

    int cnum;
    for (int i=0; i<n; ++i) {
        cin >> cnum;
        cnt[cnum]++;
    }
    
    int a[n];
    int k = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<cnt[i]; ++j) {
            a[k++] = i;
        }
    }

    for (int i=0; i<n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}