#include "Product.h"
using namespace std;
Product::Product(int id, const string& name, double price)
    : id(id), name(name), price(price) {}

int Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}
