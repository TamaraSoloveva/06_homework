#include "base_container.h"

template <typename T>
class Sequence_Container : public Base_Container <T>{
public:
    Sequence_Container() : mem(new T [5]), memSz(5), elNum(0)  {}
    ~Sequence_Container() { delete []mem; }

    void show() const override {
       if (elNum == 0)
           std::cout << "Container is empty" << std::endl;
       else {
           for (size_t i = 0; i < elNum; ++i)
               std::cout << mem[i] << " ";
       }
       std::cout << std::endl;
    }

    void push_back( const T & val ) override {
        elNum++;
  /*      if(elNum >= memSz ) {
            for (size_t i = 0; i < (memSz-1); ++i) {
                newMem[i] = mem[i];
            }

        }*/
        memSz++;

        T *newMem = new T [memSz];
        //mem = new T[memSz];
        for (size_t i = 0; i < (memSz-1); ++i) {
            newMem[i] = mem[i];
        }
        newMem[memSz-1]  = val;
        delete[]mem;
        mem = newMem;
    }

    size_t size() const override {
        return elNum;
    }

    void erase( const size_t ind ) override {
        if ( elNum == 0 ) {
            std::cout << "Container is empty" << std::endl;
            return;
        }
        if ((ind >= elNum) || ( ind < 0)) {
            std::cout << "Error - Bad index" << std::endl;
            return;
        }
        size_t i=0, j=0;
         T *newMem = new T [memSz];
         for (i = 0, j=0; i < elNum; ++i, ++j) {
            if ( j == ind ) {
                ++i;
            }
            newMem[j] = mem[i];
         }
         delete[]mem;
         mem = newMem;
         elNum--;
    }

    void insert( const size_t ind, const T & val ) override {
        if ((ind >= memSz) || ( ind < 0)) {
            std::cout << "Error - Bad index" << std::endl;
            return;
        }
        size_t i=0, j=0;
        elNum++;
        T *newMem = new T [memSz];
        for (i=0, j=0; i < elNum; ++i, ++j) {
            if (i == ind) {
                newMem[i] = val;
                if (i != (elNum-1))
                    newMem[i+1] = mem[j];
                --j;
            }
            else
                newMem[i] = mem[j];
         }
        delete[]mem;
        mem = newMem;
    }

    T &operator[](const size_t ind) {
        if ((ind >= memSz) || ( ind < 0)) {
            std::cout << "Error - Bad index" << std::endl;
        //    return NULL;
        }
        return mem[ind];
    }

private:
    T *mem;
    size_t memSz, elNum;
};





