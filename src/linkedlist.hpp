#include <vector>
#include "tree.hpp"
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct subnode {
    subnode *next;
    subnode *prev;
    Tree *root;
    int mark;
};

class DCLL {
    private:
        subnode* head;
        int size = 0;
    public:
        DCLL(int value);
        ~DCLL();
        void init(subnode* head, int value);
        void push_front(int value, int mark);
        void push_back(int root, int mark);
        void print();
        void delete_node();
        void delete_n(int value);
        void merging(DCLL *list);
        subnode* extractmin(DCLL *list);
};  
#endif