#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int longest_increasing_subsequence(vector<int> virus, int l)
{
    vector<int> temp;
    temp.push_back(virus[0]);
    int len = 1;
    for (int i = 0; i < l; ++i)
    {
        if (virus[i] > temp.back())
        {
            temp.push_back(virus[i]);
            len++;
        }
        else
        {
            int index = lower_bound(temp.begin(), temp.end(), virus[i]) - temp.begin();
            temp[index] = virus[i];
        }
    }
    return len;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int n, m;
        cin >> n;
        cin >> m;
        map<int, int> favorite;
        vector<int> virus(n);
        for (int j = 0; j < n; ++j)
        {
            int temp;
            cin >> temp;
            favorite[temp] = j;
        }
        int result = 0;
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                int temp;
                cin >> temp;
                virus[k] = favorite[temp];
            }
            result += n - longest_increasing_subsequence(virus, n);
        }
        cout << result << '\n';
    }
    return 0;
}
