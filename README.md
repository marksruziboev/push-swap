# push-swap

This project about sorting a stack of integers. The program consists of two main parts 
(1) Reading from user input.
(2) Sorting algorithm. 

Each of the above devided into several sections.

In (1) we check if the input is valid in two stages: 
  a) at the level of strings 
  b) after converting the input to integers. 
  
In  a) we check if the input contains valid charachters: digits, spaces, + and - signs.
this is done by functions cinsert and alldig. alldigfunction also checks if the input is a valid integer string.
Here one has to exclude situations like "5 6-", " 4 -+ 5", " 7 - 9", " " " 1 4 3".

After validating the input I convert the input to integer with ft_atoi and wrtie to a in fill_a. 
In b) I check if the input is already sorted; if it has repetitions in no_rep and is_sorted. 
Also, it is convienent to sort the array formed by the index rather than the initial array. 
In ft_index for an N element of array a I count the number of elements in a that is smaller than N.
This number gives the index where N should be located, then I copy this index string to a by ft_reset.


The main part of the project is to sort a.

Here I used an algorithm that is somewhat similar Hanoi tower construction. 


The main part of the project is to sort a.

Here I used an algorithm that is somewhat similar Hanoi tower construction. 
Recall that original array is replaced with an array of indeces: 1,2, ..., n.

Sorting is done in two steps: 
  s1. We devide the stack a into sqrt(n) groups and push all the numbers from stack a to b as follows:
      We sent two groups of elements starting with the gourps of smallest elements 
      (For example, if n = 16 we have 4 groups with 4 elements each ( 1 2 3 4 | 5 6 7 8| 9 10 11 12| 13 14 15 16 )
      we first send elements from 1 to 8 if a[0] is not in this interval we rotate a until we send all the numbers.
      For each number we check again after pushing to b  and if it is between 1 and 4 we rotate b.
      After completing the process we obtain pre-sorted stack a, where the largest group is either on the top or at the bottom.
  
  s2. Sending elements from b to a: We virtually devide a into two upper part is the place we want to ahve sorted stack and the bottom, 
  where we save increasing substack for later use by reverserotating. 
      For b[0] we check the folloiwng 3 cases:
        if stack a is empty we push b[0].
        else if a is not empty but b[0] is larer than  a[bot -1], we push b[0] and rotate.
        else if b[0] is the next element we push it to stack b.
        else (if none ofthe above is satisfied then we do one of the following two operations):
        { 
          if the largest element of b is is in the upper half of b we rotate b. 
          (Here I implemented max_ind a funtion which returns the index of max element)
          else we reverse rotate b.
        } 


This should be enough to get 5 points (100). But one can improve the statistics as follows.
Instead of printing the commands directly, i introduce a string (z in my struct) that is empty at the beginning.
The function printcom (in mess.c) takes new command and compares it with z and combines them if possible,
prints the combined function and set z = ' '. Otherwise prints z and rewrites the new command to z.
