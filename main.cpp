#include <iostream>
#include <random>
#include "Admin.h"
#include "Book.h"
#include "Customer.h"
#include "Library.h"
#include "User.h"
using namespace std;

void menu(){
    cout<<"1- Create a new user."<<endl; //done
    cout<<"2- Display existing users (by ID and name)."<<endl;//done
    cout<<"3- Remove a customer by ID."<<endl;//done
    cout<<"4- Add a book to the library."<<endl;//done
    cout<<"5- Remove a book from the library by ID."<<endl;//done
    cout<<"6- Display all books classified as borrowed and non-borrowed."<<endl;//done
    cout<<"7- Borrow a book"<<endl;//done
    cout<<"8- Return a book."<<endl;//done
    cout<<"9- Display a book info by title."<<endl;//done
    cout<<"10- Display books of a certain category."<<endl;//done
    cout<<"11- Display books of a certain author."<<endl;//done
    cout<<"12- Exit."<<endl<<endl;//done
    cout << "Enter a valid choice (1-12): ";
}
int generateRandomID() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator);
}

int main() {
    // VARIABLES SUITE
    string username;
    string name;
    string password;
    string BookTitle;
    string BookAuthor;
    string BookCategory;
    string Book_ID;
    string user_type;
    int id;
    int id_to_look_for;
    int library_size;
    int max_users;
    int cnt = 0;
    int customer_cnt=0;
    int choice;
    int customer_index; // link between users and customer_Books arrays

    // OBJECT SUITE
    USER *users;
    ADMIN admin;
    CUSTOMER customer;
    CUSTOMER *customer_Books;
    LIBRARY library;
    BOOK book;

    // START SCREEN
    cout << "-> Welcome to your Library Management System" << endl << endl;
    cout << "Enter your name :";
    getline(cin, name);
    cout << "Create admin username :";
    getline(cin, username);
    cout << "Create admin password :";
    cin >> password;
    ADMIN admin1(name, username, password);
    cout << "Enter Maximum number of users :";
    cin >> max_users;
    users = new USER[max_users];
    customer_Books=new CUSTOMER[max_users];
    cout << "Enter library size ~ Maximum books capacity :";
    cin >> library_size;
    if (library_size > 0) {
        library.set_Library_size(library_size);
    } else {
        cout << "Size invalid...";
        exit(0);
    }
    cout << "Library creation successful." << endl << endl;

    // ADMIN LOOP
    username = "", password = "";
    cout << "Enter username :";
    getline(cin, username);
    getline(cin, username);
    cout << "Enter password :";
    cin >> password;
    while (1 != admin1.verify_info(username, password)) {
        cout << "Wrong username or password.." << endl;
        cout << "Please try again ." << endl;
        username = "", password = "";
        cout << "Enter username :";
        getline(cin, username);
        getline(cin, username);
        cout << "Enter password :";
        cin >> password;
    }
    cout<<endl<<"-> Welcome "<<"@"<<username<<" !"<<endl<<endl;
    menu();
    cin >> choice;
    while(choice < 1 || choice > 12){
        cout << "Invalid choice , please try again :";
        cin >> choice;
    }
    while (choice >= 1 && choice <= 12) {
        if (choice >= 1 && choice <= 12) {
            if (choice == 1) { // CREATE NEW USER
                if (cnt == max_users) {
                    cout << "Maximum number of users reached..." << endl << endl;
                    menu();
                    cin >> choice;
                    continue;
                } else {
                    cout << "Enter name :";
                    getline(cin, name);
                    getline(cin, name);
                    cout << "Enter username :";
                    getline(cin, username);
                    cout << "Enter password :";
                    cin >> password;
                    cout << "Enter user type (A/C):";
                    cin >> user_type;
                    cout << "User successfully created." << endl;
                    id = generateRandomID();
                    cout << "-> ID : " << id << endl<<endl;
                    users[cnt] = USER(name, username, password, user_type, id);
                    cnt++;
                    if (user_type[0] == 'C' || user_type[0] == 'c') {
                        customer_Books[customer_cnt]=CUSTOMER(name);
                        customer_cnt++;
                    }
                }
            } else if (choice == 2) { // DISPLAY ALL USERS
                customer_index=0;
                for (int i = 0; i < cnt; i++) {
                    if(users[i].get_type()[0]=='A' || users[i].get_type()[0]=='a' ){
                        users[i].PRINT_INFO();
                    } else if(users[i].get_type()[0]=='C' || users[i].get_type()[0]=='c'){
                        customer.Show_Data(users[i],customer_Books[customer_index]);
                        customer_index++;
                    }

                } if (cnt == 0){
                    cout<<"No users found."<<endl<<endl;
                }
            } else if (choice == 3) { // DELETE USER
                if(cnt==0){
                    cout<<"No users found."<<endl<<endl;
                } else if(cnt > 0){
                    customer_index = 0;
                    for (int i = 0; i < cnt; i++) {
                        if (users[i].get_type() == "A" || users[i].get_type() == "a") {
                            cout << "-> Name :" << users[i].get_Name() << endl << "-> ID :" << users[i].get_ID() << endl << endl;
                        } else if (users[i].get_type() == "C" || users[i].get_type() == "c") {
                            customer.Show_Data(users[i], customer_Books[customer_index]);
                            customer_index++;
                        }
                    }
                    cout << endl << "Enter customer ID :";
                    cin >> id_to_look_for;
                    int shift_index = -1;
                    for (int i = 0; i < cnt; i++) {
                        if (users[i].get_ID() == id_to_look_for) {
                            shift_index = i + 1;
                            break;
                        }
                    }
                    customer_index = -1;
                    for (int i = 0; i < cnt; i++) {
                        if (id_to_look_for == users[i].get_ID()) {
                            customer_index = i;
                            break;
                        } else {
                            continue;
                        }
                    }
                    int actual_customer_index = 0;
                    for (int i = 0; i <= customer_index; i++) {
                        if (users[i].get_type() == "C" || users[i].get_type() == "c") {
                            actual_customer_index++;
                        }
                    }
                    if (shift_index != -1) {
                        for (int i = shift_index; i < cnt; i++) {
                            users[i - 1] = users[i];
                        }
                        for (int i = 0; i < cnt; i++) {
                            if ((users[i].get_type() == "C" || users[i].get_type() == "c") && (id_to_look_for==users[i].get_ID())) {
                                if(customer_Books[actual_customer_index-1].Num_of_Borrowed_Books()>0){
                                    for(int x=0;x<customer_Books[actual_customer_index - 1].Num_of_Borrowed_Books();x++){
                                        if((customer_Books[actual_customer_index - 1].Borrowed_Books_Array(customer_Books[actual_customer_index - 1])[x]).getId()==(library.libraryBooks[x]).getId()){
                                            library.libraryBooks[x].setBorrowed(1);
                                        } else continue;
                                    }
                                }
                                customer_cnt--;
                                customer_Books[actual_customer_index - 1]=CUSTOMER();
                            }
                        }
                        cnt--;
                        users[cnt] = USER();
                        cout << "User deleted." << endl << endl;
                    } else {
                        cout << "Can't find customer by this ID." << endl << endl;
                    }
                }
            } else if (choice == 4) { // ADD A BOOK
                if (library.get_CNT() == library_size) {
                    cout << "Library is full, cannot add more books" << endl;
                } else {
                    cout << "Enter Book title :";
                    getline(cin, BookTitle);
                    getline(cin, BookTitle);
                    cout << "Enter Book author :";
                    getline(cin, BookAuthor);
                    cout << "Enter Book category :";
                    getline(cin, BookCategory);
                    Book_ID = to_string(generateRandomID());
                    library.addingBook(BOOK(Book_ID, BookTitle, BookAuthor, BookCategory, 1));
                    cout << "Book ID :" << Book_ID << endl <<endl;
                }
            } else if (choice == 5) { // DELETE BOOK
                if(library.get_CNT()==0){
                    cout<<"No books found in the library."<<endl<<endl;
                }
                for (int i = 0; i < library_size; i++) {
                    if (library.libraryBooks[i].getTitle() != "None") {
                        cout<<"-> Title :"<<library.libraryBooks[i].getTitle()<<endl;
                        cout<<"-> ID :"<<library.libraryBooks[i].getId()<<endl<<endl;
                    } else continue;
                }
                Book_ID = "";
                cout << "Enter book ID to remove :";
                cin >> Book_ID;
                for(int j=0; j<library.get_CNT();j++){
                    if(library.libraryBooks[j].getId()==Book_ID){
                        for(int k=0;k<customer_cnt;k++){
                            for(int i=0;i<customer_Books[k].Num_of_Borrowed_Books();i++){
                                if((customer_Books[k].Borrowed_Books_Array(customer_Books[k]))[i].getId()==Book_ID){
                                    cout<<"This book is borrowed by a customer , thus you need to manually return it..."<<endl;
                                    customer_Books[k].Return_a_book(library_size,library,customer_Books[k]);
                                }
                            }
                        }
                    }
                }
                library.removingBook(Book_ID);
            } else if (choice == 6) { // DISPLAY ALL BOOKS
                if (library.get_CNT()==0){
                    cout<<"No books found in the library."<<endl<<endl;
                } else if(library.get_CNT()>0){
                    library.display_all();
                }
            } else if (choice == 7) { // BORROW A BOOK
                library.DNBB();
                id = 0;
                cout << "Enter customer ID: ";
                cin >> id;
                int flag = 0;
                customer_index = -1;
                for (int i = 0; i < cnt; i++) {
                    if (id == users[i].get_ID()) {
                        customer_index = i;
                        flag = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    cout << "Wrong ID, please try again." << endl << endl;
                } else {
                    int actual_customer_index = 0;
                    for (int i = 0; i <= customer_index; i++) {
                        if (users[i].get_type() == "C" || users[i].get_type() == "c") {
                            actual_customer_index++;
                        }
                    }
                    customer_Books[actual_customer_index - 1].Borrow_a_book(library_size, library, customer_Books[actual_customer_index - 1]);
                }
            } else if (choice == 8) { // RETURN A BOOK
                customer_index=0;
                for (int i = 0; i < cnt; i++) {
                    if(users[i].get_type()[0]=='A' || users[i].get_type()[0]=='a' ){
                        continue;
                    } else if(users[i].get_type()[0]=='C' || users[i].get_type()[0]=='c'){
                        if(customer_Books[i].Num_of_Borrowed_Books()>0) {
                            customer.Show_Data(users[i], customer_Books[customer_index]);
                            customer_index++;
                        }
                    }
                }
                id = 0;
                cout << "Enter customer ID: ";
                cin >> id;
                int flag = 0;
                customer_index = -1;
                for (int i = 0; i < cnt; i++) {
                    if (id == users[i].get_ID()) {
                        customer_index = i;
                        flag = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    cout << "Wrong ID, please try again." << endl << endl;
                } else {
                    int actual_customer_index = 0;
                    for (int i = 0; i <= customer_index; i++) {
                        if (users[i].get_type() == "C" || users[i].get_type() == "c") {
                            actual_customer_index++;
                        }
                    }
                    customer_Books[actual_customer_index - 1].Return_a_book(library_size, library, customer_Books[actual_customer_index - 1]);
                }
            } else if (choice == 9) { // SEARCH BY TITLE
                BookTitle = "";
                cout << "Enter book title to search for :";
                getline(cin, BookTitle);
                getline(cin, BookTitle);
                for (int j = 0; j < library.get_CNT(); j++) {
                    if (library.FBT(BookTitle, j).getId() != "None") {
                        library.FBT(BookTitle, j).printBook();
                    } else continue;
                }
            } else if (choice == 10) { // SEARCH BY CATEGORY
                BookCategory = "";
                cout << "Enter book category to search for :";
                getline(cin, BookCategory);
                getline(cin, BookCategory);
                for (int j = 0; j < library.get_CNT(); j++) {
                    if (library.FBC(BookCategory, j).getId() != "None") {
                        library.FBC(BookCategory, j).printBook();
                    } else continue;
                }
            } else if (choice == 11) { // SEARCH BY AUTHOR
                BookAuthor = "";
                cout << "Enter book author to search for :";
                getline(cin, BookAuthor);
                getline(cin, BookAuthor);
                for (int j = 0; j < library.get_CNT(); j++) {
                    if (library.FBA(BookAuthor, j).getId() != "None") {
                        library.FBA(BookAuthor, j).printBook();
                    } else continue;
                }
            } else if (choice == 12) { // EXIT PROGRAM
                cout << "Exiting the program..." << endl;
                delete[] users;
                delete[] customer_Books;
                delete[] library.libraryBooks;
                exit(0);
            }
            menu();
            cin >> choice;
        }
        while(choice < 1 || choice > 12){
            cout << "Invalid choice , please try again :";
            cin >> choice;
        }
    }
}