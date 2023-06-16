#include <iostream>

using namespace std;

// Struktur data untuk menyimpan informasi pemain
struct Player {
    string name;
    int speed;
    int dribbling;
    int shooting;
    int stamina;
    int passing;
    int physical;
};

// Fungsi untuk mencari tim terbaik dengan atribut terbaik untuk masing-masing posisi
void findBestTeam(Player players[], int n) {
    int maxPivotAttr = -1;
    int maxFlankAttr = -1;
    int maxAnchorAttr = -1;
    int maxKiperAttr = -1;
    int maxPivotIdx = -1;
    int maxFlank1Idx = -1;
    int maxFlank2Idx = -1;
    int maxAnchorIdx = -1;
    int maxKiperIdx = -1;
    int jml = 0;
    // Mencari pemain terbaik untuk posisi pivot
    for (int i = 0; i < n; i++) {
        int pivotAttr = players[i].shooting + players[i].physical;
        if (pivotAttr > maxPivotAttr) {
            maxPivotAttr = pivotAttr;
            maxPivotIdx = i;
        }
        jml++;
    }
    // Mencari pemain terbaik untuk posisi flank 1
    for (int i = 0; i < n; i++) {
        int flankAttr = players[i].speed + players[i].dribbling;
        if (flankAttr > maxFlankAttr) {
            maxFlankAttr = flankAttr;
            maxFlank1Idx = i;
        }
        jml++;
    }
    // Mencari pemain terbaik untuk posisi flank 2
    for (int i = 0; i < n; i++) {
        int flankAttr = players[i].speed + players[i].dribbling;
        if (flankAttr >= maxFlankAttr ) {
            maxFlankAttr = flankAttr;
            maxFlank2Idx = i;
        }
        jml++;
    }
    // Mencari pemain terbaik untuk posisi anchor
    for (int i = 0; i < n; i++) {
        int anchorAttr = players[i].stamina + players[i].passing;
        if (anchorAttr > maxAnchorAttr && i != maxFlank1Idx && i != maxFlank2Idx) {
            maxAnchorAttr = anchorAttr;
            maxAnchorIdx = i;
        }
        jml++;
    }
    // Mencari pemain terbaik untuk posisi kiper
    for (int i = 0; i < n; i++) {
        int kiperAttr = players[i].stamina + players[i].physical;
        if (kiperAttr > maxKiperAttr && i != maxFlank1Idx && i != maxFlank2Idx && i != maxAnchorIdx) {
            maxKiperAttr = kiperAttr;
            maxKiperIdx = i;
        }
        jml++;
    }
    // Menampilkan pemain terbaik untuk masing-masing posisi
    cout << "Tim Terbaik:\n";
    cout << "Pivot: " << players[maxPivotIdx].name << "\n";
    cout << "Flank 1: " << players[maxFlank1Idx].name << "\n";
    cout << "Flank 2: " << players[maxFlank2Idx].name << "\n";
    cout << "Anchor: " << players[maxAnchorIdx].name << "\n";
    cout << "Kiper: " << players[maxKiperIdx].name << "\n\n";
    cout <<"Jumlahkan pengecekan: "<<jml<< "\n";
}

int main() {
    // Menentukan jumlah pemain
    int n = 50;
    // Membuat array pemain
    Player players[50];
    // Mengisi data pemain
    players[0] = {"Agus", 5, 5, 10, 5, 5, 10};
    players[1] = {"Agis", 10, 10, 6, 6, 6, 6};
    players[2] = {"Ages", 5, 5, 10, 10, 6, 6};
    players[3] = {"Agas", 5, 5, 5, 5, 5, 5};
    players[4] = {"Agos", 5, 5, 5, 10, 5, 10};
    players[5] = {"Abi", 5, 5, 5, 5, 5, 5};
    players[6] = {"Abu", 5, 5, 5, 10, 10, 6};
    players[7] = {"Abe", 5, 5, 10, 5, 5, 10};
    players[8] = {"Abo", 5, 5, 5, 5, 5, 5};
    players[9] = {"Aba", 10, 10, 5, 5, 5, 5};
    players[10] = {"Agusx", 0, 0, 0, 0, 0, 0};
    players[11] = {"Andy", 3, 7, 8, 4, 6, 9};
    players[12] = {"Adam", 9, 2, 5, 8, 3, 7};
    players[13] = {"Alex", 7, 6, 4, 3, 9, 2};
    players[14] = {"Aria", 6, 9, 7, 2, 8, 4};
    players[15] = {"Ali", 4, 8, 9, 6, 2, 5};
    players[16] = {"Ava", 2, 4, 6, 9, 7, 3};
    players[17] = {"Amy", 8, 3, 2, 7, 5, 8};
    players[18] = {"Aris", 9, 7, 4, 1, 3, 6};
    players[19] = {"Asya", 1, 6, 8, 5, 4, 7};
    players[20] = {"Arif", 6, 9, 3, 4, 2, 9};
    players[21] = {"Aldo", 5, 3, 6, 9, 7, 1};
    players[22] = {"Alya", 7, 8, 2, 1, 9, 6};
    players[23] = {"Amin", 3, 1, 9, 7, 5, 4};
    players[24] = {"Anya", 9, 6, 7, 2, 1, 8};
    players[25] = {"Ariz", 4, 2, 5, 8, 6, 3};
    players[26] = {"Andi", 2, 4, 9, 1, 8, 7};
    players[27] = {"Ayla", 8, 9, 6, 5, 3, 2};
    players[28] = {"Azka", 1, 7, 3, 6, 4, 9};
    players[29] = {"Adit", 5, 2, 6, 8, 9, 1};
    players[30] = {"Arka", 6, 4, 1, 2, 7, 8};
    players[31] = {"Aria", 9, 6, 5, 7, 1, 3};
    players[32] = {"Alia", 2, 1, 7, 6, 9, 8};
    players[33] = {"Ayra", 4, 9, 3, 5, 8, 2};
    players[34] = {"Agil", 7, 8, 1, 4, 6, 5};
    players[35] = {"Amir", 3, 4, 9, 8, 2, 6};
    players[36] = {"Aura", 8, 2, 7, 6, 4, 1};
    players[37] = {"Arisa", 6, 5, 2, 3, 9, 7};
    players[38] = {"Arin", 1, 7, 4, 9, 8, 5};
    players[39] = {"Aria", 5, 3, 6, 7, 1, 9};
    players[40] = {"Amel", 9, 1, 8, 4, 2, 6};
    players[41] = {"Ayla", 7, 4, 1, 3, 9, 5};
    players[42] = {"Azka", 3, 6, 9, 2, 8, 4};
    players[43] = {"Arka", 4, 9, 2, 6, 1, 8};
    players[44] = {"Aria", 8, 2, 7, 1, 5, 6};
    players[45] = {"Alia", 1, 7, 4, 6, 8, 3};
    players[46] = {"Ayra", 6, 5, 3, 9, 7, 1};
    players[47] = {"Agil", 9, 3, 6, 2, 5, 8};
    players[48] = {"Amir", 2, 9, 1, 4, 6, 7};
    players[49] = {"Aura", 7, 1, 9, 8, 3, 5};
    players[50] = {"Arisa", 5, 4, 6, 7, 1, 3};



    // Mencari tim terbaik
    findBestTeam(players, n);
    return 0;
}
