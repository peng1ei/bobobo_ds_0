//
// Created by pl on 19-8-22.
//

#ifndef DS_BOBO_1_ISET_H
#define DS_BOBO_1_ISET_H

class ISet {
public:
    virtual ~ISet() {}

    virtual void add(int e) = 0;
    virtual void remove(int e) = 0;
    virtual bool contains(int e) = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

#endif //DS_BOBO_1_ISET_H
