#include "Guest.h"
using namespace std;
Guest::Guest(const string& login, const string& password)
    : login(login), password(password) {}

string Guest::getLogin() const {
    return login;
}

bool Guest::authenticate(const string& password) const {
    return this->password == password;
}

void Guest::makeOrder(const Order& order) {
    orders.push_back(order);
}

const vector<Order>& Guest::getOrders() const {
    return orders;
}
