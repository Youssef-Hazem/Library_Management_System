#include <string>
#include "User.h"
using namespace std;

class ADMIN {
private:
    string name;
    string username;
    string password;
public:
    ADMIN();
    ADMIN(string name, string username, string password);
    bool verify_info(const string& potential_username, const string& potential_password);
};