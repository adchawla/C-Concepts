#include <iostream>

//int foo() { return 2; }

int & foo() { return 2; }

int main()
{
    foo() = 2;

    return 0;
}