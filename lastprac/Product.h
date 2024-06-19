#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int id, const string& name, double price);

    int getId() const;
    string getName() const;
    double getPrice() const;
};

#endif // PRODUCT_H
