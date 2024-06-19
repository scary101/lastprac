#include "MenuItem.h"
using namespace std;
MenuItem::MenuItem(int id, const string& name, const vector<Product>& ingredients, const string& description, double price, int preparationTime)
    : id(id), name(name), ingredients(ingredients), description(description), price(price), preparationTime(preparationTime) {}

int MenuItem::getId() const {
    return id;
}

string MenuItem::getName() const {
    return name;
}

vector<Product> MenuItem::getIngredients() const {
    return ingredients;
}

string MenuItem::getDescription() const {
    return description;
}

double MenuItem::getPrice() const {
    return price;
}

int MenuItem::getPreparationTime() const {
    return preparationTime;
}
