#pragma once
#include <string>

class MyObject
{
public:
    MyObject(const std::string & id);
    virtual ~MyObject();

private:
    std::string mID;
};

