#include<iostream>
using namespace std;

const int MAX = 100;

void displayMenu()
{
    cout << "   Menu  " << endl;
    cout << "1. Insert number" << endl;
    cout << "2. Find largest number" << endl;
    cout << "3. Find smallest number" << endl;
    cout << "4. Find median number" << endl;
    cout << "5. Find average" << endl;
    cout << "6. Display all numbers" << endl;
    cout << "7. Quit" << endl;
}


char enterOperator()
{
    char opt;
    cout << "Enter: (1-7): ";
    cin >> opt;
    return opt;
}


void insert(int arr[], int &used)
{
    if(used >= MAX)
    {
        cout << "Array is full" << endl;
        return;
    }

    cout << "Enter a number to insert: ";
    int data;
    cin >> data;

    int index = used;

    for(int i = 0; i < used; i++)
    {
        if(arr[i] > data)
        {
            index = i;
            break;
        }
    }

   
    for(int i = used; i > index; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[index] = data;
    used++;
}

//largest value
void findLargest(int arr[], int used)
{
    if(used == 0)
    {
        cout << "Array empty." << endl;
        return;
    }
    cout << "Largest number : " << arr[used-1] << endl;
}

//samallest
void findSmallest(int arr[], int used)
{
    if(used == 0)
    {
        cout << "ARray empty" << endl;
        return;
    }
    cout << "Smallest number: " << arr[0] << endl;
}

// median
void findMedian(int arr[], int used)
{
    if(used == 0)
    {
        cout << "Array empty." << endl;
        return;
    }

    double median;
    if(used % 2 == 1)
    {
        median = arr[used/2];
    }
    else 
    {
        median = (arr[used/2 - 1] + arr[used/2]) / 2.0;
    }
    cout << "Median is: " << median << endl;
}

// average
void findAverage(int arr[], int used)
{
    if(used == 0)
    {
        cout << "No data in the array." << endl;
        return;
    }

    double sum = 0;
    for(int i = 0; i < used; i++)
    {
        sum += arr[i];
    }

    cout << "Average is: " << sum/used << endl;
}

void displayAll(int arr[], int used)
{
    if(used == 0)
    {
        cout << "No data to display." << endl;
        return;
    }

    cout << "Numbers in ascending order: ";
    for(int i = 0; i < used; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numbers[MAX], used = 0;
    char opt;

    do
    {
        displayMenu();
        opt = enterOperator();

        switch(opt)
        {
            case '1':
                insert(numbers, used);
                break;
            case '2':
                findLargest(numbers, used);
                break;
            case '3':
                findSmallest(numbers, used);
                break;
            case '4':
                findMedian(numbers, used);
                break;
            case '5':
                findAverage(numbers, used);
                break;
            case '6':
                displayAll(numbers, used);
                break;
            case '7':
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid." << endl;
        }

    } 
    while(opt != '7');

    return 0;
}
