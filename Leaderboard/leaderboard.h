// leaderboard.h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <time.h> // or ctime

typedef std::chrono::time_point<std::chrono::system_clock> tp_clock;

class Leaderboard {
    template <typename T>   // for score type (int, string, ...)
    private:
        // struct representing player name, score, and time
        typedef struct ranking {
            std::string playerName;
            T score;
            std::time_t time;
        } ranking;
        // leaderboard size
        int size = 20;
        // array of 20 rankings
        ranking* rankings[];
        // scoring priority. 0 if lower score is better, 1 if higher score is better
        std::bool score_priority;

    public:
        Leaderboard(int size, bool score_priority) {
            this->size = size;
            this->score_priority = score_priority;
        }

        void reinitialize(std::string filename) {
            /*
                Repopulate the leaderboard from the given filename
            */

        }

        void record(std::string filename) {
            /*
                Prints leaderboard details into the given file 
                (to be reinitialized from)
            */

            
        }

        void reSort() {
            /*
                Resort the leaderboard and 
                free/delete any rankings past the leaderboard size
            */


        }

        void clear() {
            /*
                Clear the leaderboard
            */

        }

        ranking* createRanking(std::string pname, T newscore, time_t when) {
            /*
                Creates a new ranking struct with the inputs and returns its address
            */
            ranking newRanking;



            return &newRanking;
        }

        int checkUpdate(T newscore) {
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

        int compareScore(T A, T B) {
            /*
                If score A is "higher" than B, return 0. Otherwise return 1.
            */
            int compare;
            if(score_priority == 0) {   // priority for low
                compare = (A < B) ? 0:1;
            }
            else {
                compare = (A > B) ? 0:1;
            }
            return compare;
        }

        std::string getPlayerName(int rank) {
            /*
                get player name at rank #
            */
            return rankings[rank - 1]->playerName;
        }
        std::string getScore(int rank) {
            /*
                get score at rank #
            */
            return rankings[rank - 1]->score;
        }
        time_t getTime(int rank) {
            /*
                get the time at rank #
            */
            return rankings[rank - 1]->time;
        }
        std::string getTimeString(int rank) {
            /*
                get the time at rank # in std::std::string form (dayname month day hr:day:sec year)
            */
            return std::ctime(&(rankings[rank - 1]->time));
        }
        int getSize() {
            return size;
        }
        int setSize(int size) {
            this->size = s;
        }
        std::bool getScore_Priority() {
            return score_priority;
        }
        void setScore_Priority(std::bool score_priority) {
            this->score_priority = score_priority;
        }

};