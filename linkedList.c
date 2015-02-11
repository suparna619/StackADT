#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList(void){
	LinkedList newList;
	newList.head = NULL;	//(*newList).head = NULL;
	newList.tail = NULL;
	newList.count = 0;
	return newList;
}

Node *create_node(void *data){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int add_to_list(LinkedList *list, Node *node){
	if(node == NULL)
		return 0;
	if(list->head == NULL && list->tail == NULL)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*function_ptr)(void *data)){
	Node_ptr walker = list.head;
	while(walker != NULL){
		function_ptr(walker->data);
		walker = walker->next;
	}	
}

void *getElementAt(LinkedList list, int index){
	int i;
	Node_ptr walker = list.head;
	for(i = 0; i<index; i++)
		walker = walker->next;
	return walker->data;
}

int indexOf(LinkedList list, void *data){
	int i;
	Node_ptr walker = list.head;
	for(i = 0; i<list.count; i++){
		if(data == walker->data)
			return i;
		walker = walker->next;
	}
	return -1;
}

void *deleteElementAtStart(LinkedList *list, int index){
	void *data = list->head->data;
	list->head = list->head->next;
	if(list->count == 1)
		list->tail = NULL;
	list->count--;
	return data;
}

void *deleteElementAtEnd(LinkedList *list, int index){
	int i;
	void *data = list->tail->data;
	Node_ptr walker = list->head;
	for(i = 0; i< list->count-2; i++)
		walker = walker->next;
	list->tail = walker;
	list->count--;
	return data;
}

void *deleteElementAtMiddle(LinkedList *list, int index){
	int i;
	void *data;
	Node_ptr walker = list->head;
	for(i= 0; i<index-2; i++)
		walker = walker->next;
	data = walker->next->data;
	walker->next = walker->next->next;
	list->count--;
	return data;
}

void *deleteElementAt(LinkedList *list, int index){
	if(list->count == 0 || index >= list->count || index <0)
		return NULL;
	if(index == 0)
		return deleteElementAtStart(list, index);
	if(index == list->count-1)
		return deleteElementAtEnd(list, index);
	else
		return deleteElementAtMiddle(list, index);
}

int asArray(LinkedList list, void **array){
	int i = 0;
	Node_ptr walker = list.head;
	while(i<list.count){
		array[i] = walker->data;
		walker = walker->next;
		i++;
	}
	return i;
}

LinkedList *filter(LinkedList list, int (*function_ptr)(void *data)){
	LinkedList_ptr resultedLinkedList;
	Node_ptr walker = list.head;
	resultedLinkedList = malloc(sizeof(LinkedList));
	while(walker != NULL){
		if(function_ptr(walker->data))
			add_to_list(resultedLinkedList, create_node(walker->data));
		walker = walker->next;
	}
	return resultedLinkedList;
}