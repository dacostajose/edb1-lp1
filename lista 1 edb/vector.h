#ifndef VECTOR_H
#define VECTOR_H


struct vector {
    int at(int i);
    int insert(int e);
    void erase(int i);
    int size();
    bool empty();
    int search(int e);
    void print();
};

#endif