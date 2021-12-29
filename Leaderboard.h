#pragma once

struct Leaderboard
{
    int cntEasy, cntMed, cntHard;
    float Easy[11], Medium[11], Hard[11];
};

void SaveNewScore(float time, Leaderboard& LB, int dif);
void LoadLeaderboard(Leaderboard& LB);
void SeeLeaderboard(Leaderboard& LB);