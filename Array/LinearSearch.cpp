#include <iostream>
#include <cmath>
using namespace std;
int linearsearch(int arr[], int size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int num = 5;
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = linearsearch(arr, size, num);
    cout << "\nArray : 2, 3, 4, 5, 6"<<endl;
    cout << "value 5 is at index " << value << endl;
}