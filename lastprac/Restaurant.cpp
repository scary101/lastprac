#include "Restaurant.h"
#include <stdexcept>

using namespace std;

Restaurant::Restaurant() : balance(0.0) {}


void Restaurant::addGuest(const Guest& guest) {
	guests.push_back(guest);
}

void Restaurant::addAdmin(const Admin& admin) {
	admins.push_back(admin);
}

void Restaurant::addEmployee(const Employee& employee) {
	employees.push_back(employee);
}

void Restaurant::addProduct(const Product& product) {
	products.push_back(product);
}

void Restaurant::addMenuItem(const MenuItem& menuItem) {
	menu.push_back(menuItem);
}

void Restaurant::addOrder(const Order& order) {
	orders.push_back(order);
}

void Restaurant::updateBalance(double amount) {
	balance += amount;
}

double Restaurant::getBalance() const {
	return balance;
}

Product Restaurant::getProductById(int id) const {
	for (const auto& product : products) {
		if (product.getId() == id) {
			return product;
		}
	}
	throw invalid_argument("Product not found");
}

MenuItem Restaurant::getMenuItemById(int id) const {
	for (const auto& item : menu) {
		if (item.getId() == id) {
			return item;
		}
	}
	throw invalid_argument("Menu item not found");
}

Order& Restaurant::getOrderById(int id) {
	for (auto& order : orders) {
		if (order.getId() == id) {
			return order;
		}
	}
	throw invalid_argument("Order not found");
}

const vector<Order>& Restaurant::getOrders() const {
	return orders;
}

const vector<MenuItem>& Restaurant::getMenu() const {
	return menu;
}

int Restaurant::generateOrderId() const {
	return orders.empty() ? 1 : orders.back().getId() + 1;
}

vector<Product>& Restaurant::getProducts() {
	return products;
}
vector<MenuItem>& Restaurant::getMenu() {
	return menu;
}

vector<Order>& Restaurant::getOrders() {
	return orders;
}
vector<Product> Restaurant::getProductsList() const {
	return products;
}