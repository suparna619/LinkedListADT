#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList *newList = malloc(sizeof(LinkedList));
	newList->head = NULL;
	newList->tail = NULL;
	newList->count = 0;
	return *newList;
}

Node *create_node(void *data){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

int add_to_list(LinkedList *list, Node *node){
	if(list->head == NULL)
		list->head = node;
    else
    	list->tail->next = node;
	list->tail = node;
	list->count++;
    return list->count;
}

void *get_first_element(LinkedList list){
	return list.head;
}

void *get_last_element(LinkedList list){
	return list.tail;
}

void traverse(LinkedList list, functionRef* operation){
	while(list.head != NULL){
		operation(&(list.head->data));
		list.head = list.head->next;
	}
};