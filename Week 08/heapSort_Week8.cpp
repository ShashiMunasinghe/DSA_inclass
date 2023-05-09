#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;     //assume root node index is the index of the largest
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < n && arr[leftChild] > arr[largest] ) largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest]) largest = rightChild;

    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);   //recursively heapify the nodes which the roots get changed
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    //swap first element to the last and last element to the first
    //again heapify the arr without the sorted part
    while (n > 1) {
        n--;
        int temp = arr[n];
        arr[n] = arr[0];
        arr[0] = temp;

        heapify(arr, n, 0);
    }
}

//print contents of array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int size;
    cout << "Input array size : ";
    cin >> size;

    //using random array generating
    int heap_arrRandom[size];
    for (int i = 0; i < size; ++i) {
        heap_arrRandom[i] = rand() % 100;
    }

    cout<<"Input array : "<<endl;
    displayArray(heap_arrRandom,size);

    heapSort(heap_arrRandom, size);

    cout << "Sorted array : "<<endl;
    displayArray(heap_arrRandom, size);

    //using user input array
    int heap_arrUser[size];
    cout << "\nArray :";
    for (int i = 0; i < size; ++i) {
        cin >> heap_arrUser[i];
    }

    cout<<"Input array : "<<endl;
    displayArray(heap_arrUser,size);

    heapSort(heap_arrUser, size);

    cout << "Sorted array : "<<endl;
    displayArray(heap_arrUser, size);

}
