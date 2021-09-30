#include <iostream>
using namespace std;
// Swap two elements - Utility function

void quicksort(int arr[], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

void quicksort_with_pivot(int arr[], int first, int last, int pivot)
{
    int i, j, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main()
{
    int i, count, arr[250], pivot;
    char p;
    cout << "How many elements are u going to enter?: ";
    cin >> count;
    cout << "\nEnter " << count << " elements: ";
    for (i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    cout << "do you want to input pivot (y/n): ";

    cin >> p;

    if (p == 'y' || p == 'Y')
    {
        cout << "Enter Pivot: ";
        cin >> pivot;
        quicksort_with_pivot(arr, 0, count - 1, pivot);
    }
    else if (p == 'n' || p == 'N')
    {
        quicksort(arr, 0, count - 1);
    }
    else
    {
        return 0;
    }

    cout << "Order of Sorted elements: ";
    for (i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << "\n";
    
    return 0;
}
