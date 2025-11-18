#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int extractMax(int arr[], int &n) {
    int root = arr[0];      
    arr[0] = arr[n - 1];    
    n--;                    
    heapify(arr, n, 0);     
    return root;
}

int kthLargest(int arr[], int n, int k) {
    buildMaxHeap(arr, n);

    for (int i = 1; i < k; i++) {
        extractMax(arr, n);
    }

    return extractMax(arr, n);
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = 7, k1 = 3;
    cout << kthLargest(arr1, n1, k1) << endl; 

    int arr2[] = {12, 3, 5, 7, 19};
    int n2 = 5, k2 = 2;
    cout << kthLargest(arr2, n2, k2) << endl;
}
