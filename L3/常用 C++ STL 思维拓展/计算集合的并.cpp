#include <iostream>
#include <set>
using namespace std;
int main()
{
    freopen("merge.in", "r", stdin);
    freopen("merge.out", "w", stdout);
    set<int> se;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (set<int>::iterator it = se.begin(); it != se.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}