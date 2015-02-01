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
}

void *getElementAt(LinkedList list, int index){
	int count;
	if(list.count<index || index<0)
		return NULL;
	for(count = 0; count<=index; count++){
		if(count == index)
			return list.head->data;
		list.head = list.head->next;
	}
	return NULL;
}

int indexOf(LinkedList list, void *data){
	int count;
	for(count = 0; count<list.count; count++){
		if(list.head->data == data)
			return count;
		list.head = list.head->next;
	}
	return -1;
}

void* deleteHead(LinkedList *list,int index){
	Node_ptr walker = list->head;
	list->head = list->head->next;
	if(list->count==0)
		list->tail = NULL;
	return walker->data;
};

void * deleteElementAt(LinkedList* list, int index){
	int i=0;
	Node_ptr walker = list->head;
	Node_ptr temp;
	if(index==0)
		return deleteHead(list,0);
	for(i=0;i < list->count;i++){
		temp = walker;
		walker = walker->next;
		if(i==index-1){
			list->count--;
			(walker->next==NULL)?(list->tail = temp):(temp->next = walker->next);
			return walker->data;
		};
	}
	return NULL;
};