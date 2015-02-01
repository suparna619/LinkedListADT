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
	char *data = "01";
	int count;
	LinkedList newList = createList();
	Node_ptr expected_node = create_node((void*)data);
	count = add_to_list(&newList,expected_node);
	assertEqual(count,1);
	free(expected_node);
};

void test__add_to_list_04__add_to_list_add_the_nodes_into_list_and_give_count_of_nodes(){
	char *name = "STRING-DATA1";
	char *name1 = "STRING-DATA2";
	int count;
	Node_ptr expected_node1, expected_node2;
	LinkedList newList = createList();

	expected_node2 = create_node((void*)name);
	count = add_to_list(&newList,expected_node2);
	
	expected_node1 = create_node((void*)name1);
	count = add_to_list(&newList,expected_node1);

	assertEqual(count,2);
	free(expected_node1);
	free(expected_node2);
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

void increament_by_five(void* data){
	*(int*)data = *(int*)data+5;
};

void test__traverse_01__traverse_gives_all_elements_increament_by_five(){
	void *result1, *result2;
	int data1 = 1, data2 = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	
	traverse(list,increament_by_five);
	result1 = get_first_element(list);
	result2 = get_last_element(list);

	assertEqual(*(int*)result1, 6);
	assertEqual(*(int*)result2, 7);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__getElementAt_01__getElementAt_gives_the_data_at_valid_index(){
	void* result;
	int index = 1;
	int data1 = 1, data2 = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list, index);

	assertEqual((int)result,2);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_02__getElementAt_gives_NULL_for_an_invalid_index(){
	void* result;
	int index = 4;
	int data1 = 1, data2 = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list,index);

	assertEqual((int)result,0);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_03__getElementAt_gives_NULL_for_an_negative_index(){
	void* result;
	int index = -3;
	int data1 = 1, data2 = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list,index);

	assertEqual((int)result,0);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_04__getElementAt_gives_the_data_at_valid_index(){
	void* result;
	int index = 1;
	int data1 = '1', data2 = '2';
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list, index);

	assertEqual((char)result,'2');
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_05__getElementAt_gives_NULL_for_an_invalid_index(){
	void* result;
	int index = 4;
	int data1 = '1', data2 = '2';
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list, index);

	assertEqual((int)result,0);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_06__getElementAt_gives_NULL_for_an_negative_index(){
	void* result;
	int index = -3;
	char data1 = '1', data2 = '2';
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	result = getElementAt(list,index);

	assertEqual((int)result,0);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__getElementAt_07__getElementAt_gives_the_data_at_valid_index(){
	char *data1 = "STRING-DATA1";
	char *data2 = "STRING-DATA2";
	void *result;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	
	result = getElementAt(list,0);

	assertEqual(strcmp("STRING-DATA1",(char*)result),0);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
};

void test__indexOf_01__indexOf_returns_the_index_for_valid_elements(){
	int resultIndex1, resultIndex2, resultIndex3;
	int element1 = 1, element2 = 2, element3 = 3;
	int data1 = 1, data2 = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	resultIndex1 = indexOf(list, (void *)element1);
	resultIndex2 = indexOf(list, (void *)element2);
	resultIndex3 = indexOf(list, (void *)element3);

	assertEqual((int)resultIndex1, 0);
	assertEqual((int)resultIndex2, 1);
	assertEqual((int)resultIndex3, -1);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__indexOf_02__indexOf_returns_the_index_for_valid_elements(){
	int resultIndex1, resultIndex2, resultIndex3;
	char element1 = '1', element2 = '2', element3 = '3';
	char data1 = '1', data2 = '2';
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	resultIndex1 = indexOf(list, (void *)element1);
	resultIndex2 = indexOf(list, (void *)element2);
	resultIndex3 = indexOf(list, (void *)element3);

	assertEqual((int)resultIndex1, 0);
	assertEqual((int)resultIndex2, 1);
	assertEqual((int)resultIndex3, -1);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__indexOf_03__indexOf_returns_the_index_for_valid_elements(){
	int resultIndex1, resultIndex2, resultIndex3;
	char *element1 = "01", *element2 = "02", *element3 = "03";
	char *data1 = "01", *data2 = "02";
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);

	resultIndex1 = indexOf(list, (void *)element1);
	resultIndex2 = indexOf(list, (void *)element2);
	resultIndex3 = indexOf(list, (void *)element3);

	assertEqual((int)resultIndex1, 0);
	assertEqual((int)resultIndex2, 1);
	assertEqual((int)resultIndex3, -1);
	free(firstNodeToInsert);
	free(secondNodeToInsert);
}

void test__deleteElementAt_01__deleteElementAt_at_index_0(){
	void *result, *resultAfterDeletion;
	int data1 = 1, data2 = 2, data3 = 3;
	int index = 0;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = deleteElementAt(&list, index);
	resultAfterDeletion = getElementAt(list, index);

	assertEqual((int)result, 1);
	assertEqual((int)resultAfterDeletion, 2);
}

void test__deleteElementAt_02__deleteElementAt_at_index_1(){
	void *result, *resultAfterDeletion;
	int data1 = 1, data2 = 2, data3 = 3;
	int index = 1;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = deleteElementAt(&list, index);
	resultAfterDeletion = getElementAt(list, index);

	assertEqual((int)result, 2);
	assertEqual((int)resultAfterDeletion, 3);
}

void test__deleteElementAt_03__deleteElementAt_at_index_2(){
	void *result;
	int *resultAfterDeletion;
	int data1 = 1, data2 = 2, data3 = 3;
	int index = 2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = deleteElementAt(&list, index);
	resultAfterDeletion = get_last_element(list);

	assertEqual((int)result, 3);
	assertEqual(*resultAfterDeletion, 2);
}

void test__deleteElementAt_04__deleteElementAt_returns_NULL_for_invalid_index(){
	void *result;
	int *resultAfterDeletion;
	int data1 = 1, data2 = 2, data3 = 3;
	int index = 5;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = deleteElementAt(&list, index);
	resultAfterDeletion = get_last_element(list);

	assertEqual((int)result, 0);
	assertEqual(*resultAfterDeletion, 3);
}


void test__deleteElementAt_05__deleteElementAt_returns_NULL_for_negative_index(){
	void *result;
	int *resultAfterDeletion;
	int data1 = 1, data2 = 2, data3 = 3;
	int index = -2;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = deleteElementAt(&list, index);
	resultAfterDeletion = get_last_element(list);

	assertEqual((int)result, 0);
	assertEqual(*resultAfterDeletion, 3);
}

void test__asArray_01__asArray_contains_3_elements_reference(){
	int length,array[3];
	int data1 = 1, data2 = 2, data3 = 3;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);
	length = asArray(list,(void**)array);

	assertEqual(length,3);
	assertEqual(*(int*)array[0],1);
	assertEqual(*(int*)array[1],2);
	assertEqual(*(int*)array[2],3);
};


void test__asArray_02__asArray_contains_3(){
	int length,array[3];
	int data1 = 1, data2 = 2, data3 = 3;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);
	length = asArray(list,(void**)array);

	assertEqual(length,3);
	assertEqual(*(int*)array[0],1);
	assertEqual(*(int*)array[1],2);
	assertEqual(*(int*)array[2],3);
};

void test__asArray_03__asArray_will_contain_lenth_2(){
	char *data1 = "STRING-DATA1";
	char *data2 = "STRING-DATA2";
	char *array[2];
	int length;
	Node_ptr node1 = create_node((void*)data1);
	Node_ptr node2 = create_node((void*)data2);
	LinkedList list = createList();

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	length = asArray(list,(void**)array);
	assertEqual(length,2);

	assertEqual(strcmp(*(char**)array[0],"STRING-DATA1"),0);
	assertEqual(strcmp(*(char**)array[1],"STRING-DATA2"),0);
	free(node1);
	free(node2);
};

int isPositive(void* element){
	return ((int)element > 0);
};

void test_filter_returns_list_of_data_23_and_45(){
	LinkedList *result;

	int data1 = 1, data2 = -2, data3 = 3;
	LinkedList list = createList();
	Node_ptr firstNodeToInsert = create_node((void*)data1);
	Node_ptr secondNodeToInsert = create_node((void*)data2);
	Node_ptr thirdNodeToInsert = create_node((void*)data3);

	add_to_list(&list, firstNodeToInsert);
	add_to_list(&list, secondNodeToInsert);
	add_to_list(&list, thirdNodeToInsert);

	result = filter(list,isPositive);

	assertEqual((int)result->count,2);
	free(result);
};