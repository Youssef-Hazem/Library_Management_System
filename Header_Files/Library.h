#include <iostream>
#include "Book.h"
using namespace std;
#ifndef BOOK_CLASS_LIBRARY_H
#define BOOK_CLASS_LIBRARY_H
class LIBRARY:public BOOK{
private:
    int library_size=0;
    int library_cnt=0;
public:
    BOOK* libraryBooks{};
    LIBRARY()= default;
    int findingIndex(BOOK value) const;//to find the index of an element
    void addingBook(const BOOK& book);
    void removingBook(const string& id);
    void display_all() const;
    void set_Library_size(int& library_size);
    BOOK FBA(const string& author,const int index) const;//Finding books by author or part of the author’s name
    BOOK FBC(const string& category,const int index) const;//Finding books by category
    BOOK FBT(const string& title,const int index) const;//Finding a book by title
    void DBB() const;//Display all borrowed books
    void DNBB() const;//Display all non borrowed books-
    int get_CNT() const;
    ~LIBRARY(){delete[] libraryBooks;}

};
#endif //BOOK_CLASS_LIBRARY_H