#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

void deleteAtIndex(int arr[], int& used, int index)
{
    for (int i = index; i < used - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    used--;
}

int main ()
{
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;

    int indexToDelete;
    cout << "Enter index to delete: " << endl; 
    cin >> indexToDelete;

    deleteAtIndex(arr, size, indexToDelete);

    cout << "array after deletion: " << endl; 
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }




}