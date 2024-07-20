#include "User.h"
#include <iostream>
using namespace std;

USER::USER() {
    name="";
    username="";
    password="";
    user_type="";
    id=0;
}

USER::USER(string name, string username, string password, string user_type,int id) {
    this->name=name;
    this->username=username;
    this->password=password;
    this->user_type=user_type;
    this->id=id;
}

void USER::PRINT_INFO() {
    cout<<"-> Name :"<<name<<endl;
    cout<<"-> Username :"<<username<<endl;
    cout<<"-> User type :"<<user_type<<endl;
    cout<<"-> ID :"<<id<<endl<<endl;
}

int USER::get_ID() const{
    return id;
}
string USER::get_Name() {
    return name;
}

string USER::get_type() {
    return user_type;
}


