#pragma once

#include <vector>
#include <memory>

class Employee;

class EmployeeDirectory
{
public:
    EmployeeDirectory();
    EmployeeDirectory & addEmployee(std::shared_ptr<Employee> emp);

    std::size_t countOfEmployees();

    std::shared_ptr<const Employee> getEmployee(size_t index) const;
    std::shared_ptr<Employee> getEmployee(size_t index);

    std::vector<std::shared_ptr<const Employee>> findByName(const std::string& name) const;
    std::vector<std::shared_ptr<Employee>> findByName(const std::string& name);

    virtual ~EmployeeDirectory();

private:
    std::vector<std::shared_ptr<Employee> > _employees;
};

