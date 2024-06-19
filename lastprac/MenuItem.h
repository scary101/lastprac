#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>
#include "Product.h"
using namespace std;
class MenuItem {
private:
    int id;
    string name;
    vector<Product> ingredients;
    string description;
    double price;
    int preparationTime;

public:
    MenuItem(int id, const string& name, const vector<Product>& ingredients, const string& description, double price, int preparationTime);

    int getId() const;
    string getName() const;
    vector<Product> getIngredients() const;
    string getDescription() const;
    double getPrice() const;
    int getPreparationTime() const;
};

#endif // MENUITEM_H
