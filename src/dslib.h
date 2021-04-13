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

BSTree *binarySearchTreeFindMin(BSTree *node);
BSTree *binarySearchTreeFindMax(BSTree *node);
void binarySearchTreeInsertNode(int key, BSTree **node);
int binarySearchTreeIsEmpty(BSTree *node);
void binarySearchTreeDisplayPreOrder(BSTree *node);
void binarySearchTreeDisplayInOrder(BSTree *node);
void binarySearchTreeDisplayPostOrder(BSTree *node);
char binarySearchTreeRoot(BSTree *index);
int binarySearchTreeNode(BSTree *index);
int binarySearchTreeNodeExists(BSTree *index);
int binarySearchTreeSearch(int key, BSTree **node);
void binarySearchTreeDestroy(BSTree *node);

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

#endif