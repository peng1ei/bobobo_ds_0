//
// Created by pl on 19-8-17.
//

#include "LoopQueue.h"
#include <limits>
#include <iostream>

LoopQueue::LoopQueue() {
    capacity_ = 6 + 1;
    data_ = new int[capacity_];
    front_ = tail_ = 0;
    size_ = 0;
}

LoopQueue::LoopQueue(int capacity) {
    capacity_ = capacity + 1;
    data_ = new int[capacity_];
    front_ = tail_ = 0;
    size_ = 0;
}

LoopQueue::~LoopQueue() {
    delete []data_;
}

void LoopQueue::enqueue(int e) {
    // 第一步：判断当前队列是否为满
    if (isFull()) {
        // TODO 扩容
        std::cout << "Queue is full." << std::endl;
        return;
    }

    // 第二步：放入元素
    data_[tail_] = e;

    // 第三步：更新相关状态
    if ((tail_ + 1)%capacity_ == 0) {
        tail_ = 0;
    } else {
        tail_++;
    }

    size_++;
}

int LoopQueue::dequeue() {
    // 第一步：判断队列是否为空
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    // 第二步：如果队列非空的话，取出准备要返回的数据
    int e = data_[front_];

    // 第三步：更新相关状态
    if ((front_ + 1)%capacity_ == 0) {
        front_ = 0;
    } else {
        front_++;
    }

    size_--;

    return e;
}

bool LoopQueue::isEmpty() {
    return front_ == tail_;
}

inline bool LoopQueue::isFull() {
    return (tail_ + 1) % capacity_ == front_;
}

int LoopQueue::getFront() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    return data_[front_];
}

int LoopQueue::getSize() {
    //return (tail_ + capacity_ - front_) % capacity_;
    return size_;
}

void LoopQueue::printSelf() {
    if (isEmpty()) {
        std::cout << "Loop Queue is empty." << std::endl;
        return;
    }

    std::cout << "front(" << front_ << ") [ ";

    for (int i = front_, j = 0; j < size_ - 1; ++i, ++j) {
        if ((i + 1) % capacity_ == 0) {
            i = 0;
        }

        std::cout << data_[i] << ", ";
    }

    std::cout << getLast() << " ] tail(" << tail_<< ")" << std::endl;
}

int LoopQueue::getLast() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    // 注意获取队尾元素的方式
    return data_[(tail_+capacity_-1)%capacity_];
}





