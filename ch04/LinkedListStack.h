//
// Created by pl on 19-8-18.
//

#ifndef DS_BOBO_1_LINKEDLISTSTACK_H
#define DS_BOBO_1_LINKEDLISTSTACK_H

#include "../ch02/IStack.h"
#include "LinkedList.h"

class LinkedListStack : public IStack {
public:
    LinkedListStack();

    void push(int e) override ;
    int pop() override ;
    int peek() override ;
    int getSize() override ;
    bool isEmpty() override ;

    void printSelf();

private:
    LinkedList list_;
};

#endif //DS_BOBO_1_LINKEDLISTSTACK_H
