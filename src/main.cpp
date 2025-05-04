#include <iostream>
#include "linkedlist.hpp"
#include "tree.hpp"

int main(void){
    int value = 1;
    DCLL list(value);
    list.push_back(9, 2,1);
    list.push_back(123, 2,1);
    list.push_back(210, 2,1);
    list.push_back(211, 2,1);
    list.push_back(2, 2,1);
    list.push_back(2101, 2,1);
    list.push_back(111, 2,1);
    list.merging(&list);
    list.extractmin(&list);
    list.print();
    return 0;

}