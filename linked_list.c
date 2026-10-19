#include "linked_list.h"
#include <stdlib.h>


bool insert_sorted(Node** head, int value) {
	if (head == NULL) return false;

	Node* p_new_node = malloc(sizeof(Node));
	
	if (p_new_node == NULL) return false;

	p_new_node->value = value;
	p_new_node->next_node = NULL;

	// the list is empty and has to add the first node
	if (*head == NULL) {
		*head = p_new_node;
		return true;
	}
	
	// the list is not empty
	Node* p_previous_node = NULL;
	Node* p_actual_node = *head;

	while (1) {
		// insert node before
		if (value <= p_actual_node->value) {
			p_new_node->next_node = p_actual_node;
			if (p_previous_node == NULL) {
				*head = p_new_node;
			}
			else {
				p_previous_node->next_node = p_new_node;

			}
			return true;
		}
		// insert node after
		else {
			// next node if empty so the new value will be the last one in the linked list
			if (p_actual_node->next_node == NULL) {
				p_actual_node->next_node = p_new_node;
				return true;
			}
			p_previous_node = p_actual_node;
			p_actual_node = p_actual_node->next_node;
		}
	}
}

void free_list(Node** head) {
	if (head == NULL || *head == NULL) return;

	Node* p_actual_node = *head;

	while (1) {
		if (p_actual_node->next_node == NULL) {
			free(p_actual_node);
			*head = NULL;
			return;
		}
		
		Node* p_next_node = p_actual_node->next_node;
		free(p_actual_node);
		p_actual_node = p_next_node;
	}
}

bool remove_first(Node** head, int value) {
	if (head == NULL || *head == NULL) return false;

	// the list is not empty
	Node* p_previous_node = NULL;
	Node* p_actual_node = *head;

	while (1) {
		// remove node before
		if (value == p_actual_node->value) {
			if (p_previous_node == NULL) {
				*head = p_actual_node->next_node;
			}
			else {
				p_previous_node->next_node = p_actual_node->next_node;
			}
			free(p_actual_node);
			return true;
		}
		// remove node after
		else {
			// value was not found in the list
			if (p_actual_node->next_node == NULL) {
				return false;
			}

			p_previous_node = p_actual_node;
			p_actual_node = p_actual_node->next_node;
		}
	}
}
