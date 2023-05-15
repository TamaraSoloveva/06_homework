#include "base_container.h"


template <typename T>

class List_Container : public Base_Container<T> {
public:
    List_Container() : elNum(0), last_node(nullptr), first_node(nullptr), tmp_node(nullptr) { }
    ~List_Container() {
        Node *p = last_node;
        tmp_node = nullptr;
        while(p) {
            tmp_node = p->prev;
            delete p;
            p = tmp_node;
        }
    }

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
        /*
       //обход в обратную сторону
        Node *p = last_node;
        while (p) {
            std::cout << p->data << " ";
            p = p->prev;
        }        
        */
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
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        if ( ind < elNum/2 ) {
            Node *p = first_node;
            size_t cntr = 0;
            while ( cntr != (ind-1) ) {
                tmp_node = p;
                p = p->next;
                cntr++;
            }
            tmp_node->next = p->next;
            p->prev = tmp_node;
        }
        else {
            Node *p = last_node;
            size_t cntr = elNum;
            while ( cntr != ind ) {
                tmp_node = p;
                p = p->prev;
                cntr--;
            }
            tmp_node->prev = p->prev;
            p->prev->next = tmp_node;
        }
       elNum--;
    }

    void insert( const size_t ind, const T & val) override {
        if ((ind > elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        Node *new_node = new Node{};
        new_node->data = val;
        if ( ind < (elNum-1)/2 ) {
            Node *p = first_node;
            size_t cntr = 0;
            tmp_node = nullptr;
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
        }
        else {
            Node *p = last_node;
            size_t cntr = elNum;
            tmp_node = nullptr;
            while(cntr != ind) {
                tmp_node = p;
                p = p->prev;
                cntr--;
            }
            p->next = new_node;
            new_node->prev = p;
            if (ind == elNum) {
                new_node->next = tmp_node;
                last_node = tmp_node;
            }
            else {
                new_node->next = tmp_node;
            }
        }
        elNum++;
    }

    size_t size() const override {
        return elNum;
    }

    T & operator[](const size_t ind) const  {
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

    //оператор перемещения
    List_Container & operator = ( List_Container && other) noexcept {
        if (this != &other) {
            std::swap(*this, other);
        }
        return *this;
    }

    //конструктор сдвига
    List_Container ( List_Container && other ) noexcept {
        first_node = other.first_node;
        other.first_node = nullptr;
        elNum = other.elNum;
        other.elNum = 0;
        last_node = other.last_node;
        other.last_node = nullptr;
    }

    struct iterator {
        Node *iNode;
    public:
        iterator(Node *node = NULL) : iNode{ node } { }

        const T& get() { return iNode->data; }

        const T& operator* ( ) {
            return iNode->data;
        }

        iterator operator++ () {
           iNode = iNode->next;
           return iNode;
        }

        bool operator!= (const iterator & it1) const {
            return !(this->iNode == it1.iNode);
        }
    };


    iterator begin() {
        return iterator(first_node);
    }

    iterator end() {
        return iterator(last_node);
    }



private:
    size_t elNum;
    Node *last_node;
    Node *first_node;
    Node *tmp_node;
    Node *curr_node;
};







