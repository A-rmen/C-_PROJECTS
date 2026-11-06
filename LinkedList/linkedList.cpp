
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

public:
    LinkedList() {
    }

    ~LinkedList() {
        Node<T>* current = head;

        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    T pop_back() {
        if (tail == nullptr) {
            throw out_of_range("List is empty");
        }

        T value = tail->data;
        Node<T>* temp = tail;

        tail = tail->prev;

        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }

        delete temp;
        size--;

        return value;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        if (head == nullptr) {
            cout << "List is empty";
            return;
        }

        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    LinkedList<int> list;

    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    list.push_back(5);
    list.push_back(15);
    list.push_back(25);
    list.push_back(35);

    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Removed: " << list.pop_back() << "\n";

    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n";

    return 0;
}
