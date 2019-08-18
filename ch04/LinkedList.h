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

    // 获得链表的第 index（0-based）个位置的元素
    // 在链表中不是一个常用操作，练习用
    int get(int index);

    // 获得链表的第一个元素
    int getFirst();

    // 获得链表的最后一个元素
    int getLast();

    // 修改链表的第 index 个位置的元素为 e
    // 在链表中不是一个常用操作，练习用
    void set(int index, int e);

    // 查找链表中是否有元素e
    bool contains(int e);

    // 从链表中删除 index 位置的元素，返回删除的元素
    // 在链表中不是一个常用操作，练习用
    int remove(int index);

    int removeFirst();
    int removeLast();

private:
    //Node *head_;
    Node *dummy_head_; // 虚拟头结点
    int size_;
};

#endif //DS_BOBO_1_LINKEDLIST_H
