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

    // Leaderboard<score type> L(size, score_priority, scoreUnits)
    Leaderboard<double> L(5, 0, "s");
    chrono::system_clock::time_point clock = chrono::system_clock::now();

    L.info();

    // add 5 rankings
    cout << endl << "Add 5 scores" << endl;
    L.addRanking(L.createRanking("Player 1", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 2", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 3", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 4", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 5", chrono::duration<double>(rand() % 20 + 1).count()));
    L.info();
    L.printLeaderboard();

    // add 5 more
    cout << endl << "Add 5 more scores" << endl;
    L.addRanking(L.createRanking("Player 6", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 7", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 8", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 9", chrono::duration<double>(rand() % 20 + 1).count()));
    L.addRanking(L.createRanking("Player 10", chrono::duration<double>(rand() % 20 + 1).count()));
    L.info();
    L.printLeaderboard();

    // clear
    cout << endl << "Clear" << endl;
    L.clear();
    L.info();
    L.printLeaderboard();



    return 0;
}