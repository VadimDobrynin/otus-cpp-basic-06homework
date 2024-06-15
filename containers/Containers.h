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
    MyVector() : adr{nullptr}, size_vector{0}, size_reserved{0}, count{0} {}
    void push_back(int) override;
    int operator[](int) override;
    void erase(size_t) override;
    void insert(size_t, int) override;
    size_t size() override;
    ~MyVector(){
        delete[] adr;
    }
private:
    size_t size_vector;
    size_t size_reserved;
    size_t count;
    int* adr;
};

#endif //OTUS_CPP_BASIC_06HOMEWORK__STATISTICS_H
