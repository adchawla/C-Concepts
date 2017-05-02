#include "EmployeeDirectory.h"
#include "Employee.h"


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

std::vector<std::shared_ptr<Employee>> EmployeeDirectory::find(std::function<bool(std::shared_ptr<const Employee>)> func)
{
    std::vector<std::shared_ptr<Employee>> list;
    for each (auto employee in _employees)
    {
        if (func(employee)) {
            list.push_back(employee);
        }
    }
    return list;
}

std::vector<std::shared_ptr<const Employee>> EmployeeDirectory::findByName(const std::string& name) const
{
    std::vector<std::shared_ptr<const Employee>> list;
    for each (auto employee in _employees)
    {
        if (employee->Name().find(name) != std::string::npos) {
            list.push_back(employee);
        }
    }
    return list;
}

std::vector<std::shared_ptr<Employee>> EmployeeDirectory::findByName(const std::string& name)
{
    std::vector<std::shared_ptr<Employee>> list;
    for each (auto employee in _employees)
    {
        if (employee->Name().find(name) != std::string::npos) {
            list.push_back(employee);
        }
    }
    return list;
}

EmployeeDirectory::~EmployeeDirectory()
{
}
