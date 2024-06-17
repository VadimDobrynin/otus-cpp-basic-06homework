#include <iostream>
#include "containers//Containers.h"
#include <vector>

void test(IContainers*);
int main() {
    std::cout << "containers" << std::endl;
    IContainers* v = new MyVector;
    IContainers* l = new MyLinkedList;
    std::cout << "vector" <<std::endl;
    test(v);
    std::cout << "linked list" <<std::endl;
    test(l);

    return 0;
}

void test(IContainers* cont){
    for(int i = 0; i < 10; i++){
        cont->push_back(i);
    }
    for(int i = 0; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;
    std::cout << cont->size() <<std::endl;

    cont->erase(2);
    cont->erase(3);
    cont->erase(4);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    cont->insert(0, 10);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;

    cont->insert(4, 20);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;

    cont->insert(cont->size(), 30);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;
}