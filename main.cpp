#include <iostream>
#include "book.h"
using namespace std;
//#include "book.cpp"

int main(){
    int command;
    do{
        cout << "pilih perintah:\n";
        cout << "1 : tambah data buku\n";
        cout << "2 : tampilkan semua buku\n";
        cout << "3 : hapus semua buku\n";
        cin >> command;
        switch(command){
        case 1:
            addBook();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            clearData();
            break;
        }
    }while(command == 1 | command == 2 | command == 3);
    system("pause");
}