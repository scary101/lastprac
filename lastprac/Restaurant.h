#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>
#include "Guest.h"
#include "Admin.h"
#include "Employee.h"
#include "Waiter.h"
#include "Chef.h"
#include "Product.h"
#include "MenuItem.h"
#include "Order.h"
using namespace std;
class Restaurant {
private:
	vector<Guest> guests;
	vector<Admin> admins;
	vector<Employee> employees;
	vector<Product> products;
	vector<MenuItem> menu;
	vector<Order> orders;
	double balance;

public:
	Restaurant();
	void addGuest(const Guest& guest);
	void addAdmin(const Admin& admin);
	void addEmployee(const Employee& employee);
	void addProduct(const Product& product);
	void addMenuItem(const MenuItem& menuItem);
	void addOrder(const Order& order);
	void updateBalance(double amount);
	double getBalance() const;

	Product getProductById(int id) const;
	MenuItem getMenuItemById(int id) const;
	Order& getOrderById(int id);
	const vector<Order>& getOrders() const;
	const vector<MenuItem>& getMenu() const;
	int generateOrderId() const;
	vector<Product>& getProducts();
	vector<MenuItem>& getMenu();
	vector<Order>& getOrders();
	vector<Product> getProductsList() const;
};

#endif // RESTAURANT_H