// leaderboard.h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <time.h> // or ctime


typedef std::chrono::time_point<std::chrono::system_clock> tp_clock;

class Leaderboard {
    private:
        int size = 20;
        // struct representing player name, score, and time
        typedef struct ranking {
            std::string playerName;
            std::string score;
            std::time_t time;
        } ranking;
        // array of 20 rankings
        ranking rankings[];

    public:
        void reinitialize(std::string filename) {
            /*
                Repopulate the leaderboard from the given filename
            */

        }

        void clear() {
            /*
                Clear the leaderboard
            */

        }

        ranking* createRanking(std::string pname, std::string newscore, time_t when) {
            /*
                Creates a new ranking struct with the inputs and returns its address
            */
            ranking newRanking;



            return &newRanking;
        }

        int update(std::string newscore) {
            /*
                Checks if the leaderboard must be updated with the new score
                Returns 0 if false, 1 if true
            */

        }

        int addRanking(ranking r) {
            /*
                Adds the new ranking into the correct spot 
                and updates the rest of the leaderboard
            */
            int status = 0;


            return status;
        }

        std::string getPlayerName(int rank) {
            /*
                get player name at rank #
            */
            return rankings[rank - 1].playerName;
        }
        std::string getScore(int rank) {
            /*
                get score at rank #
            */
            return rankings[rank - 1].score;
        }
        time_t getTime(int rank) {
            /*
                get the time at rank #
            */
            return rankings[rank - 1].time;
        }
        std::string getTimeString(int rank) {
            /*
                get the time at rank # in std::std::string form (dayname month day hr:day:sec year)
            */
            return std::ctime(&(rankings[rank - 1].time));
        }

};