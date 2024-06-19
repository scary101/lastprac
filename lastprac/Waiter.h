#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"
#include "Order.h"
#include <vector>

class Waiter : public Employee {
public:
    Waiter(const std::string& login, const std::string& password);
    void serveOrder(Order& order);
    bool operator==(const Waiter& other) const {
        return login == other.login && password == other.password;
    }
};

#endif // WAITER_H
