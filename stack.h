#include "linkedList.h"

typedef struct stack Stack;
struct stack
{
	LinkedList_ptr list;
	Node_ptr* top;
};

Stack createStack(void);
int push(Stack, void *);
void *pop(Stack);