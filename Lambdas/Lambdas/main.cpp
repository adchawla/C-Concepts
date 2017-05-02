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

int main() {
    populateEmployees();
    printAllEmployees();
}
