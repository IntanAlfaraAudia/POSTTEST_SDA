#include <iostream>
#include <string>
using namespace std;

struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
};

JadwalPenerbangan* headJadwal = nullptr;
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
    cout << "|                  PILIH STATUS                   |" << endl;
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
        default: return "Tidak diketahui";
    }
}

void tambahJadwal(string tujuan, string status) {
    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
    nodeBaru->kodePenerbangan = generateKode();
    nodeBaru->tujuan = tujuan;
    nodeBaru->status = status;
    nodeBaru->next = nullptr;

    if (headJadwal == nullptr) {
        headJadwal = nodeBaru;
    } else {
        JadwalPenerbangan* temp = headJadwal;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "=================================================================" << endl;
    cout << " Jadwal penerbangan berhasil ditambahkan dengan kode " << nodeBaru->kodePenerbangan << endl;
    cout << "=================================================================" << endl;
}

void sisipJadwal(string tujuan, string status) {
    int posisi = 8 + 1; // digit terakhir NIM = 8 → posisi = 9

    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
    nodeBaru->kodePenerbangan = generateKode();
    nodeBaru->tujuan = tujuan;
    nodeBaru->status = status;

    if (headJadwal == nullptr || posisi == 1) {
        nodeBaru->next = headJadwal;
        headJadwal = nodeBaru;
    } else {
        JadwalPenerbangan* temp = headJadwal;
        for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
    counter++;
    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan telah disisipkan di posisi " << posisi << "  |" << endl;
    cout << "====================================================" << endl;
}

void hapusAwal() {
    if (headJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Ups, Tidak ada jadwal untuk dihapus nih.                 |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    JadwalPenerbangan* hapus = headJadwal;
    headJadwal = headJadwal->next;
    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan dengan kode " << hapus->kodePenerbangan << " berhasil dihapus dari awal |" << endl;
    cout << "====================================================" << endl;
    delete hapus;
    counter--;
}

void hapusAkhir() {
    if (headJadwal == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Ups, Tidak ada jadwal untuk dihapus nih.                 |" << endl;
        cout << "====================================================" << endl;
        return;
    }
    if (headJadwal->next == nullptr) {
        cout << "====================================================" << endl;
        cout << "| Jadwal penerbangan dengan kode " << headJadwal->kodePenerbangan << " berhasil dihapus dari akhir |" << endl;
        cout << "====================================================" << endl;
        delete headJadwal;
        headJadwal = nullptr;
        counter--;
        return;
    }
    JadwalPenerbangan* temp = headJadwal;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "====================================================" << endl;
    cout << "| Jadwal penerbangan dengan kode " << temp->next->kodePenerbangan << " berhasil dihapus dari akhir |" << endl;
    cout << "====================================================" << endl;
    delete temp->next;
    temp->next = nullptr;
    counter--;
}

void updateStatus(string kode) {
    JadwalPenerbangan* temp = headJadwal;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "====================================================" << endl;
            cout << "| Status lama: " << temp->status << endl;
            temp->status = pilihStatus();
            cout << "| Status berhasil diperbarui.                      |" << endl;
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
    cout << "|              DAFTAR JADWAL PENERBANGAN           |" << endl;
    cout << "====================================================" << endl;
    while (temp != nullptr) {
        cout << "| Kode   : " << temp->kodePenerbangan << endl;
        cout << "| Tujuan : " << temp->tujuan << endl;
        cout << "| Status : " << temp->status << endl;
        cout << "----------------------------------------------------" << endl;
        temp = temp->next;
    }
    cout << "====================================================" << endl;
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
        cout << "| 5. Tampilkan Semua Jadwal                        |" << endl;
        cout << "| 6. Hapus Jadwal Paling Akhir                     |" << endl;
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
        }
    } while (pilihan != 0);

    cout << "===========================================================" << endl;
    cout << "| Terima kasih telah menggunakan sistem penerbangan ini.  |" << endl;
    cout << "===========================================================" << endl;

    return 0;
}