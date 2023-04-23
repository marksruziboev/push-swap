Title: Project on Sorting a Stack of Integers

The program consists of two main parts:
(1) Reading from user input.
(2) Sorting algorithm.

Each of the above is divided into several sections.

============   PARSING   ============

In (1), we check if the input is valid in two stages:
a) At the level of strings.
b) After converting the input to integers.

In a), we check if the input contains valid characters such as digits, spaces, + and - signs. 
This is done by functions cinsert and alldig. The alldig function also checks if the input is a valid integer string, 
excluding situations like "5 6-", " 4 -+ 5", " 7 - 9", "", and "1 4 3".

After validating the input, we convert it to integers with ft_atoi and write it to an array in fill_a.

In b), we check if the input is already sorted, if it has repetitions in no_rep and is_sorted. 
It is also convenient to sort the array formed by the index rather than the initial array. 
In ft_index, for an N element of array a, we count the number of elements in a that are smaller than N. 
This number gives the index where N should be located, and then we copy this index string to a by ft_reset.

The main part of the project is to sort the stack a.

============   SORTING   ============

The main part of the project is to sort stack a.

Here, I used an algorithm that is somewhat similar to the Hanoi tower construction. 
Recall that the original array is replaced with an array of indices: 1, 2, ..., n.

============   STEP 1: PUSHING ELMENTS TO B   ============

Sorting is done in two steps:
s1. We divide the stack a into sqrt(n) groups and push all the numbers from stack a to stack b as follows:
We send two groups of elements starting with the groups of smallest elements.
For example, if n = 16, we have 4 groups with 4 elements each (1 2 3 4 | 5 6 7 8 | 9 10 11 12 | 13 14 15 16).
We first send elements from 1 to 8. If a[0] is not in this interval, we rotate a until we send all the numbers.
For each number, we check again after pushing to stack b, and if it is between 1 and 4, we rotate b.
After completing the process, we obtain a pre-sorted stack a, where the largest group is either on the top or at the bottom.

============   STEP 2: PUSHING ELMENTS BACK TO A   ============

s2. Sending elements from stack b to stack a:
For b[0], we check the following 3 cases:

If stack a is empty, we push b[0].

Else if a is not empty but b[0] is larger than a[bot-1], we push b[0] and rotate.

Else if b[0] is the next element, we push it to stack b.

Else (if none of the above is satisfied), we do one of the following two operations:

If the largest element of b is in the upper half of b, we rotate b. (Here I implemented max_ind, a function which returns the index of the maximum element).

Else, we reverse rotate b.

We continue this process until all elements from stack b are pushed to stack a and reversre rotate a if the smallest element is at the bottom to get a fully sorted stack a.

============   OPTIMIZATION   ============

The above  should be enough to get 5 points (100). But one can improve the statistics as follows.
Instead of printing the commands directly, i introduce a string (z in my struct) that is empty at the beginning.
The function printcom (in mess.c) takes new command and compares it with z and combines them if possible,
prints the combined function and set z = ' '. Otherwise prints z and rewrites the new command to z.
