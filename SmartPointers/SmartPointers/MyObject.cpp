#include "MyObject.h"
#include <iostream>



MyObject::MyObject(const std::string & id)
    : mID(id)
{
    std::cout << "MyObject with id = "<<mID<<" is constructed\n";
}


MyObject::~MyObject()
{
    std::cout << "MyObject with id = "<< mID<<" is destructed\n";
}
