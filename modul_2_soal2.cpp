#include <iostream>
#include <stdlib.h>

#define max 20
using namespace std;

struct Stack {
    int atas;
    int data[max];
};

Stack Tumpuk;

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

int kosong() {
    return (Tumpuk.atas == -1);
}

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data_baru) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data_baru; // Tadi di sini mungkin kamu tulis 'Atas'
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    } 
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data_baru;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    } 
    else {
        cout << "Tumpukan Penuh" << endl;
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil" << endl;
        Tumpuk.atas--;
    } 
    else {
        cout << "Data Kosong" << endl;
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
        cout << endl;
    } 
    else {
        cout << "Tumpukan Kosong" << endl;
    }
}

int main() {
    Tumpuk.atas = -1; 
    int pilihan, nilai;

    do {
        cout << "\n\nSTACK (SOAL 2)" << endl;
        cout << "==============" << endl;
        cout << "1. INPUT" << endl;
        cout << "2. HAPUS" << endl;
        cout << "3. TAMPIL" << endl;
        cout << "4. BERSIH" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nilai: "; cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
        }

        if (pilihan != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore(1000, '\n');
            cin.get();
        }

    } while (pilihan != 5);

    return 0;
}