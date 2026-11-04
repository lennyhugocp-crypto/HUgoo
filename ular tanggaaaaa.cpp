
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===============================
// CEK ULAR DAN TANGGA
// ===============================
int ularTangga(int posisi) {

    // TANGGA
    if (posisi == 3) {
        cout << "TANGGA! 3 -> 11\n";
        return 11;
    }
    else if (posisi == 8) {
        cout << "TANGGA! 8 -> 17\n";
        return 17;
    }
    else if (posisi == 12) {
        cout << "TANGGA! 12 -> 19\n";
        return 19;
    }
    else if (posisi == 17) {
        cout << "TANGGA! 17 -> 25\n";
        return 25;
    }

    // ULAR
    else if (posisi == 5) {
        cout << "ULAR! 5 -> 2\n";
        return 2;
    }
    else if (posisi == 14) {
        cout << "ULAR! 14 -> 5\n";
        return 5;
    }
    else if (posisi == 19) {
        cout << "ULAR! 19 -> 9\n";
        return 9;
    }
    else if (posisi == 29) {
        cout << "ULAR! 29 -> 21\n";
        return 21;
    }

    return posisi;
}


// ===============================
// MENAMPILKAN ISI PETAK
// ===============================
void isiPetak(int nomor, int p1, int p2) {

    // Pemain
    if (p1 == nomor && p2 == nomor) {
        cout << "P1/P2";
    }
    else if (p1 == nomor) {
        cout << " P1  ";
    }
    else if (p2 == nomor) {
        cout << " P2  ";
    }

    // Finish
    else if (nomor == 30) {
        cout << "30 F ";
    }

    // Tangga
    else if (nomor == 3 ||
             nomor == 8 ||
             nomor == 12 ||
             nomor == 17) {

        cout << nomor << " T ";

        if (nomor < 10)
            cout << " ";
    }

    // Ular
    else if (nomor == 5 ||
             nomor == 14 ||
             nomor == 19 ||
             nomor == 29) {

        cout << nomor << " U ";

        if (nomor < 10)
            cout << " ";
    }

    // Petak biasa
    else {
        cout << " " << nomor << "  ";

        if (nomor < 10)
            cout << " ";
    }
}


// ===============================
// MENAMPILKAN MAP
// ===============================
void tampilkanMap(int p1, int p2) {

    cout << "\n";
    cout << "==================== ULAR TANGGA ====================\n";

    // 30 - 25
    cout << "+-------+-------+-------+-------+-------+-------+\n";

    for (int i = 30; i >= 25; i--) {
        cout << "|";
        isiPetak(i, p1, p2);
        cout << "   ";
    }

    cout << "|\n";
    cout << "+-------+-------+-------+-------+-------+-------+\n";


    // 19 - 24
    for (int i = 19; i <= 24; i++) {
        cout << "|";
        isiPetak(i, p1, p2);
        cout << "   ";
    }

    cout << "|\n";
    cout << "+-------+-------+-------+-------+-------+-------+\n";


    // 18 - 13
    for (int i = 18; i >= 13; i--) {
        cout << "|";
        isiPetak(i, p1, p2);
        cout << "   ";
    }

    cout << "|\n";
    cout << "+-------+-------+-------+-------+-------+-------+\n";


    // 7 - 12
    for (int i = 7; i <= 12; i++) {
        cout << "|";
        isiPetak(i, p1, p2);
        cout << "   ";
    }

    cout << "|\n";
    cout << "+-------+-------+-------+-------+-------+-------+\n";


    // 6 - 1
    for (int i = 6; i >= 1; i--) {
        cout << "|";
        isiPetak(i, p1, p2);
        cout << "   ";
    }

    cout << "|\n";
    cout << "+-------+-------+-------+-------+-------+-------+\n";

    cout << "\nKeterangan:\n";
    cout << "P1 = Pemain 1\n";
    cout << "P2 = Pemain 2\n";
    cout << "F  = Finish\n";
    cout << "U  = Ular\n";
    cout << "T  = Tangga\n";
}


// ===============================
// MAIN
// ===============================
int main() {

    srand(time(0));

    int p1 = 1;
    int p2 = 1;

    int giliran = 1;

    cout << "=====================================\n";
    cout << "          GAME ULAR TANGGA\n";
    cout << "=====================================\n";

    while (p1 != 30 && p2 != 30) {

        tampilkanMap(p1, p2);

        cout << "\n-------------------------------------\n";
        cout << "Giliran Pemain " << giliran << endl;
        cout << "Tekan ENTER untuk melempar dadu...";

        cin.get();

        int dadu = rand() % 6 + 1;

        cout << "\nDadu = " << dadu << endl;


        // PEMAIN 1
        if (giliran == 1) {

            int posisiBaru = p1 + dadu;

            if (posisiBaru <= 30) {

                p1 = posisiBaru;

                cout << "P1 bergerak ke petak "
                     << p1 << endl;

                p1 = ularTangga(p1);
            }
            else {
                cout << "P1 tidak bergerak karena "
                     << "melewati petak 30.\n";
            }

            if (p1 == 30)
                break;

            giliran = 2;
        }


        // PEMAIN 2
        else {

            int posisiBaru = p2 + dadu;

            if (posisiBaru <= 30) {

                p2 = posisiBaru;

                cout << "P2 bergerak ke petak "
                     << p2 << endl;

                p2 = ularTangga(p2);
            }
            else {
                cout << "P2 tidak bergerak karena "
                     << "melewati petak 30.\n";
            }

            if (p2 == 30)
                break;

            giliran = 1;
        }
    }


    // HASIL AKHIR
    tampilkanMap(p1, p2);

    cout << "\n=====================================\n";

    if (p1 == 30) {
        cout << "          P1 MENANG!\n";
    }
    else {
        cout << "          P2 MENANG!\n";
    }

    cout << "=====================================\n";

    return 0;
}
