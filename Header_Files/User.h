#ifndef PROJECT_USER_H
#define PROJECT_USER_H
#include <string>
using namespace std;
class USER {
private:
    string name;
    string username;
    string password;
    string user_type;
    int id;
public:
    USER();
    USER(string name, string username , string password , string user_type,int id);
    void PRINT_INFO();
    string get_Name();
    int get_ID() const;
    string get_type();
};
#endif //PROJECT_USER_H
