#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    freopen("study.in", "r", stdin);
    freopen("study.out", "w", stdout);
    set<string> se;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        string word;
        cin >> op >> word;
        for (int j = 0; j < word.size(); j++)
        {
            if (word[j] >= 'A' && word[j] <= 'Z')
            {
                word[j] += 'a' - 'A';
            }
        }
        if (op == 0)
        {
            se.insert(word);
        }
        else
        {
            if (se.count(word))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}