#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Antri {
    Node* front;
    Node* rear;
    int count;

    Antri() : front(nullptr), rear(nullptr), count(0) {}
};

// Menambahkan elemen ke antrian
void tambahantri(Antri* antrian, int data) {
    Node* new_node = new Node{data, nullptr};

    if (antrian->front == nullptr) {
        antrian->front = new_node;
        antrian->rear = new_node;
    } else {
        antrian->rear->next = new_node;
        antrian->rear = new_node;
    }

    antrian->count++;
}

// Menghapus elemen dari antrian
int hapusantri(Antri* antrian) {
    if (antrian->front == nullptr) {
        return -1;
    }

    int data = antrian->front->data;
    Node* temp = antrian->front;
    antrian->front = antrian->front->next;
    delete temp;

    antrian->count--;
    return data;
}

// Menampilkan antrian
void tampilantri(Antri* antrian) {
    Node* temp = antrian->front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// menampilkan menu
void showMenu() {
    cout << "===== Menu Antrian Bank BRI=====\n"
         << "1. Tambah antrian\n"
         << "2. Hapus antrian\n"
         << "3. Lihat antrian\n"
         << "4. Keluar\n"
         << "Pilih menu: ";
}

int main() {
    // Membuat antrian
    Antri antrian;

    // Menampilkan menu
    showMenu();

    int choice;
    int deletedData;

    // Menjalankan program
    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                // Menambah antrian
                int data;
                cout << "Masukkan data: ";
                cin >> data;
                tambahantri(&antrian, data);
                break;
            case 2:
                // Menghapus antrian
                deletedData = hapusantri(&antrian);
                if (deletedData != -1) {
                    cout << "Data yang dihapus: " << deletedData << endl;
                }
                break;
            case 3:
                // Menampilkan antrian
                tampilantri(&antrian);
                break;
            case 4:
                // Keluar
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }

        showMenu();
    }

    return 0;
}
