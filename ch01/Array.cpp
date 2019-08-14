//
// Created by pl on 19-8-13.
//
#include "Array.h"
#include <iostream>
#include <cstring>

Array::Array() {
    capacity_ = 10;
    data_ = new int[capacity_];
    size_ = 0;
}

Array::Array(int capacity) {
    capacity_ = capacity;
    data_ = new int[capacity];
    size_ = 0;
}

void Array::add(int index, int e) {
    // index = 0, 表示在数组首位插入元素
    // index = size_, 表示在数组尾部插入元素
    if (index < 0 || index > size_)
        return;

    // 数组已满
    if (size_ == capacity_)
        resize(2*capacity_);

    for (int i = size_-1; i >= index; --i) {
        data_[i+1] = data_[i];
    }

    data_[index] = e;
    size_++;
}

void Array::printSelf() {
    if (size_ == 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }

    std::cout << "data_: " << data_ << std::endl;
    std::cout << "size_: " << size_ << std::endl;
    std::cout << "capacity_: " << capacity_ << std::endl;

    std::cout << "Array: [ ";

    for (int i = 0; i < size_ - 1; ++i) {
        std::cout << data_[i] << ", ";
    }

    std::cout << data_[size_-1] << " ]" << std::endl << std::endl;
}

int& Array::operator[](int index) {
    return data_[index];
}

bool Array::contains(int e) {
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == e)
            return true;
    }

    return false;
}

int Array::find(int e) {
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == e)
            return i;
    }

    return -1;
}

void Array::remove(int index) {
    if (index < 0 || index >= size_)
        return;

    for (int i = index + 1; i < size_; ++i) {
        data_[i-1] = data_[i];
    }

    size_--;

    if (size_ == capacity_ / 2)
        resize(capacity_ / 2);
}

void Array::removeElement(int e) {
    int index = find(e);
    remove(index);
}

void Array::removeFirst() {
    remove(0);
}

void Array::removeLast() {
    remove(size_-1);
}

void Array::resize(int new_capacity) {
    // 第一步：申请新空间
    int *new_data = new int[new_capacity];

    // 第二步：将原数组内容拷贝至新空间
    std::memcpy(new_data, data_, sizeof(int)*capacity_);

    // 第三步：释放原数组空间
    delete[]data_;

    // 第四步：更新相关状态
    data_ = new_data;
    capacity_ = new_capacity;
}


