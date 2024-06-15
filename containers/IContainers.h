//
// Created by vadim on 13.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK__ICONTAINERS_H
#define OTUS_CPP_BASIC_06HOMEWORK__ICONTAINERS_H

/*!
 * Интерфейс классов по расчёту статистики
 */
#include <cstddef>
class IContainers{
public:
    virtual void push_back(int) = 0;
    virtual void insert(size_t, int)  = 0;
    virtual void erase(size_t) = 0;
    virtual size_t size() = 0;
    virtual int operator[](int) = 0;
//    virtual ~IContainers() = 0;
};

#endif //OTUS_CPP_BASIC_05HOMEWORK__ISTATISTICS_H