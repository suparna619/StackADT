#include "linkedList.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void test_createList_creates_a_new_linked_list(){
	LinkedList newList = createList();
	assert(newList.head == NULL);
	assert(newList.tail == NULL);
	assert(newList.count == 0);
}

void test_create_node_creates_a_new_node_with_int_data(){
	int data = 5;
	Node *newNode = create_node(&data);
	assert(*(int *)newNode->data == data);
	assert(newNode->next == NULL);
	free(newNode);
}

void test_create_node_creates_a_new_node_with_char_data(){
	char data = '5';
	Node *newNode = create_node(&data);
	assert(*(char *)newNode->data == data);
	assert(newNode->next == NULL);
	free(newNode);
}

void test_create_node_creates_a_new_node_with_float_data(){
	float data = 5.2;
	Node *newNode = create_node(&data);
	assert(*(float*)newNode->data == data);
	assert(newNode->next == NULL);
	free(newNode);
}


void test_add_to_list_add_a_new_node_in_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data = 2, result;
	Node *newNode = create_node(&data);
	result = add_to_list(&list, newNode);
	assertEqual(list.count, 1);
	assert(list.head == newNode);
	free(newNode);
}

void test_add_to_list_add_two_new_node_in_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data1 = 2, data2 = 3;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	assertEqual(list.count, 2);
	assert(list.head == newNode1);
	free(newNode1);
	free(newNode2);
}

void test_add_to_list_add_a_NULL_node_in_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data = 2, result;
	Node *newNode = NULL;
	result = add_to_list(&list, newNode);
	assert(result == 0);
	assertEqual(list.count, 0);
	assert(list.head == newNode);
	free(newNode);
}

void test_add_to_list_add_one_new_NULL_node_and_one_new_node_with_data_in_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data = 2;
	Node *newNode1 = NULL;
	Node *newNode2 = create_node(&data);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	assertEqual(list.count, 1);
	assert(list.head == newNode2);
	free(newNode1);
	free(newNode2);
}

void test_get_first_element_returns_the_data_in_head_of_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data1 = 2, data2 = 3, *result;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	result = get_first_element(list);
	assert(*(int *)result == data1);
	free(newNode1);
	free(newNode2);	
}

void test_get_firstst_element_returns_the_data_in_head_of_a_previously_created_linked_list_with_float_element(){
	LinkedList list = createList();
	float data1 = 2.5, data2 = 3.6, *result;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	result = get_first_element(list);
	assertEqual(*(float *)result, data1);
	free(newNode1);
	free(newNode2);	
}

void test_get_last_element_returns_the_data_in_tail_of_a_previously_created_linked_list(){
	LinkedList list = createList();
	int data1 = 2, data2 = 3, *result;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	result = get_last_element(list);
	assert(*(int *)result == data2);
	free(newNode1);
	free(newNode2);	
}

void test_get_last_element_returns_the_data_in_tail_of_a_previously_created_linked_list_with_float_element(){
	LinkedList list = createList();
	float data1 = 2.5, data2 = 3.6, *result;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);

	result = get_last_element(list);
	assertEqual(*(float *)result, data2);
	free(newNode1);
	free(newNode2);	
}

void increment_by_one(void *data){
	(*(int *)data)++;
}

void test_tarverse_increased_two_elements_by_one_in_a_linked_list(){
	LinkedList list = createList();
	int data1 = 2, data2 = 3;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);
	traverse(list, increment_by_one);

	assert(*(int *)newNode1->data == 3);
	assert(*(int *)newNode2->data == 4);
	free(newNode1);
	free(newNode2);	
}


void test_tarverse_increased_three_elements_by_one_in_a_linked_list(){
	LinkedList list = createList();
	int data1 = 2, data2 = 3, data3 = 4;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);
	Node *newNode3 = create_node(&data3);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);
	add_to_list(&list, newNode3);
	traverse(list, increment_by_one);

	assert(*(int *)newNode1->data == 3);
	assert(*(int *)newNode2->data == 4);
	assert(*(int *)newNode3->data == 5);
	free(newNode1);
	free(newNode2);
	free(newNode3);
}

void toUppercase(void *data){
	(*(char *)data) = toupper(*(char *)data);
}

void test_tarverse_change_char_elements_into_uppercase_of_a_linked_list(){
	LinkedList list = createList();
	int data1 = 'a', data2 = 'b', data3 = 'c';
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);
	Node *newNode3 = create_node(&data3);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);
	add_to_list(&list, newNode3);
	traverse(list, toUppercase);

	assert(*(int *)newNode1->data == 'A');
	assert(*(int *)newNode2->data == 'B');
	assert(*(int *)newNode3->data == 'C');
	free(newNode1);
	free(newNode2);
	free(newNode3);
}

void mathFloor(void *data){
	(*(float *)data) = floor(*(float *)data);
}

void test_tarverse_change_float_elements_into_its_float_value_of_a_linked_list(){
	LinkedList list = createList();
	float data1 = 1.4, data2 = 3.7, data3 = 2.5;
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);
	Node *newNode3 = create_node(&data3);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);
	add_to_list(&list, newNode3);
	traverse(list, mathFloor);

	assert(*(float *)newNode1->data == 1.0);
	assert(*(float *)newNode2->data == 3.0);
	assert(*(float *)newNode3->data == 2.0);
	free(newNode1);
	free(newNode2);
	free(newNode3);
}

void test_tarverse_change_double_elements_into_its_float_value_of_a_linked_list(){
	double data1 = 1.54, data2 = 0.012, data3 = 99.9;
	LinkedList list = createList();
	Node *node1 = create_node(&data1);
	Node *node2 = create_node(&data2);
	Node *node3 = create_node(&data3);

	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	traverse(list, mathFloor);

	assertEqual(*(double*)node1->data, 1.000000);
	assertEqual(*(double*)node2->data, 0.000000);
	assertEqual(*(double*)node3->data, 99.000000);
	free(node1);
	free(node2);
	free(node3);
}

void stringToLowercase(void *data){
	int i = 0;
	while(((char *)data)[i]){
		((char *)data)[i] = (char)tolower(((char *)data)[i]);
		i++;
	}
}

void test_tarverse_change_String_elements_into_its_float_value_of_a_linked_list(){
	LinkedList list = createList();
	char data1[] = "ABC", data2[] = "DEF", data3[] = "GHI";
	Node *newNode1 = create_node(&data1);
	Node *newNode2 = create_node(&data2);
	Node *newNode3 = create_node(&data3);

	add_to_list(&list, newNode1);
	add_to_list(&list, newNode2);
	add_to_list(&list, newNode3);
	traverse(list, stringToLowercase);

	assertEqual(strcmp((char*)newNode1->data,"abc"),0);
	assertEqual(strcmp((char*)newNode2->data,"def"),0);
	assertEqual(strcmp((char*)newNode3->data,"ghi"),0);

	free(newNode1);
	free(newNode2);
	free(newNode3);
}

void test_getElementAt_returns_the_first_element_of_list(){
	int data = 1;
	LinkedList list = createList();
	Node *node = create_node(&data);
	int result = add_to_list(&list, node);
	assertEqual(*(int*)getElementAt(list, 0),1);
	free(node);
}

void test_getElementAt_returns_the_second_element_of_list(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(int*)getElementAt(list, 1),4);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_floating_point_numbers(){
	float data1 = 2.5, data2 = 4.1, data3 = 6.3;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);	
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(float*)getElementAt(list, 1), (float)4.1);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_characters(){
	char data1 = '1', data2 = '2', data3 = '3';
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(char*)getElementAt(list, 1),'2');
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_strings(){
	char *data1 = "123", *data2 = "456", *data3 = "789";
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(strcmp(*(String*)getElementAt(list, 2),"789"),0);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_0_when_element_is_present_at_first_position_in_int_data_type(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data1),0);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_float_data_type(){
	float data1 = 10.23, data2 = 44.24, data3 = 86.78;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_char_data_type(){
	char data1 = 'k', data2 = 'a', data3 = 'v';
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_string_data_type(){
	char *data1 = "123", *data2 = "456", *data3 = "789";
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_minus_1_when_element_is_not_present_in_int_data_type(){
	int data1 = 2, data2 = 4, data3 = 6, data4 = 20;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data4),-1);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_0_deletes_the_first_element(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual(*((int*)deleteElementAt(&list, 0)), data1);
	assertEqual(indexOf(list, &data3),1);
	assertEqual(list.count,2);
	assert(list.head == node2);
    assert(list.tail == node3);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_2_deletes_the_last_element() {
    int data1 = 2, data2 = 4, data3 = 6;
    LinkedList list = createList();
    Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

    assertEqual(*(int*)deleteElementAt(&list, 2), data3);
    assert(list.head == node1);
    assert(list.tail == node2);
    free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_1_deletes_the_second_element(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual(*((int*)deleteElementAt(&list, 1)), data2);
	assertEqual(indexOf(list, &data3),1);
	assertEqual(list.count,2);
	assert(list.head == node1);
	assert(list.tail == node3);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_returns_NULL__when_index_is_less_than_zero(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual((int)deleteElementAt(&list, -1), 0);
}

void test_deleteElementAt_returns_NULL__when_index_is_equal_with_count(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual((int)deleteElementAt(&list, 3), 0);
}

void test_deleteElementAt_returns_NULL_when_index_is_greater_than_count(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual((int)deleteElementAt(&list, 5), 0);
}

void test_deleteElementAt_returns_NULL_when_count_is_zero(){
	LinkedList list = createList();

	assertEqual(list.count,0);
	assertEqual((int)deleteElementAt(&list, 1), 0);
}

void test_deleteElementAt_list_will_be_empty_if_there_is_only_one_node(){
	int data1 = 2;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);

	add_to_list(&list,node1);

	assertEqual(list.count,1);
	assertEqual(*((int*)deleteElementAt(&list, 0)), data1);
	assert(list.head == NULL);
	assert(list.tail == NULL);
	free(node1);
}

void test_deleteElementAt_after_deletion_head_tail_points_to_a_single_node_1(){
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assertEqual(list.count,2);
	assertEqual(*((int*)deleteElementAt(&list, 1)), data2);
	assert(list.head == node1);
	assert(list.tail == node1);
	free(node1);
	free(node2);
}

void test_deleteElementAt_after_deletion_head_tail_points_to_a_single_node_2(){
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assertEqual(list.count,2);
	assertEqual(*((int*)deleteElementAt(&list, 0)), data1);
	assert(list.head == node2);
	assert(list.tail == node2);
	free(node1);
	free(node2);
}

void test_asArray_filled_an_array_with_the_integer_elements_of_a_linked_list(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	void **array;
	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	array = malloc(sizeof(void *)*list.count);

	assert(asArray(list, array) == 3);
	assert(*(int *)(array)[0] == 2);
	assert(*(int *)(array)[1] == 4);	
	assert(*(int *)(array)[2] == 6);
	free(array);
}

int isPositive(void *data){
	return *(int *)data > 0;
}

void test_filter_returns_a_linked_list_populets_with_positive_data(){
	int data1 = 2, data2 = -4, data3 = 6;
	LinkedList list = createList();
	LinkedList_ptr linked_list_of_positive_numbers;

	Node_ptr node1 = create_node(&data1);
	Node_ptr node2 = create_node(&data2);
	Node_ptr node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	linked_list_of_positive_numbers = filter(list, isPositive);

	assert(linked_list_of_positive_numbers->head->data == &data1);
	assert(linked_list_of_positive_numbers->tail->data == &data3);
	assertEqual(linked_list_of_positive_numbers->count, 2);

	free(node1);
	free(node2);
	free(node3);
}


int isEven(void *data){
	return *(int*)data % 2 == 0;
}

void test_filter_gives_list_of_even_numbers(){
	int data1 = 18, data2 = 12, data3 = 13, data4 = 15;
	LinkedList list = createList();
	LinkedList *evenNumbers;
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3), *node4 = create_node(&data4);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	evenNumbers = filter(list, isEven);

	assert(evenNumbers->head->data==&data1);
	assert(evenNumbers->tail->data==&data2);
	assertEqual(evenNumbers->count,2)
	free(node1);
	free(node2);
	free(node3);
	free(node4);
}