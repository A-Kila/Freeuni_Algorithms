<h1>AIBOHP - Aibohphobia (spoj.com)</h1>
<p>https://www.spoj.com/problems/AIBOHP/</p>
<p>BuggyD suffers from AIBOHPHOBIA - the fear of Palindromes.  A palindrome is a string that reads the same forward and backward.</p>

<p>To cure him of this fatal disease, doctors from all over the world discussed his fear and decided to expose him to large number of palindromes.  To do this, they decided to play a game with BuggyD.  The rules of the game are as follows:</p>

<p>BuggyD has to supply a string <b>S</b>. The doctors have to add or insert characters to the string to make it a palindrome.  Characters can be inserted anywhere in the string.</p>

<p>The doctors took this game very lightly and just appended the reverse of <b>S</b> to the end of <b>S</b>, thus making it a palindrome.  For example, if <b>S</b> = <tt>"fft"</tt>, the doctors change the string 
to <tt>"ffttff"</tt>.</p>

<p>Nowadays, BuggyD is cured of the disease (having been exposed to a large number of palindromes), but he still wants to continue the game by his rules. He now asks the doctors to insert the minimum number of characters needed to make <b>S</b> a palindrome.  Help the doctors accomplish this task.</p>

<p>For instance, if <b>S</b> = <tt>"fft"</tt>, the doctors should change the string to <tt>"tfft"</tt>, adding only 1 character.</p>

<h3>Input</h3>
<p>The first line of the input contains an integer <b>t</b>, the number of test cases.  <b>t</b> test cases follow.</p>

<p>Each test case consists of one line, the string <b>S</b>.  The length of <b>S</b> will be no more than 6100 characters, and <b>S</b> will contain no whitespace characters.</p>

<h3>Output</h3>

<p>For each test case output one line containing a single integer denoting the minimum number of characters that must be inserted into <b>S</b> to make it a palindrome.</p>

<h3>Example</h3>

<pre>
<b>Input:</b>
1
fft

<b>Output:</b>
1
</pre>

<h1>1303. Minimal Coverage (acm.timus.ru)</h1>
<p>https://acm.timus.ru/problem.aspx?space=1&num=1303</p>
<div id="problem_text"><div class="problem_par"><div class="problem_par_normal">Given set of line segments [L<sub>i</sub>, R<sub>i</sub>] with integer coordinates of their end points.
Your task is to find the minimal subset of the given set which covers segment [0, M] completely (M is a positive integer).
</div></div><h3 class="problem_subtitle">Input</h3><div class="problem_par"><div class="problem_par_normal">First line of the input contains an integer M (1&nbsp;≤&nbsp;M&nbsp;≤&nbsp;5000). Subsequent lines of input contain pairs of integers L<sub>i</sub> and R<sub>i</sub> (−50000 ≤ L<sub>i</sub> &lt; R<sub>i</sub> ≤ 50000). Each pair of coordinates is placed on separate line. Numbers in the pair are separated with space. Last line of input data contains a pair of zeroes. The set contains at least one and at most 99999 segments.
</div></div><h3 class="problem_subtitle">Output</h3><div class="problem_par"><div class="problem_par_normal">Your program should print in the first line of output the power of minimal subset of segments which covers segment [0, M]. The list of segments of covering subset must follow. Format of the list must be the same as described in input with exception that ending pair of zeroes should not be printed. Segments should be printed in increasing order of their left end point coordinate.
</div></div><div class="problem_par"><div class="problem_par_normal">If there is no covering subset then print “No solution” to output.
</div></div><h3 class="problem_subtitle">Samples</h3><table class="sample"><tbody><tr><th width="350">input</th><th width="350">output</th></tr><tr><td><pre>1
-1 0
-5 -3
2 5
0 0
</pre></td><td><pre>No solution
</pre></td></tr><tr><td><pre>1
-1 0
0 1
0 0
</pre></td><td><pre>1
0 1
</pre></td></tr></tbody></table><div class="problem_source"><b>Problem Source: </b>II Collegiate Students Urals Programming Contest. Yekaterinburg, April 3-4, 1998<br></div></div>
