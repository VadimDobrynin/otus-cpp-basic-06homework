//
// Created by vadim on 13.06.2024.
//
#include "Containers.h"

///---------------------------------------------------------------------------------------------------------------------
/*!
 * Добавление элемента в конец спсика.
 */
void MyVector::push_back(int value) {
    if(adr == nullptr){
        adr = new int[size_reserved];
        adr[0] = value;
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
/*!
 * Удаление элемента из списка по индексу.
 * Если индекс больше размера массива, операция игнорируется(возвращается false);
 */
bool MyVector::erase(size_t index) {
    if(index <= count - 1){
        for(size_t i = index; i < count - 1; i++){
            adr[i] = adr[i + 1];
        }
        count--;
        return true;
    }
    return false;
}
/*!
 *
 * @param index
 * @param value
 * @return false - в случае неуспеха операции
 */
bool MyVector::insert(size_t index, int value) {
    ///< невозможная позиция
    if(index > count){
        return false;
    }
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
        for(size_t i = count; i > index; i--){
            adr[i] = adr[i - 1];
        }
        adr[index] = value;
        count++;
    }
    return true;
}
size_t MyVector::size(){
    return this->count;
}
///---------------------------------------------------------------------------------------------------------------------

void MyLinkedList::push_back(int value) {
    if(count_elements == 0){
        this->val = value;
        count_elements += 1;
        return;
    }
    MyLinkedList* lastObject = this;
    while(lastObject->nextObject != nullptr){
        lastObject = lastObject->nextObject;
    }
    lastObject->nextObject = new MyLinkedList(value);
    count_elements++;
}
int MyLinkedList::operator[] (int index) {
       auto res = get(index);
       if(res == nullptr){
           return val;
       }else{
           return res->val;
       }
}
bool MyLinkedList::erase(size_t index) {
    if(index < count_elements){
        auto tmp_prev = get(index - 1);
        auto tmp_index = get(index);
        if(tmp_prev == nullptr) {
            if(tmp_index->nextObject != nullptr){
                tmp_index->val = tmp_index->nextObject->val;
                auto t = tmp_index->nextObject;
                tmp_index->nextObject = tmp_index->nextObject->nextObject;
                count_elements--;
                delete t;
                return true;
            }
        }else{
            tmp_prev->nextObject = tmp_index->nextObject;
            count_elements--;
            delete tmp_index;
            return true;
        }
    }else{
        return false;
    }
}
bool MyLinkedList::insert(size_t index, int value) {return false;}
size_t MyLinkedList::size() {return count_elements;}

MyLinkedList* MyLinkedList::get(size_t index){
    MyLinkedList* indexObject = this;
    if(index < count_elements){
        for(size_t i = 0; i < index; i++){
            indexObject = indexObject->nextObject;
        }
        return indexObject;
    }
    return nullptr;
}

///---------------------------------------------------------------------------------------------------------------------
