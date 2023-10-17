#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Heap {
    public:
        vector<int> v;
        void insert(int x) {
            v.push_back(x);

            int i = v.size()-1;
            while (i>0 && v[i] > v[i-1>>1]) {
                swap(v[i], v[i-1>>1]);
                i = i-1>>1;
            }
        }
        
        int get_max() {
            int max = v[0];

            swap(v.front(), v.back());
            v.pop_back();

            int i = 0;
            int n = v.size();
            while (2*i+1 < n) {
                int j = 2*i + 1;
                if (j+1 < n && v[j] < v[j+1]) {
                    ++j;
                }

                if (v[i] >= v[j]) break;
                else {
                    swap(v[i], v[j]);
                    i = j;
                }
            }

            return max;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Heap h = Heap();

    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        int cmd, val;
        cin >> cmd;

        if (cmd) {
            cout << h.get_max() << '\n';
        } else {
            cin >> val;
            h.insert(val);
        }
    }

    return 0;
}