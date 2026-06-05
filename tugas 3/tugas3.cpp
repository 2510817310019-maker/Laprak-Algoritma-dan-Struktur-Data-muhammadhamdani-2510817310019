#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int X;
    cout << "Masukkan target (X): ";
    cin >> X;

    const int N = 25;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        int j = rand() % N;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "\nArray Random:\n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int jumlahPasangan = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int target = X - arr[i];

        if (binarySearch(arr, i + 1, N - 1, target) != -1)
        {
            jumlahPasangan++;
        }
    }

    cout << "\n\nJumlah pasangan = " << jumlahPasangan << endl;

    return 0;
}