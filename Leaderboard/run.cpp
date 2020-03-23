/*
    run.cpp
    By Vincent Li <vincentl@asu.edu>
    Version 3/18/2020
*/
#include "leaderboard.h"
#include <time.h>

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

    /* 
        Creating a Leaderboard of size 20 for the Reaction Speed Game,
        in which the score is a number of seconds to the thousandths,
        and a better score is a smaller score
    */

    chrono::system_clock::time_point clock;

    // Leaderboard<score type> L(size, score_priority)
    Leaderboard<millis_type> L(20, 0);

    clock = chrono::system_clock::now();
    string name = "First";
    chrono::duration<double> score = chrono::duration<double>(5.0);
    L.addRanking(L.createRanking("First", score));

    

    return 0;
}