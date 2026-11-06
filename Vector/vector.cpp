
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class myVector {
private:
    T* data;
    int size;
    int capacity;

public:
    myVector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    myVector(T arr[], int n) {
        size = n;
        capacity = n;
        data = new T[capacity];

        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    myVector(const myVector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~myVector() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    bool empty() const {
        return size == 0;
    }

    void push_back(T value) {
        if (size == capacity) {
            int newCapacity;

            if (capacity == 0)
                newCapacity = 1;
            else
                newCapacity = capacity * 2;

            T* temp = new T[newCapacity];

            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
            capacity = newCapacity;
        }

        data[size] = value;
        size++;
    }

    T pop_back() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }

        size--;
        return data[size];
    }

    void clear() {
        size = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }

        return data[index];
    }

    bool operator==(const myVector& other) const {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i])
                return false;
        }

        return true;
    }

    bool operator!=(const myVector& other) const {
        return !(*this == other);
    }

    myVector& operator=(const myVector& other) {
        if (this == &other)
            return *this;

        T* temp = new T[other.capacity];

        for (int i = 0; i < other.size; i++) {
            temp[i] = other.data[i];
        }

        delete[] data;
        data = temp;
        size = other.size;
        capacity = other.capacity;

        return *this;
    }

    myVector& operator+=(const myVector& other) {
        int n = other.size;

        if (this == &other) {
            myVector temp(other);
            return *this += temp;
        }

        for (int i = 0; i < n; i++) {
            push_back(other.data[i]);
        }

        return *this;
    }

    myVector operator+(const myVector& other) const {
        myVector result(*this);
        result += other;
        return result;
    }

    void print() const {
        if (empty()) {
            cout << "Vector is empty\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

        cout << "\n";
    }
};

int main() {
    int nums[] = { 1, 2, 3 };

    myVector<int> ob(nums, 3);

    ob.push_back(45);
    ob.push_back(86);
    ob.push_back(7);
    ob.push_back(77);

    cout << "First vector: ";
    ob.print();

    cout << "Size: " << ob.getSize() << "\n";
    cout << "Capacity: " << ob.getCapacity() << "\n";

    myVector<int> ob1;

    ob1.push_back(45);
    ob1.push_back(86);
    ob1.push_back(7);
    ob1.push_back(77);

    ob1[2] = 6;

    cout << "Second vector: ";
    ob1.print();

    myVector<int> ob2 = ob + ob1;

    cout << "Combined vector: ";
    ob2.print();

    cout << "Last element: " << ob2.pop_back() << "\n";

    ob2.clear();

    cout << "Is empty: " << ob2.empty() << "\n";

    return 0;
}
