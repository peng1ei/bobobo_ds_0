//
// Created by pl on 19-8-18.
//

#include "LinkedListStack.h"
#include <iostream>

LinkedListStack::LinkedListStack() {

}

void LinkedListStack::push(int e) {
    list_.addFirst(e);
}

int LinkedListStack::pop() {
    return list_.removeFirst();
}

int LinkedListStack::peek() {
    return list_.getFirst();
}

int LinkedListStack::getSize() {
    return list_.getSize();
}

bool LinkedListStack::isEmpty() {
    return list_.isEmpty();
}

void LinkedListStack::printSelf() {
    if (list_.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack: top ";
    list_.printSelf();
}