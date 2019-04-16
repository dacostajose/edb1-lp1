#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"

struct queue {
    queue(int capacity);
    vector data;
    void clear();
    bool empy();
    void push_bach(int element);
    int pop_front();
    int peek();
    int size();
};

#endif