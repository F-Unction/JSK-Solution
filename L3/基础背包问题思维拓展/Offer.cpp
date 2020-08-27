#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 1e4 + 9;
double f[N];
int main()
{
    freopen("offer.in", "r", stdin);
    freopen("offer.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int x;
    double y;
    while (m--)
    {
        cin >> x >> y;
        for (int j = n; j >= x; j--)
        {
            f[j] = max(f[j], 1.0 - (1 - f[j - x]) * (1 - y));
        }
    }
    printf("%.1lf%%\n", f[n] * 100);
    return 0;
}