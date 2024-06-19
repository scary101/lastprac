#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "MenuItem.h"
using namespace std;
class Order {
public:
    enum class Status {
        Pending,
        InPreparation,
        Served
    };

private:
    int id;
    vector<MenuItem> items;
    Status status;

public:
    Order(int id, const vector<MenuItem>& items);

    int getId() const;
    vector<MenuItem> getItems() const;
    double getTotalCost() const;
    Status getStatus() const;
    void setStatus(Status status);
};

#endif // ORDER_H
