
#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T arr[], int count) {
    for (int i = 1; i < count; i++) {
        T current = arr[i];
        int pos = i - 1;

        while (pos >= 0 && arr[pos] > current) {
            arr[pos + 1] = arr[pos];
            pos--;
        }

        arr[pos + 1] = current;
    }
}

int main() {
    int numbers[6] = { 9, 5, 7, 1, 4, 2 };

    insertionSort(numbers, 6);

    for (int i = 0; i < 6; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    double values[6] = { 3.5, 1.2, 6.4, 0.8, 4.1, 2.3 };

    insertionSort(values, 6);

    for (int i = 0; i < 6; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}
