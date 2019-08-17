//
// Created by pl on 19-8-13.
//

#ifndef DS_BOBO_1_ARRAY_H
#define DS_BOBO_1_ARRAY_H

#include <cstdio>

class Array {
public:
    Array();
    Array(int capacity);
    ~Array();

    size_t getSize() {
        return size_;
    }

    size_t getCapacity() {
        return capacity_;
    }

    bool isEmpty() {
        return size_ == 0;
    }

    // 向数组第一个位置插入元素
    void addFirst(int e) {
        add(0, e);
    }

    // 向数组末尾添加一个元素
    void addLast(int e) {
//        // 如果空间不够，则直接返回
//        if (size_ == capacity_) {
//            return;
//        }
//
//        data_[size_] = e;
//        size_++;

        add(size_, e);
    }

    // 在第 index 个位置插入一个新元素 e
    void add(int index, int e);

    int get(int index) {
        return data_[index];
    }

    void set(int index, int e) {
        data_[index] = e;
    }

    bool contains(int e);

    // 查找元素 e 第一次出现的位置，如果不存在，返回 -1
    int find(int e);

    // 删除指定的元素 e
    void removeElement(int e);
    void removeFirst();
    void removeLast();

    void remove(int index);

    void printSelf();

    int& operator[](int index);

    int getLast();
    int getFirst();

private:
    void resize(int new_capacity);

private:
    int *data_;
    int size_, capacity_;
};


#endif //DS_BOBO_1_ARRAY_H
