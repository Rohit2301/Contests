#include <bits/stdc++.h>
using namespace std;

vector<int> GetHIndexScore(vector<int> cit)
{
    int n = cit.size();
    vector<int> hind(n, 0);

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[cit[i]]++;
        if (i == 0)
        {
            hind[0] = 1;
            continue;
        }

        hind[i] = hind[i - 1];
        int count = hind[i] + 1;
        int curcnt = 0;
        auto begin = freq.begin();
        int f = 0;
        for (auto k = freq.begin(); k != freq.end(); k++)
        {
            if (k->first >= count)
            {
                begin = k;
                f = 1;
                break;
            }
        }
        if (!f)
        {
            begin = freq.end();
        }

        for (auto j = begin; j != freq.end(); j++)
        {
            curcnt += j->second;
            if (curcnt >= count)
            {
                hind[i]++;
                break;
            }
        }
    }

    return hind;
}

int main()
{
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++)
    {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++)
        {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "\nCase #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
