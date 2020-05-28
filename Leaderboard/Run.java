/**
 *  Run.java
 *  By Vincent Li <vincentl@asu.edu>
 */

import java.util.Random;
//import java.time.Duration;
import java.io.*;

public class Run {
    public static void main(String[] args) {

        // Leaderboard<score type> = new Leaderboard<>(size, score priority, score unit)
        Leaderboard<Float> L = new Leaderboard<>(5, 0, "s");
        Random rand = new Random();

        L.info();

        // add 5 rankings
        System.out.println("Add 5 scores");
        L.addRanking(L.createRanking("Player 1", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 2", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 3", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 4", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 5", 1 + 8 * rand.nextFloat()));
        L.printLeaderboard();
        L.info();

        // add 5 more
        System.out.println("Add 5 more scores");
        L.addRanking(L.createRanking("Player 6", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 7", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 8", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 9", 1 + 8 * rand.nextFloat()));
        L.addRanking(L.createRanking("Player 10", 1 + 8 * rand.nextFloat()));
        L.printLeaderboard();
        L.info();

        // try serializing
        //save(L);

        // try deserializing
        //L = load();

        // clear
        System.out.println("Clear");
        L.clearLeaderboard();
        L.printLeaderboard();
        L.info();
    }

    // in progress
    public static void save(Leaderboard<Float> L) {
        /*
         * Serialize the object to saved_leaderboard.txt.
         */
        try {
            final FileOutputStream outfile = new FileOutputStream("saved_leaderboard.txt");
            System.out.println("1");
            final ObjectOutputStream obj = new ObjectOutputStream(outfile);
            System.out.println("1");
            obj.writeObject(L);
            System.out.println("1");
            obj.close();
            System.out.println("1");
            outfile.close();
        } 
        catch(final IOException i) {
            System.out.println("Leaderboard cannot be saved.");
        }
    }

    // in progress
    public static Leaderboard<Float> load() {
        /**
         * Deserialize from saved_leaderboard.txt.
         */
        Leaderboard<Float> L = null;
        try {
            final FileInputStream infile = new FileInputStream("saved_leaderboard.txt");
            final ObjectInputStream obj = new ObjectInputStream(infile);
            L = (Leaderboard<Float>)obj.readObject();
            obj.close();
            infile.close();
        } 
        catch(final IOException i) {
            System.out.println("Leaderboard cannot be deserialized.");
        } 
        catch(final ClassNotFoundException i) {
            System.out.println("Leaderboard cannot be deserialized.");
        }

        return L;
    }
}

