#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

#include <iostream>

template <typename TYPE>
class Base_Container {
public:
    virtual ~Base_Container() {}
    virtual void show() const = 0;
    virtual void push_back( TYPE val ) = 0;
    virtual void erase( size_t ind ) = 0;
    virtual void insert( size_t ind, TYPE val) = 0;
    virtual size_t size() const = 0;
};







#endif // BASE_CONTAINER_H
