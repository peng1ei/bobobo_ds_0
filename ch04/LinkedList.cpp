//
// Created by pl on 19-8-18.
//

#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
///! 无虚拟头节点
//    head_ = nullptr;
//    size_ = 0;
///!

    dummy_head_ = new Node(0, nullptr);
    size_ = 0;
}

LinkedList::~LinkedList() {
    // TODO 释放资源
    Node *curr = dummy_head_->next_;
    while (curr != nullptr) {
        Node *tmp = curr->next_;
        delete curr;
        curr = tmp;
    }

///! 无虚拟头节点
//    // 注意没有哨兵节点时第一个节点的特殊性
//    if (head_) {
//        Node *cur = head_;
//
//        for (int i = 0; i < size_; ++i) {
//            Node *tmp = cur->next_;
//            delete cur;
//            cur = tmp;
//        }
//    }
///!
}

void LinkedList::addFirst(int e) {
    add(0, e);

///! 无虚拟头节点
//    // 第一步：先准备好要插入的节点
//    Node *node = new Node();
//    node->elem_ = e;
//    node->next_ = head_;
//
//    // 第二步：更新头节点指针，使其指向新插入的节点
//    head_ = node;
//    size_++;
//
//    // 以上几步逻辑可以整合至如下一句代码
//    //head_ = new Node(e, head_);
//    //size_++;
///!
}

void LinkedList::add(int index, int e) {
    if (index < 0 || index > size_) {
        std::cout << "Index " << index << " is invalid." << std::endl;
        return;
    }

    // 查找需要插入的位置的上一个节点
    // 注意和遍历元素的区别
    Node *prev = dummy_head_;
    for (int i = 0; i < index; ++i) {
        prev = prev->next_;
    }

    // 插入新节点
    prev->next_ = new Node(e, prev->next_);

    // 更新链表大小
    size_++;

///! 无虚拟头节点
//    // 先判断 index 的合法性
//    if (index < 0 || index > size_) {
//        return;
//    }
//
//    // 没有哨兵节点时，注意在位置 0 插入的特殊性
//    if (index == 0) {
//        addFirst(e);
//    } else {
//        // 查找待插入位置的上一个节点
//        Node *prev = head_;
//
//        for (int i = 0; i < index - 1; ++i) {
//            prev = prev->next_;
//        }
//
////        Node *node = new Node(e);
////        node->next_ = prev->next_;
////        prev->next_ = node;
//        prev->next_ = new Node(e, prev->next_);
//
//        size_++;
//    }
///!
}

void LinkedList::addLast(int e) {
    add(size_, e);

///! 无虚拟头节点
//    Node *node = new Node(e, nullptr);
//
//    // 如果当前链表为空，则直接插入
//    if (head_ == nullptr) {
//        head_ = node;
//        size_++;
//        return;
//    }
//
//    // 如果链表不为空，则查找最后一个节点
//    // 查找过程：
//    // 使用一个临时变量 last，用来记录当前待判断是否为最后一个节点的节点
//    // 从第一个节点开始，如果当前节点的 next == nullptr，则表明
//    // 当前节点就是最后一个节点；否则 last = last->next，进行下一个节点
//    // 的判断。
//    Node *last = head_; // 从第一个节点开始
//    while (last->next_ != nullptr) {    // 判断当前节点是否为最后一个节点
//                                        // 如果是，就直接退出。
//                                        // 如果不是，就移向下一个节点进行判断
//        last = last->next_;
//    }
//
//    last->next_ = node;
//    size_++;
///!
}

void LinkedList::printSelf() {
    if (isEmpty()) {
        std::cout << "LinkedList is Empty." << std::endl;
        return;
    }

    // 方式1
//    Node *curr = dummy_head_->next_;
//    for (int i = 0; i < size_ - 1; ++i) {
//        std::cout << curr->elem_ << "->";
//        curr = curr->next_;
//    }
//
//    std::cout << curr->elem_ << "->NULL" << std::endl;

    // 方式2
    for (Node *curr = dummy_head_->next_;
        curr != nullptr; curr = curr->next_) {
        std::cout << curr->elem_ << "->";
    }

    std::cout << "NULL" << std::endl;

///! 无虚拟头节点
//    if (isEmpty()) {
//        std::cout << "LinkedList is Empty." << std::endl;
//        return;
//    }
//
//    std::cout << "[";
//
//    Node *cur = head_;
//    for (int i = 0; i < size_ - 1; ++i) {
//        std::cout << cur->elem_ << ", ";
//        cur = cur->next_;
//    }
//
//    // 如果只有一个元素时，需要特别处理
//    if (cur->next_ == nullptr) {
//        std::cout << cur->elem_ << "]" << std::endl;
//    } else {
//        std::cout << cur->next_->elem_ << "]" << std::endl;
//    }
///!
}

int LinkedList::get(int index) {
    if (index < 0 || index > size_) {
        std::cout << "Index " << index << " is invalid." << std::endl;
        return std::numeric_limits<int>::min();
    }

    // 遍历链表，遍历元素
    // 注意和查找前一个节点时遍历的区别
    Node *curr = dummy_head_->next_;
    for (int i = 0; i < index; ++i) {
        curr = curr->next_;
    }

    return curr->elem_;
}

int LinkedList::getFirst() {
    return get(0);
}

int LinkedList::getLast() {
    return get(size_ - 1);
}

void LinkedList::set(int index, int e) {
    if (index < 0 || index > size_) {
        std::cout << "Index " << index << " is invalid." << std::endl;
        return;
    }

    Node *curr = dummy_head_->next_;
    for (int i = 0; i < index; ++i) {
        curr = curr->next_;
    }

    curr->elem_ = e;
}

bool LinkedList::contains(int e) {
    Node *curr = dummy_head_->next_;
    while (curr != nullptr) {
        if (curr->elem_ == e) {
            return true;
        }

        curr = curr->next_;
    }

    return false;
}

int LinkedList::remove(int index) {
    if (index < 0 || index >= size_) {
        std::cout << "Index " << index << " is invalid." << std::endl;
        return std::numeric_limits<int>::min();
    }

    Node *prev = dummy_head_;
    for (int i = 0; i < index; ++i) {
        prev = prev->next_;
    }

    Node *del_node = prev->next_;
    prev->next_ = del_node->next_;
    size_--;

    int ret = del_node->elem_;
    delete del_node;

    return ret;
}

int LinkedList::removeFirst() {
    return remove(0);
}

int LinkedList::removeLast() {
    return remove(size_ - 1);
}