typedef char * String;

typedef struct node Node;
typedef Node * Node_ptr;
typedef struct linkedList LinkedList;
typedef LinkedList * LinkedList_ptr;

struct node
{
	void *data;
	Node *next;
};

struct linkedList
{
	Node *head;
	Node *tail;
	int count;
};


LinkedList createList(void);
Node *create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void traverse(LinkedList, void (*)(void *data));
void *getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **);
LinkedList *filter(LinkedList, int (*)(void *));