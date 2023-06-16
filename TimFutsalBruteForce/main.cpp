#include <iostream>

using namespace std;

// Struktur data untuk menyimpan informasi pemain
struct Player {
    char name[50];
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

    int jumlah = 0;

    // Melakukan iterasi untuk semua kombinasi pemain
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                for (int l = 0; l < n; l++) {
                    if (l == i || l == j || l == k) continue;

                    for (int m = 0; m < n; m++) {
                        if (m == i || m == j || m == k || m == l) continue;

                        // Menghitung total atribut untuk masing-masing posisi
                        int pivotAttr = players[i].shooting + players[i].physical;
                        int flank1Attr = players[j].speed + players[j].dribbling;
                        int flank2Attr = players[k].speed + players[k].dribbling;
                        int anchorAttr = players[l].stamina + players[l].passing;
                        int kiperAttr = players[m].stamina + players[m].physical;

                        // Memperbarui atribut maksimum dan indeks pemain terbaik
                        int maxTotal = -1;
                        if (pivotAttr > maxPivotAttr) {
                            maxPivotAttr = pivotAttr;
                            maxPivotIdx = i;
                        }

                        if (flank1Attr > maxFlankAttr) {
                            maxFlankAttr = flank1Attr;
                            maxFlank1Idx = j;
                        }

                        if (flank2Attr >= maxFlankAttr) {
                            if (k!=maxFlank1Idx){
                                maxFlankAttr = flank2Attr;
                                maxFlank2Idx = k;
                            }

                        }

                        if (anchorAttr > maxAnchorAttr) {
                            maxAnchorAttr = anchorAttr;
                            maxAnchorIdx = l;
                        }

                        if (kiperAttr > maxKiperAttr) {
                            maxKiperAttr = kiperAttr;
                            maxKiperIdx = m;
                        }
                        jumlah++;
                    }
                }
            }
        }
    }

    // Menampilkan tim terbaik
    cout << "Tim Terbaik:\n";
    cout << "Pivot: " << players[maxPivotIdx].name << "\n";
    cout << "Flank 1: " << players[maxFlank1Idx].name << "\n";
    cout << "Flank 2: " << players[maxFlank2Idx].name << "\n";
    cout << "Anchor: " << players[maxAnchorIdx].name << "\n";
    cout << "Kiper: " << players[maxKiperIdx].name << "\n\n";
    cout << "Jumlah pengecekan: " << jumlah << "\n";
}

int main() {
    // Menyiapkan data pemain
    Player players[50] = {
        {"Agus", 5, 5, 10, 5, 5, 10},
        {"Agis", 10, 10, 6, 6, 6, 6},
        {"Ages", 5, 5, 10, 10, 6, 6},
        {"Agas", 5, 5, 5, 5, 5, 5},
        {"Agos", 5, 5, 5, 10, 5, 10},
        {"Abi", 5, 5, 5, 5, 5, 5},
        {"Abu", 5, 5, 5, 10, 10, 6},
        {"Abe", 5, 5, 10, 5, 5, 10},
        {"Abo", 5, 5, 5, 5, 5, 5},
        {"Aba", 10, 10, 5, 5, 5, 5},
        {"Aba1", 0, 0, 0, 0, 0, 0},
        {"Aba2", 0, 0, 0, 0, 0, 0},
        {"Aba3", 0, 0, 0, 0, 0, 0},
        {"Aba4", 0, 0, 0, 0, 0, 0},
        {"Aba5", 0, 0, 0, 0, 0, 0},
        {"Aba16", 0, 0, 0, 0, 0, 0},
        {"Aba17", 0, 0, 0, 0, 0, 0},
        {"Aba18", 0, 0, 0, 0, 0, 0},
        {"Aba19", 0, 0, 0, 0, 0, 0},
        {"Aba20", 0, 0, 0, 0, 0, 0},
        {"Aba1", 0, 0, 0, 0, 0, 0},
        {"Aba2", 0, 0, 0, 0, 0, 0},
        {"Aba3", 0, 0, 0, 0, 0, 0},
        {"Aba4", 0, 0, 0, 0, 0, 0},
        {"Aba5", 0, 0, 0, 0, 0, 0},
        {"Aba16", 0, 0, 0, 0, 0, 0},
        {"Aba17", 0, 0, 0, 0, 0, 0},
        {"Aba18", 0, 0, 0, 0, 0, 0},
        {"Aba19", 0, 0, 0, 0, 0, 0},
        {"Aba30", 0, 0, 0, 0, 0, 0},
        {"Aba1", 0, 0, 0, 0, 0, 0},
        {"Aba2", 0, 0, 0, 0, 0, 0},
        {"Aba3", 0, 0, 0, 0, 0, 0},
        {"Aba4", 0, 0, 0, 0, 0, 0},
        {"Aba5", 0, 0, 0, 0, 0, 0},
        {"Aba16", 0, 0, 0, 0, 0, 0},
        {"Aba17", 0, 0, 0, 0, 0, 0},
        {"Aba18", 0, 0, 0, 0, 0, 0},
        {"Aba19", 0, 0, 0, 0, 0, 0},
        {"Aba40", 0, 0, 0, 0, 0, 0},
        {"Aba1", 0, 0, 0, 0, 0, 0},
        {"Aba2", 0, 0, 0, 0, 0, 0},
        {"Aba3", 0, 0, 0, 0, 0, 0},
        {"Aba4", 0, 0, 0, 0, 0, 0},
        {"Aba5", 0, 0, 0, 0, 0, 0},
        {"Aba16", 0, 0, 0, 0, 0, 0},
        {"Aba17", 0, 0, 0, 0, 0, 0},
        {"Aba18", 0, 0, 0, 0, 0, 0},
        {"Aba19", 0, 0, 0, 0, 0, 0},
        {"Aba50", 0, 0, 0, 0, 0, 0}
    };

    // Memanggil fungsi untuk mencari tim terbaik
    findBestTeam(players, 50);

    return 0;
}
