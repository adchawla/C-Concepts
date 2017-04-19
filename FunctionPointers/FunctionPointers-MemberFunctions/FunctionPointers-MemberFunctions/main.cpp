//
//  main.cpp
//  FunctionPointers-MemberFunctions
//
//  Created by Amandeep Chawla on 19/04/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#include <iostream>

class A {
public:
    void print1() {
        std::cout<<"print1\n";
    }
    
    void print2() {
        std::cout<<"print2\n";
    }
};

typedef void (A::*fnPtr)();
int main(int argc, const char * argv[]) {
    
    fnPtr f = &A::print2;
    A a;
    A * b = &a;
    
    (a.*f)();
    (b->*f)();
    return 0;
}
