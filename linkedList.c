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

Node_ptr getNodeAt(LinkedList *list, int index){
	int counter;
	Node_ptr walker = list->head;
	if(index > list->count-1)
		return NULL;
	for(counter=0; counter<=index ;++counter){
		if(counter == index)
			return walker;
		walker = walker->next;
	}
	return NULL;
};

void* deleteHead(LinkedList *list, int index){
	void* data = list->head->data;
	(list->head == list->tail) && (list->tail = NULL);
	list->head = list->head->next;
	list->count -= 1;
	return data;
}

void *deleteTail(LinkedList *list, int index){
	Node_ptr walker = list->head, previous_node, target_node;
	previous_node = getNodeAt(list, index -1);
	target_node = getNodeAt(list, index);
	list->tail = previous_node;
	previous_node->next = NULL;
	list->count -= 1;
	return target_node->data;
}

void *deleteMiddle(LinkedList *list, int index){
	Node_ptr walker = list->head, previous_node, target_node;
	previous_node = getNodeAt(list, index -1);
	target_node = getNodeAt(list, index);
	previous_node->next = target_node->next;
	list->count -= 1;
	return target_node->data;
}

void * deleteElementAt(LinkedList *list, int index){
	Node_ptr walker = list->head, previous;
	if(index > list->count-1) return NULL;
	if(index == 0)	return deleteHead(list,index);
	if(index == list->count-1)
		return deleteTail(list,index);
	else
		return deleteMiddle(list,index);
};

int asArray(LinkedList list, void** array){
	int counter;
	for (counter = 0; counter < list.count; counter++)
	{
		array[counter] = list.head;
		list.head = list.head->next;
	}
	return counter;
}

LinkedList * filter(LinkedList list,MatchFunc* funcRef){
	LinkedList *result = malloc(sizeof(LinkedList));
	int counter;
	*result = createList();
	for(counter = 0; counter < list.count; counter++){
		if(funcRef(list.head->data))
			add_to_list(result,list.head);
		list.head = list.head->next;
	}
	return result;
}