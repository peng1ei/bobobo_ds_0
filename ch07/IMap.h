//
// Created by pl on 19-8-22.
//
// Key -- string
// Value -- int

#ifndef DS_BOBO_1_IMAP_H
#define DS_BOBO_1_IMAP_H

#include <string>

class IMap {
public:
    virtual ~IMap() {};

    virtual void add(const std::string &key, int value) = 0;
    virtual int remove(const std::string &key) = 0;
    virtual bool contains(const std::string &key) = 0;
    virtual int get(const std::string &key) = 0;
    virtual void set(const std::string &key, int new_value) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

#endif //DS_BOBO_1_IMAP_H
