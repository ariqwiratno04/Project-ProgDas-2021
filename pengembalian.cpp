#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Pengembalian{
    public:
        string title;
        string penulis;

        string nama;
        string alamat;
        string no_hp;

    Pengembalian(string inTitle, string inPenulis, string inNama, string inAlamat, string inNo_hp){

    Pengembalian::title     = inTitle;
    Pengembalian::penulis   = inPenulis;
    Pengembalian::nama      = inNama;
    Pengembalian::alamat    = inAlamat;
    Pengembalian::no_hp     = inNo_hp;
    }

};

    void addDataPengembalian(){
        string inputJudul, inputPenulis, inputNama, inputAlamat;
        string inputNo_hp;

        cout << "INPUT DATA BUKU" << endl;
        cout << "Judul\t\t: ";
        getline(cin, inputJudul);
        cout << "Penulis\t\t: ";
        getline(cin, inputPenulis);
        cout << "Nama peminjam\t: ";
        getline(cin, inputNama);
        cout << "Alamat\t\t: ";
        getline(cin, inputAlamat);
        cout << "Nomor hape\t: ";
        cin >> inputNo_hp;

    Pengembalian p1 = Pengembalian(inputJudul, inputPenulis, inputNama, inputAlamat, inputNo_hp);

    ofstream outFile;
    outFile.open("DataPengembalian.txt", ios::app);

    if(outFile.is_open()){
        outFile << "Judul\t\t: " << p1.title << endl;
        outFile << "Penulis\t\t: " << p1.penulis << endl;
        outFile << "Nama Peminjam\t: " << p1.nama << endl;
        outFile << "Alamat\t\t: " << p1.alamat << endl;
        outFile << "Nomor hape\t: " << p1.no_hp << endl;
        outFile << " " << endl;

    }
}

    void displayDataPengembalian(){
        ifstream inFile;
        string lines;
        inFile.open("DataPengembalian.txt");
        cout << " " << endl;
        cout << "Data Pengembalian" << endl;
        cout << "=========================" << endl;
        while(getline(inFile, lines)){
            cout << lines << endl;
        }
    }

    void deleteDataPengembalian(){
	string judul, baru;
	cout << "===================================================" << endl;
	cout << "MENGHAPUS DATA PENGEMBALIAN" << endl;
	cout << "Note : Judul harus sama persis (Kapital harus sesuai)" << endl;
	cout << "===================================================" << endl;
	cout << "Masukkan judul buku : ";
	getline(cin, judul);
	ifstream myfile;
	myfile.open("DataPengembalian.txt");
	ofstream newfile;
	newfile.open("new.txt", ios::app);

	while(getline(myfile, baru)){
    size_t foundInfo = baru.find(judul);
    if(foundInfo != string::npos){
        for(int a=0; a<6; a++){
				getline(myfile, baru);
			}
    }
    if(!myfile.eof()){
		newfile<<baru<<"\n";
		}
	}
	myfile.close();
	newfile.close();

	remove("DataPengembalian.txt");
	rename("new.txt","DataPengembalian.txt");
    }

/*int main(){

    return 0;
}*/
