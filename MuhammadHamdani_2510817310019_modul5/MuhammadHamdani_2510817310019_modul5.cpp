#include <iostream>
using namespace std;

// ===================== INSERTION SORT =====================
void insertionSort(char data[], int n) {
    for(int i = 1; i < n; i++) {
        char key = data[i];
        int j = i - 1;

        while(j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}

// ===================== MERGE SORT =====================
void merge(char data[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[100], R[100];

    for(int i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }

    for(int j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char data[], int left, int right) {

    if(left < right) {

        int mid = (left + right) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }
}

// ===================== SHELL SORT =====================
void shellSort(char data[], int n) {

    for(int gap = n / 2; gap > 0; gap /= 2) {

        for(int i = gap; i < n; i++) {

            char temp = data[i];
            int j;

            for(j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }

            data[j] = temp;
        }
    }
}

// ===================== QUICK SORT =====================
void quickSort(char data[], int low, int high) {

    int i = low;
    int j = high;

    char pivot = data[(low + high) / 2];

    while(i <= j) {

        while(data[i] < pivot) {
            i++;
        }

        while(data[j] > pivot) {
            j--;
        }

        if(i <= j) {

            swap(data[i], data[j]);

            i++;
            j--;
        }
    }

    if(low < j) {
        quickSort(data, low, j);
    }

    if(i < high) {
        quickSort(data, i, high);
    }
}

// ===================== BUBBLE SORT =====================
void bubbleSort(char data[], int n) {

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - i - 1; j++) {

            if(data[j] > data[j + 1]) {

                swap(data[j], data[j + 1]);
            }
        }
    }
}

// ===================== SELECTION SORT =====================
void selectionSort(char data[], int n) {

    for(int i = 0; i < n - 1; i++) {

        int min = i;

        for(int j = i + 1; j < n; j++) {

            if(data[j] < data[min]) {
                min = j;
            }
        }

        swap(data[i], data[min]);
    }
}

// ===================== MENAMPILKAN DATA =====================
void tampilkan(char data[], int n) {

    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

// ===================== MAIN PROGRAM =====================
int main() {

    int pilihan;

    do {

        cout << "\n====================================";
        cout << "\n         PROGRAM SORTING";
        cout << "\n====================================";
        cout << "\n1. Insertion Sort (Nama)";
        cout << "\n2. Merge Sort (Nama)";
        cout << "\n3. Shell Sort (Nama)";
        cout << "\n4. Quick Sort (NIM)";
        cout << "\n5. Bubble Sort (NIM)";
        cout << "\n6. Selection Sort (NIM)";
        cout << "\n0. Keluar";
        cout << "\n====================================";
        cout << "\nMasukkan Pilihan : ";
        cin >> pilihan;

        // ===================== SORTING NAMA =====================
        if(pilihan >= 1 && pilihan <= 3) {

            char nama[100];
            int panjang = 0;

            cout << "\nMasukkan Nama : ";
            cin >> nama;

            while(nama[panjang] != '\0') {
                panjang++;
            }

            cout << "\nData Sebelum Sorting : ";
            tampilkan(nama, panjang);

            if(pilihan == 1) {

                insertionSort(nama, panjang);

                cout << "\nHasil Insertion Sort : ";
                tampilkan(nama, panjang);
            }

            else if(pilihan == 2) {

                mergeSort(nama, 0, panjang - 1);

                cout << "\nHasil Merge Sort : ";
                tampilkan(nama, panjang);
            }

            else if(pilihan == 3) {

                shellSort(nama, panjang);

                cout << "\nHasil Shell Sort : ";
                tampilkan(nama, panjang);
            }
        }

        // ===================== SORTING NIM =====================
        else if(pilihan >= 4 && pilihan <= 6) {

            char nim[100];
            int panjang = 0;

            cout << "\nMasukkan NIM : ";
            cin >> nim;

            while(nim[panjang] != '\0') {
                panjang++;
            }

            cout << "\nData Sebelum Sorting : ";
            tampilkan(nim, panjang);

            if(pilihan == 4) {

                quickSort(nim, 0, panjang - 1);

                cout << "\nHasil Quick Sort : ";
                tampilkan(nim, panjang);
            }

            else if(pilihan == 5) {

                bubbleSort(nim, panjang);

                cout << "\nHasil Bubble Sort : ";
                tampilkan(nim, panjang);
            }

            else if(pilihan == 6) {

                selectionSort(nim, panjang);

                cout << "\nHasil Selection Sort : ";
                tampilkan(nim, panjang);
            }
        }

        else if(pilihan == 0) {

            cout << "\nProgram Selesai.\n";
        }

        else {

            cout << "\nPilihan Tidak Tersedia.\n";
        }

    } while(pilihan != 0);

    return 0;
}