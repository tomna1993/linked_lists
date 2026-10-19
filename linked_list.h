#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node* next_node;
} Node;

bool insert_sorted(Node** head, int value);
void free_list(Node** head);
bool remove_first(Node** head, int value);

#endif
