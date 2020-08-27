#include <iostream>
#include <set>
using namespace std;
int main()
{
    freopen("coin.in", "r", stdin);
    freopen("coin.out", "w", stdout);
    int n;
    cin >> n;
    set<multiset<int>> se;
    for (int i = 0; i < n; i++)
    {
        multiset<int> tmp;
        for (int j = 0; j < 5; j++)
        {
            int x;
            cin >> x;
            tmp.insert(x);
        }
        if (se.count(tmp))
        {
            cout << "pass" << endl;
        }
        else
        {
            se.insert(tmp);
            cout << "buy" << endl;
        }
    }
    return 0;
}