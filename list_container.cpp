#include "base_container.h"


template <typename T>

class List_Container : public Base_Container<T> {
public:
    List_Container() : elNum(0), last_node(nullptr), first_node(nullptr), tmp_node(nullptr) { std::cout << "Constructor List" << std::endl; }
    ~List_Container() {  }

    struct Node {
        Node* next;
        Node* prev;
        T data;
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
        new_node->prev = last_node;
        new_node->next = nullptr;
        tmp_node = new_node;
        last_node = new_node;
        elNum++;
    }


    void erase( const size_t ind ) override {
        Node *p = first_node;
        size_t cntr = 0;
        last_node = nullptr;
        while ( cntr != ind ) {
            last_node = p;
            p = p->next;
            cntr++;
        }
       last_node->next = p->next;
       p->prev = last_node;
//     std::cout << "el " <<ind+1 << " data= " << p->data << std::endl;
    }

    void insert( const size_t ind, const T & val) override {
        Node *p = first_node;
        size_t cntr = 0;
        last_node = nullptr;
        Node *new_node = new Node{};
        new_node->data = val;
        if (ind == 0) {
            first_node = new_node;
           // new_node->next = p;
           // new_node->prev = nullptr;
        }
        while ( cntr != ind ) {
            last_node = p;
            p = p->next;
            cntr++;
        }
        if (last_node) last_node->next = new_node;
        new_node->next = p;

        std::cout << "el " <<ind << " data= " << p->data << std::endl;

    }

    size_t size() const override {
        return elNum;
    }





private:
    size_t elNum;
    Node *last_node;
    Node *first_node;
    Node *tmp_node;
};







