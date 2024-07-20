#include <iostream>
#include "Book.h"
using namespace std;
BOOK::BOOK() {BookId="None",BookTitle="None",BookAuthor="None",BookCategory="None",BookBorrowed=1;}
BOOK::BOOK(string ID,string Title, string Author, string Category, int Borrowed) {
    BookId=ID;
    BookTitle=Title;
    BookAuthor=Author;
    BookCategory=Category;
    BookBorrowed=Borrowed;
}
//setters
void BOOK::setId(string s) {BookId=s;}
void BOOK::setTitle(string s) {BookTitle=s;}
void BOOK::setAuthor(string s) {BookAuthor=s;}
void BOOK::setCategory(string s) {BookCategory=s;}
void BOOK::setBorrowed(int i) {BookBorrowed=i;}
void BOOK::printBook() {
    cout<<"Book Title:"<<BookTitle<<endl
        <<"Book Author:"<<BookAuthor<<endl
        <<"Book Category:"<<BookCategory<<endl
        <<"Book ID:"<<BookId<<endl;
    if(BookBorrowed==1)cout<<"The Book is available to be borrowed."<<endl<<endl;
    else if(BookBorrowed==0) cout<<"Book is borrowed."<<endl<<endl;

}