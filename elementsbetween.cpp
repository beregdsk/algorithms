#include <bits/stdc++.h>
#include <string.h>
#include <iterator>
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

int bin_search(int a[], int n, int x, bool dir) {
    int l = -1;
    int r = n;

    if (dir) {
        while (r > l+1) {
            int m = l+r>>1;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }

        return r;
    } else {
        while (r > l+1) {
            int m = l+r>>1;
            if (a[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }

        return l;
    }
}

int elements_between(int a[], int n, int l, int r) {
    return bin_search(a, n, r, 1)-bin_search(a, n, l, 0)-1;
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
    
    int m;
    cin >> m;
    
    for (int i=0; i<m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << elements_between(a, n, l, r) << '\n';
    }

    return 0;
}