#include "EmployeeDirectory.h"



EmployeeDirectory::EmployeeDirectory()
{
}


EmployeeDirectory & EmployeeDirectory::addEmployee(std::shared_ptr<Employee> emp)
{
    _employees.push_back(emp);
    return *this;
}

std::size_t EmployeeDirectory::countOfEmployees()
{
    return _employees.size();
}

std::shared_ptr<const Employee> EmployeeDirectory::getEmployee(size_t index) const
{
    return _employees.at(index);
}

std::shared_ptr<Employee> EmployeeDirectory::getEmployee(size_t index)
{
    return _employees.at(index);
}

EmployeeDirectory::~EmployeeDirectory()
{
}
