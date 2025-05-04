#include "linkedlist.hpp"
#include "tree.hpp"
#include <cstddef>
#include <iostream>
#include <vector>
#include <limits.h>

DCLL::DCLL(int value) {
    std::cout << "DCLL: Construction start\n";   
    head = new subnode;
    head->root = new Tree;
    head->root->root = new node;
    head->root->init(head->root->root, value);
    head->next = head;
    head->prev = head;
    size ++;
    std::cout << "DCLL: Object is created\n";   
};

void DCLL::push_front(int value, int mark, int size) {
    subnode* new_node = new subnode;
    new_node->root = new Tree;
    new_node->root->root = new node;
    if (head == nullptr) {
        head = new_node;
        new_node->root->init(new_node->root->root, value);
        new_node->root->size = size;
        new_node->root->root->size = size;
        head->mark = mark;
        head->next = head;
        head->prev = head;
        this->size ++;
        return;
    } else {
        new_node->root->init(new_node->root->root, value);
        new_node->mark = mark;
        new_node->next = head;
        new_node->prev = head->prev;
        new_node->root->size = size;
        new_node->root->root->size = size;
        head->prev->next = new_node;
        head->prev = new_node;
        this->size ++;
    }
};

void DCLL::push_front_node(node* node, int value, int mark, int size) {
    subnode* new_node = new subnode;
    new_node->root = new Tree;
    new_node->root->root = node;
    new_node->root->root->parent = nullptr;
    if (head == nullptr) {
        head = new_node;
        head->mark = mark;
        head->next = head;
        head->prev = head;
        this->size ++;
        return;
    } else {
        new_node->root->size = size;
        new_node->root->root->size = size;
        head->prev->next = new_node;
        head->prev = new_node;
        this->size ++;
    }
};


void DCLL::push_back(int value, int mark, int size) {
    subnode* new_node = new subnode;
    new_node->root = new Tree;
    new_node->root->root = new node;
    if (head == nullptr) {
        head = new_node;
        new_node->root->init(new_node->root->root, value);
        new_node->root->size = size;
        new_node->root->root->size = size;
        head->mark = mark;
        head->next = head;
        head->prev = head;
        this->size ++;
        return;
    } else {
        new_node->root->init(new_node->root->root, value);
        new_node->root->size = size;
        new_node->root->root->size = size;
        new_node->mark = mark;
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
        this->size ++;
    }
};

void DCLL::push_back_node(node* node, int value, int mark, int size) {
    subnode* new_node = new subnode;
    new_node->root = new Tree;
    new_node->root->root = node;
    new_node->root->root->parent = nullptr;
    if (head == nullptr) {
        head = new_node;
        head->mark = mark;
        head->next = head;
        head->prev = head;
        this->size ++;
        return;
    } else {
        new_node->mark = mark;
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
        this->size ++;
    }
};


void DCLL::delete_node() {
    subnode* current = head;
    int counter = 0;
    if (current == nullptr) {
        std::cout << "List is empty\n";
        return;
    } else if (size == 1){
        delete current;
        head = nullptr;
    } else {
        head = head->next;
        head->prev = current->prev;
        current->prev->next = head;
        delete current; 
        size --;
    }
};

void DCLL::delete_n(int value){
    subnode* current = head;
    int counter = 0;
    if (this->size == 1){
        std::cout << "List is about to end\n";
        delete current->root;
        delete current;
    } else {
        while (current != nullptr && counter < size) {
            counter ++;
            if (current->root->root->value == value){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                this->size --;
                return;
            }
            current = current->next;
        }
    }

};

void DCLL::print() {
    subnode* current = head;
    int counter = 0;
    std::cout << "\nThe size = " << this->size << "\n\n\n\n";
    while (current != nullptr && counter < this->size) {
        current = current->next;
        current->root->print_info();
        counter ++;
    }
    std::cout << std::endl;
};

void DCLL::merging(DCLL *list) {
    if (list->head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }
    int counter = 0;
    auto temp = head;
    auto temp2 = temp->next;
    while (counter < size) {
        int in_counter = 0;
        temp2 = temp->next;
        while (in_counter < (size)) {
            if (temp->root->max_degree == temp2->root->max_degree){
                auto value = std::max(temp->root->root->value, temp2->root->root->value);
                auto value1 = std::min(temp->root->root->value, temp2->root->root->value);
                Tree::merge(temp->root, temp2->root);   
                list->delete_n(value);
                if (temp2->root->root->value < temp->root->root->value)
                    temp = temp->next;
            }
            in_counter ++;
            temp2 = temp2->next;
        }
        counter ++;
        temp = temp->next;
    }
};

subnode* DCLL::extractmin(DCLL *list){
    subnode* tmp = head;
    subnode* out = nullptr;
    int counter = 0;
    int Max = INT_MAX;
    while (tmp->next != nullptr && counter <= size){
        counter ++;
        if (tmp->root->root->value < Max){
            Max = tmp->root->root->value;
            out = tmp;     
        }
        tmp = tmp->next;
    }
    out->root->print_info();
    int value;
    for (auto child : out->root->root->children) {
        value = child->value;
        auto mark = child->mark;
        list->push_front(value, mark, child->size);
    }
    delete_n(Max);
    return out;
}

void DCLL::decrease_key(int key, int new_key){
    int counter = 0;
    subnode* current = this->head;
    if (current == nullptr)
        return;

    while (counter < this->size) {
        counter ++;
        if (current->root->root->value == key) {
            current->root->root->value = new_key;
            return;
        }
        current = current->next;
    }
    counter = 0;
    current = this->head;
    node* new_node ;
    while (counter < this->size) {
        new_node = Tree::cut_tree(current->root->root, key, new_key);
        current = current->next;
        counter++;
    }
}
DCLL::~DCLL(){
    std::cout << "DCLL: Destruction start\n";
    int counter = 0;
    if (head == nullptr) {

    } else {
        while (head->next != nullptr && counter < size) {
            counter ++;
            auto temp = head;
            head = head->next;
            if (temp->root != nullptr) {
                delete temp->root;
                temp->root = nullptr;
            }
            if (temp != nullptr) {
                delete temp;
            }
        }
    }
    std::cout << "DCLL: Destroyed\n";
}