#include <iostream>
#include <string>

using namespace std;

string GetRuler(const string &kingdom)
{
    if (kingdom == "")
    {
        return "nobody";
    }

    int ind = kingdom.length() - 1;
    char ch = kingdom[ind];
    if (ch == 'y' || ch == 'Y')
    {
        return "nobody";
    }
    else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
             ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return "Alice";
    }
    else
    {
        return "Bob";
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    string kingdom;

    for (int t = 1; t <= testcases; ++t)
    {
        cin >> kingdom;
        cout << "Case #" << t << ": " << kingdom << " is ruled by "
             << GetRuler(kingdom) << ".\n";
    }
    return 0;
}
