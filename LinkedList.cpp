#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Player {
    string nickname;
    string id;
    string server;
};


struct TeamNode {
    string teamName;
    Player players[5];  
    int playerCount;    
    TeamNode* next;
    };

void showMenu() {
    cout << "\n=== SISTEM PENDAFTARAN TURNAMEN MOBILE LEGENDS ===\n";
    cout << "1. Tambah Tim Baru\n";
    cout << "2. Lihat & Hapus Tim\n";
    cout << "3. Insert Tim di Posisi Tertentu\n";
    cout << "4. Kelola Player Tim\n";
    cout << "5. Tampilkan Semua Tim (Detail)\n";
    cout << "6. Tampilkan Detail Tim Tertentu\n";
    cout << "7. Keluar\n";
    cout << "Pilih menu (1-7): ";
}
