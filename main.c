#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "linked_list.h"

bool list_equals(const Node* head, const int* expected, size_t expected_count);

int main(void) {
	
	Node* head = NULL;

	assert(list_equals(head, NULL, 0) == true);

	bool result = false;

	result = insert_sorted(&head, 12);
	assert(result == true);
	int expected_1[] = { 12 };
	assert(list_equals(head, expected_1, 1) == true);

	result = insert_sorted(&head, 12);
	assert(result == true);
	int expected_1_1[] = { 12, 12 };
	assert(list_equals(head, expected_1_1, 2) == true);

	result = insert_sorted(&head, 10);
	assert(result == true);
	int expected_2[] = { 10, 12,12 };
	assert(list_equals(head, expected_2, 3) == true);

	result = insert_sorted(&head, 13);
	assert(result == true);

	// test of the test
	int expected_3_wrong[] = { 10, 12,12 };
	assert(list_equals(head, expected_3_wrong, 3) == false);

	int expected_3[] = { 10, 12,12, 13 };
	assert(list_equals(head, expected_3, 4) == true);

	result = insert_sorted(&head, 13);
	assert(result == true);
	int expected_4[] = { 10, 12,12, 13, 13 };
	assert(list_equals(head, expected_4, 5) == true);

	result = insert_sorted(&head, 11);
	assert(result == true);
	int expected_5[] = { 10, 11, 12,12, 13, 13 };
	assert(list_equals(head, expected_5, 6) == true);

	result = insert_sorted(NULL, 13);
	assert(result == false);
	assert(list_equals(head, expected_5, 6) == true);


	result = remove_first(&head, 11);
	assert(result == true);
	int expected_6[] = { 10, 12,12, 13, 13 };
	assert(list_equals(head, expected_6, 5) == true);

	result = remove_first(NULL, 11);
	assert(result == false);
	assert(list_equals(head, expected_6, 5) == true);

	result = remove_first(&head, 13);
	assert(result == true);
	int expected_7[] = { 10, 12,12, 13 };
	assert(list_equals(head, expected_7, 4) == true);


	result = remove_first(&head, 9);
	assert(result == false);
	assert(list_equals(head, expected_7, 4) == true);

	result = remove_first(&head, 10);
	assert(result == true);
	int expected_8[] = { 12,12, 13 };
	assert(list_equals(head, expected_8, 3) == true);



	free_list(NULL);
	assert(head != NULL);

	free_list(&head);
	assert(head == NULL);

	free_list(&head);
	assert(head == NULL);

	result = remove_first(&head, 9);
	assert(result == false);

	result = insert_sorted(&head, 12);
	assert(result == true);
	int expected_9[] = { 12 };
	assert(list_equals(head, expected_9, 1) == true);
	
	result = remove_first(&head, 12);
	assert(result == true);
	assert(head == NULL);




	result = insert_sorted(&head, -10);
	assert(result == true);
	int expected_10[] = { -10 };
	assert(list_equals(head, expected_10, 1) == true);


	result = insert_sorted(&head, -5);
	assert(result == true);
	int expected_11[] = { -10, -5 };
	assert(list_equals(head, expected_11, 2) == true);


	result = insert_sorted(&head, -15);
	assert(result == true);
	int expected_12[] = { -15, -10, -5 };
	assert(list_equals(head, expected_12, 3) == true);


	result = insert_sorted(&head, 2);
	assert(result == true);
	int expected_13[] = { -15, -10, -5, 2 };
	assert(list_equals(head, expected_13, 4) == true);

	result = insert_sorted(&head, INT_MIN);
	assert(result == true);
	int expected_14[] = { INT_MIN, -15, -10, -5, 2 };
	assert(list_equals(head, expected_14, 5) == true);

	result = insert_sorted(&head, INT_MAX);
	assert(result == true);
	int expected_15[] = { INT_MIN, -15, -10, -5, 2, INT_MAX };
	assert(list_equals(head, expected_15, 6) == true);

	// free all the memory used in the program
	free_list(&head);
	assert(head == NULL);

	puts("All test passed");
	return 0;
}

bool list_equals(const Node* head, const int* expected, size_t expected_count) {
	if(head != NULL && expected_count == 0) return false;
	
	const Node* p_actual_node = head;

	for (size_t i = 0; i < expected_count; i++) {
		if (p_actual_node == NULL) return false;
		if (expected[i] != p_actual_node->value) return false;

		p_actual_node = p_actual_node->next_node;
	}
	
	// there is no other node in the list to check
	if (p_actual_node == NULL) return true;

	// the list is bigger then the expected
	return false;
}
