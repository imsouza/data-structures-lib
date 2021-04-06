#ifndef DSLIB_H_
#define DSLIB_H_
#ifndef NEXT         ///< Macro to advance the index circularly.
#define NEXT(element) \
(element = (element + 1) % index->max)
#endif
#ifndef FREQ
#define FREQ 256    ///< Frequency constant.
#endif
#ifndef SIZE
#define SIZE 25     ///< Define the size of the 'value' field.
#endif
#ifndef HCOL
#define HCOL 5      ///< Define the number of columns that will be displayed.
#endif

typedef struct stack *Stack;
typedef struct queue *Queue;
typedef struct tree BSTree;
typedef struct htree *Hufftree;
typedef struct list *List;
typedef struct map *Map;
typedef struct set Set;

extern const char * const messages[];

Stack createStack(int max);
int stackIsEmpty(Stack index);
int stackIsFull(Stack index);
void stackPush(char element, Stack index);
char stackPop(Stack index);
char stackTop(Stack index);
int getStackSize(Stack index);
void displayStack(Stack index);
void deleteStack(Stack *index);
Queue createQueue(int max);
int queueIsEmpty(Queue index);
int queueIsFull(Queue index);
void enqueue(char element, Queue index);
char dequeue(Queue index);
int getQueueSize(Queue index);
void displayQueue(Queue index);
void deleteQueue(Queue *index);
BSTree *generateEmptyTree();
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
List createNodeList(int element, List index);
void displayList(List index);
void displayReverseList(List index);
List *concatList(List *A, List *B);
List cloneList(List index);
int getListSize(List index);
int listIsEmpty(List index);
int getHead(List index);
int itemExists(int item, List index);
void deleteList(List *index);
Map createMap(int key, char *value, Map index);
void insertMap(int key, char *value, Map *index);
int removeMap(int key, Map *index);
int keyExists(int key, Map index);
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
void insertItemSet(Set *set, int item); 
void removeItemSet(Set *set, int item);
int setSize(Set *set);
int setIsEmpty(Set *set);
int searchItemSet(Set *set, int item);
void displaySet(Set *set);
Set *unionSet(Set *A, Set *B);
Set *intersectionSet(Set *A, Set *B);
Set *differenceSet(Set *A, Set *B);
int highestSetValue(Set *set);
int lowestSetValue(Set *set);

#endif