#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isswap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isswap = true;
            }
        }
        if (!isswap)
        {
            return;
        }
    }
}

void selection_sort(vector<int>&arr){
    for (int  i = 0; i < arr.size()-1; i++)
    {
        int small_ele = i;
       for (int  j = i+1; j < arr.size(); j++)
       {
        if(arr[j]<arr[small_ele]){
            small_ele=j;
        }
        
       }
       swap(arr[i],arr[small_ele]);
        
    }
    
}

void Recusrive_bubble(vector<int> &arr, int n) {
    if (n == 1) return;

    // One bubble pass
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Solve the smaller problem
    Recusrive_bubble(arr, n - 1);
}

void Traversal(vector<int> arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

 void Recursion_insertionSort(vector<int> &arr, int n) {
        // Base case: 1 element is always sorted
        if (n <= 1) return;

 
        insertionSort(arr, n - 1);

    
        int key = arr[n - 1];
        int j = n - 2;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

int main()
{
    vector<int> arr = {7, 6, 5, 4, 3, 2, 1};
    cout<<"Traversal before swap function:"<<endl;
    Traversal(arr);
    selection_sort(arr);
    // bubble_sort(arr, arr.size());
    Traversal(arr);
    return 0;
}
