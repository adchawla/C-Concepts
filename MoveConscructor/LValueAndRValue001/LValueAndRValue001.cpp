#include <iostream>

//int foo() { return 2; }
int a;
int & foo() { return a; }

int main()
{
    foo() = 2;

    return 0;
}