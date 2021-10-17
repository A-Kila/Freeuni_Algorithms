<h1>1527. Bad Roads (acm.timus.ru)</h1>
<p>https://acm.timus.ru/problem.aspx?space=1&num=1527</p>
<div id="problem_text"><div class="problem_par"><div class="problem_par_normal">In a country, there is a number of cities connected by unidirectional roads. Due to
insufficient budget, some roads are covered with pot-holes, so certain
cars cannot use certain roads. Thus each road has the height number
associated with it&nbsp;— that is the minimal height of the bottom of a car
that can drive through that road. On the other hand, some roads are private,
and one should pay for using them. Luckily, the amount to be paid is
standartized and equals one standard unit. Finally, for each road, the time
required to drive through it is known.
</div></div><div class="problem_par"><div class="problem_par_normal">Given that you have to drive from city <i>s</i> to city <i>f</i> using no more than
<i>t</i> minutes of time, no more than <i>b</i> standard units, find the
minimal height of the bottom of the car which makes it possible.
</div></div><h3 class="problem_subtitle">Input</h3><div class="problem_par"><div class="problem_par_normal">The first line of the input contains the number of cities <i>n</i> (1&nbsp;≤&nbsp;<i>n</i>&nbsp;≤&nbsp;100), the number of roads <i>m</i>
(1&nbsp;≤&nbsp;<i>m</i>&nbsp;≤&nbsp;10<sup>4</sup>), and the numbers of starting and ending cities <i>s</i>
and <i>f</i> (1&nbsp;≤&nbsp;<i>s</i>, <i>f</i>&nbsp;≤&nbsp;<i>n</i>).
The second line contains numbers <i>b</i> (0&nbsp;≤&nbsp;<i>b</i>&nbsp;≤&nbsp;10<sup>6</sup>) and <i>t</i>
(0&nbsp;≤&nbsp;<i>t</i>&nbsp;≤&nbsp;10<sup>6</sup>).
</div></div><div class="problem_par"><div class="problem_par_normal">Each of the next <i>m</i> lines has the form <i>u<sub>i</sub> v<sub>i</sub> c<sub>i</sub> t<sub>i</sub> h<sub>i</sub></i>.
Here, <i>u<sub>i</sub></i> is the starting city for <i>i</i>-th road, <i>v<sub>i</sub></i> is the ending city,
<i>c<sub>i</sub></i> is 1 if it is a private road and 0 otherwise, <i>t<sub>i</sub></i> is the time
required to drive through that road, and <i>h<sub>i</sub></i> is the height of the car
required to pass (1&nbsp;≤&nbsp;<i>u<sub>i</sub></i>, <i>v<sub>i</sub></i>&nbsp;≤&nbsp;<i>n</i>; 0&nbsp;≤&nbsp;<i>t<sub>i</sub></i>&nbsp;≤&nbsp;10<sup>4</sup>; 
0&nbsp;≤&nbsp;<i>h<sub>i</sub></i>&nbsp;≤&nbsp;10<sup>6</sup>). All the numbers in the input are integers.</div></div><h3 class="problem_subtitle">Output</h3><div class="problem_par"><div class="problem_par_normal">If there is no way to drive from <i>s</i> to <i>f</i> under given restrictions,
output "−1". Otherwise write on the first line the minimal height
of the car; the second line should contain the number of roads used to travel
from <i>s</i> to <i>f</i>; and the third line must be filled by the numbers of the roads
you used in the order of usage. Roads are numbered from 1 to <i>m</i>; the
order is the same as in input.
</div></div><h3 class="problem_subtitle">Samples</h3><table class="sample"><tbody><tr><th width="350">input</th><th width="350">output</th></tr><tr><td><pre>2 2 1 2     
1 100       
1 2 1 100 77
1 2 1 100 66
</pre></td><td><pre>66
1
2
</pre></td></tr><tr><td><pre>2 2 1 2     
0 100       
1 2 0 101 77
1 2 1 100 66
</pre></td><td><pre>-1
</pre></td></tr></tbody></table><div class="problem_source"><b>Problem Author: </b>Dmitry Gozman<br><b>Problem Source: </b>Dmitry Gozman Contest 1, Petrozavodsk training camp, January 2007<br></div></div>

<h1>10937 - Blackbeard the Pirate (onlinejudge.org)</h1>
<p>https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1878</p>
<p>Blackbeard the Pirate has stashed up to 10 treasures on a tropical
island, and now he wishes to retrieve them. He is being chased by
several authorities however, and so would like to retrieve his treasure as
quickly as possible. Blackbeard is no fool; when he hid the treasures,
he carefully drew a map of the island which contains the position of
each treasure and positions of all obstacles and hostile natives that are
present on the island.</p>
<p>Given a map of an island and the point where he comes ashore,
help Blackbeard determine the least amount of time necessary for him
to collect his treasure.</p>
<h3>Input:</h3>
<p>Input consists of a number of test cases. The first line of each test
case contains two integers h and w giving the height and width of the
map, respectively, in miles. For simplicity, each map is divided into grid
points that are a mile square. The next h lines contain w characters,
each describing one square on the map. Each point on the map is one
of the following:</p>
<ul>
	<li>@ The landing point where Blackbeard comes ashore.</li>
	<li>˜ Water. Blackbeard cannot travel over water while on the island</li>
	<li># A large group of palm trees; these are too dense for Blackbeard to travel through.</li>
	<li>. Sand, which he can easily travel over.</li>
	<li>∗ A camp of angry natives. Blackbeard must stay at least one square away or risk being captured
by them which will terminate his quest. Note, this is one square in any of eight directions,
including diagonals.</li>
	<li>! A treasure. Blackbeard is a stubborn pirate and will not leave unless he collects all of them.</li>
</ul>
<p>Blackbeard can only travel in the four cardinal directions; that is, he cannot travel diagonally.
Blackbeard travels at a nice slow pace of one mile (or square) per hour, but he sure can dig fast,
because digging up a treasure incurs no time penalty whatsoever.</p>
<p>The maximum dimension of the map is 50 by 50. The input ends with a case where both h and w
are 0. This case should not be processed.</p>
<h3>Output:</h3>
<p>For each test case, simply print the least number of hours Blackbeard needs to collect all his treasure
and return to the landing point. If it is impossible to reach all the treasures, print out ‘-1’</p>

<h3>Sample Input:</h3>
<pre>
7 7
~~~~~~~
~#!###~
~...#.~
~~....~
~~~.@~~
.~~~~~~
...~~~.
10 10
~~~~~~~~~~
~~!!!###~~
~##...###~
~#....*##~
~#!..**~~~
~~....~~~~
~~~....~~~
~~..~..@~~
~#!.~~~~~~
~~~~~~~~~~
0 0
</pre>
<h3>Sample Output:</h3>
<pre>
10
32
</pre>
