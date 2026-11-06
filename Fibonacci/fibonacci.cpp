
#include <iostream>
using namespace std;

template <int n>
int fib() {
    return fib<n - 1>() + fib<n - 2>();
}

template <>
int fib<0>() {
    return 1;
}

template <>
int fib<1>() {
    return 1;
}

int main() {
    cout << fib<6>() << endl;
    return 0;
}
