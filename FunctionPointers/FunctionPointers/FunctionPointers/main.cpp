//
//  main.cpp
//  FunctionPointers
//
//  Created by Amandeep Chawla on 18/04/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#include <iostream>
#include <map>

typedef int (*operationFn)(int, int);

class OperationRegistry {
public:
    void addOperation(char operation, operationFn func) {
        mOperationFns[operation] = func;
    }
    
    operationFn getOperation(char operation) {
        return mOperationFns.at(operation);
    }
    
private:
    std::map<char, operationFn> mOperationFns;
};

static OperationRegistry sOperationRegistry;

void performComputation(char symbol, int a, int b) {
    std::cout<<a<<" "<<symbol<<" "<<b<<" = ";
    int result = 0;
    try {
        operationFn funcPtr = sOperationRegistry.getOperation(symbol);
        result = funcPtr(a, b);
        std::cout<<result<<"\n";
    } catch (...) {
        std::cout<<"undefined\n";
    }
}

int addition(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int multiply(int a, int b);
int modulus(int a, int b);

int main(int argc, const char * argv[]) {
    sOperationRegistry.addOperation('+', addition);
    sOperationRegistry.addOperation('-', subtract);
    sOperationRegistry.addOperation('/', divide);
    sOperationRegistry.addOperation('*', multiply);
    sOperationRegistry.addOperation('%', modulus);
    sOperationRegistry.addOperation('x', multiply);
        
    performComputation('+', 2, 3);
    performComputation('-', 2, 3);
    performComputation('/', 2, 3);
    performComputation('*', 2, 3);
    performComputation('%', 2, 3);
    performComputation('x', 2, 3);
}

int addition(int a, int b) { return a + b;}
int subtract(int a, int b) { return a - b;}
int divide(int a, int b) { return a / b;}
int multiply(int a, int b) { return a * b;}
int modulus(int a, int b) { return a % b; }
