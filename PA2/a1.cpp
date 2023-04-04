// T17 A0244126M

#include <iostream>
#include <vector>

using namespace std;

void checkMultiplication(int n, int x, int m, vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>> c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int value = 0;
            for (int k = 0; k < x; k++)
            {
                value += a[i][k] * b[k][j];
            }
            if (c[i][j] != value)
            {
                cout << "WA" << endl;
                return;
            }
        }
    }
    cout << "AC" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> ws;
        int n, x, y, m;
        cin >> n >> x >> y >> m;
        // create a matrix a
        vector<vector<int>> a(n, vector<int>(x));
        int value;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < x; k++)
            {
                cin >> value;
                a[j][k] = value;
            }
        }
        vector<vector<int>> b(y, vector<int>(m));
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> value;
                b[j][k] = value;
            }
        }
        vector<vector<int>> c(n, vector<int>(m));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> value;
                c[j][k] = value;
            }
        }

        if (x != y)
        {
            cout << "Inner matrix dimensions must agree" << endl;
            continue;
        }
        checkMultiplication(n, x, m, a, b, c);
    }
    return 0;
}