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
        cout << "3 : hapus satu buku\n";
        cout << "4 : hapus semua buku\n";
        cout << "Input angka lain untuk keluar\n";
        cout << "--> ";
        cin >> command;
        switch(command){
        case 1:
            addBook();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            cin.ignore();
            deleteBook();
            break;
        case 4:
            cout << "====== WARNING ======\n";
            cout << "Anda akan menghapus semua buku";
            cout << "\nContinue? (y/n)";
            char choice;
            cin >> choice;
            switch(choice){
                case 'y':
                    clearData();
                    break;
                case 'n':
                    cout << "penghapusan dibatalkan";
                    break;
            }
            break;
        default:
            cout << "Invalid input\nProgram akan ditutup.\n";
            system("pause");
            break;
        }
    }while(command == 1 | command == 2 | command == 3 | command == 4 );
    system("pause");
}