#include <vector>
#ifndef TREE_HPP
#define TREE_HPP

struct node {
    int value;
    int mark;
    node* parent;
    std::vector<node*> children;
};

class Tree{
    private:
        int size = 0;
    public:
        int max_degree = 0;
        node* root;
        Tree();
        Tree(int value);
        ~Tree();
        void print_info();
        void init(node* root, int value); 
        void delete_tree(node*);
        static void merge(Tree *, Tree *);
};
#endif