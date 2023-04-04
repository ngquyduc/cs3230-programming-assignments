// T17 A0244126M
#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<vector<int> > multiply(int n, int x, int m, vector<vector<int> > a, vector<vector<int> > b)
{
    vector<vector<int> > c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int value = 0;
            for (int k = 0; k < x; k++)
            {
                value += a[i][k] * b[k][j];
            }
            c[i][j] = value;
        }
    }
    return c;
}

void checkMultiplication(int n, int x, int y, int m, vector<vector<int> > a, vector<vector<int> > b, vector<vector<int> > c)
{
    if (x != y)
    {
        cout << "Inner matrix dimensions must agree" << endl;
        return;
    }   
    bool result;
    for (int k = 0; k < 10; k++) {
        vector<vector<int> > r(m, vector<int>(1));
        for (int i = 0; i < m; i++)
        {
            r[i][0] = rand() % 2 ? 1 : -1;
        }

        vector<vector<int> > cr = multiply(n, m, 1, c, r);

        vector<vector<int> > br = multiply(x, m, 1, b, r);

        vector<vector<int> > abr = multiply(n, x, 1, a, br);

        if (abr == cr)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    if (result)
        {
            cout << "AC" << endl;
        }
    else
    {
        cout << "WA" << endl;
    }
}

// main function
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
        vector<vector<int> > a(n, vector<int>(x));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < x; k++)
            {
                int value;
                cin >> value;
                a[j][k] = value;
            }
        }
        vector<vector<int> > b(y, vector<int>(m));
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int value;
                cin >> value;
                b[j][k] = value;
            }
        }
        vector<vector<int> > c(n, vector<int>(m));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int value;
                cin >> value;
                c[j][k] = value;
            }
        }

        checkMultiplication(n, x, y, m, a, b, c);
    }
}
