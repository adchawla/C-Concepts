//
//  TStack.hpp
//  002BasicClassTemplates
//
//  Created by Amandeep Chawla on 7/4/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#ifndef TStack_hpp
#define TStack_hpp

#include <stdio.h>
#define STACK_SIZE 100

template< typename dataType, size_t StackSize = STACK_SIZE >
class TStack {
public:
    TStack()
    : mCount(0) { }

    void push(const dataType & data) {
        mStorage[mCount] = data;
        mCount++;

    }
    dataType pop() {
        mCount--;
        return mStorage[mCount];
    }

    size_t count();

private:
    dataType mStorage[StackSize];
    size_t   mCount;
};

template< typename T, size_t StackSize >
size_t TStack<T, StackSize>::count() {
    return mCount;
}

/*
template<>
class TStack<bool> {
    TStack() : mCount(0) {}

    void push(const bool & data) {

    }
    bool pop() {
    }

    size_t count();


private:
    char mStorage[13];
    size_t mCount;
};
*/
#endif /* TStack_hpp */
