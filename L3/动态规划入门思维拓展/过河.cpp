#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1010];
int f[1010];
int main()
{
    freopen("bridge.in", "r", stdin);
    freopen("bridge.out", "w".stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    f[0] = a[0];
    f[1] = a[1];
    for (int i = 2; i < n; ++i)
    {
        f[i] = min(f[i - 1] + a[0] + a[i], f[i - 2] + a[0] + 2 * a[1] + a[i]);
    }
    cout << f[n - 1] << endl;
}