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

// partial specialization: both template parameters have same type
template <typename T>
class MyClass<T,T> {
public:
    MyClass(T t1, T t2) {
        _t[0] = t1;
        _t[1] = t2;
        printf("MyClass<T> constructed with %s\n", __PRETTY_FUNCTION__);
    }

private:
    T _t[2];
};

// partial specialization: second type is int
template <typename T>
class MyClass<T,int> {
public:
    MyClass(T t, int a) {
        _t = t;
        _a = a;
        printf("MyClass<T, int> constructed with %s\n", __PRETTY_FUNCTION__);
    }

private:
    T _t;
    int _a;
};

// partial specialization: both template parameters are pointer types
template <typename T1, typename T2>
class MyClass<T1*,T2*> {
public:
    MyClass(T1 * t1, T2 * t2)
    : _t1(t1)
    , _t2(t2) {
        printf("MyClass<T*, T*> constructed with %s\n", __PRETTY_FUNCTION__);
    }
private:
    T1 * _t1;
    T2 * _t2;
};

int main() {
    int a = 1;
    float b = 1.1f;
    float c = 2.1f;

    MyClass<int,float> mif(a, b);
    MyClass<float,float> mff(b, c);
    MyClass<float,int> mfi(c, a);
    MyClass<int*,float*> mp(&a, &c);
    return 0;
}
