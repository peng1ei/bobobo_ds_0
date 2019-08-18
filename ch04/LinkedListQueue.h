//
// Created by pl on 19-8-18.
//

#ifndef DS_BOBO_1_LINKEDLISTQUEUE_H
#define DS_BOBO_1_LINKEDLISTQUEUE_H

#include "../ch02/IQueue.h"

class LinkedListQueue : public IQueue {
private:
    struct Node {
        int elem_;
        Node *next_;

        Node() : elem_(), next_(nullptr) {}
        Node(int e) : elem_(e), next_(nullptr) {}
        Node(int e, Node *next) : elem_(e), next_(next) {}
    };

public:
    LinkedListQueue();
    ~LinkedListQueue();

    // 时间复杂度 O(1)
    void enqueue(int e) override ;

    // 时间复杂度为 O(1)
    int dequeue() override ;
    int getFront() override ;
    int getSize() override ;
    bool isEmpty() override ;

    void printSelf();

private:
    // head_ 队首；tail_ 队尾
    Node *head_, *tail_;
    int size_;
};

#endif //DS_BOBO_1_LINKEDLISTQUEUE_H
