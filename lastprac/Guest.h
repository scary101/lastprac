#ifndef GUEST_H
#define GUEST_H

#include <string>
#include <vector>
#include "Order.h"
using namespace std;
class Guest {
private:
    std::string login;
    std::string password;
    std::vector<Order> orders;

public:
    Guest(const std::string& login, const std::string& password);
    std::string getLogin() const;
    bool authenticate(const std::string& password) const;
    void makeOrder(const Order& order);
    const std::vector<Order>& getOrders() const;
    bool operator==(const Guest& other) const {
        return login == other.login && password == other.password;
    }
};



#endif // GUEST_H
