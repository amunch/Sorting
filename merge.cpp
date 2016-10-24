// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations
//takes list and is a wrapper for the recursive msort
void merge_sort(List &l, bool numeric) {
	CompareFunction compare;
	
	if(numeric) { //use numeric
		compare = node_number_compare;
	}
	else { //do not use numeric
		compare = node_string_compare;
	}
	//call recursive function
	Node* head = msort(l.head, compare);
	l.head = head;
}
//recursive function that calls spilt to divide and merge to conquer
Node *msort(Node *head, CompareFunction compare) {
	if(head == NULL || head->next == NULL) { //base case
		return head;
	}
	
	Node* left; //Split lists.
	Node* right;
	//spilt the lists
	split(head, left, right);
	//recursive call
	left= msort(left,compare);
	right=msort(right,compare);
	//merge back together
	head = merge(left, right, compare);		

	return head;
}
//helper function that spilts list by using two pointers
void split(Node *head, Node *&left, Node *&right) {
	Node* slow = head;
	Node* fast = head;
	//go through with fast
	while(fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	//right is where slow is
	right = slow->next;
	slow->next = NULL; //cut it
	left = head;		
}
//helper function that combines left and right lists
Node *merge(Node *left, Node *right, CompareFunction compare) {
	Node* head = NULL;
	Node* current = NULL;
	
	while(left && right) { //while we got more to combine
			if(compare(left, right)) { //which one is bigger
				if(head) { //head already exist
					current->next = left;
					left = left->next;
					current = current->next;
		                        current->next = NULL;
				}
				else { //first one
					head = left;
					current = head;
					left = left->next;
					current->next = NULL;
				}
			} else {
				if(head) { //head already exists
                                        current->next = right;
                                        right = right->next;
                                        current = current->next;
                                        current->next = NULL;
                                }
                                else { //first one so make head  
                                        head = right;
                                        current = head;
                                        right = right->next;
                                        current->next = NULL;
                                }
			}
	}
	
	if(left) { //we still got left 
		if(head) { //head exists
			current->next = left; //attach to end
		}
		else { //no head so make one
			head = left;
		}
	}
	else if(right) { //we still got right
		if(head) { //head exists
			current->next = right;
		} 
		else { //no head so make one
			head = right;
		}
	}
	
	return head;			
}
