<h1>Leaderboard</h1>
<p>
    This code implements a game leaderboard of a chosen size with fields player-name, score (templated/generic), and a date/time.  There are two versions.  One is in C++ and another is in Java, which can use serialization.
</p>
<h2>Getting the code</h2>
<pre>
    <code>git clone https://github.com/17livincent/Leaderboard.git</code>
</pre>
<p>
    Or
</p>
<pre>
    <code>git clone git@github.com:17livincent/Leaderboard.git</code>
</pre>
<h2>Usage</h2>
<p>
    For the C++ version, simply <code>#include "leaderboard.h"</code> and use the various methods to interact with it.  <code>run.cpp</code> implements <code>leaderboard.h</code> for testing purposes.
    For the Java version, simply reference the <code>Leaderboard</code> class in your code.  <code>Run.java</code> is also a testing program for <code>Leaderboard.java</code>.
</p>
<h2>Features include:</h2>
<ul>
    <li>
        A <code>ranking</code> struct/class with player name, score, and time parameters.
    </li>
    <li>
        A choosable and updatable <code>size</code> for the leaderboard, as well as the option to clear the leaderboard.
    </li>
    <li>
        A templated/generic <code>score</code> field in the ranking to be able to hold any type of data (int, double, string, ...).  However, for C++, it must be a primitive.  For Java, the <code>compareTo(T A, T B)</code> method must be updated for the <code>score</code> type.
    </li>
    <li>
        The capability of specifying the hierarchy of the scoring, such as whether a numerically greater/lesser score is higher or lower.
    </li>
    <li>
        For the Java version, the ability to save the current leaderboard info to a text file in order to reload it in the future.
    </li>
</ul>