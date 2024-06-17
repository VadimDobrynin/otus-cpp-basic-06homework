//
// Created by vadim on 17.06.2024.
//
#include "linkedList.h"
#include <algorithm>

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
bool MyLinkedList::insert(size_t index, int value) {
    if(index == 0){
        auto item = new MyLinkedList(value);
        std::swap(this->val, item->val);
        std::swap(this->nextObject, item->nextObject);
        this->nextObject = item;
        count_elements++;
    }else{
        auto item_prev = get(index - 1);
        auto item = new MyLinkedList(value);
        item->nextObject = item_prev->nextObject;
        item_prev->nextObject = item;
        count_elements++;
    }
    return true;
}
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
