#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();

void hapusDepanH();
void hapusDepanHT();

void hapusBelakangH();
void hapusBelakangHT();

void hapusTargetH();
void hapusTargetHT();

void tampilkanH();
void tampilkanHT();

void clearH();
void clearHT();

int main()
{
menu:

    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"1. DLLNC Head"<<endl;
    cout<<"2. DLLNC Head Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;

    system("cls");

    if(menu==1){

        do{

            cout<<"DLLNC HEAD"<<endl;
            cout<<"=============="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali"<<endl;
            cout<<"Pilihan : ";

            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){

            case 1:
                tambahDepanH();
                break;

            case 2:
                tambahBelakangH();
                break;

            case 3:
                tampilkanH();
                break;

            case 4:
                hapusDepanH();
                break;

            case 5:
                hapusBelakangH();
                break;

            case 6:
                hapusTargetH();
                break;

            case 7:
                clearH();
                break;

            default:
                system("cls");
                goto menu;
            }

            cout<<"\nPress any key...";
            getch();
            system("cls");

        }while(pil<8);

    } else if(menu==2){

        do{

            cout<<"DLLNC HEAD TAIL"<<endl;
            cout<<"=================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (ke-N dari belakang)"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali"<<endl;
            cout<<"Pilihan : ";

            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){

            case 1:
                tambahDepanHT();
                break;

            case 2:
                tambahBelakangHT();
                break;

            case 3:
                tampilkanHT();
                break;

            case 4:
                hapusDepanHT();
                break;

            case 5:
                hapusBelakangHT();
                break;

            case 6:
                hapusTargetHT();
                break;

            case 7:
                clearHT();
                break;

            default:
                system("cls");
                goto menu;
            }

            cout<<"\nPress any key...";
            getch();
            system("cls");

        }while(pil<8);

    } else {

        cout<<"TERIMA KASIH"<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    return head == NULL;
}

int isEmptyHT(){
    return tail == NULL;
}

void tambahDepanH(){

    cin.ignore();

    string input;
    cout<<"Masukkan data : ";
    getline(cin,input);

    stringstream ss(input);

    string data[100];
    int n=0;

    while(ss>>data[n]){
        n++;
    }

    for(int i=n-1;i>=0;i--){

        TNode *baru;

        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH()){

            head = baru;

        } else {

            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data berhasil ditambahkan.";
}

void tambahBelakangH(){

    cin.ignore();

    string input;
    cout<<"Masukkan data : ";
    getline(cin,input);

    stringstream ss(input);

    string data;

    while(ss>>data){

        TNode *baru,*bantu;

        baru = new TNode;

        baru->data = data;
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH()){

            head = baru;

        } else {

            bantu = head;

            while(bantu->next != NULL){
                bantu = bantu->next;
            }

            bantu->next = baru;
            baru->prev = bantu;
        }
    }

    cout<<"Data berhasil ditambahkan.";
}

void tambahDepanHT(){

    cin.ignore();

    string input;
    cout<<"Masukkan data : ";
    getline(cin,input);

    stringstream ss(input);

    string data[100];
    int n=0;

    while(ss>>data[n]){
        n++;
    }

    for(int i=n-1;i>=0;i--){

        TNode *baru;

        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT()){

            head = baru;
            tail = baru;

        } else {

            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data berhasil ditambahkan.";
}

void tambahBelakangHT(){

    cin.ignore();

    string input;
    cout<<"Masukkan data : ";
    getline(cin,input);

    stringstream ss(input);

    string data;

    while(ss>>data){

        TNode *baru;

        baru = new TNode;

        baru->data = data;
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT()){

            head = baru;
            tail = baru;

        } else {

            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    cout<<"Data berhasil ditambahkan.";
}

void tampilkanH(){

    TNode *bantu;

    bantu = head;

    if(!isEmptyH()){

        while(bantu != NULL){

            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }

        cout<<endl;

    } else {

        cout<<"Linked List kosong";
    }
}

void tampilkanHT(){

    TNode *bantu;

    bantu = head;

    if(!isEmptyHT()){

        while(bantu != NULL){

            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }

        cout<<endl;

    } else {

        cout<<"Linked List kosong";
    }
}

void hapusDepanH(){

    if(isEmptyH()){

        cout<<"Linked List kosong";
        return;
    }

    TNode *hapus;

    hapus = head;

    string data = hapus->data;

    if(head->next != NULL){

        head = head->next;
        head->prev = NULL;

    } else {

        initH();
    }

    delete hapus;

    cout<<"Data "<<data<<" berhasil dihapus.";
}

void hapusDepanHT(){

    if(isEmptyHT()){

        cout<<"Linked List kosong";
        return;
    }

    TNode *hapus;

    hapus = head;

    string data = hapus->data;

    if(head->next != NULL){

        head = head->next;
        head->prev = NULL;

    } else {

        initHT();
    }

    delete hapus;

    cout<<"Data "<<data<<" berhasil dihapus.";
}

void hapusBelakangH(){

    if(isEmptyH()){

        cout<<"Linked List kosong";
        return;
    }

    TNode *hapus;

    hapus = head;

    while(hapus->next != NULL){
        hapus = hapus->next;
    }

    string data = hapus->data;

    if(head->next != NULL){

        hapus->prev->next = NULL;

    } else {

        initH();
    }

    delete hapus;

    cout<<"Data "<<data<<" berhasil dihapus.";
}

void hapusBelakangHT(){

    if(isEmptyHT()){

        cout<<"Linked List kosong";
        return;
    }

    int n;

    cout<<"Hapus node ke-N dari belakang : ";
    cin>>n;

    TNode *bantu;

    bantu = tail;

    int hitung = 1;

    while(hitung < n && bantu->prev != NULL){

        bantu = bantu->prev;
        hitung++;
    }

    string data = bantu->data;

    if(bantu == head && bantu == tail){

        head = NULL;
        tail = NULL;

    } else if(bantu == head){

        head = head->next;
        head->prev = NULL;

    } else if(bantu == tail){

        tail = tail->prev;
        tail->next = NULL;

    } else {

        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }

    delete bantu;

    cout<<"Data "<<data<<" berhasil dihapus.";
}

void hapusTargetH(){

    if(isEmptyH()){

        cout<<"Linked List kosong";
        return;
    }

    string target;

    cout<<"Masukkan target : ";
    cin>>target;

    TNode *bantu = head;

    bool ketemu = false;

    while(bantu != NULL){

        if(bantu->data == target){

            ketemu = true;

            TNode *hapus = bantu;

            if(hapus == head){

                head = head->next;

                if(head != NULL)
                    head->prev = NULL;

            } else {

                hapus->prev->next = hapus->next;

                if(hapus->next != NULL)
                    hapus->next->prev = hapus->prev;
            }

            bantu = bantu->next;

            delete hapus;

        } else {

            bantu = bantu->next;
        }
    }

    if(ketemu)
        cout<<"Semua data berhasil dihapus.";
    else
        cout<<"Data tidak ditemukan.";
}

void hapusTargetHT(){

    if(isEmptyHT()){

        cout<<"Linked List kosong";
        return;
    }

    string target;

    cout<<"Masukkan target : ";
    cin>>target;

    TNode *bantu = head;

    bool ketemu = false;

    while(bantu != NULL){

        if(bantu->data == target){

            ketemu = true;

            TNode *hapus = bantu;

            if(hapus == head && hapus == tail){

                head = NULL;
                tail = NULL;

            } else if(hapus == head){

                head = head->next;
                head->prev = NULL;

            } else if(hapus == tail){

                tail = tail->prev;
                tail->next = NULL;

            } else {

                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }

            bantu = bantu->next;

            delete hapus;

        } else {

            bantu = bantu->next;
        }
    }

    if(ketemu)
        cout<<"Semua data berhasil dihapus.";
    else
        cout<<"Data tidak ditemukan.";
}

void clearH(){

    TNode *bantu,*hapus;

    bantu = head;

    int urutan = 1;

    while(bantu != NULL){

        hapus = bantu;

        cout<<urutan<<". Menghapus : "<<hapus->data<<endl;

        bantu = bantu->next;

        delete hapus;

        urutan++;
    }

    initH();

    cout<<"Semua data berhasil dihapus.";
}

void clearHT(){

    int urutan = 1;

    while(head != NULL){

        if(head == tail){

            cout<<urutan<<". Menghapus : "
                <<head->data<<endl;

            delete head;

            head = NULL;
            tail = NULL;

        } else {

            TNode *hapusDepan = head;

            cout<<urutan<<". Menghapus depan : "
                <<hapusDepan->data<<endl;

            head = head->next;
            head->prev = NULL;

            delete hapusDepan;

            urutan++;

            if(head == NULL)
                break;

            TNode *hapusBelakang = tail;

            cout<<urutan<<". Menghapus belakang : "
                <<hapusBelakang->data<<endl;

            tail = tail->prev;
            tail->next = NULL;

            delete hapusBelakang;
        }

        urutan++;
    }

    cout<<"Seluruh data berhasil dihapus.";
}