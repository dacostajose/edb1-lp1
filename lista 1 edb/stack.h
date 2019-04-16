#ifndef STACK_H
#define STACK_H

#include "vector.h"

struct stack {
    vector data;
    void clear();
    bool empty();
    void push(int elemento);
    int pop();
    int top();
    int size();
};

#endif