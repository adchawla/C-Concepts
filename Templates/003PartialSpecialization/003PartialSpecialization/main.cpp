//
//  main.cpp
//  003PartialSpecialization
//
//  Created by Amandeep Chawla on 7/11/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MyClass {
public:
    MyClass(T1 t1, T2 t2)
    : _t1(t1)
    , _t2(t2)
    {
        printf("MyClass<T1, T2> constructed with %s\n", __PRETTY_FUNCTION__);
    }

private:
    T1 _t1;
    T2 _t2;
};

int main() {
    int a = 1;
    float b = 1.1f;
    float c = 2.1f;

    MyClass<int,float> mif(a, b);    // uses MyClass<T1,T2>
    MyClass<float,float> mff(b, c);  // uses MyClass<T,T>
    MyClass<float,int> mfi(c, a);    // uses MyClass<T,int>
    MyClass<int*,float*> mp(&a, &c);   // uses MyClass<T1*,T2*>
    return 0;
}
