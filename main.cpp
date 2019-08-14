#include <iostream>
#include "ch01/Array.h"


int main() {
    Array arr(6);
    arr.addLast(2);
    arr.addLast(3);
    arr.addLast(4);
    arr.addLast(5);

    arr.printSelf();

    arr.add(1, 6);
    arr.printSelf();

    arr[0] = 88;
    arr.printSelf();

    arr.addFirst(-1);
    arr.printSelf();

    arr.addLast(-9);
    arr.printSelf();

    arr.add(2, 99);
    arr.printSelf();

    arr.remove(0);
    arr.remove(1);
    arr.remove(2);
    arr.printSelf();

    arr.add(2, 99);
    arr.add(2, 99);
    arr.printSelf();

    return 0;
}