// stl.cpp

#include "lsort.h"

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <array>

void qsort_sort(List &l, bool numeric) {
	Node** to_sort = NULL; //Initialize array as pointer to Node*'s.
	to_sort = new Node*[l.size]; //Create an array of node*
	Node* head = l.head; 

	size_t val = 0;

	while(head) { //Push back all elements into the deque.
		to_sort[val] = head;
		head = head->next;
		val++;
	}
	
	if(numeric) { //Sort numerically.
		qsort(to_sort, val, sizeof(Node*), void_number_compare);	
	}
	else { //Sort by string.
		qsort(to_sort, val, sizeof(Node*), void_string_compare);
	}	
	
	if(!(val == 0)) { //While there are still nodes in the vector.
		head = to_sort[0];
		Node* current = head;
		for(size_t i = 1; i < val; i++) {
			//Add the node to the list and update its next pointer to NULL
			Node* to_add = to_sort[i];
			to_add->next = NULL;
			current->next = to_add;
			current = current->next;
		}
	}
	//Update list to head of sorted linked list.
	l.head = head;
	//clean up
	delete [] to_sort;
}
