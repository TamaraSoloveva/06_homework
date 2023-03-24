#include "base_container.h"

template <typename T>
class Sequence_Container : public Base_Container <T>{
public:
    Sequence_Container() : mem(new T (1)),sz(0) { std::cout << "constructor" << std::endl;}
    ~Sequence_Container() { delete []mem; }

    void show() const override {
       if (sz == 0)
           std::cout << "Container is empty" << std::endl;
       else {
           for (size_t i = 0; i < sz; ++i)
               std::cout << mem[i] << " ";
       }
       std::cout << std::endl;
    }

    void push_back( T val ) override {
        sz++;
        T *newMem = new T [sz];
        for (size_t i = 0; i < (sz-1); ++i) {
            newMem[i] = mem[i];
        }
        newMem[sz-1]  = val;
        delete[]mem;
        mem = newMem;
    }

    size_t size() const override {
        return sz;
    }

    void erase( size_t ind ) override {
        if ((ind >= sz) || ( ind < 0)) {
            std::cout << "Error - Bad index" << std::endl;
            return;
        }
        size_t i=0, j=0;
         T *newMem = new T [sz-1];
         for (i = 0, j=0; i < sz; ++i, ++j) {
            if ( j == ind ) {
                ++i;
            }
            newMem[j] = mem[i];
         }
         delete[]mem;
         mem = newMem;
         sz--;
    }

    void insert( size_t ind, T val ) override {
        if ((ind >= sz) || ( ind < 0)) {
            std::cout << "Error - Bad index" << std::endl;
            return;
        }
        size_t i=0, j=0;
        T *newMem = new T [sz];
        for (i=0, j=0; i < sz; ++i, ++j) {
            if (i == ind) {
                newMem[i] = val;

            }
            else
                newMem[i] = mem[i];
         }
        delete[]mem;
        mem = newMem;

    }


private:
    T *mem;
    size_t sz;
};





