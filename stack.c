#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack createStack(){
	LinkedList *new_list= calloc(1, sizeof(LinkedList));
	Stack new_stack = { new_list, &new_list->tail };
	return new_stack;
}

int push(Stack *stack, void *data){
	Node *new_node = create_node(data);
	int count = stack->list->count;
	add_to_list(stack->list,new_node);
	stack->top = &new_node;
	if(stack->list->count == count+1){
		return stack->list->count;
	}
	return -1;
}

void * pop(Stack stack){
	return deleteElementAt(stack.list, stack.list->count-1);
};