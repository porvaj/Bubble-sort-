#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;   // Return index if found
    }
    return -1;          // Return -1 if not found
}

int main() {
    int arr[] = {5, 15, 25, 35, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 35;

    int result = sequentialSearch(arr, n, key);

    if(result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}