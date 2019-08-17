//
// Created by pl on 19-8-17.
//

#ifndef DS_BOBO_1_IQUEUE_H
#define DS_BOBO_1_IQUEUE_H

class IQueue {
public:
    virtual ~IQueue() {}

    // 入队
    virtual void enqueue(int e) = 0;

    // 出队
    virtual int dequeue() = 0;

    // 获取第一个元素
    virtual int getFront() = 0;

    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;
};

#endif //DS_BOBO_1_IQUEUE_H
