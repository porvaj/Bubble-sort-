#include <iostream>
using namespace std;

int heap[100];
int size = 0;


void insert(int value) {
    size++;
    int index = size;
    heap[index] = value;

    while (index > 1) {
        int parent = index / 2;

        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else {
            return;
        }
    }
}


void deleteRoot() {
    if (size == 0) {
        cout << "Heap is empty";
        return;
    }

    heap[1] = heap[size];
    size--;

    int index = 1;

    while (index <= size) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int largest = index;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
            break;
    }
}


void display() {
    for (int i = 1; i <= size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {

    insert(50);
    insert(30);
    insert(40);
    insert(10);
    insert(20);

    cout << "Max Heap: ";
    display();

    deleteRoot();

    cout << "After deleting root: ";
    display();

    return 0;
}