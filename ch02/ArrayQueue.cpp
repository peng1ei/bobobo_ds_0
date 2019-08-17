//
// Created by pl on 19-8-17.
//

#include "ArrayQueue.h"
#include <iostream>

ArrayQueue::ArrayQueue() {}

ArrayQueue::ArrayQueue(int capacity) : array_(capacity) {
}

void ArrayQueue::enqueue(int e) {
    array_.addLast(e);
}

int ArrayQueue::dequeue() {
    int e = array_.getFirst();
    array_.removeFirst();
    return e;
}

int ArrayQueue::getFront() {
    return array_.getFirst();
}

int ArrayQueue::getSize() {
    return array_.getSize();
}

bool ArrayQueue::isEmpty() {
    return array_.isEmpty();
}

void ArrayQueue::printSelf() {
    if (array_.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "front [ ";

    for (int i = 0; i < array_.getSize() - 1; ++i) {
        std::cout << array_.get(i) << ", ";
    }

    std::cout << array_.getLast() << " ] tail" << std::endl;
}
