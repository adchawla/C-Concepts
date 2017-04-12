
#include <iostream>
#include <conio.h>

class Base {
	void fun1() { }
	void fun2() { }
	uint32_t a;
	char b;
	char d;
	float c;

	virtual void func1() {}
	virtual void func2() {}
};

class Derived : virtual public Base {
public:
	void func1() {}
	int e;
	virtual void func3() {
		std::cout << "Derived::func3()";
	}
};

int main() {
	Derived * d1 = new Derived();
	Derived * d2 = new Derived();
	Base *b1 = new Base();
	Base * b = d1;
	d1->func3();
	std::cout << "Size of Base is " << sizeof(Base) << "and size of Derived is " << sizeof(Derived);
	getch();
}