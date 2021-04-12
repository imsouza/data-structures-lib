#ifndef DSLIB_H_
#define DSLIB_H_
#ifndef NEXT
#define NEXT(element) \
(element = (element + 1) % index->max)
#endif
#ifndef FREQ
#define FREQ 256
#endif
#ifndef SIZE
#define SIZE 25
#endif
#ifndef HCOL
#define HCOL 5
#endif

typedef struct stack Stack;
typedef struct queue Queue;
typedef struct tree BSTree;
typedef struct htree *Hufftree;
typedef struct list List;
typedef struct map *Map;
typedef struct set Set;

typedef struct node {
  int item;
  struct node *next;
  struct node *prev;
} Node;

extern const char * const messages[];

Stack *createStack(int max);
int stackIsEmpty(Stack *index);
int stackIsFull(Stack *index);
void stackPush(char element, Stack *index);
char stackPop(Stack *index);
char stackTop(Stack *index);
int getStackSize(Stack *index);
void displayStack(Stack *index);
void deleteStack(Stack *index);

Queue *createQueue(int max);
int queueIsEmpty(Queue *index);
int queueIsFull(Queue *index);
void enqueue(char element, Queue *index);
char dequeue(Queue *index);
int getQueueSize(Queue *index);
void displayQueue(Queue *index);
void deleteQueue(Queue *index);

BSTree *findMax(BSTree *node);
void insertNode (int key, BSTree **node);
int treeIsEmpty (BSTree *node);
void displayPreOrder (BSTree *node);
void displayInOrder (BSTree *node);
void displayPostOrder (BSTree *node);
char getRoot(BSTree *index);
int getNode(BSTree *index);
int nodeExists(BSTree *index);
int search(int key, BSTree **node);
BSTree *findMin(BSTree *node);
BSTree *findMax(BSTree *node);
void deleteTree(BSTree *node);

List *createLinkedList();
void insertItemBeginLinkedList(int item, List *list);
void insertItemEndLinkedList(int item, List *list);
void displayLinkedList(List *list);
void displayReverseLinkedList(List *list);
int getLinkedListNodeItem(Node *index);
Node *getLinkedListHead(List *list);
Node *getLinkedListTail(List *list);
Node *searchLinkedListItem(int item, List *list);
int getLinkedListSize(List *list);
int linkedListIsEmpty(List *list);
void removeLinkedListItem(int item, List *list);
void deleteLinkedList(List *list);

Map createMap(int key, char *value, Map index);
void insertMap(int key, char *value, Map *index);
int removeMap(int key, Map *index);
int mapKeyExists(int key, Map index);
void displayMap(Map index);
void deleteMap(Map *index);

Hufftree createHufftreeNode (Hufftree left, char chr, \
int frq, Hufftree right);
int *frequency(char *string);
void insertTree(Hufftree tree, Hufftree *forest, int *qty);
Hufftree removeTree(Hufftree *forest, int *qty);
Hufftree createHufftree (char *string);
void displayHufftree(Hufftree tree);
void displayLeaves(Hufftree tree);
void createTable(Hufftree tree, char *T[]);
void compressString(char *string, Hufftree tree);
void decompressString(char *string, Hufftree tree);
void deleteHufftree(Hufftree tree);

Set *createEmptySet(int max);
void deleteSet(Set *set);
void insertItemSet(int item, Set *set); 
void removeItemSet(int item, Set *set);
int getSetSize(Set *set);
int setIsEmpty(Set *set);
int searchItemSet(int item, Set *set);
void displaySet(Set *set);
Set *unionSet(Set *A, Set *B);
Set *intersectionSet(Set *A, Set *B);
Set *differenceSet(Set *A, Set *B);
int getHighestSetValue(Set *set);
int getLowestSetValue(Set *set);

#endif