/*
    leaderboard.h
    By Vincent Li <vincentl@asu.edu>
*/
#pragma once
#ifndef GUARD
#define GUARD

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <vector>

typedef std::chrono::time_point<std::chrono::system_clock> tp_clock;

template <typename T>   // for score type (int, string, ...)

class Leaderboard {
    private:
        // struct representing player name, score, and time
        typedef struct ranking {
            std::string playerName;
            T score;
            tp_clock time;
        } ranking;

        // leaderboard size
        int maxSize;
        int currentSize;
        
        // vector of rankings
        std::vector<ranking*> rankings;
        
        // scoring priority. 0 if lower score is better, 1 if higher score is better
        bool score_priority;

    public:
        // completed
        Leaderboard(int size, bool score_priority) {
            this->maxSize = size;
            this->score_priority = score_priority;
            this->currentSize = 0;
        }

        // completed
        ~Leaderboard() {
            save();
            this->rankings.clear();
            this->maxSize = 0;
            this->currentSize = 0;
        }

        // completed
        bool checkUpdate(T newscore) {
            /*
                Checks if the leaderboard must be updated with the new score
                Returns true or false
            */
            bool update = false;
            int i = 0;
            while(i < maxSize && !update) {
                if(i >= currentSize) {  // found empty spot
                    update = true;
                }
                else if(compareScores(this->rankings[i]->score, newscore)) {    // found a lower score
                    update = true;
                }
                i++;
            }
        }

        // completed
        ranking* createRanking(std::string pname, T newscore) {
            /*
                Creates a new ranking struct with the inputs and returns its address
            */
            ranking* r = new ranking;
            r->playerName = pname;
            r->score = newscore;
            r->time = std::chrono::system_clock::now();

            return r;
        }

        // completed
        int addRanking(ranking* r) {
            /*
                Adds the new ranking into the correct spot 
                and updates the rest of the leaderboard
                If added, returns 1. Else returns 0.
            */
            bool added = false;
            int i = 0;

            while(i < this->currentSize && !added) { // while within size and not added
                // if the spot is empty, or if the vector is empty
                if(currentSize == 0 || this->rankings[i] == NULL) {
                    this->rankings.push_back(r);
                    this->currentSize = this->rankings.size();
                    added = true;
                }
                else if(compareScores(this->rankings[i]->score, r->score) == 1) {  // if rankings[i] is "higher" than r
                    // place r at i
                    this->rankings.insert(rankings.begin() + i, r);
                    this->currentSize = this->rankings.size();
                    // delete the one that is beyond the rankings size, if there is one
                    if(this->currentSize == this->maxSize) {
                        delete this->rankings[this->currentSize];
                        // resize to size
                        this->rankings.resize(this->currentSize);
                        this->rankings.shrink_to_fit();
                    }
                    added = true;
                }
                i++;
            }

            return added;
        }

        // completed
        int compareScores(T A, T B) {
            /*
                If score A is "higher" than or equal to B, return 1. Otherwise return 0.
            */
            int compare = 0;
            if(A == B) {
                compare = 1;    
            }
            else {
                if(score_priority == 0) {   // priority for low
                    compare = (A < B) ? 1:0;
                }
                else {
                    compare = (A > B) ? 1:0;
                }
            }
            return compare;
        }

        // completed
        void clear() {
            /*
                Clear the leaderboard
            */
            for(int i = 0; i < this->currentSize; i++) {
                delete this->*(rankings[i]);
            }
            this->rankings.clear();
            this->currentSize = 0;
        }


        void printLeaderboard() {
            for(int i = 0; i < this->currentSize; i++) {

            }
        }

        void load(std::string filename = "saved_leaderboard.txt") {
            /*
                Repopulate the leaderboard from the given filename
            */

        }

        void save(std::string filename = "saved_leaderboard.txt") {
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

        // getters and setters
        std::string getPlayerName(int rank) {
            /*
                get player name at rank #
            */
            return this->rankings[rank - 1]->playerName;
        }
        T getScore(int rank) {
            /*
                get score at rank #
            */
            return this->rankings[rank - 1]->score;
        }
        time_t getTime(int rank) {
            /*
                get the time at rank #
            */
            return this->rankings[rank - 1]->time;
        }
        std::string getTimeString(int rank) {
            /*
                get the time at rank # in std::std::string form (dayname month day hr:day:sec year)
            */
            return std::ctime(&(this->rankings[rank - 1]->time));
        }
        int getSize() {
            return this->currentSize;
        }
        int setSize(int size) {
            this->currentSize = size;
        }
        bool getScore_Priority() {
            return this->score_priority;
        }
        void setScore_Priority(bool score_priority) {
            this->score_priority = score_priority;
        }

};

#endif