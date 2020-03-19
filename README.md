<h1>Leaderboard</h1>
<p>
    This code implements a game leaderboard of a chosen size with fields player-name, score (templated), and a date and time.
</p>
<h2>Getting Leaderboard</h2>
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
    To use this in your own program,simply <code>#include "leaderboard.h"</code> and use the various methods to interact with it.  <code>run.cpp</code> implements <code>leaderboard.h</code> for testing purposes.
</p>
<h2>Features include:</h2>
<ul>
    <li>
        A <code>ranking</code> struct with player name, score, and time parameters.
    </li>
    <li>
        A choosable and updatable <code>size</code> for the leaderboard, as well as the option to clear the leaderboard.
    </li>
    <li>
        A templated <code>score</code> field in the ranking to be able to hold any type of data (time_point, int, string, ...).
    </li>
    <li>
        The capability of specifying the hierarchy of the scoring, such as whether a numerically greater/lesser score is higher or lower.
    </li>
    <li>
        The ability to save the current leaderboard info to a text file in order to reload it in the future.
    </li>
</ul>