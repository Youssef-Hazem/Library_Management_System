#include <iostream>
#include "Library.h"
using namespace std;


void LIBRARY::set_Library_size(int &size) {
    library_size=size;
    libraryBooks=new BOOK[library_size];
}

int LIBRARY::findingIndex(BOOK value) const {
    for (int i = 0; i < library_size; i++) {
        if (libraryBooks[i].getId() == value.getId()) {
            return i;
        }
    }
    return -1; // Book not found
}

void LIBRARY::addingBook(const BOOK& book) {
    int index = findingIndex(book);
    if (index != -1) {
        cout << "Book already exists in the library" << endl << endl;
    } else {
        libraryBooks[library_cnt] = book;
        cout << "Book added to the library" << endl;
        library_cnt++;
    }
}
void LIBRARY::removingBook(const string& id) {
    int shift_index = -1;
    for (int i = 0; i < library_cnt; i++) {
        if (libraryBooks[i].getId() == id) {
            shift_index= i + 1;
            cout << "Book removed from the library" << endl << endl;
            break;
        }
    }
    if (shift_index != -1) {
        for(int i=shift_index;i<library_cnt;i++){
            libraryBooks[i-1]=libraryBooks[i];
        }
        libraryBooks[library_cnt-1]=BOOK();
        library_cnt--;
    } else cout << "Book not found in the library" << endl << endl;
}

void LIBRARY::display_all() const {
    for (int i = 0; i < library_size; i++) {
        if ((!(libraryBooks[i].getTitle() == "None"))) {
            libraryBooks[i].printBook();
            cout << endl;
        }
    }
}

BOOK LIBRARY::FBA(const string& author,const int index) const {
    int flag;
    for(int j=0;j<author.length();j++){
        if (libraryBooks[index].getAuthor()[j]==author[j]){
            flag = 1;
        } else flag = 0;
    }if(flag == 1) {return libraryBooks[index];}
    return {}; // Book not found
}
BOOK LIBRARY::FBC(const string& category,const int index) const {
    if (category == libraryBooks[index].getCategory()) {
        return libraryBooks[index];
    }
    return {}; // Book not found
}

BOOK LIBRARY::FBT(const string& title,const int index) const {
    if (title == libraryBooks[index].getTitle()) {
        return libraryBooks[index];
    }
    return {}; // Book not found
}

void LIBRARY::DBB() const {
    for (int i = 0; i < library_size; i++) {
        if (libraryBooks[i].getBorrowed() == 0) {
            libraryBooks[i].printBook();
            cout << endl;
        }
    }
}

void LIBRARY::DNBB() const {
    for (int i = 0; i < library_size; i++) {
        if ((!(libraryBooks[i].getTitle() == "None"))) {
            if (libraryBooks[i].getBorrowed() == 1) {
                libraryBooks[i].printBook();
                cout << endl;
            }
        }
    }
}

int LIBRARY::get_CNT() const {
    return library_cnt;
}
