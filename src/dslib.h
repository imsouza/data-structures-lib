#ifndef DSLIB_H_
#define DSLIB_H_
#ifndef NEXT
#define NEXT(element) \
(element = (element + 1) % queue->max)
#endif
#ifndef FREQ
#define FREQ 256
#endif
#ifndef SIZE
#define SIZE 200
#endif
#ifndef HCOL
#define HCOL 5
#endif

typedef struct stack Stack;
typedef struct queue Queue;
typedef struct bstree BSTree;
typedef struct htree *Hufftree;
typedef struct list List;
typedef struct map *Map;
typedef struct set Set;
typedef struct prioq PrioQ;

typedef struct node {
  int item;
  struct node *next;
  struct node *prev;
} Node;

typedef enum {
  false,
  true
} bool;

extern const char * const messages[];

Stack *stackCreate(int max);
int stackIsEmpty(Stack *stack);
int stackIsFull(Stack *stack);
void stackPush(char element, Stack *stack);
char stackPop(Stack *stack);
char stackTop(Stack *stack);
int stackSize(Stack *stack);
void stackDisplay(Stack *stack);
void stackDestroy(Stack *stack);

Queue *queueCreate(int max);
int queueIsEmpty(Queue *queue);
int queueIsFull(Queue *queue);
void queueEnqueue(char element, Queue *queue);
char queueDequeue(Queue *queue);
int queueSize(Queue *queue);
void queueDisplay(Queue *queue);
void queueDestroy(Queue *queue);

BSTree *binarySearchTreeCreateNode(int item);
BSTree *binarySearchTreeInsertNode(BSTree *newNode, BSTree *root);
BSTree *binarySearchTreeRemoveNode(int key, BSTree *root);
BSTree *binarySearchTreeSearch(int key, BSTree *root);
BSTree *binarySearchTreeFindMin(BSTree *root);
BSTree *binarySearchTreeFindMax(BSTree *root);
int binarySearchTreeIsEmpty(BSTree *root);
void binarySearchTreeDisplayPreOrder(BSTree *root);
void binarySearchTreeDisplayInOrder(BSTree *root);
void binarySearchTreeDisplayPostOrder(BSTree *root);
void binarySearchTreeDisplayTree(int level, BSTree *root);
int binarySearchTreeGetItem(BSTree *root);
int binarySearchTreeItemExists(int item, BSTree *root);
int binarySearchTreeTotalNodes(BSTree *root);
int binarySearchTreeHeight(BSTree *root);
int binarySearchTreeIsBalanced(BSTree *root);
int binarySearchTreeTotalLeafs(BSTree *root);
void binarySearchTreeDestroy(BSTree *root);

List *linkedListCreate();
Node *linkedListHead(List *list);
Node *linkedListTail(List *list);
Node *linkedListSearch(int item, List *list);
void linkedListInsertItemBegin(int item, List *list);
void linkedListInsertItemEnd(int item, List *list);
void linkedListDisplay(List *list);
void linkedListReverseDisplay(List *list);
int linkedListNode(Node *index);
int linkedListSize(List *list);
int linkedListIsEmpty(List *list);
void linkedListRemove(int item, List *list);
void linkedListDestroy(List *list);

Map mapCreate(int key, char *value, Map index);
void mapInsert(int key, char *value, Map *index);
int mapRemove(int key, Map *index);
int mapKeyExists(int key, Map index);
void mapDisplay(Map index);
void mapDestroy(Map *index);

Hufftree hufftreeCreateNode(Hufftree left, char chr, int frq, Hufftree right);
Hufftree hufftreeRemove(Hufftree *forest, int *qty);
Hufftree hufftreeCreate(char *string);
int *hufftreeFrequency(char *string);
void hufftreeInsert(Hufftree tree, Hufftree *forest, int *qty);
void hufftreeDisplay(Hufftree tree);
void hufftreeDisplayLeaves (Hufftree tree);
void hufftreeCreateTable(Hufftree tree, char *T[]);
void hufftreeCompressString(char *string, Hufftree tree);
void hufftreeDecompressString(char *string, Hufftree tree);
void hufftreeDestroy(Hufftree tree);

Set *setCreate(int max);
Set *setUnion(Set *A, Set *B);
Set *setIntersection(Set *A, Set *B);
Set *setDifference(Set *A, Set *B);
void setInsert(int item, Set *set);
void setRemove(int item, Set *set);
int setSize(Set *set);
int setHighestValue(Set *set);
int setLowestValue(Set *set);
int setIsEmpty(Set *set);
int setSearch(int item, Set *set);
void setDisplay(Set *set);
void setDestroy(Set *set);

PrioQ *priorityQueueCreate();
void priorityQueueDestroy(PrioQ *queue);
void priorityQueueInsert( int value, PrioQ *queue);
void priorityQueueRemoveHighestPrio(PrioQ *queue);
int priorityQueueFirst(PrioQ *queue);
bool priorityQueueIsEmpty(PrioQ *queue);
bool priorityQueueIsFull(PrioQ *queue);
int priorityQueueSize(PrioQ *queue);
#endif