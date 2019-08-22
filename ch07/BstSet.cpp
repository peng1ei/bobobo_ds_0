//
// Created by pl on 19-8-22.
//

#include "BstSet.h"

BstSet::BstSet() {
    bst_ = new Bst;
}

BstSet::~BstSet() {
    delete bst_;
}

int BstSet::getSize() {
    return bst_->size();
}

bool BstSet::isEmpty() {
    return bst_->isEmpty();
}

void BstSet::add(int e) {
    bst_->add(e);
}

void BstSet::remove(int e) {
    bst_->remove(e);
}

bool BstSet::contains(int e) {
    return bst_->contains(e);
}

