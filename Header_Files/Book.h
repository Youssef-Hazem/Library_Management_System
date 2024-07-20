#include <iostream>
using namespace std;
#ifndef BOOK_CLASS_BOOK_H
#define BOOK_CLASS_BOOK_H
class BOOK{
private:
    string BookTitle;
    string BookId;
    string BookAuthor;
    string BookCategory ;
    int BookBorrowed;//if the value is 0 means can not be borrowed if 1 mean can borrow
public:
    BOOK();
    BOOK(string ID,string Title,string Author,string Category,int Borrowed);
    void setId(string s);
    void setTitle(string s);
    void setAuthor(string s);
    void setCategory(string s);
    void setBorrowed(int i);
    string getId(){return BookId;};
    string getTitle(){return BookTitle;};
    string getAuthor(){return BookAuthor;};
    string getCategory(){return BookCategory;};
    int getBorrowed() const{return BookBorrowed;};
    void printBook();
};

#endif //BOOK_CLASS_BOOK_H
