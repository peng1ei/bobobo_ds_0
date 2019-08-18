//
// Created by pl on 19-8-18.
//

#ifndef DS_BOBO_1_ISTACK_H
#define DS_BOBO_1_ISTACK_H

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


#endif //DS_BOBO_1_ISTACK_H
