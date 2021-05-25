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
typedef struct avltree AVLTree;
typedef struct htree *Hufftree;
typedef struct list List;
typedef struct map *Map;
typedef struct set Set;
typedef struct prioq PrioQ;

typedef struct node {
  long int item;
  struct node *next;
  struct node *prev;
} Node;

typedef enum {
  false,
  true
} bool;

extern const char * const messages[];

Stack *stackCreate();
long int stackIsEmpty(Stack *stack);
long int stackIsFull(Stack *stack);
void stackPush(long int item, Stack *stack);
void stackPop(Stack *stack);
long int stackTop(Stack *stack);
long int stackSize(Stack *stack);
void stackDisplay(Stack *stack);
void stackDestroy(Stack *stack);

Queue *queueCreate();
long int queueIsEmpty(Queue *queue);
long int queueIsFull(Queue *queue);
long int queueFront(Queue *queue);
void queueEnqueue(long int item, Queue *queue);
void queueDequeue(Queue *queue);
long int queueSize(Queue *queue);
void queueDisplay(Queue *queue);
void queueDestroy(Queue *queue);

BSTree *binarySearchTreeCreateNode(long int item);
BSTree *binarySearchTreeInsertNode(BSTree *newNode, BSTree *root);
BSTree *binarySearchTreeRemoveNode(long int key, BSTree *root);
BSTree *binarySearchTreeSearch(long int key, BSTree *root);
BSTree *binarySearchTreeFindMin(BSTree *root);
BSTree *binarySearchTreeFindMax(BSTree *root);
long int binarySearchTreeIsEmpty(BSTree *root);
void binarySearchTreeDisplayPreOrder(BSTree *root);
void binarySearchTreeDisplayInOrder(BSTree *root);
void binarySearchTreeDisplayPostOrder(BSTree *root);
void binarySearchTreeDisplayTree(long int level, BSTree *root);
long int binarySearchTreeGetItem(BSTree *root);
long int binarySearchTreeItemExists(long int item, BSTree *root);
long int binarySearchTreeTotalNodes(BSTree *root);
long int binarySearchTreeHeight(BSTree *root);
long int binarySearchTreeIsBalanced(BSTree *root);
long int binarySearchTreeTotalLeafs(BSTree *root);
void binarySearchTreeDestroy(BSTree *root);

AVLTree *AVLTreeCreateNode(long int item);
AVLTree *AVLTreeSearch(long int item, AVLTree *root);
long int AVLTreeHeight(AVLTree *root);
void AVLTreeDisplayTree (long int level, AVLTree *root);
AVLTree *AVLTreeInsertNode(AVLTree *new, AVLTree *root);
AVLTree *AVLTreeRemoveNode(long int key, AVLTree *root);
void AVLTreeDestroy(AVLTree *root);

List *linkedListCreate();
Node *linkedListHead(List *list);
Node *linkedListTail(List *list);
Node *linkedListSearch(long int item, List *list);
void linkedListInsertItemBegin(long int item, List *list);
void linkedListInsertItemEnd(long int item, List *list);
void linkedListDisplay(List *list);
void linkedListReverseDisplay(List *list);
long int linkedListNode(Node *index);
long int linkedListSize(List *list);
long int linkedListIsEmpty(List *list);
void linkedListRemove(long int item, List *list);
void linkedListDestroy(List *list);

Map mapCreate(long int key, char *value, Map index);
void mapInsert(long int key, char *value, Map *index);
long int mapRemove(long int key, Map *index);
long int mapKeyExists(long int key, Map index);
void mapDisplay(Map index);
void mapDestroy(Map *index);

Hufftree hufftreeCreateNode(Hufftree left, char chr, long int frq, Hufftree right);
Hufftree hufftreeRemove(Hufftree *forest, long int *qty);
Hufftree hufftreeCreate(char *string);
long int *hufftreeFrequency(char *string);
void hufftreeInsert(Hufftree tree, Hufftree *forest, long int *qty);
void hufftreeDisplay(Hufftree tree);
void hufftreeDisplayLeaves (Hufftree tree);
void hufftreeCreateTable(Hufftree tree, char *T[]);
void hufftreeCompressString(char *string, Hufftree tree);
void hufftreeDecompressString(char *string, Hufftree tree);
void hufftreeDestroy(Hufftree tree);

Set *setCreate(long int max);
Set *setUnion(Set *A, Set *B);
Set *setIntersection(Set *A, Set *B);
Set *setDifference(Set *A, Set *B);
void setInsert(long int item, Set *set);
void setRemove(long int item, Set *set);
long int setSize(Set *set);
long int setHighestValue(Set *set);
long int setLowestValue(Set *set);
long int setIsEmpty(Set *set);
long int *setSearch(long int item, Set *set);
void setDisplay(Set *set);
void setDestroy(Set *set);

PrioQ *priorityQueueCreate();
void priorityQueueDestroy(PrioQ *queue);
void priorityQueueInsert( long int value, PrioQ *queue);
void priorityQueueRemoveHighestPrio(PrioQ *queue);
long int priorityQueueFirst(PrioQ *queue);
bool priorityQueueIsEmpty(PrioQ *queue);
bool priorityQueueIsFull(PrioQ *queue);
long int priorityQueueSize(PrioQ *queue);
#endif