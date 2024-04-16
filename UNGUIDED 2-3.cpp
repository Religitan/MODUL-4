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
    
    head = tambahDepan(head, "Jawad", "23300001");  
    head = tambahBelakang(head, "Religita", "2311102025"); 
    head = tambahTengah(head, "Farrel", "23300003", 2); 
    head = tambahTengah(head, "Denis", "23300005", 3); 
    head = tambahTengah(head, "Anis", "23300008", 4); 
    head = tambahBelakang(head, "Bowo", "23300015"); 
    head = tambahBelakang(head, "Gahar", "23300040"); 
    head = tambahBelakang(head, "Udin", "23300048"); 
    head = tambahBelakang(head, "Ucok", "23300050"); 
    head = tambahBelakang(head, "Budi", "23300099"); 
    
      char choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "a) Tambahkan data berikut diantara Farrel dan Denis" << endl;
        cout << "b) Hapus data Denis" << endl;
        cout << "c) Tambahkan data berikut di awal" << endl;
        cout << "d) Tambahkan data berikut di akhir" << endl;
        cout << "e) Ubah data Udin menjadi data berikut" << endl;
        cout << "f) Ubah data terakhir menjadi berikut" << endl;
        cout << "g) Hapus data awal" << endl;
        cout << "h) Ubah data awal menjadi berikut" << endl;
        cout << "i) Hapus data akhir" << endl;
        cout << "j) Tampilkan seluruh data" << endl;
        cout << "k) Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
            case 'a':
            {
                string nama, nim;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                head = tambahTengah(head, nama, nim, 3);
                break;
            }
            case 'b':
            {
                head = hapusTengah(head, 4);
                break;
            }
            case 'c':
            {
                string nama, nim;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                head = tambahDepan(head, nama, nim);
                break;
            }
            case 'd':
            {
                string nama, nim;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                head = tambahBelakang(head, nama, nim);
                break;
            }
            case 'e':
            {
                Node *bantu = head;
                while (bantu != nullptr)
                {
                    if (bantu->nama == "Udin" && bantu->nim == "23300048")
                    {
                        bantu->nama = "Idin";
                        bantu->nim = "23300045";
                        break;
                    }
                    bantu = bantu->next;
                }
                break;
            }
            case 'f':
            {
                Node *bantu = head;
                while (bantu->next != nullptr)
                {
                    bantu = bantu->next;
                }
                bantu->nama = "Lucy";
                bantu->nim = "23300101";
                break;
            }
            case 'g':
            {
                head = hapusDepan(head);
                break;
            }
            case 'h':
            {
                head->nama = "Bagas";
                head->nim = "2330002";
                break;
            }
            case 'i':
            {
                Node *bantu = head;
                while (bantu->next->next != nullptr)
                {
                    bantu = bantu->next;
                }
                delete bantu->next;
                bantu->next = nullptr;
                break;
            }
            case 'j':
            {
                tampil(head);
                break;
            }
            case 'k':
            {
                break;
            }
            default:
            {
                cout << "Pilihan tidak valid!" << endl;
            }
        }
    } while (choice != 'k');

    hapusList(head);

    return 0;
}
