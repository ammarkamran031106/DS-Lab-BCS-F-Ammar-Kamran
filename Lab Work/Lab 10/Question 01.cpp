#include <iostream>
using namespace std;

class MaxHeap {
public:
    int heap[100];
    int size;

    MaxHeap() {
        size = 0;
    }

    int parent(int i) { return i / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    void insert(int val) {
        heap[++size] = val;
        bubbleUp(size);
    }

    void bubbleUp(int i) {
        while (i > 1 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void bubbleDown(int i) {
        while (true) {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if (l <= size && heap[l] > heap[largest])
                largest = l;

            if (r <= size && heap[r] > heap[largest])
                largest = r;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    void update_key(int i, int new_val) {
        int old_val = heap[i];
        heap[i] = new_val;

        if (new_val > old_val)
            bubbleUp(i);     
        else
            bubbleDown(i);    
    }

    void delete_at_index(int i) {
        heap[i] = heap[size];
        size--;

        bubbleUp(i);
        bubbleDown(i);
    }
    void print() {
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    int arr[] = {8, 7, 6, 5, 4};
    for (int x : arr)
        h.insert(x);

    cout << "Initial Max Heap: ";
    h.print();

    h.update_key(2, 10);
    cout << "After update_key(2, 10): ";
    h.print();

    h.delete_at_index(3);
    cout << "After delete_at_index(3): ";
    h.print();

    return 0;
}
