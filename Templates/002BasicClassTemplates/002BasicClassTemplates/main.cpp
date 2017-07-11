//
//  main.cpp
//  002BasicClassTemplates
//
//  Created by Amandeep Chawla on 7/4/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#include <iostream>

#include "TStack.hpp"

int main(int argc, const char * argv[]) {
    TStack<int> intStack;

    for(int i = 0; i < 500; ++i) {
        intStack.push(i);
    }


    for(int i = 0; i < 25; ++i) {
        std::cout<<intStack.pop()<<"\n";
    }

    std::cout<<intStack.count()<< " elements are still left in the stack";
    return 0;
}
