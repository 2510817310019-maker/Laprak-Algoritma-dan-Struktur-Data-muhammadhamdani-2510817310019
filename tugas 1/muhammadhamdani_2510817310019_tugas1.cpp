#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
}TNode;

TNode *head,*tail;

int pil;
string dataBaru,dataHapus;

// Deklarasi fungsi
void init();
int isEmpty();
void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();

int main(){

    init();

    do{

        cout<<"Single Linked List Circular (SLLC)\n";
        cout<<"==================================\n";
        cout<<"1. Tambah Depan\n";
        cout<<"2. Tambah Belakang\n";
        cout<<"3. Hapus Depan\n";
        cout<<"4. Hapus Belakang\n";
        cout<<"5. Tampilkan Data\n";
        cout<<"6. Reset\n";
        cout<<"7. Quit\n";
        cout<<"Pilihan : ";

        // Validasi input menu
        if(!(cin >> pil)){
            cin.clear();
            cin.ignore(1000,'\n');
            pil = 0;
        }

        switch(pil){

        case 1:
            tambahDepan();
            break;

        case 2:
            tambahBelakang();
            break;

        case 3:
            hapusDepan();
            break;

        case 4:
            hapusBelakang();
            break;

        case 5:
            tampilkan();
            break;

        case 6:
            reset();
            break;

        case 7:
            cout<<"TERIMA KASIH\n";
            break;

        default:
            cout<<"Pilihan salah\n";
        }

        if(pil!=7){

            cout<<"\nTekan ENTER untuk lanjut...";
            cin.ignore(1000,'\n');
            cin.get();

            system("cls");
        }

    }while(pil!=7);

    return 0;
}

void init(){

    head=NULL;
    tail=NULL;
}

int isEmpty(){

    return head==NULL;
}


// ================= MODIFIKASI 1 =================

void tambahDepan(){

    cin.ignore();

    string input;

    cout<<"Masukkan beberapa data (pisah spasi): ";
    getline(cin,input);

    stringstream ss(input);

    string kata;

    TNode *awal=NULL;
    TNode *akhir=NULL;

    while(ss>>kata){

        TNode *baru=new TNode;

        baru->data=kata;
        baru->next=NULL;

        if(awal==NULL){

            awal=baru;
            akhir=baru;
        }

        else{

            akhir->next=baru;
            akhir=baru;
        }
    }

    if(awal==NULL)
        return;


    if(isEmpty()){

        head=awal;
        tail=akhir;

        tail->next=head;
    }

    else{

        akhir->next=head;

        head=awal;

        tail->next=head;
    }

    cout<<"Data berhasil ditambahkan\n";
}


void tambahBelakang(){

    cout<<"Masukkan data : ";
    cin>>dataBaru;

    TNode *baru=new TNode;

    baru->data=dataBaru;

    if(isEmpty()){

        head=baru;
        tail=baru;

        tail->next=head;
    }

    else{

        baru->next=head;

        tail->next=baru;

        tail=baru;

        tail->next=head;
    }

    cout<<"Data berhasil ditambahkan\n";
}



// ================= MODIFIKASI 2 =================

void hapusDepan(){

    if(isEmpty()){

        cout<<"List kosong\n";
        return;
    }

    int N;

    cout<<"Hapus posisi ke-N dari depan : ";
    cin>>N;

    int jumlah=0;

    TNode *bantu=head;

    do{

        jumlah++;
        bantu=bantu->next;

    }while(bantu!=head);

    if(N>jumlah)
        N=jumlah;


    TNode *hapus=head;
    TNode *sebelum=tail;

    for(int i=1;i<N;i++){

        sebelum=hapus;
        hapus=hapus->next;
    }

    if(head==tail){

        delete hapus;
        init();
    }

    else{

        sebelum->next=hapus->next;

        if(hapus==head)
            head=hapus->next;

        if(hapus==tail)
            tail=sebelum;

        tail->next=head;

        delete hapus;
    }

    cout<<"Data dihapus\n";
}



// ================= MODIFIKASI 3 =================

void hapusBelakang(){

    if(isEmpty()){

        cout<<"List kosong\n";
        return;
    }

    int N;

    cout<<"Hapus node ke-N dari belakang : ";
    cin>>N;

    int jumlah=0;

    TNode *bantu=head;

    do{

        jumlah++;
        bantu=bantu->next;

    }while(bantu!=head);


    int posisi;

    if(N>jumlah)
        posisi=1;

    else
        posisi=jumlah-N+1;


    TNode *hapus=head;
    TNode *sebelum=tail;

    for(int i=1;i<posisi;i++){

        sebelum=hapus;
        hapus=hapus->next;
    }

    if(head==tail){

        delete hapus;
        init();
    }

    else{

        sebelum->next=hapus->next;

        if(hapus==head)
            head=hapus->next;

        if(hapus==tail)
            tail=sebelum;

        tail->next=head;

        delete hapus;
    }

    cout<<"Data dihapus\n";
}


void tampilkan(){

    if(isEmpty()){

        cout<<"Data kosong\n";
        return;
    }

    TNode *bantu=head;

    cout<<"Data : ";

    do{

        cout<<bantu->data<<" ";

        bantu=bantu->next;

    }while(bantu!=head);

    cout<<endl;
}



// ================= MODIFIKASI 4 =================

void reset(){

    if(isEmpty()){

        cout<<"List kosong\n";
        return;
    }

    int no=1;

    while(head!=NULL){

        TNode *hapus=head;

        cout<<"Menghapus node ke-"
            <<no
            <<" isi : "
            <<hapus->data
            <<endl;

        if(head==tail){

            delete hapus;
            init();
        }

        else{

            head=head->next;

            tail->next=head;

            delete hapus;
        }

        no++;
    }

    cout<<"Semua data berhasil dihapus\n";
}