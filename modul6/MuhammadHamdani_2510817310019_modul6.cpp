#include <iostream>
using namespace std;

void sequentialSearch() {
    int data[100], n, cari;
    bool ditemukan = false;

    cout << "\n=== SEQUENTIAL SEARCHING ===\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    for(int i = 0; i < n; i++) {
        if(data[i] == cari) {
            cout << "Data ditemukan pada index ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan) {
        cout << "Data tidak ditemukan!\n";
    }
}

void binarySearch() {
    int data[100], n, cari;
    int awal, tengah, akhir;
    bool ditemukan = false;

    cout << "\n=== BINARY SEARCHING ===\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Masukkan data secara URUT!\n";

    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    awal = 0;
    akhir = n - 1;

    while(awal <= akhir) {
        tengah = (awal + akhir) / 2;

        if(data[tengah] == cari) {
            cout << "Data ditemukan pada index ke-" << tengah << endl;
            ditemukan = true;
            break;
        }
        else if(cari < data[tengah]) {
            akhir = tengah - 1;
        }
        else {
            awal = tengah + 1;
        }
    }

    if(!ditemukan) {
        cout << "Data tidak ditemukan!\n";
    }
}

// Main Program
int main() {
    int pilihan;

    do {
        cout << "\n============================";
        cout << "\n       MENU SEARCHING";
        cout << "\n============================";
        cout << "\n1. Sequential Searching";
        cout << "\n2. Binary Searching";
        cout << "\n3. Keluar";
        cout << "\n============================";
        cout << "\nPilih menu : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                sequentialSearch();
                break;

            case 2:
                binarySearch();
                break;

            case 3:
                cout << "Program selesai...\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while(pilihan != 3);

    return 0;
}