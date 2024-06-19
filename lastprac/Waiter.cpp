#include "Waiter.h"
using namespace std;
Waiter::Waiter(const string& login, const string& password)
    : Employee(login, password) {}

void Waiter::serveOrder(Order& order) {
    order.setStatus(Order::Status::Served);
}
