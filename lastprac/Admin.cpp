#include "Admin.h"
#include <algorithm>
#include <stdexcept>


using namespace std;
Admin::Admin(const string& login, const string& password) : User(login, password) {}

void Admin::addProduct(vector<Product>& products, const Product& product) {
    products.push_back(product);
}

void Admin::editProduct(vector<Product>& products, int id, const Product& newProduct) {
    for (auto& p : products) {
        if (p.getId() == id) {
            p = newProduct;
            return;
        }
    }
    throw runtime_error("Продукт с указанным ID не найден");
}

void Admin::deleteProduct(vector<Product>& products, int id) {
    auto it = find_if(products.begin(), products.end(), [id](const Product& p) { return p.getId() == id; });
    if (it != products.end()) {
        products.erase(it);
    }
    else {
        throw runtime_error("Продукт с указанным ID не найден");
    }
}

void Admin::addMenuItem(vector<MenuItem>& menu, const MenuItem& menuItem) {
    menu.push_back(menuItem);
}

void Admin::editMenuItem(vector<MenuItem>& menu, int id, const MenuItem& newItem) {
    for (auto& item : menu) {
        if (item.getId() == id) {
            item = newItem;
            return;
        }
    }
    throw invalid_argument("Menu item not found");
}

void Admin::deleteMenuItem(vector<MenuItem>& menu, int id) {
    auto it = find_if(menu.begin(), menu.end(), [id](const MenuItem& item) { return item.getId() == id; });
    if (it != menu.end()) {
        menu.erase(it);
    }
    else {
        throw runtime_error("Позиция меню с указанным ID не найдена");
    }
}

