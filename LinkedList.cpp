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

void addTeam(TeamNode*& head, string teamName) {
    TeamNode* newTeam = new TeamNode;
    newTeam->teamName = teamName;
    newTeam->playerCount = 0;
    newTeam->next = nullptr;

    if (head == nullptr) {
        head = newTeam;
    } else {
        TeamNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTeam;
    }
    cout << "Tim '" << teamName << "' berhasil ditambahkan!\n";
}

void displayRegisteredTeams(TeamNode* head) {
    if (head == nullptr) {
        cout << "Tidak ada tim yang terdaftar!\n";
        return;
    }

    cout << "\n=== DAFTAR TIM TERDAFTAR ===\n";
    TeamNode* current = head;
    int number = 1;

    while (current != nullptr) {
        cout << number << ". " << current->teamName 
             << " (" << current->playerCount << "/5 player)\n";
        current = current->next;
        number++;
    }
    cout << "\nTotal tim terdaftar: " << number - 1 << "\n";
}

bool removeTeam(TeamNode*& head, string teamName) {
    if (head == nullptr) {
        cout << "Tidak ada tim yang terdaftar!\n";
        return false;
    }

    if (head->teamName == teamName) {
        TeamNode* temp = head;
        head = head->next;
        delete temp;
        cout << "\nTim '" << teamName << "' berhasil dihapus!\n";
        return true;
    }

    TeamNode* current = head;
    while (current->next != nullptr && current->next->teamName != teamName) {
        current = current->next;
    }

    if (current->next != nullptr) {
        TeamNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "\nTim '" << teamName << "' berhasil dihapus!\n";
        return true;
    }

    cout << "\nTim '" << teamName << "' tidak ditemukan dalam daftar!\n";
    return false;
}

bool addPlayerToTeam(TeamNode* head, string teamName, string nickname, string id, string server) {
    TeamNode* current = head;
    while (current != nullptr) {
        if (current->teamName == teamName) {
            if (current->playerCount >= 5) {
                cout << "Tim '" << teamName << "' sudah penuh (5 player)!\n";
                return false;
            }
            current->players[current->playerCount] = {nickname, id, server};
            current->playerCount++;
            cout << "Player '" << nickname << "' berhasil ditambahkan ke tim '" << teamName << "'!\n";
            return true;
        }
        current = current->next;
    }
    cout << "Tim '" << teamName << "' tidak ditemukan!\n";
    return false;
}


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
