#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "expr_assert.h"



void test__createList_01__createList_creates_a_linkedList_with_NULL_head_and_tail(){
	int count = 0;
	LinkedList expected_linked_list = createList();
	assertEqual(0,((int)expected_linked_list.head));
	assertEqual(0,((int)expected_linked_list.head));
};

void test__createList_02__createList_creates_a_linkedList_which_return_with_0_element(){
	LinkedList expected_linked_list = createList();
	assertEqual(0,((int)expected_linked_list.count));
};

void test__create_node_01__create_node_creates_a_node_which_contain_an_intiger_as_data_and_NULL_as_next(){
	int data = 01;
	Node_ptr expected_node = create_node((void*)data);
	assertEqual(data,(int)expected_node->data);
	assertEqual(0,(int)expected_node->next);
	free(expected_node);
};

void test__create_node_02__create_node_creates_a_node_which_contain_an_character_as_data_and_NULL_as_next(){
	char data = 'a';
	Node_ptr expected_node = create_node((void*)data);
	assertEqual(data,(char)expected_node->data);
	assertEqual(0,(int)expected_node->next);
	free(expected_node);
};

void test__create_node_03__create_node_creates_a_node_which_contain_an_string_as_data_and_NULL_as_next(){
	char* data = "STRING-DATA";
	Node_ptr expected_node = create_node((void*)data);
	char* expData = expected_node->data;
	assertEqual(strcmp(expData,data),0);
	assertEqual(0,(int)expected_node->next);
	free(expected_node);
};

void test__add_to_list_01__add_to_list_add_the_node_into_the_list_and_return_1_as_count(){
	int data = 01;
	int count;
	LinkedList newList = createList();
	Node_ptr expected_node = create_node((void*)data);
	count = add_to_list(&newList,expected_node);
	assertEqual(count,1);
	free(expected_node);
};

void test__add_to_list_02__add_to_list_add_the_node_into_the_list_and_return_1_as_count(){
	char data = '1';
	int count;
	LinkedList newList = createList();
	Node_ptr expected_node = create_node((void*)data);
	count = add_to_list(&newList,expected_node);
	assertEqual(count,1);
	free(expected_node);
};

void test__add_to_list_03__add_to_list_add_the_node_into_the_list_and_return_1_as_count(){
	char* data = "01";
	int count;
	LinkedList newList = createList();
	Node_ptr expected_node = create_node((void*)data);
	count = add_to_list(&newList,expected_node);
	assertEqual(count,1);
	free(expected_node);
};

void test__get_first_element_01__get_first_element_will_return_the_data_of_first_node(){
	int data1 = 01, data2 = 02;
	int *result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_first_element(list);

	assertEqual(*result,01);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__get_first_element_02__get_first_element_will_return_the_data_of_first_node(){
	char data1 = '1', data2 = '2';
	int *result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_first_element(list);

	assertEqual(*result,'1');
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__get_first_element_03__get_first_element_will_return_the_data_of_first_node(){
	char *data1 = "01", *data2 = "02";
	char **result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_first_element(list);

	assert(*result == "01");
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__get_last_element_01__get_first_element_will_return_the_data_of_last_node(){
	int data1 = 01, data2 = 02;
	int *result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_last_element(list);

	assertEqual(*result,02);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__get_last_element_02__get_first_element_will_return_the_data_of_last_node(){
	char data1 = '1', data2 = '2';
	int *result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_last_element(list);

	assertEqual(*result,'2');
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};


void test__get_last_element_03__get_first_element_will_return_the_data_of_last_node(){
	char *data1 = "01", *data2 = "02";
	char **result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = get_last_element(list);

	assert(*result == "02");
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};