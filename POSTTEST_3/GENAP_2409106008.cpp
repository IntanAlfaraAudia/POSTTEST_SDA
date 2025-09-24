#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
    JadwalPenerbangan* prev;
};

JadwalPenerbangan* headJadwal = nullptr;
JadwalPenerbangan* tailJadwal = nullptr;
int counter = 0;

string generateKode() {
    string base = "JT-008";
    if (counter == 0) {
        counter++;
        return base;
    } else {
        return base + "-" + to_string(counter++);
    }
}

string pilihStatus() {
    int pilihan;
    cout << "====================================================" << endl;
    cout << "|                PILIH STATUS PENERBANGAN          |" << endl;
    cout << "====================================================" << endl;
    cout << "| 1. Tepat Waktu                                  |" << endl;
    cout << "| 2. Terlambat                                    |" << endl;
    cout << "| 3. Naik Pesawat                                 |" << endl;
    cout << "| 4. Dibatalkan                                   |" << endl;
    cout << "====================================================" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1: return "Tepat Waktu";
        case 2: return "Terlambat";
        case 3: return "Naik Pesawat";
        case 4: return "Dibatalkan";
        default: return "Tidak Diketahui";
    }
}

void tambahJadwal(string tujuan, string status) {
    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
    nodeBaru->kodePenerbangan = generateKode();
    nodeBaru->tujuan = tujuan;
    nodeBaru->status = status;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (headJadwal == nullptr) {
        headJadwal = tailJadwal = nodeBaru;
    } else {
        tailJadwal->next = nodeBaru;
        nodeBaru->prev = tailJadwal;
        tailJadwal = nodeBaru;
    }
    cout << "=================================================================" << endl;
    cout << " Jadwal penerbangan berhasil ditambahkan dengan kode " << nodeBaru->kodePenerbangan << endl;
    cout << "=================================================================" << endl;
}

void sisipJadwal(string tujuan, string status) {
    int posisi = 8 + 1; 

    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
    nodeBaru->kodePenerbangan = generateKode();
    nodeBaru->tujuan = tujuan;
    nodeBaru->status = status;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (headJadwal == nullptr || posisi == 1) {
        nodeBaru->next = headJadwal;
        if (headJadwal != nullptr) {
            headJadwal->prev = nodeBaru;
        }
        headJadwal = nodeBaru;
        if (tailJadwal == nullptr) {
            tailJadwal = nodeBaru;
        }
    } else {
        JadwalPenerbangan* temp = headJadwal;
        for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        nodeBaru->next = temp->next;
        nodeBaru->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = nodeBaru;
        } else {
            tailJadwal = nodeBaru;
        }
        temp->next = nodeBaru;
    }

    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan telah disisipkan di posisi " << posisi << "  |" << endl;
    cout << "====================================================" << endl;
}

void hapusAwal() {
    if (headJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Ups, Tidak ada jadwal untuk dihapus nih.         |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    JadwalPenerbangan* hapus = headJadwal;
    headJadwal = headJadwal->next;
    if (headJadwal != nullptr) {
        headJadwal->prev = nullptr;
    } else {
        tailJadwal = nullptr;
    }
    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan dengan kode " << hapus->kodePenerbangan << " berhasil dihapus dari awal |" << endl;
    cout << "====================================================" << endl;
    delete hapus;
    counter--;
}

void hapusAkhir() {
    if (headJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Ups, Tidak ada jadwal untuk dihapus nih.         |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    if (headJadwal->next == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Jadwal penerbangan dengan kode " << headJadwal->kodePenerbangan << " berhasil dihapus dari akhir |" << endl;
        cout << "====================================================" << endl;
        delete headJadwal;
        headJadwal = tailJadwal = nullptr;
        counter--;
        return;
    }
    JadwalPenerbangan* temp = tailJadwal;
    tailJadwal = tailJadwal->prev;
    tailJadwal->next = nullptr;
    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan dengan kode " << temp->kodePenerbangan << " berhasil dihapus dari akhir |" << endl;
    cout << "====================================================" << endl;
    delete temp;
    counter--;
}

void updateStatus(string kode) {
    JadwalPenerbangan* temp = headJadwal;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "====================================================" << endl;
            cout << "| Status lama: " << temp->status << endl;
            temp->status = pilihStatus();
            cout << "| Status berhasil diperbarui menjadi: " << temp->status << endl;
            cout << "====================================================" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "======================================================" << endl;
    cout << "| Ups, Kode penerbangan tidak ditemukan dalam daftar.|" << endl;
    cout << "======================================================" << endl;
}

void tampilkanJadwal() {
    if (headJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Belum ada jadwal penerbangan tersedia saat ini . |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    JadwalPenerbangan* temp = headJadwal;
    cout << "====================================================" << endl;
    cout << "|           DAFTAR JADWAL PENERBANGAN (DEPAN)      |" << endl;
    cout << "====================================================" << endl;
    while (temp != nullptr) {
        cout << "| Kode   : " << left << setw(15) << temp->kodePenerbangan << "|" << endl;
        cout << "| Tujuan : " << left << setw(15) << temp->tujuan << "|" << endl;
        cout << "| Status : " << left << setw(15) << temp->status << "|" << endl;
        cout << "----------------------------------------------------" << endl;
        temp = temp->next;
    }
    cout << "====================================================" << endl;
}

void tampilkanJadwalDariBelakang() {
    if (tailJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Belum ada jadwal penerbangan tersedia saat ini . |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    JadwalPenerbangan* temp = tailJadwal;
    cout << "====================================================" << endl;
    cout << "|           DAFTAR JADWAL PENERBANGAN (BELAKANG)   |" << endl;
    cout << "====================================================" << endl;
    while (temp != nullptr) {
        cout << "| Kode   : " << left << setw(15) << temp->kodePenerbangan << "|" << endl;
        cout << "| Tujuan : " << left << setw(15) << temp->tujuan << "|" << endl;
        cout << "| Status : " << left << setw(15) << temp->status << "|" << endl;
        cout << "----------------------------------------------------" << endl;
        temp = temp->prev;
    }
    cout << "====================================================" << endl;
}

void tampilkanDetailJadwal(string kode) {
    JadwalPenerbangan* temp = headJadwal;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "====================================================" << endl;
            cout << "|           DETAIL JADWAL PENERBANGAN              |" << endl;
            cout << "====================================================" << endl;
            cout << "| Kode Penerbangan : " << left << setw(15) << temp->kodePenerbangan << "|" << endl;
            cout << "| Tujuan          : " << left << setw(15) << temp->tujuan << "|" << endl;
            cout << "| Status          : " << left << setw(15) << temp->status << "|" << endl;
            cout << "====================================================" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "======================================================" << endl;
    cout << "| Ups, Kode penerbangan tidak ditemukan dalam daftar.|" << endl;
    cout << "======================================================" << endl;
}

int main() {
    string nama, nim;
    cout << "====================================================" << endl;
    cout << "|             SISTEM JADWAL PENERBANGAN            |" << endl;
    cout << "====================================================" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM : ";
    getline(cin, nim);

    int pilihan;
    do {
        cout << endl;
        cout << "====================================================" << endl;
        cout << "|              FLIGHT SCHEDULE SYSTEM              |" << endl;
        cout << "|                 [ " << nama << " - " << nim << " ]                  |" << endl;
        cout << "====================================================" << endl;
        cout << "| 1. Tambah Jadwal Penerbangan                     |" << endl;        
        cout << "| 2. Sisipkan Jadwal Penerbangan                   |" << endl;
        cout << "| 3. Hapus Jadwal Paling Awal                      |" << endl;
        cout << "| 4. Update Status Penerbangan                     |" << endl;
        cout << "| 5. Tampilkan Semua Jadwal (Dari Depan)           |" << endl;
        cout << "| 6. Hapus Jadwal Paling Akhir                     |" << endl;
        cout << "| 7. Tampilkan Semua Jadwal (Dari Belakang)        |" << endl;
        cout << "| 8. Tampilkan Detail Jadwal Berdasarkan Kode      |" << endl;
        cout << "| 0. Keluar                                        |" << endl;
        cout << "====================================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            status = pilihStatus();
            tambahJadwal(tujuan, status);
        } else if (pilihan == 2) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            status = pilihStatus();
            sisipJadwal(tujuan, status);
        } else if (pilihan == 3) {
            hapusAwal();
        } else if (pilihan == 4) {
            string kode;
            cout << "Masukkan kode penerbangan: ";
            getline(cin, kode);
            updateStatus(kode);
        } else if (pilihan == 5) {
            tampilkanJadwal();
        } else if (pilihan == 6) {
            hapusAkhir();
        } else if (pilihan == 7) {
            tampilkanJadwalDariBelakang();
        } else if (pilihan == 8) {
            string kode;
            cout << "Masukkan kode penerbangan: ";
            getline(cin, kode);
            tampilkanDetailJadwal(kode);
        }
    } while (pilihan != 0);

    cout << "===========================================================" << endl;
    cout << "| Terima kasih telah menggunakan sistem penerbangan ini.  |" << endl;
    cout << "===========================================================" << endl;

    return 0;
}