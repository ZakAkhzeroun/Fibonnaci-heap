#include <iostream>
#include "linkedlist.hpp"
#include "tree.hpp"

int main(void){
    int value = 1;
    DCLL list(value);
    list.push_back(9, 2);
    list.push_back(123, 2);
    list.push_back(210, 2);
    list.push_back(211, 2);
    list.push_back(2, 2);
    list.push_back(2101, 2);
    list.push_back(111, 2);
    list.print();
    list.merging(&list);
    list.print();
    auto a = list.extractmin(&list);
    list.print();

    return 0;

}