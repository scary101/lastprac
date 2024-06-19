#include "Chef.h"
using namespace std;
Chef::Chef(const string& login, const string& password)
    : Employee(login, password) {}

void Chef::startPreparation(Order& order) {
    order.setStatus(Order::Status::InPreparation);
}
