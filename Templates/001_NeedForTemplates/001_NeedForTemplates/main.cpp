#include <iostream>


int const& max (int const& a, int const& b);

// maximum of two values of any type
/*
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
    return max (max(a,b), c);
}
 */


inline int const& max (int const& a, int const& b)
{
    std::cout<<"max(1,2)\n";
    return a<b?b:a;
}

int main()
{
    /*::max(7, 42, 68);

    ::max(7.0, 42.0);
    ::max('a', 'b');
    ::max(7, 42);
    ::max<>(7, 42);
    ::max<double>(7, 42);
     */
    ::max('a', 42.7);

    return 0;
}
