//
// Created by vadim on 13.06.2024.
//
#include "Containers.h"

///---------------------------------------------------------------------------------------------------------------------
void MyVector::push_back(int value) {
    /*!
     * проверка на то,
     * было ли хоть раз что то добавлено
     */
    if(adr == nullptr){
        size_vector = 1;
        size_reserved = 2 * size_vector;
        adr = new int[size_reserved];
        adr[count] = value;
        count++;
    }else{
        if(count == size_reserved){
            int* tmp = new int[2 * size_reserved];
            for(size_t i = 0; i < size_reserved; i++){
                tmp[i] = adr[i];
            }
            size_reserved *= 2;
            tmp[count] = value;
            delete[] adr;
            adr = tmp;
            tmp = nullptr;
            count++;
        }else{
            adr[count] = value;
            count++;
        }
    }
}
int MyVector::operator[] (int index) {
    return adr[index];
}
void MyVector::erase(size_t index) {
    if(index == count - 1){
        count--;
    }else if(index < count - 1){
        for(size_t i = index; i < count - 1; i++){
            adr[i] = adr[i + 1];
        }
        count--;
    }
}
void MyVector::insert(size_t index, int value) {
    if(count == size_reserved){
        int* tmp = new int[2 * size_reserved];
        for(size_t i = 0; i < index; i++){
            tmp[i] = adr[i];
        }
        for(size_t i = index; i < count; i++){
            tmp[i + 1] = adr[i];
        }
        size_reserved *= 2;
        count++;
        tmp[index] = value;
        delete[] adr;
        adr = tmp;
    }else{
        for(size_t i = 0; i < index; i++){
            adr[i] = adr[i];
        }
        for(size_t i = count; i > index; i--){
            adr[i] = adr[i - 1];
        }
        adr[index] = value;
        count++;
    }

}
size_t MyVector::size(){
    return this->count;
}
///---------------------------------------------------------------------------------------------------------------------

