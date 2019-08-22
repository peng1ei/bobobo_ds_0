//
// Created by pl on 19-8-22.
//
// 基于链表实现的集合（Set）
// 不要求存放的元素的类型具有可比性

#ifndef DS_BOBO_1_LINKEDLISTSET_H
#define DS_BOBO_1_LINKEDLISTSET_H

#include "ISet.h"
#include "../ch04/LinkedList.h"

class LinkedListSet : ISet {
public:
    LinkedListSet();
    ~LinkedListSet();

    void add(int e) override ;
    void remove(int e) override ;
    bool contains(int e) override ;
    bool isEmpty() override ;
    int getSize() override ;

private:
    LinkedList *list_;
};

#endif //DS_BOBO_1_LINKEDLISTSET_H
