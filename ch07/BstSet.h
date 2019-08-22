//
// Created by pl on 19-8-22.
//
// 基于二分搜索树（Bst）实现的集合（Set）
// 要求存放的元素的类型具有可比性

#ifndef DS_BOBO_1_BSTSET_H
#define DS_BOBO_1_BSTSET_H
#include "ISet.h"
#include "../ch06/Bst.h"

class BstSet : public ISet {
public:
    BstSet();
    ~BstSet();

    void add(int e) override ;
    void remove(int e) override ;
    bool contains(int e) override ;
    bool isEmpty() override ;
    int getSize() override ;

private:
    Bst *bst_;
};

#endif //DS_BOBO_1_BSTSET_H
