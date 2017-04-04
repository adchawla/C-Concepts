#include <iostream>

class Base {
public:
	std::string func1() {
		return("Base::func1() called");
	}

	std::string func2() {
		return("Base::func2() called");
	}
};

class Derived1 : public Base {
public:
	std::string func1() {
		return("Derived1::func1() called");
	}

	std::string func2() {
		return("Derived1::func2() called");
	}
};

class Derived2 : public Base {
public:
	std::string func1() {
		return("Derived2::func1() called");
	}

	std::string func2() {
		return("Derived2::func2() called");
	}
};

int main() {
	Base b;
	Derived1 d1;
	Derived2 d2;
	std::cout << "Scenario 1 : Calling functions on objects directly\n";
	std::cout << "\tb.func1(): " << b.func1().c_str() << "\n";
	std::cout << "\tb.func2(): " << b.func2().c_str() << "\n";
	std::cout << "\t\td1.func1(): " << d1.func1().c_str() << "\n";
	std::cout << "\t\td1.func2(): " << d1.func2().c_str() << "\n";
	std::cout << "\t\t\td2.func1(): " << d2.func1().c_str() << "\n";
	std::cout << "\t\t\td2.func2(): " << d2.func2().c_str() << "\n";

	Base * pb = &b;
	std::cout << "Scenario 2 : Calling functions on pointer to base\n";
	std::cout << "\tb.func1(): " << pb->func1().c_str() << "\n";
	std::cout << "\tb.func2(): " << pb->func2().c_str() << "\n";
	pb = &d1;
	std::cout << "\t\td1.func1(): " << pb->func1().c_str() << "\n";
	std::cout << "\t\td1.func2(): " << pb->func2().c_str() << "\n";
	pb = &d2;
	std::cout << "\t\t\td2.func1(): " << pb->func1().c_str() << "\n";
	std::cout << "\t\t\td2.func2(): " << pb->func2().c_str() << "\n";

	Base & rb = b;
	std::cout << "Scenario 2 : Calling functions on reference to base\n";
	std::cout << "\tb.func1(): " << rb.func1().c_str() << "\n";
	std::cout << "\tb.func2(): " << rb.func2().c_str() << "\n";
	Base & rb2 = d1;
	std::cout << "\t\td1.func1(): " << rb2.func1().c_str() << "\n";
	std::cout << "\t\td1.func2(): " << rb2.func2().c_str() << "\n";
	Base & rb3 = d2;
	std::cout << "\t\t\td2.func1(): " << rb3.func1().c_str() << "\n";
	std::cout << "\t\t\td2.func2(): " << rb3.func2().c_str() << "\n";
}
