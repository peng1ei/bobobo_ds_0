//
// Created by pl on 19-8-20.
//

#include "Bst.h"
#include <iostream>

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

    std::cout << node->elem_ << std::endl;
    preOrder(node->left_);
    preOrder(node->right_);
}

