//
// Created by pl on 19-8-18.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head_ = nullptr;
    size_ = 0;
}

LinkedList::~LinkedList() {
    // TODO 释放资源
    // 注意没有哨兵节点时第一个节点的特殊性
    if (head_) {
        Node *cur = head_;

        for (int i = 0; i < size_; ++i) {
            Node *tmp = cur->next_;
            delete cur;
            cur = tmp;
        }
    }
}

void LinkedList::addFirst(int e) {
    // 第一步：先准备好要插入的节点
    Node *node = new Node();
    node->elem_ = e;
    node->next_ = head_;

    // 第二步：更新头节点指针，使其指向新插入的节点
    head_ = node;
    size_++;

    // 以上几步逻辑可以整合至如下一句代码
    //head_ = new Node(e, head_);
    //size_++;
}

void LinkedList::add(int index, int e) {
    // 先判断 index 的合法性
    if (index < 0 || index > size_) {
        return;
    }

    // 没有哨兵节点时，注意在位置 0 插入的特殊性
    if (index == 0) {
        addFirst(e);
    } else {
        // 查找待插入位置的上一个节点
        Node *prev = head_;

        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next_;
        }

//        Node *node = new Node(e);
//        node->next_ = prev->next_;
//        prev->next_ = node;
        prev->next_ = new Node(e, prev->next_);

        size_++;
    }
}

void LinkedList::addLast(int e) {
    Node *node = new Node(e, nullptr);

    // 如果当前链表为空，则直接插入
    if (head_ == nullptr) {
        head_ = node;
        size_++;
        return;
    }

    // 如果链表不为空，则查找最后一个节点
    // 查找过程：
    // 使用一个临时变量 last，用来记录当前待判断是否为最后一个节点的节点
    // 从第一个节点开始，如果当前节点的 next == nullptr，则表明
    // 当前节点就是最后一个节点；否则 last = last->next，进行下一个节点
    // 的判断。
    Node *last = head_; // 从第一个节点开始
    while (last->next_ != nullptr) {    // 判断当前节点是否为最后一个节点
                                        // 如果是，就直接退出。
                                        // 如果不是，就移向下一个节点进行判断
        last = last->next_;
    }

    last->next_ = node;
    size_++;
}

void LinkedList::printSelf() {
    if (isEmpty()) {
        std::cout << "LinkedList is Empty." << std::endl;
        return;
    }

    std::cout << "[";

    Node *cur = head_;
    for (int i = 0; i < size_ - 1; ++i) {
        std::cout << cur->elem_ << ", ";
        cur = cur->next_;
    }

    // 如果只有一个元素时，需要特别处理
    if (cur->next_ == nullptr) {
        std::cout << cur->elem_ << "]" << std::endl;
    } else {
        std::cout << cur->next_->elem_ << "]" << std::endl;
    }
}

