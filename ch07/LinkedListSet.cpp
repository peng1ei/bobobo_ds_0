//
// Created by pl on 19-8-22.
//

#include "LinkedListSet.h"

LinkedListSet::LinkedListSet() {
    list_ = new LinkedList;
}

LinkedListSet::~LinkedListSet() {
    delete list_;
}

int LinkedListSet::getSize() {
    return list_->getSize();
}

bool LinkedListSet::isEmpty() {
    return list_->isEmpty();
}

bool LinkedListSet::contains(int e) {
    return list_->contains(e);
}

void LinkedListSet::add(int e) {
    if (!contains(e)) {
        list_->addFirst(e);
    }
}

void LinkedListSet::remove(int e) {
    list_->removeElement(e);
}

