#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void merge(int a[], int l, int d, int r)
{
    int c[r-l+1];
    int i = 0, j = 1, k = 0;
    while(i<=d-l && j<=r-d) {
        c[k++] = a[l+i]<a[d+j] ? a[l+i++] : a[d+j++];
    }

    if (i<=d-l) {
        copy(a+l+i, a+d+1, c+k);
    } else {
        copy(a+d+j, a+r+1, c+k);
    }

    copy(c, c+r-l+1, a+l);
}

void merge_sort(int a[], int l, int r)
{
    if (r<=l) return;

    int d = (l+r)/2;
    merge_sort(a, l, d);
    merge_sort(a, d+1, r);

    merge(a, l, d, r);
}

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

    merge_sort(a, 0, n-1);
    for (int i=0; i<n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}