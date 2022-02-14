#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int z = 0; z < n; z++)
    {
        int num_bag, num_kid;
        cin >> num_bag;
        cin >> num_kid;
        vector<int> candy(num_bag);
        int sum = 0;
        for (int i = 0; i < num_bag; i++)
        {
            cin >> candy[i];
            sum += candy[i];
        }
        int remain = 0;

        remain = sum % num_kid;

        cout << "Case #" << z + 1 << ": " << remain << endl;
    }

    return 0;
}