#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[i])
            return false;

        if (right < n && arr[right] > arr[i])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int n = 5;

    if (isMaxHeap(arr, n))
        cout << "It IS a Max Heap";
    else
        cout << "It is NOT a Max Heap";

    return 0;
}
