#include "Order.h"
using namespace std;
Order::Order(int id, const vector<MenuItem>& items)
    : id(id), items(items), status(Status::Pending) {}

int Order::getId() const {
    return id;
}

vector<MenuItem> Order::getItems() const {
    return items;
}

double Order::getTotalCost() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total;
}

Order::Status Order::getStatus() const {
    return status;
}

void Order::setStatus(Status status) {
    this->status = status;
}
