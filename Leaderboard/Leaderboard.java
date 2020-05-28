/**
 *  leaderboard.java
 *  By Vincent Li <vincentl@asu.edu>
 */

import java.util.ArrayList;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Leaderboard<T extends Comparable<? super T>> implements java.io.Serializable {

    private static final long serialVersionUID = 1L;

    private class ranking {
        String playerName;
        T score;
        String time;

        public ranking(String playerName, T score, String time) {
            this.playerName = playerName;
            this.score = score;
            this.time = time;
        }
    }

    // leaderboard size
    int maxSize;
    int currentSize;

    // list of rankings
    ArrayList<ranking> rankings;

    // scoring priority. 0 if lower score is better, 1 if higher is better
    int score_priority;
    // unit of score
    String scoreUnits;

    // file of save file
    String saveFile = "saved_leaderboard.txt";

    ////////////////////////////

    public Leaderboard(int size, int score_priority, String units) {
        rankings = new ArrayList<ranking>();
        this.maxSize = size;
        this.score_priority = score_priority;
        this.scoreUnits = units;
        this.currentSize = 0;
    }

    public void info() {
        /*
            Prints the max size, current size, and score priority of the leaderboard.
        */
        String sp = "";
        if(this.score_priority == 0) sp = "LOW";
        else sp = "HIGH";
        System.out.println("INFO: " + "\n\tMax size: " + this.maxSize + "\n\tCurrent size: " + this.currentSize + "\n\tScore priority: " + sp);
    }

    public boolean checkUpdate(T newscore) {
        /*
            Checks if the leaderboard must be updated with the new score
            Returns true or false
        */
        boolean update = false;
        int i = 0;
        while(i < maxSize && !update) {
            if(i >= currentSize) {  // found empty spot
                update = true;
            }
            else if(compareScores(this.rankings.get(i).score, newscore)  == 1) {
                update = true;
            }
            i++;
        }
        return update;
    }

    public ranking createRanking(String pname, T newscore) {
        /*
            Creates a new ranking  with the inputs and returns its address
        */
        LocalDateTime time = LocalDateTime.now();
        DateTimeFormatter format = DateTimeFormatter.ofPattern("MM/dd/yyyy hh:mm a");
        String now = time.format(format);
        ranking r = new ranking(pname, newscore, now);
        return r;
    }

    public void addRanking(ranking r) {
        /*
            Adds the new ranking into the correct spot 
            and updates the rest of the leaderboard
            If added, returns 1. Else returns 0.
        */
        boolean added = false;
        if(this.currentSize == 0) { // if the leaderboard is empty
            this.rankings.add(r);
            this.currentSize = this.rankings.size();
            added = true;
        }
        else if(this.currentSize > 0) { // not empty
            int i = 0;
            while(i < this.currentSize && !added) {
                if(compareScores(this.rankings.get(i).score, r.score) == 1) {   // if rankings[i] is "higher" than r
                    // place r at i
                    this.rankings.add(i, r);
                    this.currentSize = this.rankings.size();
                    added = true;

                }
                i++;
            }
        }
        if(!added) {    // add to end
            this.rankings.add(r);
            this.currentSize = this.rankings.size();
            added = true;
        }
        // delete the one that is beyond the rankings size, if there is one
        if(this.currentSize > this.maxSize) {
            // delete the last one
            this.rankings.remove(currentSize - 1);
            // resize to maxSize
            this.rankings.trimToSize();
            this.currentSize = this.rankings.size();
        }
    }

    // might need to change
    public int compareScores(T A, T B) {
        /*
            If score A is "higher" than or equal to B, return 1. Otherwise return 0.
        */
        int compare = 0;
        if(A.compareTo(B) == 0) {    // A == B
            compare = 1;
        }
        else {
            if(score_priority == 1) {
                if(A.compareTo(B) < 0) compare = 1;
                else compare = 0;
            }
            else {
                if(A.compareTo(B) > 0) compare = 1;
                else compare = 0;
            }
        }
        return compare;
    }

    void clearLeaderboard() {
        for(int i = 0; i < this.currentSize; i++) {
            rankings.remove(0);
        }
        this.currentSize = 0;
    }

    void printLeaderboard() {
        String print = "";
        print += "Leaderboard: (" + this.currentSize + ")\n";
        ranking r;
        for(int i = 0; i < this.currentSize; i++) {
            r = this.rankings.get(i);
            print += (i + 1) + ":\t" + r.playerName + "\t" + r.score + " " + this.scoreUnits + "\t" + r.time + "\n";
        }
        
        System.out.println(print);
    }

    // getters and setters
    public String getPlayerName(int rank) {
        /*
            get player name at rank #
        */
        return this.rankings.get(rank - 1).playerName;
    }
    public T getScore(int rank) {
        /*
            get score at rank #
        */
        return this.rankings.get(rank - 1).score;
    }
    public String getTime(int rank) {
        /*
            get the time at rank #
        */
        return this.rankings.get(rank - 1).time;
    }
    public int getSize() {
        return this.currentSize;
    }
    public int getScorePriority() {
        return this.score_priority;
    }
    
}