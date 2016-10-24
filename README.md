Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

Problem 1
---------
	STL
		Best: O(nlog(n))
		Average: O(nlog(n))
		Worst: O(n^2)

	QSORT
		Best: O(nlog(n))
		Average: O(nlog(n))
		Worst: O(nlog(n))

	Merge
		Best: O(nlog(n))
		Average: O(nlog(n))
		Worst: O(nlog(n))

	Quick
		Best: O(nlog(n))
		Average: O(nlog(n))
		Worst: O(n^2)

Problem 2
---------
	| Mode  |   Size   |  Elapsed Time(seconds)  |  Memory (Mbytes) |
	|----------------------------------------------------------------
	| STL   | 10       |       0.000999          |     1.187500     |
	| STL   | 100      |       0.000999          |     1.195312     |
	| STL   | 1000     |       0.002998          |     1.269531     |
	| STL   | 10000    |       0.025995          |     2.023438     |
	| STL   | 100000   |       0.282956          |     9.539062     |
	| STL   | 1000000  |       3.352490          |    85.070312     |
	| STL   | 10000000 |      39.436005          |   840.378906     |
	|       |          |                         |                  |
	| QSort | 10       |       0.000999          |     1.187500     |
	| QSort | 100      |       0.000999          |     1.195312     |
	| QSort | 1000     |       0.002999          |     1.328125     |
	| QSort | 10000    |       0.023996          |     2.121094     |
	| QSort | 100000   |       0.275957          |    10.359375     |
	| QSort | 1000000  |       3.217510          |    92.757812     |
	| QSort | 10000000 |      35.335629          |   916.730469     |
	|       |          |                         |                  |
	| Merge | 10       |       0.000999          |     1.187500     |
	| Merge | 100      |       0.000999          |     1.191406     |
	| Merge | 1000     |       0.002998          |     1.261719     |
	| Merge | 10000    |       0.023996          |     1.949219     |
	| Merge | 100000   |       0.267958          |     8.816406     |
	| Merge | 1000000  |       3.298498          |    77.480469     |
	| Merge | 10000000 |      39.247032          |   764.125000     |
	|       |          |                         |                  |
	| Quick | 10       |       0.000999          |     1.187500     |
	| Quick | 100      |       0.000999          |     1.191406     |
	| Quick | 1000     |       0.002998          |     1.261719     |
	| Quick | 10000    |       0.024995          |     1.949219     |
	| Quick | 100000   |       0.295954          |     8.816406     |
	| Quick | 1000000  |       4.100376          |    77.480469     |
	| Quick | 10000000 |      51.079235          |   764.125000     | 

Problem 3
---------
For the timing, STL, QSORT, and Merge sort are all very similar but QSort being the fastest one at 35 seconds for the largest size and STL and Merge being at 39 seconds. However, Quick sort is much higher when it reaches the largest size being at 51 seconds. Quick sort takes a lot longer because it needs to run through the whole list again during the concatenate stage to relink the list in sorted order. 

For the size, Merge and Quick sort used the least amount with only using 764 megabytes each at the largest size. However, STL and QSORT use much more memory with STL using 840 megabytes at the largest size and QSORT using 916 megabytes. STL and QSORT use a lot more memory because it needs to force the linked list into an array while merge and quick sort simply used the linked list to sort.

These results reveal that while theoretical complexities can be the same, the real results could be significantly different. Since you are cutting off the additions for the theoretical complexities, you lose a sense that the real results could be different. For example, quick and merge sort are the same theoretical complexity but quick sort is a significant 12 seconds slower than merge sort for the largest size.

In our opinion, the best sorting method for linked list is merge sort. It is one of the faster sorts on linked list at 39 seconds for the largest size which is not too much slower than QSORT at 35 seconds. Furthermore, it uses the least amount of memory for 764 megabytes for the largest size while QSORT using 916 and STL 840. Therefore, it seems to get the best of both worlds (hannah montanta reference) because it is quick and does not use much memory. Also, we found it to be relatively easy to understand and implement.

Partner Input
-------------
The code was written by pair programming with the expection of Andy writing the shell script. The table was put together by Mark.
