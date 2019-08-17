//
// Created by pl on 19-8-17.
//

#include "ArrayStack.h"

ArrayStack::ArrayStack(){
}

ArrayStack::ArrayStack(int capacity) : array_(capacity) {
}

void ArrayStack::push(int e) {
    array_.addLast(e);
}

int ArrayStack::pop() {
    int e = array_.getLast();
    array_.removeLast();
    return e;
}

int ArrayStack::peek() {
    return array_.getLast();
}

int ArrayStack::getSize() {
    return array_.getSize();
}

bool ArrayStack::isEmpty() {
    return array_.isEmpty();
}

void ArrayStack::printSelf() {
    array_.printSelf();
}


