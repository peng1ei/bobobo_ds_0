#include <iostream>
#include <stack>
#include "ch01/Array.h"
#include "ch02/ArrayStack.h"

void TestArray() {
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
}

void TestArrayStack() {
    ArrayStack stack(10);
    stack.printSelf();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.printSelf();

    stack.pop();
    stack.printSelf();

    stack.peek();
    stack.printSelf();
}

int main() {
    // TestArray();
    TestArrayStack();

    return 0;
}