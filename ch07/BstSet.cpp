//
// Created by pl on 19-8-22.
//

#include "BstSet.h"

BstSet::BstSet() {
    bst = new Bst;
}

BstSet::~BstSet() {
    delete bst;
}

int BstSet::getSize() {
    return bst->size();
}

bool BstSet::isEmpty() {
    return bst->isEmpty();
}

void BstSet::add(int e) {
    bst->add(e);
}

void BstSet::remove(int e) {
    bst->remove(e);
}

bool BstSet::contains(int e) {
    return bst->contains(e);
}

