//
// Created by pl on 19-8-17.
//

#ifndef DS_BOBO_1_ARRAYQUEUE_H
#define DS_BOBO_1_ARRAYQUEUE_H

#include "../ch01/Array.h"
#include "IQueue.h"

class ArrayQueue : public IQueue {
public:
    ArrayQueue();
    ArrayQueue(int capacity);

    // 时间复杂度 O(1)
    void enqueue(int e) override ;

    // 时间复杂度为 O(n)
    int dequeue() override ;
    int getFront() override ;
    int getSize() override ;
    bool isEmpty() override ;

    void printSelf();

private:
    Array array_;
};

#endif //DS_BOBO_1_ARRAYQUEUE_H
