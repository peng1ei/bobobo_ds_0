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
        resize(getCapacity() * 2);
        //std::cout << "Queue is full." << std::endl;
        //return;
    }

    // 第二步：放入元素
    data_[tail_] = e;

    // 第三步：更新相关状态
//    if ((tail_ + 1)%capacity_ == 0) {
//        tail_ = 0;
//    } else {
//        tail_++;
//    }
    // 循环队列特有的操作
    tail_ = (tail_ + 1) % capacity_;
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
//    if ((front_ + 1)%capacity_ == 0) {
//        front_ = 0;
//    } else {
//        front_++;
//    }
    // 循环队列特有的操作
    front_ = (front_ + 1) % capacity_;
    size_--;

    // TODO 缩容
    // 在完成出队后，看看队列存放的元素是否太少，如果太少的话
    // 就缩减空间，以防空间浪费。这里缩减的条件是：当队列中的元素
    // 只占整个空间的 1/4 的时候，就将队列的容量缩小一半。
    // 为什么不在元素等于一半的时候进行缩容呢？因为如果在元素等于容量
    // 一半的时候就进行缩容的话，容易造成频繁的缩容和扩容，形成时间
    // 复杂度震荡，因为缩容和扩容的时间复杂度都为 O(n)，而经过均摊后，
    // 时间复杂度可以降为 O(1)，如果时间复杂度震荡发生，则最终还是 O(n)
    // 所以，往往当元素个数少于一定缩放因子（如 0.25）的时候才进行缩容。
    if (size_ == getCapacity() / 4 && getCapacity() / 2  != 0) {
        resize(getCapacity() / 2);
    }

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
    //return (tail_ - front_ + capacity_) % capacity_;
    return size_;
}

void LoopQueue::printSelf() {
    if (isEmpty()) {
        std::cout << "Loop Queue is empty." << std::endl;
        return;
    }

    std::cout << "front(" << front_ << ") [ ";

//    for (int i = front_, j = 0; j < size_ - 1; ++i, ++j) {
//        if ((i + 1) % capacity_ == 0) {
//            i = 0;
//        }
//
//        std::cout << data_[i] << ", ";
//    }

    // 遍历循环队列
    for (int i = front_; i != tail_; i = (i + 1) % capacity_) {
        if (i == (tail_ - 1) % capacity_) {
            std::cout << data_[i];
            break;
        }

        std::cout << data_[i] << ", ";
    }

    std::cout << " ] tail(" << tail_<< ")" << std::endl;
}

int LoopQueue::getLast() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    // 注意获取队尾元素的方式
    return data_[(tail_ - 1 + capacity_)%capacity_];
}

void LoopQueue::resize(int new_capacity) {
    // 第一步：创建新空间
    int *new_data = new int[new_capacity + 1];

    // 第二步：复制相关元素至新的空间中
    for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[(i + front_)%capacity_];
    }

    // 第三步：释放原有空间
    delete []data_;

    // 第四步：更新相关状态
    data_ = new_data;
    capacity_ = new_capacity + 1;
    front_ = 0;
    tail_ = size_;
}



