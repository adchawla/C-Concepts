#pragma once
#include <string>

class Employee
{
public:
    Employee(
        const std::string &name, const std::string &department,
        const std::string &email, uint8_t age);

    virtual ~Employee();

    std::string Name() const;
    void Name(const std::string &val);

    std::string Department() const;
    void Department(const std::string &val);

    std::string EmailID() const;
    void EmailID(const std::string &val);

    uint8_t Age() const;
    void Age(uint8_t val);
private:
    std::string _name;
    std::string _department;
    std::string _emailID;
    uint8_t _age;
};

