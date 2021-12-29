#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

#include "Leaderboard.h"

void SaveNewScore(float time, Leaderboard& LB, int dif) {
    switch(dif) {
    case 1:
        LB.Easy[LB.cntEasy++] = time;
        sort(LB.Easy, LB.Easy + LB.cntEasy);
        if (LB.cntEasy == 11)
            LB.cntEasy--;
        break;
    case 2:
        LB.Medium[LB.cntMed++] = time;
        sort(LB.Medium, LB.Medium + LB.cntMed);
        if (LB.cntMed == 11)
            LB.cntMed--;
        break;
    case 3:
        LB.Hard[LB.cntHard++] = time;
        sort(LB.Hard, LB.Hard + LB.cntHard);
        if (LB.cntHard == 11)
            LB.cntHard--;
        break;
    }
    ofstream fout;
    fout.open("Leaderboard.txt");
    fout << LB.cntEasy << ' ' << LB.cntMed << ' ' << LB.cntHard << endl;
    for(int i = 0; i < LB.cntEasy; i++) {
        fout << LB.Easy[i] << endl;
    }
    for(int i = 0; i < LB.cntMed; i++) {
        fout << LB.Medium[i] << endl;
    }
    for(int i = 0; i < LB.cntHard; i++) {
        fout << LB.Hard[i] << endl;
    }
    fout.close();
}

void LoadLeaderboard(Leaderboard& LB) {
    ifstream fin;
    fin.open("Leaderboard.txt");
    fin >> LB.cntEasy >> LB.cntMed >> LB.cntHard;
    for(int i = 0; i < LB.cntEasy; i++) {
        fin >> LB.Easy[i];
    }
    for(int i = 0; i < LB.cntMed; i++) {
        fin >> LB.Medium[i];
    }
    for(int i = 0; i < LB.cntHard; i++) {
        fin >> LB.Hard[i];
    }
    fin.close();
}

void SeeLeaderboard(Leaderboard& LB) {
    LoadLeaderboard(LB);
    system("cls");
    cout << "Easy:\n";
    for(int i = 0; i < LB.cntEasy; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Easy[i] << " secs.\n";
    }
    cout << "Medium:\n";
    for(int i = 0; i < LB.cntMed; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Medium[i] << " secs.\n";
    }
    cout << "Hard:\n";
    for(int i = 0; i < LB.cntHard; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Hard[i] << " secs.\n";
    }
    system("pause");
}