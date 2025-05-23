#include "tree.hpp"
#include <iostream>
#include <vector>

Tree::Tree() {
    std::cout << "Tree: Construction start\n";   
    this->root = new node;
    this->root->parent = nullptr;
    size = 0;
    max_degree = 0;
    root->children = {};
    std::cout << "Tree: Object is created\n";   
};

Tree::Tree(int value) {
    std::cout << "Tree: Construction start and will be initialized\n";   
    this->root = new node;
    if (this->root == NULL) {
        std::cout << "Tree: Construction failed, root is not null\n";
        return;
    }
    this->root->value = value;
    // root->size = 1;
    this->size = 1;
    this->max_degree = 0;
    std::cout << "Tree: Object is created and initialized\n";   
};

void Tree::init(node* node, int value) {
    if (node == NULL || node->parent != NULL || node->children.size() != 0) {
        std::cout << "Tree: Initialization failed\n";
        return;
    }
    if (this->root == NULL) {
        std::cout << "Tree: Initialization failed, root is not null\n";
        return;
    }
    this->root = node;
    this->root->value = value;
    // root->size = 1;
    this->size = 1;
    this->max_degree = 0;
};

void Tree::print_info(){
    std::cout << "Root value: " << root->value << "\n";
    std::cout << "Root size: " << size << "\n\n";
};

void Tree::merge(Tree *rtree, Tree* ltree){
    if (rtree->root->value < ltree->root->value) {
        rtree->root->children.push_back(ltree->root);
        ltree->root->parent = rtree->root;
        rtree->size += ltree->size;
        rtree->root->size += ltree->root->size;
        rtree->max_degree ++;
        if (ltree->max_degree > rtree->max_degree) {
            rtree->max_degree = ltree->max_degree;
        }
    } else {
        ltree->root->children.push_back(rtree->root);
        rtree->root->parent = ltree->root;
        ltree->size += rtree->size;
        ltree->root->size += rtree->root->size;
        ltree->max_degree ++;
        if (rtree->max_degree > ltree->max_degree) {
            ltree->max_degree = rtree->max_degree;
        }
    }
}

void Tree::delete_tree(node* root){
    if (root == nullptr) 
        return;
    if (root->children.size() > 1) {
        for (auto child : root->children) {
            delete_tree(child);
        }
    }
    delete root;
}

node* Tree::cut_tree(node *head, int key, int new_key){
    if (head == nullptr){
        std::cout << "No node was found\n";
        return nullptr;
    }
    if (head->value == key){
        head->value = new_key;
        if (head->parent != nullptr && head->parent->value > head->value){
            head->parent = nullptr;
            return head;
        }
    } else {
        for (auto child : head->children){
            cut_tree(child, key, new_key);
        }
    }

}

Tree::~Tree() {
    std::cout << "Tree: Destruction start\n";
    if (root == nullptr)
        return;
    delete_tree(root);
    std::cout << "Tree: Destroyed\n";
}