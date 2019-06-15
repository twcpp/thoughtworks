#include <iostream>
#include "lib/Math.h"

using namespace std;

int main() {
    Math *math = new Math();
    std::cout << math->add(1, 2) << std::endl;

    auto myvar = 25;
    cout << myvar << endl;
    auto foo = &myvar;
    cout << *foo << endl;

    auto bar = myvar;
    cout << bar << endl;

    int* haha;
    haha = new(nothrow) int[5];
    haha[0] = 9;
    haha[1] = 2;
    haha[2] = 3;
    haha[3] = 4;
    haha[4] = 5;

    cout << *haha << endl;
    cout << haha << endl;
    cout << &haha << endl;
}