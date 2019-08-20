//
// Created by pl on 19-8-20.
//
// 二分搜索树中存放的数据必须要能够进行比较
// 我们的二分搜索树不包含重复元素
//      TODO
//      如果想包含重复元素的话，只需定义：
//      左子树小于等于节点；或者右子树大于等于节点

#ifndef DS_BOBO_1_BST_H
#define DS_BOBO_1_BST_H

class Bst {
private:
    struct Node {
        int elem_;
        Node *left_, *right_;

        Node(int e) : elem_(e), left_(nullptr), right_(nullptr) {}
    };

public:
    Bst();
    ~Bst();

    int size() {
        return size_;
    }

    bool isEmpty() {
        return size_ == 0;
    }

    // 递归版本_v1
    //void add(int e);

    // 递归版本_v2
    void add(int e);

    bool contains(int e);

private:
    // // 递归版本_v1
    //void add(Node *root, int e);

    // 递归版本_v2
    Node* add(Node *root, int e);

    bool contains(Node *node, int e);

private:
    Node *root_;
    int size_;
};

#endif //DS_BOBO_1_BST_H
