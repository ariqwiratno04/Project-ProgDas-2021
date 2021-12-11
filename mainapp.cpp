#include <iostream>
#include "book.h"
#include "peminjaman.h"
#include "pengembalian.h"
using namespace std;

void mainMenu();

void MenuBuku(){
    int command;
    do{
        cout << "\npilih perintah:\n";
        cout << "1 : tambah data buku\n";
        cout << "2 : tampilkan semua buku\n";
        cout << "3 : hapus satu buku\n";
        cout << "4 : hapus semua buku\n";
        cout << "Input angka lain untuk kembali ke main menu\n";
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
            cout << "\n[Kembali ke main menu]\n";
            system("pause");
            system("cls");
            mainMenu();
            break;
        }
    }while(command == 1 | command == 2 | command == 3 | command == 4 );
    system("pause");
}

void MenuPeminjaman(){
    menuPinjam();
}

void MenuPengembalian(){
    int command3;
    do{
        cout << "\npilih perintah:\n";
        cout << "1 : tambah data pengembalian\n";
        cout << "2 : tampilkan semua pengembalian\n";
        cout << "3 : hapus satu pengembalian\n";
        cout << "4 : hapus semua pengembalian\n";
        cout << "Input angka lain untuk kembali ke main menu\n";
        cout << "--> ";
        cin >> command3;
        switch(command3){
        case 1:
            cin.ignore();
            addDataPengembalian();
            break;
        case 2:
            displayDataPengembalian();
            break;
        case 3:
            cin.ignore();
            deleteDataPengembalian();
            break;
        case 4:
            cout << "====== WARNING ======\n";
            cout << "Anda akan menghapus semua pengembalian";
            cout << "\nContinue? (y/n)";
            char choice;
            cin >> choice;
            switch(choice){
                case 'y':
                    clearDataPengembalian();
                    break;
                case 'n':
                    cout << "penghapusan dibatalkan";
                    break;
            }
            break;
        default:
            cout << "\n[Kembali ke main menu]\n";
            system("pause");
            system("cls");
            mainMenu();
            break;
        }
    }while(command3 == 1 | command3 == 2 | command3 == 3 | command3 == 4 );
}

void mainMenu(){
    cout << "========== BOOK MANAGER ===========\n";
    cout << "Silakan Pilih Menu:\n";
    cout << "1 : Manage Data Buku\n";
    cout << "2 : Manage Data Peminjaman\n";
    cout << "3 : Manage Data Pengembalian\n";
    
    int chooseMenu;
    cin >> chooseMenu;

    switch (chooseMenu)
    {
    case 1:
        MenuBuku();
        break;
    case 2:
        MenuPeminjaman();
        break;
    case 3:
        MenuPengembalian();
        break;
    default:
        "Input tidak dipahami\n Program akan ditutup.";
        break;
    }
}

int main(){
    mainMenu();
}