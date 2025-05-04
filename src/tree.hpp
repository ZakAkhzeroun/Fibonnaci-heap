#include <vector>
#ifndef TREE_HPP
#define TREE_HPP

struct node {
    int value;
    int mark;
    int size;
    node* parent;
    std::vector<node*> children;
};

class Tree{
    public:
        int size = 0;
        int max_degree = 0;
        node* root;
        Tree();
        Tree(int value);
        ~Tree();
        void print_info();
        void init(node* root, int value); 
        void delete_tree(node*);
        static node* cut_tree(node*, int key, int new_key);
        static void merge(Tree *, Tree *);
};
#endif