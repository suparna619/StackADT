#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr_assert.h"
#include "stack.h"


Stack stack;
void test__creatStack_01__creatStack_initalize_a_stack_where_top_filled_with_NULL_and_has_a_blank_list(){
	Stack new_stack = createStack();
	assertEqual((int)new_stack.list->count,0);
	assertEqual(*(int*)new_stack.top,0);
	free(new_stack.list);
}


void test_push_puts_the_data_in_stack(){
	int data = 1;
	stack = createStack();
	assertEqual(push(&stack, &data),data);
	assertEqual(*(int*)stack.list->tail->data, data);
	assertEqual(*(int *)(*stack.top)->data, data);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_INTEGER(){
	int data1 = 10, data2 = 20;
	stack = createStack();
	assertEqual(push(&stack, &data1),1);
	assertEqual(push(&stack, &data2),2);
	assert(*(int*)stack.list->head->data == data1);
	assert(*(int*)stack.list->tail->data == data2);
	assertEqual(*(int *)(*stack.top)->data, data2);
}

void test_push_should_return_number_of_pushed_elements_on_the_stack_for_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	stack = createStack();
	assertEqual(push(&stack, &a), 1);
	assertEqual(push(&stack, &b), 2);
	assertEqual(push(&stack, &b), 3);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_FLOAT(){
	float a = 99.12345, b = 31.242409;
	stack = createStack();
	assertEqual(push(&stack, &a),1);
	assertEqual(push(&stack, &b),2);
	assert(*(float*)stack.list->head->data == a);
	assert(*(float*)stack.list->tail->data == b);
	assertEqual(*(float *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_DOUBLE(){
	double a = 99.12345, b = 31.242409;
	stack = createStack();
	assertEqual(push(&stack, &a),1);
	assertEqual(push(&stack, &b),2);
	assert(*(double*)stack.list->head->data == a);
	assert(*(double*)stack.list->tail->data == b);
	assertEqual(*(double *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_STRING(){
	char *a = "Age of Empires", b[] = "Call of Duty";
	stack = createStack();
	assertEqual(push(&stack, a), 1);
	assertEqual(push(&stack, b), 2);
	assert((char*)stack.list->head->data == a);
	assert((char*)stack.list->tail->data == b);
	assertEqual(strcmp((char *)(*stack.top)->data, b), 0);
}

void test_top_should_point_to_the_latest_pushed_element_on_stack_for_STRING(){
	char a[] = "Age of Empires", b[] = "Call of Duty", c[] = "Prince of Persia";
	stack = createStack();
	assertEqual(push(&stack, a), 1);
	assertEqual(push(&stack, b), 2);
	assertEqual(push(&stack, c), 3);
	assertEqual(strcmp((char *)(*stack.top)->data, c), 0);
}

void test_top_should_point_to_the_latest_pushed_element_on_stack_for_STRUCTURE(){
	Employee a = {1,"Jai"}, b = {2,"Ram"}, c = {3,"Jiya"};
	stack = createStack();
	assertEqual(push(&stack, &a), 1);
	assertEqual(push(&stack, &b), 2);
	assertEqual(push(&stack, &c), 3);
	assert((*stack.top)->data == &c);
	assertEqual(((Employee*)(*stack.top)->data)->id, 3);
	assertEqual(strcmp(((Employee*)(*stack.top)->data)->name, c.name),0);
}

void test_pop_should_return_popped_element_from_top_of_stack_for_INTEGER(){
	int a = 10, b = 20, c = 30;
	stack = createStack();
	assertEqual(push(&stack, &a),1);
	assertEqual(push(&stack, &b),2);
	assertEqual(push(&stack, &c),3);
	assertEqual(*(int*)pop(stack),30);
	assertEqual(*(int*)pop(stack),20);
	assertEqual(*(int*)pop(stack),10);
}

void test_pop_should_pop_last_element_from_stack_and_decreases_no_of_elements_for_INTEGER(){
	int a = 10, b = 20, c = 30;
	stack = createStack();
	assertEqual(push(&stack, &a),1);
	assertEqual(push(&stack, &b),2);
	assertEqual(push(&stack, &c),3);
	assertEqual(*(int*)pop(stack),30);
	assertEqual(stack.list->count,2);
	assertEqual(*(int*)pop(stack),20);
	assertEqual(stack.list->count,1);
	assertEqual(*(int*)pop(stack),10);
	assertEqual(stack.list->count,0);
}
