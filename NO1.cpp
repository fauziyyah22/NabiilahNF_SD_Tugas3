#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan nilai - nilai mahasiswa
struct Nilai {
    float absen;
    float tugas;
    float uts;
    float uas;
    float nilai_akhir;
    char index_huruf;
};

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string npm;
    string nama;
    Nilai nilai; // Menggunakan struktur nilai
};

// Deklarasi array untuk menyimpan data mahasiswa
Mahasiswa data_mahasiswa[20]; // Array untuk menyimpan data mahasiswa dengan batasan maksimum 20 mahasiswa
int jumlah_mahasiswa = 0; // Variabel unutk menyimpan jumlah mahasiswa yang telah dimasukkan ke dalam program

// Fungsi untuk menghitung nilai akhir dan index huruf dari nilai mahasiswa
void hitungNilai(Nilai &nilai) {
    nilai.nilai_akhir = 0.1 * nilai.absen + 0.2 * nilai.tugas + 0.3 * nilai.uts + 0.4 * nilai.uas;
    if (nilai.nilai_akhir > 80)
        nilai.index_huruf = 'A';
    else if (nilai.nilai_akhir > 70)
        nilai.index_huruf = 'B';
    else if (nilai.nilai_akhir > 60)
        nilai.index_huruf = 'C';
    else
        nilai.index_huruf = 'D';
}

// Fungsi untuk menampilkan data mahasiswa yang telah dimasukkan
void tampilkanData() {
    if (jumlah_mahasiswa == 0) {
        cout << "Tidak ada data mahasiswa\n";
        return;
    }

    cout << "Data Mahasiswa:\n";
    for (int j = 0; j < 100; j++) {
        cout << "=";}
    cout << "\nNo\tNPM\t\tNama\t\tAbsen\tTugas\tUTS\tUAS\tNilai Akhir\tIndex Huruf\n";
    for (int j = 0; j < 100; j++) {
        cout << "=";}
    cout << "\n";
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        cout << i+1 << "\t" << data_mahasiswa[i].npm << "\t" << data_mahasiswa[i].nama << "\t\t";
        cout << data_mahasiswa[i].nilai.absen << "\t" << data_mahasiswa[i].nilai.tugas << "\t";
        cout << data_mahasiswa[i].nilai.uts << "\t" << data_mahasiswa[i].nilai.uas << "\t";
        cout << data_mahasiswa[i].nilai.nilai_akhir << "\t\t" << data_mahasiswa[i].nilai.index_huruf << "\n";
    }
    for (int j = 0; j < 100; j++) {
        cout << "=";}
    cout << "\n";
}

// Fungsi untuk memasukkan data mahasiswa baru ke dalam program
void inputData() {
    if (jumlah_mahasiswa == 20) {
        cout << "Data mahasiswa sudah penuh\n";
        return;
    }

    cout << "Masukkan data mahasiswa ke-" << jumlah_mahasiswa + 1 << ":\n";
    cout << "NPM: ";
    cin >> data_mahasiswa[jumlah_mahasiswa].npm;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, data_mahasiswa[jumlah_mahasiswa].nama);
    cout << "Nilai Absen: ";
    cin >> data_mahasiswa[jumlah_mahasiswa].nilai.absen;
    cout << "Nilai Tugas: ";
    cin >> data_mahasiswa[jumlah_mahasiswa].nilai.tugas;
    cout << "Nilai UTS: ";
    cin >> data_mahasiswa[jumlah_mahasiswa].nilai.uts;
    cout << "Nilai UAS: ";
    cin >> data_mahasiswa[jumlah_mahasiswa].nilai.uas;

    hitungNilai(data_mahasiswa[jumlah_mahasiswa].nilai);
    jumlah_mahasiswa++;
}

// Fungsi untuk mengedit data mahasiswa berdasarkan NPM
void editData() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin di edit: ";
    cin >> npm;

    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        if (data_mahasiswa[i].npm == npm) {
            cout << "Masukkan data baru untuk mahasiswa dengan NPM " << npm << ":\n";
            cout << "Nilai Absen: ";
            cin >> data_mahasiswa[i].nilai.absen;
            cout << "Nilai Tugas: ";
            cin >> data_mahasiswa[i].nilai.tugas;
            cout << "Nilai UTS: ";
            cin >> data_mahasiswa[i].nilai.uts;
            cout << "Nilai UAS: ";
            cin >> data_mahasiswa[i].nilai.uas;

            hitungNilai(data_mahasiswa[i].nilai);
            cout << "Data mahasiswa dengan NPM " << npm << " berhasil diupdate\n";
            return;
        }
    }

    cout << "Data mahasiswa dengan NPM " << npm << " tidak ditemukan\n";
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NPM
void hapusData() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
    cin >> npm;

    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        if (data_mahasiswa[i].npm == npm) {
            for (int j = i; j < jumlah_mahasiswa - 1; ++j) {
                data_mahasiswa[j] = data_mahasiswa[j + 1];
            }
            jumlah_mahasiswa--;
            cout << "Data mahasiswa dengan NPM " << npm << " berhasil dihapus\n";
            return;
        }
    }

    cout << "Data mahasiswa dengan NPM " << npm << " tidak ditemukan\n";
}

int main() {
    char menu;

    // Untuk menampilkan menu program dan memproses input data
    do {
        cout << "Menu:\n";
        cout << "1. Input Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Edit Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> menu;

        // Untuk memilih tindakan yang akan dilakukan berdasarkan pilihan menu yang dimasukkan pengguna
        switch (menu) {
            case '1':
                inputData();
                break;
            case '2':
                tampilkanData();
                break;
            case '3':
                editData();
                break;
            case '4':
                hapusData();
                break;
            // Program akan berhenti jika pengguna memilih keluar atau menu ke 5
            case '5':
                cout << "\nTerima kasih telah menggunakan program ini\n";
                for (int j = 0; j < 60; j++) {
                cout << "=";}
                cout << "\nNama     : Nabiilah Nur Fauziyyah";
                cout << "\nNPM      : 2310631170105";
                cout << "\nKelas    : 2C - Informatika";
                cout << "\nProgram Struct Data Nilai Mahasiswa " << "\n";
                for (int j = 0; j < 60; j++) {
                cout << "=";}
                break;
            default:
                cout << "Menu tidak valid\n";
                break;
        }
    } while (menu != '5');

    return 0;
}

