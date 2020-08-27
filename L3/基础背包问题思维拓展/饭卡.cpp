#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e3 + 9;

int a[1010], f[N];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    memset(f, 0, sizeof f);
    f[0] = 1;
    sort(a, a + n);
    int ma = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 5; j >= 0; --j)
        {
            if (f[j])
            {
                f[j + a[i]] = 1;
                ma = max(ma, j + a[i]);
            }
        }
    }
    cout << m - ma << endl;
    return 0;
}