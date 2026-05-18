#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
} TNode;

TNode *head, *tail;

int pil;
string dataBaru, dataHapus; // Menggunakan dataHapus sesuai instruksi perbaikan

// Deklarasi Fungsi
void init();
int isEmpty();
void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init(); 
    
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        
        if (!(cin >> pil)) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue; 
        }

        switch(pil) {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                if(!dataHapus.empty())
                    cout<<"Data \""<<dataHapus<<"\" yang berada di depan telah berhasil dihapus."<<endl;
                break;
            case 4:
                hapusBelakang();
                if(!dataHapus.empty())
                    cout<<"Data \""<<dataHapus<<"\" yang berada di belakang telah berhasil dihapus."<<endl;
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cariData();
                break;
            case 8:
                hapusData();
                break;
            case 9:
                sisipkanSebelum();
                break;
            case 10:
                sisipkanSetelah();
                break;
            case 11:
                cout<<"\nTERIMA KASIH"<<endl;
                cout<<"Program was made Muhammad Hamdani (2510817310019)."<<endl;
                break;
            default:
                cout<<"\nPilihan tidak tersedia!"<<endl;
        }
        if(pil != 11) {
            cout<<"\nPress any key to continue!";
            getch();
        }

    } while (pil != 11);
    
    return 0;
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

void tambahDepan() {
    cout<<"Masukkan data : ";
    TNode *baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
        tail->next = head; 
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan."<<endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    TNode *baru = new TNode;
    cin>>dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
        tail->next = head; 
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang."<<endl;
}

void hapusDepan() {
    dataHapus = ""; // Reset variabel
    if(isEmpty() == 0) {
        TNode *hapus = head;
        dataHapus = hapus->data;

        if(head != tail) {
            head = head->next;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void hapusBelakang() {
    dataHapus = ""; // Reset variabel
    if(isEmpty() == 0) {
        TNode *hapus = tail;
        TNode *newTail;
        dataHapus = hapus->data;

        if(head != tail) {
            newTail = head;
            while(newTail->next != tail) {
                newTail = newTail->next;
            }
            tail = newTail;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        cout << "Data: ";
        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        TNode *hapusNode;

        do {
            hapusNode = bantu;
            bantu = bantu->next;
            delete hapusNode;
        } while(bantu != head);

        init();
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu = head;
        TNode *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if(cari == bantu->data){
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;

                do {
                    if(cari == bantuTampilkan->data)
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    else
                        cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);

                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(!apaDitemukan)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu = head;
        TNode *sebelum = tail; 
        TNode *hapusArr[255]; 
        int hitung = 0;
        bool apaDitemukan = false;

        do {
            TNode *bantu2 = bantu;
            if(cari == bantu->data){
                hapusArr[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan) {
            for(int i = 0; i < hitung; i++) {
                if(hapusArr[i] == head){
                    hapusDepan();
                } else if(hapusArr[i] == tail) {
                    hapusBelakang();
                } else {
                    delete hapusArr[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus."<<endl;
        } else {
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        }
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        TNode *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do {
            if(nextData == bantu->data){
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if(bantu == head) head = baru;

            cout << "Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
        }
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do {
            if(prevData == bantu->data){
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if(bantu == tail) tail = baru;

            cout << "Data \""<<dataBaru<<"\" berhasil disisipkan setelah data \""<<prevData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
        }
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}