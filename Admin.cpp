#include "Admin.h"
using namespace std;

ADMIN::ADMIN() {
    name="";
    username="";
    password="";
}

ADMIN::ADMIN(string name, string username, string password) {
    this->name=name;
    this->username=username;
    this->password=password;
}

bool ADMIN::verify_info(const string& potential_username, const string& potential_password) {
    if((potential_username == username) && (potential_password==password)){
        return true;
    } else return false;
}
