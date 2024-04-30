#include <iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
    int i, j, mini;
    for (int i = 0; i <= n - 1; i++)
    {
        int miniindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[miniindex])
                miniindex = j;
        }
        int temp = arr[miniindex]; // mini=a[5] 9=temp
        arr[miniindex] = arr[i];   // a[i] i=0 13mini
        arr[i] = temp;             // temp=9  i=9
    }
    cout << "After selection sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void bubblesort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "After bubble sort: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        for (j = i; j > 0; j--)
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
    }
    cout << "After insertion sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {9, 4, 3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\n\nBefore sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    bubblesort(arr, n);
    cout << endl;
    selectionsort(arr, n);
    cout << endl;
    insertionsort(arr, n);
    return 0;
}