#include "base_container.h"


template <typename T>

class List_Container_oneDir : public Base_Container<T> {
public:
    List_Container_oneDir() : elNum(0), first_node(nullptr), tmp_node(nullptr) { std::cout << "create" << std::endl; }

    ~List_Container_oneDir() {
        std::cout << "destr" << std::endl;
        Node *p = first_node;
        while(p) {
            tmp_node = p->next;
            delete p;
            p = tmp_node;
        }
    }

    struct Node {
        Node* next;
        T data;
    };

    struct iterator {
        iterator(Node *node = NULL) : iNode{node} { }

        Node *iNode;

    };
    void show() const override {
        if (elNum == 0) {
            std::cout << "Container is empty" << std::endl;
            return;
        }
        Node *p = first_node;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout<<std::endl;
    }

    void push_back( const T & val ) override {
        Node* new_node = new Node{};
        if (size() == 0) {
            first_node = new_node;
        }
        else {
            tmp_node->next = new_node;
        }
        new_node->data = val;
        new_node->next = nullptr;
        tmp_node = new_node;
        elNum++;
    }


    void erase( const size_t ind ) override {
        Node *p = first_node;
        size_t cntr = 0;
        tmp_node = nullptr;
        while ( cntr != (ind-1) ) {
            tmp_node = p;
            p = p->next;
            cntr++;
        }
       tmp_node->next = p->next;
       elNum--;
    }

    void insert( const size_t ind, const T & val) override {
        Node *p = first_node;
        size_t cntr = 0;
        tmp_node = nullptr;
        Node *new_node = new Node{};
        new_node->data = val;
        if (ind == 0) {
            first_node = new_node;
        }
        while ( cntr != ind ) {
            tmp_node = p;
            p = p->next;
            cntr++;
        }
        if (tmp_node) tmp_node->next = new_node;
        new_node->next = p;
        elNum++;
    }

    size_t size() const override {
        return elNum;
    }

    T & operator[](const size_t ind) {
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        Node *p = first_node;
        size_t cntr = 0;
        while ( cntr != ind ) {
            p = p->next;
            cntr++;
        }
        return p->data;
    }

    iterator begin() {
        return iterator(first_node);
    }

    iterator end() {
        return iterator(first_node);
    }



private:
    size_t elNum;
    Node *first_node;
    Node *tmp_node;
};







