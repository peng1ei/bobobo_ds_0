//
// Created by pl on 19-8-17.
//

#ifndef DS_BOBO_1_LOOPQUEUE_H
#define DS_BOBO_1_LOOPQUEUE_H

#include "IQueue.h"

class LoopQueue : public IQueue {
public:
    LoopQueue();
    LoopQueue(int capacity);
    ~LoopQueue();

    // 时间复杂度 O(1) 均摊
    void enqueue(int e) override ;

    // 时间复杂度为 O(1) 均摊
    int dequeue() override ;
    int getFront() override ;
    int getSize() override ;
    bool isEmpty() override ;

    void printSelf();

    int getCapacity() {
        return capacity_ - 1;
    }

    int getLast();

private:
    bool isFull();
    void resize(int new_capacity);

private:
    int *data_;

    // 实际只能存 capacity_ - 1 个元素，其中一个空间用作
    // 标识队列为满的条件，相当于浪费了一个空间。
    int front_, tail_, capacity_;

    // TODO 通过 front_ 和 tail_ 实现
    int size_;
};


#endif //DS_BOBO_1_LOOPQUEUE_H
