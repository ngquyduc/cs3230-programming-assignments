// T17 A0244126M
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMedian(vector<long long> &arr, int size);
long long randomizedQuickSelect(vector<long long> &arr, int start, int end, int i);
int partition(vector<long long> &arr, int start, int end, int pivot);

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int tc, n, a, b, c, x, y;
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        cin >> n >> a >> b >> c >> x >> y;
        vector<long long> u(n);
        u[0] = a;

        for (int j = 1; j < n; ++j)
        {
            long long d = ((a + (u[j - 1] * 1ll % c) * b) % c) * a;
            u[j] = d;
        }

        findMedian(u, n);
    }
}

void findMedian(vector<long long> &arr, int size) {
    if (size % 2 != 0) {
        cout << randomizedQuickSelect(arr, 0, size - 1, size / 2) << endl;
    } 
    else {
        long long res1 = randomizedQuickSelect(arr, 0, size - 1, size / 2 - 1);
        long long res2 = randomizedQuickSelect(arr, 0, size - 1, size / 2);
        long long res = (res1 + res2) / 2;
        string suffix = ((res1 + res2) % 2 != 0) ? ".5" : "";
        cout << res << suffix << endl;
    } 
}

long long randomizedQuickSelect(vector<long long> &arr, int start, int end, int i) {
    if (start == end) {
        return arr[start];
    }
    int pivotIndex = start + rand() % (end - start + 1);
    pivotIndex = partition(arr, start, end, pivotIndex);
    if (i == pivotIndex) {
        return arr[i];
    }
    else if (i < pivotIndex) {
        return randomizedQuickSelect(arr, start, pivotIndex - 1, i);
    }
    else {
        return randomizedQuickSelect(arr, pivotIndex, end, i);
    }
}

int partition(vector<long long> &arr, int start, int end, int pivotIndex) {
    long long pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[end]);
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}