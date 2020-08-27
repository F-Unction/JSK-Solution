#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    freopen("fruit.in", "r", stdin);
    freopen("fruit.out", "w", stdout);
    int n;
    cin >> n;
    map<string, map<string, int>> mp;
    for (int i = 0; i < n; i++)
    {
        string place, name;
        int x;
        cin >> name >> place >> x;
        mp[place][name] += x;
    }
    for (map<string, map<string, int>>::iterator it1 = mp.begin();
         it1 != mp.end(); it1++)
    {
        cout << it1->first << endl;
        for (map<string, int>::iterator it2 = it1->second.begin();
             it2 != it1->second.end(); it2++)
        {
            cout << "   |----" << it2->first << "(" << it2->second << ")" << endl;
        }
    }
    return 0;
}