//
// Created by pl on 19-8-18.
//

#ifndef DS_BOBO_1_LINKEDLIST_H
#define DS_BOBO_1_LINKEDLIST_H

class LinkedList {
private:
    struct Node {
        int elem_;
        Node *next_;

        Node() : elem_(), next_(nullptr) {}
        Node(int e) : elem_(e), next_(nullptr) {}
        Node(int e, Node *next) : elem_(e), next_(next) {}
    };

public:
    LinkedList();
    ~LinkedList();

    // 返回链表中元素的大小
    int getSize() {
        return size_;
    }

    // 链表是否为空
    bool isEmpty() {
        return size_ == 0;
    }

    // 在链表头部添加元素
    void addFirst(int e);

    // 在链表的index（0-based）位置添加新的元素 e
    // 在链表中不是一个常用操作，练习用
    void add(int index, int e);

    // 在链表尾部添加元素
    void addLast(int e);

    void printSelf();

private:
    Node *head_;
    int size_;
};

#endif //DS_BOBO_1_LINKEDLIST_H
