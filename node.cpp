// node.cpp

#include "lsort.h"
#include <string.h>
#include <iostream>

bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
	return a->string < b->string;
}

int void_number_compare(const void *a, const void *b) {
	const Node* node_a = *(const Node**)a;
	const Node* node_b = *(const Node**)b;
	return node_a->number - node_b->number;
}

int void_string_compare(const void *a, const void *b) {
	const Node* node_a = *(const Node**)a;
	const Node* node_b = *(const Node**)b;
	return strcmp(node_a->string.c_str(), node_b->string.c_str());
}

void dump_node(Node *n) {
	while(n) {
		std::cout << "Number: " << n->number << " | " << n->string << std::endl;
		n = n->next;
	}
}
