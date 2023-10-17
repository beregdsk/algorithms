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

    int a[n] = {0};
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    int counter = 0;
    for (int i=1; i<n; ++i) {
        int j = i-1;
        while(j>=0 && a[j+1]<a[j]) {
            swap(a[j+1], a[j]);
            --j;
            ++counter;
        }
    }

    cout << counter << '\n';
    for (int i=0; i<n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}