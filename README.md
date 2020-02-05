# Booble_internship_answer
**Assignment solutios for all 3 Questions**

**Questions 1: Permutations**<br/><br/>
First I extract all words like ('a', 'b', 'c') from dynamic array in every line and store in my container 
and then use a recursive approach to calculate all permutations.<br/><br/>
1 Functions</br>
<ul>
  <li>recursive_call():  Calculate all different permutation for the dynamic array</li>
 </ul>
<br/>
<br/>
<br/>




**Question 2:Character Tree serialization**
<br/>
<br/>
Data Structure used: Tree
<br/>
4 Functions<br/>
<ul>
  <li>Insert():  Make a tree and Inserting the characters in thr tree</li>
  <li>Traverse(): Traversing the tree</li>
  <li>Create(): Read words from the CSV file, create tree of characters and then serialize it and save it to the file-path accepted after csv file name</li>
  <li>Load():  Read the serialized file, recreate the character tree and print all the words present in the tree.</li>
  </ul>
<br/>
<br/>
<br/>

**Question 3:Word suggestions**
<br/>
<br/>
first I used Trie data structure which used a very unique and efficient approach to insert all the string and then extract first 5 string which is starting from that prefix or query string .<br/><br/>
Data structure used: Trie (most efficient for information retrieval)
<br/>
4 Functions</br>
<ul>
  <li>Insert():  Make a tree and Inserting the characters in thr tree</li>
  <li>Traverse(): Traversing the tree</li>
  <li>booblesugg(): Helping function for print function</li>
  <li>Print():  Print 5 word suggestions .</li>
  </ul>
<br/>
