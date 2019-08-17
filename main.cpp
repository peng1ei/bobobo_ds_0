#include "ch01/Array.h"
#include "ch02/ArrayStack.h"
#include "ch02/ArrayQueue.h"
#include "ch02/LoopQueue.h"

#include <iostream>
#include <stack>

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

void TestArrayQueue() {
    ArrayQueue queue;
    queue.printSelf();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.printSelf();

    queue.dequeue();
    queue.printSelf();
}

void TestLoopQueue() {
    LoopQueue queue;
    queue.printSelf();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.printSelf();

    queue.enqueue(2);
    queue.printSelf();

    queue.dequeue();
    queue.printSelf();

    queue.enqueue(2);
    queue.printSelf();

    queue.enqueue(66);
    queue.printSelf();

    queue.dequeue();
    queue.printSelf();
    queue.dequeue();
    queue.printSelf();
    queue.dequeue();
    queue.printSelf();
    queue.dequeue();
    queue.printSelf();

    queue.enqueue(100);
    queue.printSelf();

    queue.dequeue();
    queue.printSelf();
    queue.dequeue();
    queue.printSelf();

    queue.enqueue(200);
    queue.printSelf();

    queue.dequeue();
    queue.printSelf();

    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(88);
    queue.printSelf();
}

int main() {
    // TestArray();
    //TestArrayStack();
    //TestArrayQueue();
    TestLoopQueue();

    return 0;
}