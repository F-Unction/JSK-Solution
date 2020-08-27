#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    int n;
    LL a[51];
    a[1] = 3;
    a[2] = 6;
    a[3] = 6;
    for (int i = 4; i <= 50; ++i)
    {
        a[i] = a[i - 1] + a[i - 2] * 2;
    }
    cin >> n;
    cout << a[n] << endl;
    return 0;
}