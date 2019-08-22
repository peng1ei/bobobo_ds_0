//
// Created by pl on 19-8-20.
//

#include "Bst.h"
#include <iostream>
#include <stack>
#include <queue>
#include <limits>

Bst::Bst() {
    root_ = nullptr;
    size_ = 0;
}

Bst::~Bst() {

}

//// 递归版本_v1
//void Bst::add(int e) {
//    if (root_ == nullptr) {
//        root_ = new Node(e);
//        size_++;
//        return;
//    }
//
//    add(root_, e);
//}
//// 递归版本_v1
//void Bst::add(Bst::Node *root, int e) {
//    // 递归基
//    if (root->elem_ == e) {
//        return;
//    } else if (root->elem_ > e && root->left_ == nullptr) {
//        root->left_ = new Node(e);
//        size_++;
//        return;
//    } else if (root->elem_ < e && root->right_ == nullptr) {
//        root->right_ = new Node(e);
//        size_++;
//        return;
//    }
//
//    if (root->elem_ > e) {
//        add(root->left_, e);
//    } else {
//        add(root->right_, e);
//    }
//}

// 递归版本_v2
void Bst::add(int e) {
    root_ = add(root_, e);
}

// 递归版本_v2
Bst::Node* Bst::add(Bst::Node *root, int e) {
    if (root == nullptr) {
        size_++;
        return new Node(e);
    }

    if (root->elem_ > e) {
        root->left_ = add(root->left_, e);
    } else if (root->elem_ < e) {
        root->right_ = add(root->right_, e);
    }

    return root;
}

bool Bst::contains(int e) {
    return contains(root_, e);
}

bool Bst::contains(Bst::Node *node, int e) {
    if (node == nullptr) {
        return false;
    }

    if (node->elem_ == e) {
        return true;
    } else if (node->elem_ > e) {
        return contains(node->left_, e);
    } else {
        return contains(node->right_, e);
    }
}

void Bst::preOrder() {
    preOrder(root_);
}

void Bst::preOrder(Bst::Node *node) {
    if (node == nullptr)
        return;

    // 访问节点
    std::cout << node->elem_ << std::endl;
    preOrder(node->left_);
    preOrder(node->right_);
}

void Bst::inOrder() {
    inOrder(root_);
}

void Bst::inOrder(Bst::Node *node) {
    if (node == nullptr)
        return;

    inOrder(node->left_);
    // 访问节点
    std::cout << node->elem_ << std::endl;
    inOrder(node->right_);
}

void Bst::postOrder() {
    postOrder(root_);
}

void Bst::postOrder(Bst::Node *node) {
    if (node == nullptr)
        return;

    postOrder(node->left_);
    postOrder(node->right_);

    // 访问节点
    std::cout << node->elem_ << std::endl;
}

void Bst::preOrderNR() {
    std::stack<Node*> st;
    st.push(root_);

    while (!st.empty()) {
        Node *node = st.top();
        st.pop();

        // 访问当前节点
        std::cout << node->elem_ << std::endl;

        // 访问完每棵子树的根节点时，接下来要要访问当前根节点
        // 的左右子树。
        // 由于使用栈结构来存放下次需要访问的节点，而栈的特点是
        // 后进先出，所以这里需要将右孩子节点先压入栈中，然后再
        // 压入左子树，这样当下次访问时，从栈中首先弹出的就是左
        // 孩子节点了
        if (node->right_ != nullptr)
            st.push(node->right_);

        if (node->left_ != nullptr)
            st.push(node->left_);
    }
}

void Bst::levelOrder() {
    std::queue<Node*> queue;
    queue.push(root_);

    while (!queue.empty()) {
        Node *node = queue.front();
        queue.pop();

        // 访问当前节点
        std::cout << node->elem_ << std::endl;
        if (node->left_ != nullptr) {
            queue.push(node->left_);
        }

        if (node->right_ != nullptr) {
            queue.push(node->right_);
        }
    }
}

int Bst::minimum() {
    if (size_ == 0) {
        std::cout << "BST is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    return minimum(root_)->elem_;
}

Bst::Node* Bst::minimum(Bst::Node *node) {
    if (node->left_ == nullptr)
        return node;
    return minimum(node->left_);
}

int Bst::maximum() {
    if (size_ == 0) {
        std::cout << "BST is empty." << std::endl;
        return std::numeric_limits<int>::min();
    }

    return maximum(root_)->elem_;
}

Bst::Node* Bst::maximum(Bst::Node *node) {
    if (node->right_ == nullptr)
        return node;

    return maximum(node->right_);
}

int Bst::removeMin() {
    int ret = minimum();
    root_ = removeMin(root_);
    return ret;
}

// 删除掉以node为根的二分搜索树中的最小节点
// 返回删除节点后新的二分搜索树的根
Bst::Node* Bst::removeMin(Bst::Node *node) {
    // 如果当前节点已经没有左孩子了，则说明当前节点就是值
    // 最小的节点
    if (node->left_ == nullptr) {
        // 如果当前待删除的节点有右孩子的话，需要将其返回
        Node *right_node = node->right_;
        // 删除当前最小值所在的节点
        delete node;
        size_--;
        return right_node;
    }

    node->left_ = removeMin(node->left_);
    return node;
}

int Bst::removeMax() {
    int ret = maximum();
    root_ = removeMax(root_);
    return ret;
}

Bst::Node* Bst::removeMax(Bst::Node *node) {
    // 如果当前节点已经没有左=右孩子了，则说明当前节点就是值
    // 最大的节点
    if (node->right_ == nullptr) {
        Node *left_node = node->left_;
        delete node;
        size_--;
        return left_node;
    }

    node->right_ = removeMax(node->right_);
    return node;
}