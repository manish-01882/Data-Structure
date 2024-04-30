#include <iostream>
using namespace std;
int binarysearch(int arr[], int size, int num)
{
    int first = 0;
    int last = size - 1;
    int mid = first + (last - first) / 2;
    while (first <= last)
    {
        if (arr[mid] == num)
        {
            return mid;
        }
        if (num > arr[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
        mid = (first + last) / 2;
    }
    return -1;
}
int main()
{
    int even[6] = {13, 14, 15, 22, 64, 71};
    int odd[5] = {3, 4, 5, 2, 1};
    int evenindex = binarysearch(even, 6, 64);
    cout << "\n\nfor evenindex the index of 64 is:" << evenindex << endl;
    int oddindex = binarysearch(odd, 5, 5);
    cout << "for oddindex the index of 1 is:" << oddindex << endl;
}