//
// Created by vadim on 17.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H
#define OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H

#include "IContainers.h"

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

#endif //OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H
