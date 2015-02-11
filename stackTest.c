#include "stack.h"
#include <stdlib.h>
#include "expr_assert.h"


void test_createStack_creates_an_empty_stack(){
	Stack stack = createStack();
	assert(stack.list != NULL);
	assertEqual(stack.list->count, 0);
	assert((*stack.top) == NULL);
	free(stack.list);
}

void test_push_insert_an_int_element_in_stack(){
	int data = 5, countNode;
	Stack stack = createStack();
	countNode = push(stack,&data);
	assertEqual(countNode, 1);
	assertEqual(*(int*)(*stack.top)->data,data);
}

void test_pop_delete_the_element_of_top_from_stack(){
	int data1=1,data2 =4,countNode;
	int poped;
	Stack s = createStack();

	countNode = push(s,&data1);
	countNode = push(s,&data2);
	assertEqual(countNode, 2);

	poped = *(int *)pop(s);
	assertEqual(poped, data2);
	assert((*s.top)->data==&data1);
	assertEqual(*(int*)(*s.top)->data,data1);
}