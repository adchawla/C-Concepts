//
//  main02.cpp
//  001_NeedForTemplates
//
//  Created by Amandeep Chawla on 7/4/17.
//  Copyright © 2017 Amandeep Chawla. All rights reserved.
//
/*

#include "main02.hpp"
#include <iostream>

// maximum of two values of any type
template <typename T>
inline T const& max (T const& a, T const& b)
{
    std::cout<<"max<T>(1,2)\n";
    return a<b?b:a;
}

// maximum of three values of any type
template <typename T>
inline T const& max (T const& a, T const& b, T const& c)
{
    std::cout<<"max<T>(1,2,3)\n";
    return max (max(a,b), c);  // uses the template version even for ints
}                              // because the following declaration comes
// too late:
// maximum of two int values
inline int const& max (int const& a, int const& b)
{
    std::cout<<"max(1,2)\n";
    return a<b?b:a;
}

int main2()
{
    ::max(7, 42, 68);



     ::max(7.0, 42.0);
     ::max('a', 'b');
     ::max(7, 42);
     ::max<>(7, 42);
     ::max<double>(7, 42);
     ::max('a', 42.7);
    
    return 0;
}
*/
