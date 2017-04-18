//
//  main.cpp
//  FunctionPointers
//
//  Created by Amandeep Chawla on 18/04/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#include <iostream>

int addition(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int multiply(int a, int b);

void performComputation(char symbol, int a, int b) {
    std::cout<<a<<" "<<symbol<<" "<<b<<" = ";
    int result = 0;
    bool validSymbol = true;
    switch(symbol) {
        case '+' : result = addition(a, b); break;
        case '-' : result =  subtract(a, b); break;
        case '/' : result =  divide(a, b); break;
        case '*' : result =  multiply(a, b); break;
        default : validSymbol = false;
    }
    if (validSymbol) {
        std::cout<<result<<"\n";
    } else {
        std::cout<<"undefined\n";
    }
    
}

int main(int argc, const char * argv[]) {
    performComputation('+', 2, 3);
    performComputation('-', 2, 3);
    performComputation('/', 2, 3);
    performComputation('*', 2, 3);
}

int addition(int a, int b) { return a + b;}
int subtract(int a, int b) { return a - b;}
int divide(int a, int b) { return a / b;}
int multiply(int a, int b) { return a * b;}
