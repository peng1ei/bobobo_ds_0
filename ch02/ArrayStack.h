//
// Created by pl on 19-8-17.
//

#ifndef DS_BOBO_1_ARRAYSTACK_H
#define DS_BOBO_1_ARRAYSTACK_H

#include "../ch01/Array.h"

class IStack {
public:
    virtual ~IStack() {}

    virtual void push(int e) = 0;
    virtual int pop() = 0;

    // 查询栈顶元素
    virtual int peek() = 0;

    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

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
