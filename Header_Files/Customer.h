#ifndef PROJECT_CUSTOMER_H
#define PROJECT_CUSTOMER_H
#include <string>
#include "Book.h"
#include "Library.h"
#include "User.h"
using namespace std;

class CUSTOMER : public BOOK,USER{
private:
    string name;
    int CBB_cnt;
    BOOK* CBB; // CUSTOMER BORROWED BOOKS
public:
    CUSTOMER();
    CUSTOMER(const string& name);;
    void Borrow_a_book(int &size,LIBRARY& library,CUSTOMER& customer);
    void Return_a_book(int &size,LIBRARY& library,CUSTOMER& customer);
    void Show_Data(USER& user,const CUSTOMER& customer);
    int Num_of_Borrowed_Books() const;
    BOOK* Borrowed_Books_Array(CUSTOMER& customer);
};
#endif //PROJECT_CUSTOMER_H
