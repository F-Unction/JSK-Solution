#include <iostream>
#include <map>
using namespace std;
int main()
{
    freopen("interview.in", "r", stdin);
    freopen("interview.out", "w", stdout);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans, mx = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second >= mx)
        {
            mx = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << mx << endl;
    return 0;
}