//
// Created by pl on 19-8-17.
//

#ifndef DS_BOBO_1_ARRAYSTACK_H
#define DS_BOBO_1_ARRAYSTACK_H

#include "../ch01/Array.h"
#include "IStack.h"

class ArrayStack : public IStack {
public:
    ArrayStack();
    ArrayStack(int capacity);

    void push(int e) override ;
    int pop() override ;
    int peek() override ;
    int getSize() override ;
    bool isEmpty() override ;

    void printSelf();

private:
    Array array_;
};

#endif //DS_BOBO_1_ARRAYSTACK_H
