#include "MyObject.h"
#include <iostream>

int main() {
    MyObject myObj1("1");
    MyObject * myObj2 = new MyObject("2");
    delete myObj2;
}
