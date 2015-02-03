typedef struct node Node;
typedef Node * Node_ptr;
typedef struct student Student;

typedef struct linked_list LinkedList;
typedef LinkedList * linkedList_ptr;
typedef void functionRef(void*); 
typedef int MatchFunc (void*);


struct student
{
	int id;
	char *name;
	int score;
	Student *next;	
};

struct linked_list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void* data;
	Node_ptr next;
};


LinkedList createList(void);
Node *create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList list, functionRef* operation);
void *getElementAt(LinkedList list, int index);
int indexOf(LinkedList list, void *data);
void * deleteElementAt(LinkedList* list, int index);
int asArray(LinkedList list, void** array);
LinkedList * filter(LinkedList list,MatchFunc* funcRef);