//
// Created by pl on 19-8-20.
//

#include "Bst.h"

Bst::Bst() {
    root_ = nullptr;
    size_ = 0;
}

Bst::~Bst() {

}

void Bst::add(int e) {
    if (root_ == nullptr) {
        root_ = new Node(e);
        size_++;
        return;
    }

    add(root_, e);
}

void Bst::add(Bst::Node *root, int e) {
    // 递归基
    if (root->elem_ == e) {
        return;
    } else if (root->elem_ > e && root->left_ == nullptr) {
        root->left_ = new Node(e);
        size_++;
        return;
    } else if (root->elem_ < e && root->right_ == nullptr) {
        root->right_ = new Node(e);
        size_++;
        return;
    }

    if (root->elem_ > e) {
        add(root->left_, e);
    } else {
        add(root->right_, e);
    }
}



