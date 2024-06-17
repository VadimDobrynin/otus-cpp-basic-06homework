//
// Created by vadim on 17.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H
#define OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H

#include "IContainers.h"

class MyLinkedList : public IContainers{
public:
    MyLinkedList(): nextObject{nullptr}, val{0}, count_elements{0}{}
    MyLinkedList(int value): nextObject{nullptr},count_elements{1}, val{value}{}
    void push_back(int) override;
    int operator[](int) override;
    bool erase(size_t) override;
    bool insert(size_t, int) override;
    size_t size() override;
    ~MyLinkedList(){
        for(size_t i = this->size(); i > 0; i--){
            delete this->get(i);
        }
    }
private:
    int val;
    size_t count_elements;
    MyLinkedList *nextObject;
    MyLinkedList* get(size_t index);
};
#endif //OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H
