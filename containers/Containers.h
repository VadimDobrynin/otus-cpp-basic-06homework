//
// Created by vadim on 13.06.2024.
//

#ifndef OTUS_CPP_BASIC_05HOMEWORK__CONTAINERS_H
#define OTUS_CPP_BASIC_05HOMEWORK__CONTAINERS_H

#include "IContainers.h"
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>


class MyVector : public IContainers{
public:
    MyVector() : adr{nullptr}, size_reserved{2}, count{0} {}
    void push_back(int) override;
    int operator[](int) override;
    bool erase(size_t) override;
    bool insert(size_t, int) override;
    size_t size() override;
    ~MyVector() override{
        delete[] adr;
    }
private:
    size_t size_reserved;
    size_t count;
    int* adr;
};


/*!
 * односвязный спсиок
 */

class MyLinkedList : public IContainers{
public:
    MyLinkedList(): nextObject{nullptr}, val{0}, count_elements{0}{}
    MyLinkedList(int value): nextObject{nullptr},count_elements{1}, val{value}{}
    void push_back(int) override;
    int operator[](int) override;
    bool erase(size_t) override;
    bool insert(size_t, int) override;
    size_t size() override;
    ~MyLinkedList(){}
private:
    int val;
    size_t count_elements;
    MyLinkedList *nextObject;
    MyLinkedList* get(size_t index);
};

#endif //OTUS_CPP_BASIC_06HOMEWORK__STATISTICS_H
