#include "Customer.h"

CUSTOMER::CUSTOMER() {
    name="";
    CBB_cnt=0;
    CBB = new BOOK[5];
}

CUSTOMER::CUSTOMER(const string& name) {
    this->name = name;
    CBB_cnt=0;
    CBB = new BOOK[5];
}

void CUSTOMER::Borrow_a_book(int &size,LIBRARY& library,CUSTOMER& customer) {
    string book_ID;
    cout<<"Enter the book ID you wish to borrow :";
    getline(cin,book_ID);
    getline(cin,book_ID);
    if(customer.CBB_cnt<5){
        for(int i=0;i<size;i++){
            if(book_ID==library.libraryBooks[i].getId()){
                if(library.libraryBooks[i].getBorrowed()==1){
                    CBB[customer.CBB_cnt]=library.libraryBooks[i];
                    library.libraryBooks[i].setBorrowed(0);
                    cout<<"Book successfully borrowed."<<endl<<endl;
                    customer.CBB_cnt++;
                    break;
                } else if(library.libraryBooks[i].getBorrowed()==0) {
                    cout << "Book is borrowed by another customer." << endl << endl;
                    break;
                }
            } else if(library.libraryBooks[i].getTitle()=="None" || library.libraryBooks[i].getTitle().empty()){
                cout<<"Cannot find book you wish to borrow."<<endl<<endl;
                break;
            }
        }
    } else cout<<"Cannot borrow more books , max capacity reached."<<endl;
}

void CUSTOMER::Return_a_book(int &size,LIBRARY& library,CUSTOMER& customer) {
    string book_ID;
    cout<<"Enter the book ID you wish to return :";
    getline(cin,book_ID);
    getline(cin,book_ID);
    for(int i=0;i<size;i++){
        if((book_ID==library.libraryBooks[i].getId()) && (library.libraryBooks[i].getBorrowed()==0) && (CBB[i].getId()==book_ID)){
                int shift_index = -1;
                for(int j=0;j<customer.CBB_cnt;j++){
                    if(customer.CBB[j].getId()==book_ID){
                        shift_index = j + 1;
                        break;
                    }
                }
                if(shift_index != -1){
                    for(int k = shift_index;k < customer.CBB_cnt ; k++){
                        customer.CBB[k-1] = customer.CBB[k];
                    }
                }
                customer.CBB_cnt--;
                customer.CBB[customer.CBB_cnt] = BOOK();
                library.libraryBooks[i].setBorrowed(1);
                cout<<"Book successfully returned."<<endl<<endl;
                break;
        } else if(library.libraryBooks[i].getTitle()=="None" || library.libraryBooks[i].getTitle().empty()){
            cout<<"Cannot find book you wish to return."<<endl<<endl;
        }
    }
}

void CUSTOMER::Show_Data(USER& user,const CUSTOMER& customer){
    cout << "-> Name :" << user.get_Name()<<endl;
    cout << "-> ID :" << user.get_ID()<<endl;
    cout << "-> Number of borrowed books :"<<customer.Num_of_Borrowed_Books()<<endl;
    if(customer.CBB_cnt!=0){
        cout << "-> Borrowed Books :" << endl;
        for(int i=0;i<customer.CBB_cnt;i++){
            cout<<"    - "<<customer.CBB[i].getTitle()<<" ,ID :"<<customer.CBB[i].getId()<<endl;
        }
    } cout<<endl;
}

int CUSTOMER::Num_of_Borrowed_Books() const {
    return CBB_cnt;
}

BOOK* CUSTOMER::Borrowed_Books_Array(CUSTOMER& customer){
    return customer.CBB;
}
