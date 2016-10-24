// list.cpp

#include "lsort.h"

#include <memory>
#include <iostream>

List::List() {
	head = nullptr; //Nothing in the list.
	size = 0;
}

List::~List() {
	Node* current;
	while(head) {
		current = head; //Store address of current node.
		head = head->next; //Increment to next node.
		delete current; //Delete previous node.
	}	
}

void List::push_front(const std::string &s) {
	Node* to_add = new Node; //Allocate a new node
	to_add->string = s; //edit the string.
	try { //Try to convert the string to an int, and if not set to 0.
		to_add->number = std::stoi(s); 
	}
	catch(const std::exception& ex) {
		to_add->number = 0;
	}
	if(!head) {
		head = to_add;
		head->next = NULL;
	}
	else {
		to_add->next = head;
		head = to_add;
	}
	size++;
	//std::cout << size << std::endl;
}
