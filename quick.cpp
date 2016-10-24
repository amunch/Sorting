// quick.cp

#include <unistd.h>

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations
// takes list and is a wrapper function for the recursive qsort
void quick_sort(List &l, bool numeric) {
    CompareFunction compare;
    
    if(numeric) { //use numeric
        compare = node_number_compare;
    }
    else { //use string
        compare = node_string_compare;
    }
    //call recursive function
    Node* head = qsort(l.head, compare);
    l.head = head;
}
// recursive function that partitions the list and then concatenates it together
Node *qsort(Node *head, CompareFunction compare) {
    if(head == NULL || head->next == NULL) { //base case
        return head; 
    }
    
    Node* left = NULL;
    Node* right = NULL;
    //partion the list into two parts
    partition(head, head, left, right, compare);
    //recursive call on each side
    left = qsort(left, compare);
    right = qsort(right,compare);
    //re-link everything together
    head = concatenate(left,right);
    return head;
}
//helper function that spilts the lists into left and right such that everything less than pivort is on left and everything else of right
void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    head = head->next; //move head off pivot
    Node* curr_left = NULL;
    Node* curr_right = NULL;
    //while we still got nodes
    while(head != NULL) {
        if(compare(head,pivot)) { //which one is bigger
            if(left) { //left exists so attach to end
                curr_left->next = head;
                curr_left = curr_left->next;
            } else { //no left so make left this node
                curr_left = head;
                left = curr_left;
            }
            //move on
            head = head->next;
        }
        else { //adding to right so bigger
            if(right) { //right exists so attach to end
                curr_right->next = head;
                curr_right = curr_right->next;
            } else { //no right so make right this node     
                curr_right = head;
                right = curr_right;
            }
            head = head->next; //move on
        } 
    }
    if(left) { //we made a left part  
        curr_left->next = pivot; //add pivot
        curr_left = curr_left->next;
    } else { //we did not make a left part
        left = pivot; //add pivot
        left->next = NULL;
    }
    if(curr_left) { //cut the list
        curr_left->next = NULL;
    }
    if(curr_right) { //cut list
        curr_right->next = NULL;
    }
}
//helper function that combines left and right
Node *concatenate(Node *left, Node *right) {
    Node* head = left;

    while(left->next) { //while we got left
        left = left->next; //add left
    }
    left->next = right; //add right
 
    return head;    
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
