/*
    run.cpp
    By Vincent Li <vincentl@asu.edu>
    Version 3/18/2020
*/
#include "leaderboard.h"
#include <time.h>
#include <stdlib.h>

typedef std::chrono::duration<double> millis_type;

using namespace std;

int main(int argc, char** argv) {
    /*
        Leaderboard(..., ...)
        if saved, load()
        checkUpdate(...)
        if update is true, createRanking(..., ..., ...)
            addRanking(...)
            save()
        
    */

    srand(time(NULL));

    /* 
        Creating a Leaderboard of size 10 for the Reaction Speed Game,
        in which the score is a number of seconds to the thousandths,
        and a better score is a smaller score
    */

    // Leaderboard<score type> L(size, score_priority)
    Leaderboard<millis_type> L(10, 0);
    chrono::system_clock::time_point clock = chrono::system_clock::now();

    // add 10 rankings
    cout << "Add 10 scores" << endl;
    L.addRanking(L.createRanking("Player 1", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 2", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 3", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 4", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 5", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 6", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 7", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 8", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 9", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 10", chrono::duration<double>(rand() % 10 + 1)));

    L.printLeaderboard();

    // add 10 more
    cout << "Add 10 more scores" << endl;
    L.addRanking(L.createRanking("Player 11", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 12", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 13", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 14", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 15", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 16", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 17", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 18", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 19", chrono::duration<double>(rand() % 10 + 1)));
    L.addRanking(L.createRanking("Player 20", chrono::duration<double>(rand() % 10 + 1)));
    
    L.printLeaderboard();

    return 0;
}