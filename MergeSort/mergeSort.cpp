
#include <iostream>
using namespace std;

template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* a = new T[n1];
    T* b = new T[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        b[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = a[i++];
    }

    while (j < n2) {
        arr[k++] = b[j++];
    }

    delete[] a;
    delete[] b;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main() {
    int numbers[6] = { 7, 3, 9, 2, 5, 1 };

    mergeSort(numbers, 0, 5);

    for (int i = 0; i < 6; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;
    return 0;
}
