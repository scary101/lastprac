#ifndef USER_H
#define USER_H

#include <string>
#include <sstream>
using namespace std;
class User {
protected:
    string login;
    string password;

public:
    User() = default;
    User(const string& login, const string& password);
    string getLogin() const;
    bool authenticate(const string& password) const;

    string serialize() const {
        return login + " " + password;
    }

    void deserialize(const string& data) {
        istringstream iss(data);
        iss >> login >> password;
    }


};

#endif  USER_H

