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
        void display1Book(){
            cout << Buku::judul << endl;
            cout << Buku::penulis << endl;
            cout << Buku::tipe << endl;
            cout << Buku::penerbit << endl;
            cout << Buku::tahunTerbit << endl;
            cout << Buku::status << endl;
        }
};

void addBook();


void addBook(){
    //input data buku dari user
    string inputJudul, inputPenulis, inputTipe, inputPenerbit, inputStatus;
    int inputTahun;
    cout << "\nINPUT DATA BUKU" << endl;
    cin.ignore();
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
    cout << endl << endl;
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
        outFile.close();
    }
    else 
    cout << "File gagal terbuka";
}

void displayAll(){
    ifstream inFile;
    string lines;
    inFile.open("List Buku.txt");
    if(inFile.is_open());{
            bool isEmpty = inFile.peek() == EOF;
        if(isEmpty == true){
            cout << "\n====================\n";
            cout << "\nBelum ada buku yang terdaftar\n";
        }    
        else{
            inFile.seekg(0, ios_base::beg);    
            cout << "\n===== DAFTAR BUKU =====\n\n";
            while(getline(inFile, lines)){
                cout << lines << endl;
            }
        }
    }
    cout << "\n====================\n";
}

void deleteBook(){

}

void editData(){

}

void clearData(){
    ofstream outFile;
    outFile.open("List Buku.txt", ios::trunc);
    outFile.close();
    cout << "\nSemua data buku telah terhapus\n\n";
}

//int main(){
    //addBook();
    //system("pause");
    //displayAll();
    //clearData();
    //Buku buku1 = Buku("asd","asd","asd","asd","asd",2021);
    //buku1.display1Book();
//}