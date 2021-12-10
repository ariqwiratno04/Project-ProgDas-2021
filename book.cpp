#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Buku{
    public:
        string judul, penulis, tipe, penerbit, status;
        int tahunTerbit;

        //constructor
        Buku(string inputJudul, string inputPenulis, string inputTipe, string inputPenerbit, string inputStatus, int inputTahun){
            Buku::judul = inputJudul;
            Buku::penulis = inputPenulis;
            Buku::tipe = inputTipe;
            Buku::penerbit = inputPenerbit;
            Buku::tahunTerbit = inputTahun;
            Buku::status = inputStatus;
        }
        //edit status buku
        void changeStatus(){
            if(Buku::status == "Dipinjam"){
                Buku::status = "Tersedia";
            }
            else
            Buku::status = "Dipinjam";
        }
};
//Function untuk menambah buku
void addBook(){
    //input data buku dari user
    string inputJudul, inputPenulis, inputTipe, inputPenerbit, inputStatus;
    int inputTahun;
    cout << "INPUT DATA BUKU" << endl;
    cout << "Judul\t\t: ";
    getline(cin, inputJudul);
    cout << "Penulis\t\t: ";
    getline(cin, inputPenulis);
    cout << "Tipe\t\t: ";
    getline(cin, inputTipe);
    cout << "Penerbit\t: ";
    getline(cin, inputPenerbit);
    cout << "Status\t\t: ";
    getline(cin, inputStatus);
    cout << "Tahun Terbit\t: ";
    cin >> inputTahun; 
    Buku buku1 = Buku(inputJudul, inputPenulis, inputTipe, inputPenerbit, inputStatus, inputTahun);

    //output ke file
    ofstream outFile;
    outFile.open("List Buku.txt", ios::app);
    if(outFile.is_open()){
        outFile << "Judul\t\t:" << buku1.judul << endl;
        outFile << "Penulis\t\t:" << buku1.penulis << endl;
        outFile << "Tipe\t\t:" << buku1.tipe << endl;
        outFile << "Penerbit\t:" << buku1.penerbit << endl;
        outFile << "TahunTerbit\t:" << buku1.tahunTerbit << endl;
        outFile << "Status\t\t:" << buku1.status << endl << endl;
    }
    else 
    cout << "File gagal terbuka";
}
//Function untuk menampilkan semua buku
void displayAll(){
    ifstream inFile;
    string lines;
    inFile.open("List Buku.txt");
    while(getline(inFile, lines)){
        cout << lines << endl;
    }
}
//Function untuk menghapus semua buku
void clearData(){
    ofstream outFile;
    outFile.open("List Buku.txt", ios::trunc);
    outFile.close();
    cout << "Data cleared succesfully";
}
//Function untuk menghapus buku
void deleteBook(){
    
}
//Function untuk mengedit data buku
void editData(){
    
}
