#include "User.h"
using namespace std;
User::User(const string& login, const string& password) : login(login), password(password) {}

string User::getLogin() const {
    return login;
}

bool User::authenticate(const string& password) const {
    return this->password == password;
}
