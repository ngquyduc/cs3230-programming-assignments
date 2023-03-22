#include <iostream>

using namespace std;

void minPartition(int* arr, int size, int sum)
{
    bool dp[size + 1][sum / 2 + 1];
    for (int i = 0; i <= size; ++i)
    {
        for (int j = 0; j <= sum / 2; ++j) {
            if (j == 0) {
                dp[i][j] = true;
            }
            else if (i == 0) {
                dp[i][j] = false;
            }
            else if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        } 
    }

    int min = sum;
    for (int i = sum / 2; i >= 0; --i) {
        if (dp[size][i] && min > sum - 2 * i) {
            min = sum - 2 * i;
        }
    }

    cout << min << endl;
}

int main()
{
    int tc, n;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        cin >> n;
        int arr[n];
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[j];
            sum += arr[j];
        }
        minPartition(arr, n, sum);
    }
}

