<h1>CLFLARR - COLORFUL ARRAY (spoj.com)</h1>
<p>https://www.spoj.com/problems/CLFLARR/</p>
<p>You have been given an array of <strong>n</strong> unpainted elements. By unpainted, we mean that each element initially has a value of <strong>0</strong>. You have to process <strong>q</strong> queries of the form <strong>l r c</strong>, in which you paint all the elements of the array from index <strong>l</strong> to index <strong>r</strong> with color <strong>c</strong>. Assume that, each new color currently being applied to an element overrides its previous color. Output the color of each element after all the queries have been processed.</p>
<p><strong>Note</strong>: The problem is guaranteed to be solved using C or C++ programming language.</p>
<h3>Input</h3>
<p>The first line of input consists of two integers n and q. Next q lines consists of 3 integers l, r and c denoting the starting index, ending index and the color respectively.</p>
<ul>
<li>1 &lt;=&nbsp;<strong>n</strong>&nbsp;&lt;= 200000</li>
<li>1 &lt;= <strong>q</strong> &lt;= 200000</li>
<li>1 &lt;= <strong>l</strong> &lt;= <strong>r</strong> &lt;= <strong>n</strong></li>
<li>1 &lt;= <strong>c</strong> &lt;= 1 000 000 000</li>
</ul>
<h3>Output</h3>
<p>Output the final color of each element starting from index 1 on a new line.</p>
<h3>Example</h3>
<pre><strong>Input</strong>
4 3
1 3 2
2 4 6
2 3 7</pre>
<pre><strong>Output:</strong>
2
7
7
6</pre>
<pre><strong>Input</strong>
10 5
3 9 13
1 4 9
2 10 14
2 7 10
6 9 44</pre>
<pre><strong>Output</strong>
9
10
10
10
10
44
44
44
44
14</pre>

<h1>QUERYIT - SLIS (spoj.com)</h1>
<p>https://www.spoj.com/problems/QUERYIT/</p>
<p>Rachit, Sandeep,Yogesh,Vikram and Shubham are very good friends. They participated in a contest MNNIT INSOMNIA as a team but there was a problem which was not solved by any of the teams .So they were desperate to solve that problem.After contest they asked you for your help to solve the problem.Help them to solve the problem.The problem description is as follows:</p>
<p>There is an array&nbsp;of length n consisting of only 0 and 1 as elements.You have to answer q queries.There are two type of queries&nbsp;</p>
<p>Type 0: There is l and r .You have to change each 0 to 1 and each 1 to 0 from l to r (both inclusive).</p>
<p>Type 1: print the length of longest non decreasing subsequence of the array.</p>
<p><span style="font-size: x-small;"><strong><span style="font-size: small;">Note</span></strong></span>: Indexing is 1 based.</p>
<p><span style="font-size: small;"><span style="color: #222222;">A </span><span style="color: #222222;">&nbsp;subsequence is a sequence</span><span style="color: #222222;">&nbsp;that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.</span><span style="color: #222222;">&nbsp;</span></span></p>
<p><strong><span style="font-size: small;">Input</span></strong></p>
<p>First line consists of two integers &nbsp;n and q where n is length of array and q is number of queries.</p>
<p>Second line consists of array of length n without spaces.</p>
<p>After that there are q lines containg type of query .And for type 0 query it has two integers l and r.</p>
<p>1&lt;=n,q&lt;=10^5, &nbsp; 1&lt;=l&lt;=r&lt;=n</p>
<h3>Output</h3>
<p>Print a single line for each query of type 1 containg length of longest non decreasing subsequence.</p>
<h3>Example</h3>
<pre><strong>Input:</strong>
5 5</pre>
<pre>10111</pre>
<pre>1</pre>
<pre>0 3 5</pre>
<pre>1</pre>
<pre>0 2 3</pre>
<pre>1</pre>
<pre><strong>Output:</strong>
4</pre>
<pre>4</pre>
<pre>3</pre>
