#include "linkedList.h"
typedef struct stack Stack;

struct stack
{
	LinkedList *list;
	Node **top;
};

Stack createStack(void);
int push(Stack *, void *);
void *pop(Stack);


typedef struct emp Employee;
struct emp{
	int id;
	char name[5];
};