#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Product.h"
#include "MenuItem.h"
#include <vector>
using namespace std;
class Admin : public User {
public:
    Admin () = default;
    Admin(const string& login, const string& password);
    void addProduct(vector<Product>& products, const Product& product);
    void editProduct(vector<Product>& products, int id, const Product& newProduct);
    void deleteProduct(vector<Product>& products, int id);
    void addMenuItem(vector<MenuItem>& menu, const MenuItem& menuItem);
    void editMenuItem(vector<MenuItem>& menu, int id, const MenuItem&);
    void deleteMenuItem(vector<MenuItem>& menu, int id);
    bool operator==(const Admin& other) const {
        return login == other.login && password == other.password;
    }
};

#endif // ADMIN_H
