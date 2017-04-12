#include <iostream>
#include <conio.h>

class A {
public:
    A(const std::string & name)
        : mName(name) {
        std::cout << "A's constructor for "<< mName.c_str() <<" object\n";
    }

    ~A() { 
        std::cout << "A's destructor for " << mName.c_str() << " object\n";
    }

    A(const A & src)
        : mName(src.mName) {
        mName.append(" - copy");
        std::cout << "A's copy constructor for " << mName.c_str() << " object\n";
    }

    A(const A && src)
        : mName(std::move(src.mName)) {
        std::cout << "A's move constructor for " << mName.c_str() << " object\n";
    }

    A & operator = (const A & lhs) {
        if (this != &lhs) {
            mName = lhs.mName + " - copy";
            std::cout << "A's assignment operator for " << mName.c_str() << " object\n";
        }
        else {
            std::cout << "Nothing to be done in assignment operator for " << mName.c_str() << " object\n";
        }
    }

    const std::string & getName() { return mName;  }

private:
    std::string mName;
};

A combine(A & a, A & b);
int main() {
    A a("one");
    A b("two");
    A c = combine(a, b);
    std::cout << "Name of c is " << c.getName().c_str() << "\n";
    getch();
}

A combine(A & a, A & b) {
    std::string newName(a.getName());
    newName.append(" - ").append(b.getName());
    A c(newName);
    return c;
}
