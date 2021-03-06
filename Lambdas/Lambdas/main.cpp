#include <iostream>
#include "EmployeeDirectory.h"
#include "Employee.h"

using std::shared_ptr;
using std::make_shared;

static EmployeeDirectory sEmployeeDirectory;

void populateEmployees() {
    shared_ptr<Employee> employee;

    employee = make_shared<Employee>("Nipun Jindal", "Android XD", "njindal@adobe.com", 27);
    sEmployeeDirectory.addEmployee(employee);

    employee = make_shared<Employee>("Amandeep Chawla", "Android XD", "amandeep@adobe.com", 36);
    sEmployeeDirectory.addEmployee(employee);

    employee = make_shared<Employee>("Hemant Badhani", "Adobe Capture", "hbadhani@adobe.com", 33);
    sEmployeeDirectory.addEmployee(employee);

    employee = make_shared<Employee>("Abhishek Garg", "Adobe Sketch", "abgarg@adobe.com", 24);
    sEmployeeDirectory.addEmployee(employee);
}

void printAllEmployees() {
    size_t count = sEmployeeDirectory.countOfEmployees();
    for (size_t i = 0; i < count; ++i) {
        auto employee = sEmployeeDirectory.getEmployee(i);
        std::cout << employee->Name() << "'s email ID is " << employee->EmailID() << " and he works for " << employee->Department();
        std::cout << "\n";
    }
}

void printEmployees(std::vector<shared_ptr<Employee>> employees) {
    for each (auto employee in employees)
    {
        std::cout << employee->Name() << "\t\t" << std::to_string(employee->Age()) << "\t\t" << employee->EmailID() << "\t" << employee->Department() << "\n";
    }
}

bool mySearchFunc(shared_ptr<const Employee> emp) {
    if (emp->Department() == "Android XD") {
        return true;
    }
    return false;
}

class myFunctor {
public:
    bool operator()(shared_ptr<const Employee> emp) {
        if (emp->EmailID().size() < 18) {
            return true;
        }
        return false;
    }
};

class ageFunctor {
public:
    ageFunctor(uint8_t min, uint8_t max)
        : _min(min)
        , _max(max) {}

    bool operator()(shared_ptr<const Employee> emp) {
        uint8_t age = emp->Age();
        if (age >= _min && age <= _max) {
            return true;
        }
        return false;
    }

private:
    uint8_t _min;
    uint8_t _max;
};

int main() {
    populateEmployees();
    //printAllEmployees();
    /*auto list = sEmployeeDirectory.find([](shared_ptr<const Employee> emp) {
        if (emp->Age() < 30) {
            return true;
        }
        return false;
    });
    */
    //printEmployees(list);

    //list = sEmployeeDirectory.find(mySearchFunc);
    //list = sEmployeeDirectory.find(myFunctor());
    //printEmployees(list);
    uint8_t minAge = 26, maxAge = 40;
    //printEmployees(sEmployeeDirectory.find(ageFunctor(minAge, maxAge)));
    /*printEmployees(sEmployeeDirectory.find([=](shared_ptr<const Employee> emp) {
        auto age = emp->Age();
        if (age >= minAge && age <= maxAge) {
            return false;
        }
        return true;
    }));*/
    auto lamda = [&](shared_ptr<const Employee> emp) {
        auto age = emp->Age();
        if (age >= minAge && age <= maxAge) {
            return false;
        }
        return true;
    };
    printEmployees(sEmployeeDirectory.find(lamda));
    minAge = 35;
    std::cout << "\n";
    printEmployees(sEmployeeDirectory.find(lamda));
}

