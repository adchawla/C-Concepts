#include "MyObject.h"
#include <iostream>



MyObject::MyObject()
{
    std::cout << "Object of MyObject constructed\n";
}


MyObject::~MyObject()
{
    std::cout << "Object of MyObject destructed\n";
}
