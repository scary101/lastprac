#include "Employee.h"
#include "Order.h"
using namespace std;
Employee::Employee(const string& login, const string& password) : User(login, password) {}

void Employee::startPreparation(Order& order) {
    order.setStatus(Order::Status::InPreparation);
}
