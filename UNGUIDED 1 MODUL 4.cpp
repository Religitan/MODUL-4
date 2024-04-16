#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string nama;
    string nim;
    Node *next;
};

bool isEmpty(Node *head)
{
    return head == nullptr;
}

Node* buatNode(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = nullptr;
    return baru;
}

Node* tambahDepan(Node *head, string nama, string nim)
{
    Node *baru = buatNode(nama, nim);
    if (isEmpty(head))
    {
        return baru;
    }
    baru->next = head;
    return baru;
}

Node* tambahBelakang(Node *head, string nama, string nim)
{
    Node *baru = buatNode(nama, nim);
    if (isEmpty(head))
    {
        return baru;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = baru;
    return head;
}

Node* tambahTengah(Node *head, string nama, string nim, int posisi)
{
    if (posisi < 1)
    {
        cout << "Posisi tidak valid" << endl;
        return head;
    }
    if (posisi == 1)
    {
        cout << "Gunakan tambahDepan untuk menambahkan pada posisi pertama" << endl;
        return tambahDepan(head, nama, nim);
    }
    Node *baru = buatNode(nama, nim);
    Node *bantu = head;
    for (int i = 1; i < posisi - 1 && bantu != nullptr; i++)
    {
        bantu = bantu->next;
    }
    if (bantu == nullptr)
    {
        cout << "Posisi diluar jangkauan" << endl;
        return head;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    return head;
}

void ubahDepan(Node *head, string nama, string nim)
{
    if (!isEmpty(head))
    {
        head->nama = nama;
        head->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(Node *head, string nama, string nim)
{
    if (!isEmpty(head))
    {
        Node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->nama = nama;
        tail->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(Node *head, string nama, string nim, int posisi)
{
    if (!isEmpty(head))
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node *bantu = head;
        for (int i = 1; i < posisi && bantu != nullptr; i++)
        {
            bantu = bantu->next;
        }
        if (bantu == nullptr)
        {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }
        bantu->nama = nama;
        bantu->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

Node* hapusDepan(Node *head)
{
    if (!isEmpty(head))
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
    return head;
}

Node* hapusBelakang(Node *head)
{
    if (!isEmpty(head))
    {
        Node *hapus = nullptr;
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        Node *tail = head;
        while (tail->next->next != nullptr)
        {
            tail = tail->next;
        }
        hapus = tail->next;
        tail->next = nullptr;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
    return head;
}

Node* hapusTengah(Node *head, int posisi)
{
    if (!isEmpty(head))
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak valid" << endl;
            return head;
        }
        if (posisi == 1)
        {
            return hapusDepan(head);
        }
        Node *bantu = head;
        for (int i = 1; i < posisi - 1 && bantu != nullptr; i++)
        {
            bantu = bantu->next;
        }
        if (bantu == nullptr || bantu->next == nullptr)
        {
            cout << "Posisi diluar jangkauan" << endl;
            return head;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
    return head;
}

void hapusList(Node *&head)
{
    while (!isEmpty(head))
    {
        head = hapusDepan(head);
    }
    cout << "List berhasil terhapus!" << endl;
}

int hitungList(Node *head)
{
    int jumlah = 0;
    Node *bantu = head;
    while (bantu != nullptr)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

void tampil(Node *head)
{
    if (!isEmpty(head))
    {
        Node *bantu = head;
        cout << "=========================" << endl;
        cout << "   DATA MAHASISWA" << endl;
        cout << "=========================" << endl;
        cout << "|   NAMA          |  NIM  |" << endl;
        cout << "---------------------------" << endl;
        while (bantu != nullptr)
        {
            cout << "|   " << bantu->nama << "      |  " << bantu->nim << "   |" << endl;
            bantu = bantu->next;
        }
        cout << "---------------------------" << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    Node *head = nullptr;
    int choice, posisi;
    string nama, nim;
    do
    {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "-Tambah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                head = tambahDepan(head, nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "-Tambah Belakang" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                head = tambahBelakang(head, nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "-Tambah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                head = tambahTengah(head, nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                ubahDepan(head, nama, nim);
                break;
            case 5:
                cout << "-Ubah Belakang" << endl;
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(head, nama, nim);
                cout << "Data (nama lama) telah diganti dengan data (nama baru)" << endl;
                break;
            case 6:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                ubahTengah(head, nama, nim, posisi);
                break;
            case 7:
                head = hapusDepan(head);
                break;
            case 8:
                cout << "-Hapus Belakang" << endl;
                head = hapusBelakang(head);
                cout << "Data (nama mahasiswa yang dihapus) berhasil dihapus" << endl;
                break;
            case 9:
                cout << "-Hapus Tengah" << endl;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                head = hapusTengah(head, posisi);
                cout << "Data (nama mahasiswa yang dihapus) berhasil dihapus" << endl;
                break;
            case 10:
                hapusList(head);
                break;
            case 11:
                tampil(head);
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
