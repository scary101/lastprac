#include "User.h"
#include "Restaurant.h"
#include "Guest.h"
#include "Admin.h"
#include "Waiter.h"
#include "Chef.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


template <typename T>
void saveVector(const std::vector<T>& vec, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& item : vec) {
        file << item.serialize() << "\n";
    }

    file.close();
}


template <typename T>
std::vector<T> loadVector(const std::string& filename) {
    std::vector<T> vec;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return vec;
    }

    std::string line;
    while (std::getline(file, line)) {
        T item;
        item.deserialize(line);
        vec.push_back(item);
    }

    file.close();
    return vec;
}


template <typename T>
bool containsElement(const T& element, const std::vector<T>& vec) {
    return std::find(vec.begin(), vec.end(), element) != vec.end();
}


void displayGuestMenu(Restaurant& restaurant, Guest* guest) {
    setlocale(LC_ALL, "RUS");
    while (true) {
        cout << "\nГостевое меню:\n";
        cout << "1. Показать меню\n";
        cout << "2. Разместить заказ\n";
        cout << "3. Показать мои заказы\n";
        cout << "4. Выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            vector<MenuItem> menu = restaurant.getMenu();
            for (const auto& item : menu) {
                cout << "ID блюда: " << item.getId() << ", Название: " << item.getName() << ", Описание: " << item.getDescription() << ", Цена: " << item.getPrice() << ", Время приготовления: " << item.getPreparationTime() << endl;

                vector<Product> ingredients = item.getIngredients();

                cout << "Ингредиенты в блюде:" << endl;
                for (const auto& product : ingredients) {
                    cout << ", Ингидиенты: " << product.getName() << endl;
                }
                cout << endl;
            }
            break;
        }

        case 2: {
            int menuItemId;
            cout << "Введите ID пункта меню для заказа: ";
            cin >> menuItemId;

            try {
                MenuItem menuItem = restaurant.getMenuItemById(menuItemId);
                Order order(restaurant.generateOrderId(), { menuItem });
                guest->makeOrder(order);
                restaurant.addOrder(order);
                cout << "Заказ успешно размещен." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            vector<Order> orders = guest->getOrders();
            if (orders.empty()) {
                cout << "У вас нет заказов." << endl;
            }
            else {
                cout << "Ваши заказы:" << endl;
                for (const auto& order : orders) {
                    cout << "ID заказа: " << order.getId() << ", Общая стоимость: " << order.getTotalCost() << endl;
                }
            }
            break;
        }
        case 4: {
            cout << "Выход из программы." << endl;
            return;
        }
        default: {
            cerr << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
        }
    }
}


void displayAdminMenu(Restaurant& restaurant, Admin* admin) {
    setlocale(LC_ALL, "RUS");
    while (true) {
        cout << "\nМеню администратора:\n";
        cout << "1. Добавить продукт\n";
        cout << "2. Редактировать продукт\n";
        cout << "3. Удалить продукт\n";
        cout << "4. Добавить пункт меню\n";
        cout << "5. Редактировать пункт меню\n";
        cout << "6. Удалить пункт меню\n";
        cout << "7. Показать все заказы\n";
        cout << "8. Выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            double price;
            cout << "Введите ID продукта: ";
            cin >> id;
            cout << "Введите название продукта: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите цену продукта: ";
            cin >> price;

            Product product(id, name, price);
            restaurant.addProduct(product);
            cout << "Продукт успешно добавлен." << endl;
            break;
        }
        case 2: {
            int id;
            string name;
            double price;
            cout << "Введите ID продукта для редактирования: ";
            cin >> id;
            cout << "Введите новое название продукта: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите новую цену продукта: ";
            cin >> price;

            Product newProduct(id, name, price);
            try {
                admin->editProduct(restaurant.getProducts(), id, newProduct);
                cout << "Продукт с ID " << id << " успешно обновлен." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            int id;
            cout << "Введите ID продукта для удаления: ";
            cin >> id;
            try {
                admin->deleteProduct(restaurant.getProducts(), id);
                cout << "Продукт с ID " << id << " успешно удален." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            int id;
            string name;
            string description;
            double price;
            int preparationTime;
            cout << "Введите ID пункта меню: ";
            cin >> id;
            cout << "Введите название пункта меню: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите описание пункта меню: ";
            getline(cin, description);
            cout << "Введите цену пункта меню: ";
            cin >> price;
            cout << "Введите время приготовления (в минутах): ";
            cin >> preparationTime;

            vector<Product> allProducts = restaurant.getProducts();
            cout << "Список продуктов ресторана:" << endl;
            for (const auto& product : allProducts) {
                cout << "ID: " << product.getId() << ", Название: " << product.getName() << ", Цена: " << product.getPrice() << endl;
            }

            vector<Product> ingredients;
            while (true) {
                int productId;
                cout << "Введите ID продукта для добавления в пункт меню (или 0 для завершения выбора): ";
                cin >> productId;
                if (productId == 0) {
                    break;
                }
                auto it = std::find_if(allProducts.begin(), allProducts.end(), [&](const Product& p) { return p.getId() == productId; });
                if (it != allProducts.end()) {
                    ingredients.push_back(*it);
                }
                else {
                    cerr << "Продукт с указанным ID не найден." << endl;
                }
            }

            MenuItem menuItem(id, name, ingredients, description, price, preparationTime);
            restaurant.addMenuItem(menuItem);
            cout << "Пункт меню успешно добавлен." << endl;
            break;
        }

        case 5: {
            int id;
            string name;
            string description;
            double price;
            int preparationTime;
            cout << "Введите ID пункта меню для редактирования: ";
            cin >> id;
            cout << "Введите новое название пункта меню: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите новое описание пункта меню: ";
            getline(cin, description);
            cout << "Введите новую цену пункта меню: ";
            cin >> price;
            cout << "Введите новое время приготовления (в минутах): ";
            cin >> preparationTime;

            vector<Product> ingredients;
            MenuItem newMenuItem(id, name, ingredients, description, price, preparationTime);
            try {
                admin->editMenuItem(restaurant.getMenu(), id, newMenuItem);
                cout << "Пункт меню с ID " << id << " успешно обновлен." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 6: {
            int id;
            cout << "Введите ID пункта меню для удаления: ";
            cin >> id;
            try {
                admin->deleteMenuItem(restaurant.getMenu(), id);
                cout << "Пункт меню с ID " << id << " успешно удален." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 7: {
            vector<Order> orders = restaurant.getOrders();
            for (const auto& order : orders) {
                cout << "ID заказа: " << order.getId() << ", Общая стоимость: " << order.getTotalCost() << endl;
            }
            break;
        }
        case 8: {
            cout << "Выход из программы." << endl;
            return;
        }
        default: {
            cerr << "Неверный выбор. Пожалуйста, попробуйте снова, выберите от 1 до 8." << endl;
            break;
        }
        }
    }
}

void displayWaiterMenu(Restaurant& restaurant, Waiter* waiter) {
    setlocale(LC_ALL, "RUS");
    while (true) {
        cout << "\nМеню официанта:\n";
        cout << "1. Обслужить заказ\n";
        cout << "2. Выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int orderId;
            cout << "Введите ID заказа для обслуживания: ";
            cin >> orderId;

            try {
                Order& order = restaurant.getOrderById(orderId);
                waiter->serveOrder(order);
                cout << "Заказ обслужен." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            cout << "Выход из программы." << endl;
            return;
        }
        default: {
            cerr << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
        }
    }
}

void displayChefMenu(Restaurant& restaurant, Chef* chef) {
    setlocale(LC_ALL, "RUS");
    while (true) {
        cout << "\nМеню повара:\n";
        cout << "1. Начать приготовление заказа\n";
        cout << "2. Выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int orderId;
            cout << "Введите ID заказа для приготовления: ";
            cin >> orderId;

            try {
                Order& order = restaurant.getOrderById(orderId);
                chef->startPreparation(order);
                cout << "Заказ начат в приготовление." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            cout << "Выход из программы." << endl;
            return;
        }
        default: {
            cerr << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
        }
    }
}


void displayAuthenticationAndMainMenu(Restaurant& restaurant) {
    setlocale(LC_ALL, "RUS");
    vector<Guest> guests;
    vector<Admin> admins;
    vector<Waiter> waiters;
    vector<Chef> chefs;

    guests.push_back(Guest("guest", "guest"));
    admins.push_back(Admin("admin", "admin"));
    waiters.push_back(Waiter("waiter", "waiter"));
    chefs.push_back(Chef("chef", "chef"));

    while (true) {
        cout << "\nВыберите роль:\n";
        cout << "1. Гость\n";
        cout << "2. Администратор\n";
        cout << "3. Официант\n";
        cout << "4. Повар\n";
        cout << "5. Выйти\n";
        cout << "Выберите роль (1-4): ";

        int roleChoice;
        cin >> roleChoice;

        switch (roleChoice) {
        case 1: {

            string login, password;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;
            Guest guest = Guest(login, password);

            bool authenticated = false;
            if (containsElement<Guest>(guest, guests)) {
                displayGuestMenu(restaurant, &guest);
                authenticated = true;
                break;
            }
            if (!authenticated) {
                cerr << "Ошибка аутентификации гостя. Пожалуйста, проверьте логин и пароль." << endl;
            }
            break;
        }
        case 2: {

            string login, password;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;

            Admin admin = Admin(login, password);
            bool authenticated = false;
            if (containsElement<Admin>(admin, admins)) {
                displayAdminMenu(restaurant, &admin);
                authenticated = true;
                break;
            }
            if (!authenticated) {
                cerr << "Ошибка аутентификации администратора. Пожалуйста, проверьте логин и пароль." << endl;
            }
            break;
        }
        case 3: {
            string login, password;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;

            Waiter waiter = Waiter(login, password);
            bool authenticated = false;
            if (containsElement<Waiter>(waiter, waiters)) {
                displayWaiterMenu(restaurant, &waiter);
                authenticated = true;
                break;
            }
            if (!authenticated) {
                cerr << "Ошибка аутентификации официанта. Пожалуйста, проверьте логин и пароль." << endl;
            }
            break;
        }
        case 4: {
            string login, password;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;

            Chef chef = Chef(login, password);
            bool authenticated = false;
            if (containsElement<Chef>(chef, chefs)) {
                displayChefMenu(restaurant, &chef);
                authenticated = true;
                break;
            }
            if (!authenticated) {
                cerr << "Ошибка аутентификации повара. Пожалуйста, проверьте логин и пароль." << endl;
            }
            break;
        }
        case 5: {
            cout << "Выход из программы." << endl;
            return;
        }
        default: {
            cerr << "Неверный выбор. Пожалуйста, выберите от 1 до 4." << endl;
            break;
        }
        }
    }
}

int main() {
    Restaurant restaurant;
    setlocale(LC_ALL, "RUS");
    displayAuthenticationAndMainMenu(restaurant);

    return 0;
}