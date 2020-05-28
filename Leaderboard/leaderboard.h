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
#include <ctime>

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
        // unit of score
        std::string scoreUnits; 

        // file of save file
        std::string saveFile = "saved_leaderboard.txt";

    public:
        // completed
        Leaderboard(int size, bool score_priority, std::string units) {
            this->maxSize = size;
            this->score_priority = score_priority;
            this->scoreUnits = units;
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
        void info() {
            /*
                Prints the max size, current size, and score priority of the leaderboard.
            */ 
            std::string sp = (this->score_priority == 0) ? "LOW" : "HIGH";
            std::cout << "INFO:" << "\n\tMax size: " << this->maxSize << "\n\tCurrent size: " << this->currentSize << "\n\tScore priority: " << sp << std::endl;
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
            return update;
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
        void addRanking(ranking* r) {
            /*
                Adds the new ranking into the correct spot 
                and updates the rest of the leaderboard
                If added, returns 1. Else returns 0.
            */
            int added = 0;
            if(this->currentSize == 0) {  // if the leaderboard is empty
                this->rankings.push_back(r);
                this->currentSize = this->rankings.size();
                added = 1;
            }
            else if(this->currentSize > 0) {  // not empty
                int i = 0;
                while(i < this->currentSize && added != 1) {
                    if(compareScores(this->rankings[i]->score, r->score) == 1) {  // if rankings[i] is "higher" than r
                        // place r at i
                        this->rankings.insert(this->rankings.begin() + i, r);
                        this->currentSize = this->rankings.size();
                        added = 1;
                    }
                    i++;
                }
            }
            if(added == 0) {    // add to the end
                this->rankings.push_back(r);
                this->currentSize = this->rankings.size();
                added = 1;
            }
            // delete the one that is beyond the rankings size, if there is one
            if(this->currentSize > this->maxSize) {
                // delete the last one
                delete this->rankings[this->currentSize - 1];
                this->rankings.erase(this->rankings.begin() + this->maxSize);
                // resize to maxSize
                this->rankings.resize(this->maxSize);
                this->currentSize = this->rankings.size();
            }
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
                if(score_priority == 1) {   // priority for low
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
                delete this->rankings[i];
            }
            this->rankings.clear();
            this->currentSize = 0;
        }

        // completed
        void printLeaderboard() {
            std::string print = "";
            print += "Leaderboard: (" + std::to_string(this->currentSize) + ")\n"; 
            ranking* r;
            std::time_t t;
            for(int i = 0; i < this->currentSize; i++) {
                r = this->rankings[i];
                t = std::chrono::system_clock::to_time_t(r->time);
                print += std::to_string(i + 1) + ":\t" + r->playerName + "\t" + std::to_string(r->score) + " " + this->scoreUnits + "\t" + std::ctime(&t);
            }
            std::cout << print << std::endl;
        }

        // in progress
        void load() {
            /*
                Repopulate the leaderboard from the given filename
            */

        }

        // in progress
        void save() {
            /*
                Prints leaderboard details into the given file 
                (to be reinitialized from)
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
        int getSize() {
            return this->currentSize;
        }
        bool getScorePriority() {
            return this->score_priority;
        }

};

#endif