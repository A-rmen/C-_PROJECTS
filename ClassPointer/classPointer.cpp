
#include <iostream>
using namespace std;

class Pointer {
private:
    int* ptr;

public:
    Pointer(int value) {
        ptr = new int(value);
        cout << "Constructor called\n";
    }

    Pointer(int* p) {
        ptr = p;
        cout << "Pointer constructor called\n";
    }

    Pointer(const Pointer& other) {
        ptr = new int(*other.ptr);
    }

    Pointer& operator=(const Pointer& other) {
        if (this != &other) {
            int* temp = new int(*other.ptr);
            delete ptr;
            ptr = temp;
        }
        return *this;
    }

    ~Pointer() {
        delete ptr;
    }

    int getVal() const {
        return *ptr;
    }

    void setVal(int value) {
        *ptr = value;
    }

    void printAddress() const {
        cout << "Address: " << ptr << "\n";
    }

    void reset() {
        int value = *ptr;
        int* temp = new int(value);

        delete ptr;
        ptr = temp;

        cout << "Memory changed\n";
    }
};

int main() {
    Pointer first(15);

    int* p = new int(30);
    Pointer second(p);

    cout << first.getVal() << "\n";
    cout << second.getVal() << "\n";

    first.setVal(50);
    second.setVal(40);

    cout << first.getVal() << "\n";
    cout << second.getVal() << "\n";

    first.printAddress();
    second.printAddress();

    first.reset();
    second.reset();

    first.printAddress();
    second.printAddress();

    return 0;
}
