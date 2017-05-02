#include "Employee.h"


Employee::Employee(
    const std::string &name, const std::string &department,
    const std::string &email, uint8_t age)
    : _name(name)
    , _department(department)
    , _emailID(email)
    , _age(age)
{
}

Employee::~Employee()
{
}

void Employee::Name(const std::string &val)
{
    _name = val;
}

std::string Employee::Name() const
{
    return _name;
}

void Employee::Department(const std::string &val)
{
    _department = val;
}

std::string Employee::Department() const
{
    return _department;
}

void Employee::EmailID(const std::string &val)
{
    _emailID = val;
}

std::string Employee::EmailID() const
{
    return _emailID;
}

void Employee::Age(uint8_t val)
{
    _age = val;
}

uint8_t Employee::Age() const
{
    return _age;
}
