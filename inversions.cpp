#include <bits/stdc++.h>
#include <string.h>
using namespace std;

long long cnt = 0;

int* merge(int a[], int n, int b[], int m)
{
    int *c = new int[n+m];
    int i = 0, j = 0, k = 0;
    while(k<n+m) {
        if (j==m || (i<n && a[i]<b[j])) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
            cnt += n-i;
        }
    }
    
    delete[] a;
    delete[] b;

    return c;
}

int* merge_count(int a[], int l, int r)
{
    if (r-l<=1) return new int[1]{a[l]};

    int d = l+r >> 1;
    int *b = merge_count(a, l, d);
    int *c = merge_count(a, d, r);

    return merge(b, d-l, c, r-d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *a = new int[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    int* m = merge_count(a, 0, n);
    cout << cnt << endl;

    return 0;
}