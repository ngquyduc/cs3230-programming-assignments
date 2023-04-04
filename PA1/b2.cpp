#include <cmath>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void countingSort(vector<int> &arr, int size, int digit, int base);
void linearTimeSort(int N, int A, int B, int C, int X, int Y);

int main()
{
    int TC, N, A, B, C, X, Y;
    cin >> TC;
    for (int i = 0; i < TC; ++i)
    {
        cin >> N >> A >> B >> C >> X >> Y;
        linearTimeSort(N, A, B, C, X, Y);
    }
    return 0;
}

void linearTimeSort(int N, int A, int B, int C, int X, int Y)
{
    vector<int> U(N);
    U[0] = A;
    int max = A;

    for (int i = 1; i < N; ++i)
    {
        int d = (A * 1ll + U[i - 1] * 1ll * B) % C;
        U[i] = d;
        if (max < d)
        {
            max = d;
        }
    }

    int r = 1000;
    for (int digit = 1; max / digit > 0; digit *= (r * 1ll))
    {
        countingSort(U, N, digit, r);
    }

    int V = 77;
    for (int i = 0; i < N; ++i)
    {
        V = (V * 1ll * X + 7ll * U[i]) % Y;
    }

    cout << V << "\n";
}

void countingSort(vector<int> &arr, int size, int digit, int base)
{
    vector<queue<int> > freq(base, queue<int>());

    for (int i = 0; i < size; ++i)
    {
        freq[(arr[i] / digit) % base].push(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < base; ++i)
    {
        while (!freq[i].empty())
        {
            arr[index] = freq[i].front();
            freq[i].pop();
            ++index;
        }
    }
}