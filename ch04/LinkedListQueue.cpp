//
// Created by pl on 19-8-18.
//

#include "LinkedListQueue.h"
#include <limits>
#include <iostream>

LinkedListQueue::LinkedListQueue() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

LinkedListQueue::~LinkedListQueue() {
    if (head_) {
        Node *curr = head_;
        while (curr != nullptr) {
            Node *tmp = curr->next_;
            delete curr;
            curr = curr->next_;
        }
    }
}

void LinkedListQueue::enqueue(int e) {
    // 当链表为空时，需要特殊处理
    // TODO 使用 tail_
    if (tail_ == nullptr) {
        tail_ = new Node(e, nullptr);
        head_ = tail_;
        size_++;
        return;
    }

    tail_->next_ = new Node(e);
    tail_ = tail_->next_;
    size_++;
}

int LinkedListQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    Node *del_node = head_;
    int ret = del_node->elem_;

    head_ = del_node->next_;
    size_--;

    // 注意队列只有一个元素的情况，需要注意特殊处理
    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    delete del_node;
    return ret;
}

int LinkedListQueue::getFront() {
    if (isEmpty()) {
        return std::numeric_limits<int>::min();
    }

    return head_->elem_;
}

int LinkedListQueue::getSize() {
    return size_;
}

bool LinkedListQueue::isEmpty() {
    return size_ == 0;
}

void LinkedListQueue::printSelf() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Queue: front ";
    for (Node *curr = head_; curr != nullptr; curr = curr->next_) {
        std::cout << curr->elem_ << "->";
    }

    std::cout << "NULL tail" << std::endl;
}