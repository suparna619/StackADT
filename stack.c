#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Stack createStack(void){
	Stack newStack;
	LinkedList_ptr list = calloc(1,sizeof(LinkedList));
	newStack.list = list;
	newStack.top = &(list->tail);
	return newStack;
}

int push(Stack stack, void *data){
	Node_ptr newNode = create_node(data);
	int result = add_to_list(stack.list, newNode);
	if(!result)
		return -1;
	return stack.list->count;
}

void *pop(Stack stack){
	return deleteElementAt(stack.list, stack.list->count-1);
}