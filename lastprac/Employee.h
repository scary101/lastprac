#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include "Order.h"
using namespace std;
class Employee : public User {
public:
    Employee(const string& login, const string& password);
    void startPreparation(Order& order);
};

#endif // EMPLOYEE_H
