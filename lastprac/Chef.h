#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include "Order.h"

class Chef : public Employee {
public:
    Chef(const std::string& login, const std::string& password);
    void startPreparation(Order& order);
    bool operator==(const Chef& other) const {
        return login == other.login && password == other.password;
    }
};

#endif // CHEF_H
