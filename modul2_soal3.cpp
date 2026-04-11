#include <iostream>
#include <stdlib.h>

#define n 10
using namespace std;

// Deklarasi Fungsi
void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

// Variabel Global
int PIL, F, R;
char PILIHAN[2], HURUF;
char Q[n];

int main() {
    Inisialisasi();
    do {
        cout << "\n\n\n\n\n"; 
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl; // Menambahkan menu reset
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                cout << "Antrean Berhasil Dikosongkan (Reset)." << endl;
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        if (PIL < 5) {
            cout << "\npress any key to continue" << endl;
            cin.ignore(1000, '\n');
            cin.get();
        }

    } while (PIL < 5);

    return 0;
}

void Inisialisasi() {
    F = -1;
    R = -1;
}

void RESET() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Antrean Penuh (Overflow)!" << endl;
    } else {
        cout << "Masukkan Huruf: "; cin >> HURUF;
        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " Berhasil Masuk Antrean." << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Antrean Kosong (Underflow)!" << endl;
        RESET(); // Otomatis reset jika sudah benar-benar kosong
    } else {
        cout << "Huruf " << Q[F] << " Dikeluarkan dari Antrean." << endl;
        F++;
    }
}

void CETAKLAYAR() {
    if (F == -1 || F > R) {
        cout << "Antrean Kosong!" << endl;
    } else {
        // Menampilkan isi antrean dari Front sampai Rear
        for (int i = F; i <= R; i++) {
            cout << "Queue ke- " << i << " = " << Q[i] << endl;
        }
    }
}