#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Mahasiswa {
    string nama;
    string nrp;
    string jurusan;
    string fakultas;
    string alamat;
    string asal;
    string ttl;
    string gender;
    string cita;
    string hobi;
    
};

// Menggunakan vector untuk menyimpan data mahasiswa
vector<Mahasiswa> dataMahasiswa;

// Fungsi untuk menampilkan data semua mahasiswa
void tampilkanData() {
    if (dataMahasiswa.empty()) {
        cout << "Tidak ada data mahasiswa." << endl;
    } else {
        cout << "Data Mahasiswa:" << endl;
        for (const Mahasiswa &mahasiswa : dataMahasiswa) {
            cout << "Nama: " << mahasiswa.nama << endl;
            cout << "NRP: " << mahasiswa.nrp << endl; 
            cout << "Jurusan: " << mahasiswa.jurusan << endl;
            cout << "Fakultas: " << mahasiswa.fakultas << endl;
            cout << "Alamat Domisili: " << mahasiswa.alamat << endl;
            cout << "Asal: " << mahasiswa.asal << endl; 
            cout << "Tempat, Tanggal Lahir: " << mahasiswa.ttl << endl;
            cout << "Jenis Kelamin: " << mahasiswa.gender << endl;
            cout << "Cita-Cita: " << mahasiswa.cita << endl;
            cout << "Hobi: " << mahasiswa.hobi << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}

// Fungsi untuk menambah data mahasiswa
void tambahData() {
    Mahasiswa mahasiswaBaru;
    cout << "Masukkan Nama Lengkap: ";
    cin.ignore();
    getline(cin, mahasiswaBaru.nama);
    cout << "Masukkan NRP: "; 
    getline(cin, mahasiswaBaru.nrp);
    cout << "Masukkan Jurusan: ";
    getline(cin, mahasiswaBaru.jurusan);
    cout << "Masukkan Fakultas: ";
    getline(cin, mahasiswaBaru.fakultas);
    cout << "Masukkan Alamat Domisili: ";
    getline(cin, mahasiswaBaru.alamat);
    cout << "Masukkan Asal Kota/ Kabupaten: ";
    getline(cin, mahasiswaBaru.asal);
    cout << "Masukkan Tempat, Tanggal Lahir: ";
    getline(cin, mahasiswaBaru.ttl);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, mahasiswaBaru.gender);
    cout << "Masukkan Cita-Cita: ";
    getline(cin, mahasiswaBaru.cita);
    cout << "Masukkan 1 Hobi: ";
    getline(cin, mahasiswaBaru.hobi);

    dataMahasiswa.push_back(mahasiswaBaru);
    cout << "Data mahasiswa telah ditambahkan." << endl;
}

// Fungsi untuk menghapus data mahasiswa berdasarkan jenis data
void hapusData() {
    if (dataMahasiswa.empty()) {
        cout << "Tidak ada data mahasiswa untuk dihapus." << endl;
        return;
    }

    cout << "Pilih data yang ingin dihapus:" << endl;
    cout << "1. Nama" << endl;
    cout << "2. NRP" << endl;
    cout << "3. Jurusan" << endl;
    cout << "4. Fakultas" << endl;
    cout << "5. Alamat Domisili" << endl;
    cout << "6. Asal Kota/Kabupaten" << endl;
    cout << "7. Tempat, Tanggal Lahir" << endl;
    cout << "8. Jenis Kelamin" << endl;
    cout << "9. Cita-Cita" << endl;
    cout << "10. Hobi" << endl;
    cout << "11. Hapus Data Mahasiswa (Berdasarkan NRP)" << endl;
    cout << "Pilihan (Masukkan Angka): ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    cout << "Masukkan input data yang ingin dihapus: ";
    string inputHapus;
    getline(cin, inputHapus); 
    char nrpditemukan;
    bool hapusemua = true;

    bool ditemukan = false;
    for (Mahasiswa &mahasiswa : dataMahasiswa) {
        switch (pilihan) {
            case 1: 
                if (mahasiswa.nama == inputHapus) {
                    mahasiswa.nama = "";
                    ditemukan = true;
                }
                break;
            case 2: 
                if (mahasiswa.nrp == inputHapus) {
                    mahasiswa.nrp = "";
                    ditemukan = true;
                }
                break;
            case 3: 
                if (mahasiswa.jurusan == inputHapus) {
                    mahasiswa.jurusan = "";
                    ditemukan = true;
                }
                break;
            case 4: 
                if (mahasiswa.fakultas == inputHapus) {
                    mahasiswa.fakultas = "";
                    ditemukan = true;
                }
                break;
            case 5: 
                if (mahasiswa.alamat == inputHapus) {
                    mahasiswa.alamat = "";
                    ditemukan = true;
                }
                break;
            case 6: 
                if (mahasiswa.asal == inputHapus) {
                    mahasiswa.asal = "";
                    ditemukan = true;
                }
                break;
            case 7: 
                if (mahasiswa.ttl == inputHapus) {
                    mahasiswa.ttl = "";
                    ditemukan = true;
                }
                break;
            case 8: 
                if (mahasiswa.gender == inputHapus) {
                    mahasiswa.gender = "";
                    ditemukan = true;
                }
                break;
            case 9:    
                if (mahasiswa.cita == inputHapus) {
                    mahasiswa.cita = "";
                    ditemukan = true;
                }
                break;
            case 10:
                if (mahasiswa.hobi == inputHapus) {
                    mahasiswa.hobi = "";
                    ditemukan = true;
                }
                break;
            case 11:
                for (auto it = dataMahasiswa.begin(); it != dataMahasiswa.end();) {
                    if (mahasiswa.nrp == inputHapus) {
                        it = dataMahasiswa.erase(it);
                        nrpditemukan = true;
                        cout << "Data Mahasiswa dengan NRP " << inputHapus << " telah dihapus." << endl;
                    } else {
                        ++it;
                    }
                }
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return;
        }
    }

    if (ditemukan) {
        cout << "Data yang sesuai dengan input telah dihapus." << endl;
    } else {
        if(!nrpditemukan){
            cout << "Tidak ada data yang sesuai dengan input yang dimasukkan." << endl;
        }
        
    }
}

// Fungsi untuk mengubah data mahasiswa
void ubahData() {
    if (dataMahasiswa.empty()) {
        cout << "Tidak ada data mahasiswa untuk diubah." << endl;
        return;
    } 
    
    cout << "Pilih data yang ingin diubah:" << endl;
    cout << "1. Nama" << endl;
    cout << "2. NRP" << endl;
    cout << "3. Jurusan" << endl;
    cout << "4. Fakultas" << endl;
    cout << "5. Alamat Domisili" << endl;
    cout << "6. Asal Kota/Kabupaten" << endl;
    cout << "7. Tempat, Tanggal Lahir" << endl;
    cout << "8. Jenis Kelamin" << endl;
    cout << "9. Cita-Cita" << endl;
    cout << "10. Hobi" << endl;
    cout << "11. Mahasiswa (Berdasarkan NRP)" << endl;
    cout << "Pilihan (Masukkan Angka): ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();
    cout << "Masukkan data input awal: ";
    string inputUbah;
    getline(cin, inputUbah);
    bool ditemukan = false;

    for (Mahasiswa &mahasiswa : dataMahasiswa) {
        switch (pilihan) {
            case 1:
                if (mahasiswa.nama == inputUbah) {
                    cout << "Masukkan Nama Lengkap yang diubah: ";
                    getline(cin, mahasiswa.nama);
                    ditemukan = true;
                }
                break;
            case 2:
                if (mahasiswa.nrp == inputUbah) {
                    cout << "Masukkan NRP yang diubah: ";
                    getline(cin, mahasiswa.nrp);
                    ditemukan = true;
                }
                break;
            case 3:
                if (mahasiswa.jurusan == inputUbah) {
                    cout << "Masukkan Jurusan yang diubah: ";
                    getline(cin, mahasiswa.jurusan);
                    ditemukan = true;
                }
                break;
            case 4:
                if (mahasiswa.fakultas == inputUbah) {
                    cout << "Masukkan Fakultas yang diubah: ";
                    getline(cin, mahasiswa.fakultas);
                    ditemukan = true;
                }
                break;
            case 5:
                if (mahasiswa.alamat == inputUbah) {
                    cout << "Masukkan Alamat yang diubah: ";
                    getline(cin, mahasiswa.alamat);
                    ditemukan = true;
                }
                break;
            case 6:
                if (mahasiswa.asal == inputUbah) {
                    cout << "Masukkan Asal Kota/ Kabupaten yang diubah: ";
                    getline(cin, mahasiswa.asal);
                    ditemukan = true;
                }
                break;
            case 7:
                if (mahasiswa.ttl == inputUbah) {
                    cout << "Masukkan Tempat, Tanggal Lahir yang diubah: ";
                    getline(cin, mahasiswa.ttl);
                    ditemukan = true;
                }
                break;
            case 8:
                if (mahasiswa.gender == inputUbah) {
                    cout << "Masukkan Jenis Kelamin yang diubah: ";
                    getline(cin, mahasiswa.gender);
                    ditemukan = true;
                }
                break;
            case 9:
                if (mahasiswa.cita == inputUbah) {
                    cout << "Masukkan Cita-Cita yang diubah: ";
                    getline(cin, mahasiswa.cita);
                    ditemukan = true;
                }
                break;
            case 10:
                if (mahasiswa.hobi == inputUbah) {
                    cout << "Masukkan Hobi yang diubah: ";
                    getline(cin, mahasiswa.hobi);
                    ditemukan = true;
                }
                break;
            case 11:
            if (dataMahasiswa.empty()) {
                cout << "Tidak ada data mahasiswa untuk diubah." << endl;
            } 
            
            else {
                string nrpUbah;
                cout << "Masukkan NRP Mahasiswa yang ingin diubah: "; 
                cin.ignore();
                getline(cin, nrpUbah);
                bool ditemukan = false;

                for (Mahasiswa &mahasiswa : dataMahasiswa) {
                    if (mahasiswa.nrp == nrpUbah) {
                        ditemukan = true;
                        cout << "Masukkan data baru:" << endl;
                        cout << "Masukkan Nama Lengkap yang diubah: ";
                        getline(cin, mahasiswa.nama);
                        cout << "Masukkan Jurusan Mahasiswa yang diubah: ";
                        getline(cin, mahasiswa.jurusan);
                        cout << "Masukkan Fakultas yang diubah: ";
                        getline(cin, mahasiswa.fakultas);
                        cout << "Masukkan Alamat yang diubah: ";
                        getline(cin, mahasiswa.alamat);
                        cout << "Masukkan Asal Kota/ Kabupaten yang diubah: ";
                        getline(cin, mahasiswa.asal);
                        cout << "Masukkan Tempat, Tanggal Lahir yang diubah: ";
                        getline(cin, mahasiswa.ttl);
                        cout << "Masukkan Jenis Kelamin yang diubah: ";
                        getline(cin, mahasiswa.gender);
                        cout << "Masukkan Cita-Cita yang diubah: ";
                        getline(cin, mahasiswa.cita);
                        cout << "Masukkan Hobi yang diubah: ";
                        getline(cin, mahasiswa.hobi);
                        cout << "Data mahasiswa dengan NRP  " << nrpUbah << "  telah diubah." << endl;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Data mahasiswa dengan NRP " << nrpUbah << " tidak ditemukan." << endl;
                }
            }
            default:
                cout << "Pilihan tidak valid." << endl;
                return;
        }
    }

    if (ditemukan) {
        cout << "Data yang sesuai dengan input telah diubah." << endl;
    } else {
        cout << "Tidak ada data yang sesuai dengan input yang dimasukkan." << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Data Mahasiswa\n";
        cout << "2. Tambah Data Mahasiswa\n";
        cout << "3. Hapus Data Mahasiswa\n";
        cout << "4. Ubah Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData();
                break;
            case 2:
                tambahData();
                break;
            case 3:
                hapusData();
                break;
            case 4:
                ubahData();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
