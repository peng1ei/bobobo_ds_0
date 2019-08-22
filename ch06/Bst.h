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

    // 查找是否包含某个元素
    bool contains(int e);

    // 前序遍历
    void preOrder();
    // 非递归（需要栈这个数据结构辅助，深度优先遍历）
    void preOrderNR();

    // TODO 中序和后序遍历的非递归实现
    // 中序遍历
    void inOrder();

    // 后序遍历
    void postOrder();

    // 层序遍历（广度优先遍历，需要队列这个辅助数据结构支持）
    void levelOrder();

    // TODO 寻找二分搜索树最小值和最大值的非递归实现
    // 寻找二分搜索树的最小元素
    int minimum();

    // 寻找二分搜索树的最大元素
    int maximum();

    // 删除二分搜索树中最小/大值所在的节点，并返回最小/大值
    int removeMin();
    int removeMax();

private:
    // 递归版本_v1
    //void add(Node *root, int e);

    // 递归版本_v2
    Node* add(Node *root, int e);

    bool contains(Node *node, int e);

    // 前中后序遍历，递归实现
    void preOrder(Node *node);
    void inOrder(Node *node);
    void postOrder(Node *node);

    // 返回以 node 为根的二分搜索树的最小值所在的节点
    // 基本思想就是从根节点开始，一直访问左孩子节点，直到
    // 所访问到的节点再也没有左孩子，则该节点就是元素值最小
    // 的节点
    Node* minimum(Node *node);

    // 返回以 node 为根的二分搜索树的最大值所在的节点
    // 基本思想就是从根节点开始，一直访问右孩子节点，直到
    // 所访问到的节点再也没有右孩子，则该节点就是元素值最大
    // 的节点
    Node* maximum(Node *node);

    // 删除掉以node为根的二分搜索树中的最小/最大节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMin(Node *node);
    Node* removeMax(Node *node);

private:
    Node *root_;
    int size_;
};

#endif //DS_BOBO_1_BST_H
