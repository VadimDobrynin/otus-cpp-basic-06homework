#include <iostream>
#include "containers//Containers.h"
#include <vector>
int main() {
    std::cout << "containers" << std::endl;
    MyVector v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    std::cout << "---";
    for(int i = 0 ; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    v.erase(2);
    v.erase(3);
    v.erase(4);
    std::cout << std::endl;
    std::cout << "---";
    for(int i = 0 ; i < v.size(); i++){
        std::cout << v[i] << " ";
    }

    v.insert(0, 10);
    std::cout << std::endl;
    for(int i = 0 ; i < v.size(); i++){
        std::cout << v[i] << " ";
    }

    v.insert(4, 20);
    std::cout << std::endl;
    for(int i = 0 ; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    v.insert(v.size(), 30);
    std::cout << std::endl;
    for(int i = 0 ; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl << "------------------" << std::endl;
    ///-------------------------------------
    MyLinkedList mll;
    for(int i = 0; i < 10;i++){
        mll.push_back(i);
    }
//    mll.push_back(7);
//    mll.push_back(8);
//    mll.push_back(9);
//    std::cout << mll[0] << " ";
//    std::cout << mll[1] << " ";
//    std::cout << mll[2] << " ";

    for(int i = mll.size() - 1 ; i > 0; i--){
        std::cout << mll[i] << " ";
    }
    ///-------------------------------------


    return 0;
}