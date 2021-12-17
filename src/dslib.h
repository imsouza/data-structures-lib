#ifndef DSLIB_H_
#define DSLIB_H_

#define NEXT(element) \
(element = (element + 1) % queue->max)

#define SET_MAX(A, B) \
((A->size >= B->size) ? A->size : B->size);

#define FREQ 256
#define SIZE 200
#define HCOL 5

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node Stack;
typedef struct node Queue;
typedef struct node BSTree;
typedef struct node AVLTree;
typedef struct node RBTree;
typedef struct node List;
typedef struct set Set;
typedef struct prioq PrioQ;
typedef struct graph Graph;

typedef enum {
  false,
  true
} bool;

typedef enum {
  BLACK,
  RED
} tColor;

typedef enum {
  STACK,
  QUEUE,
  BSTREE,
  AVLTREE,
  RBTREE,
  LIST,
  SET,
  PRIOQ,
  GRAPH
} sType;

struct node {
  int qty;
  int item;
  int height; 
  bool status;
  tColor color;
  sType type;
  struct node *left;
  struct node *right;
  struct node *next;
  struct node *prev;
  struct node *head;
  struct node *tail;
};

void *mallocSafe(size_t nbytes);

void treePadding(char ch, int n);
void displayTreePreOrder(struct node *root);
void displayTreeInOrder(struct node *root);
void displayTreePostOrder(struct node *root);
void displayTree (int level, sType type, struct node *root);

Stack *stackCreate();
bool stackIsEmpty(Stack *stack);
int stackIsFull(Stack *stack);
void stackPush(int item, Stack *stack);
void stackPop(Stack *stack);
int stackTop(Stack *stack);
int stackSize(Stack *stack);
void stackDisplay(Stack *stack);
void stackDestroy(Stack *stack);

Queue *queueCreate();
bool queueIsEmpty(Queue *queue);
int queueFront(Queue *queue);
void queueEnqueue(int item, Queue *queue);
void queueDequeue(Queue *queue);
int queueSize(Queue *queue);
void queueDisplay(Queue *queue);
void queueDestroy(Queue *queue);

BSTree *binarySearchTreeInit();
BSTree *binarySearchTreeCreateNode(int item);
BSTree *binarySearchTreeInsertNode(BSTree *newNode, BSTree *root);
BSTree *binarySearchTreeRemoveNode(int item, BSTree *root);
BSTree *binarySearchTreeSearch(int item, BSTree *root);
BSTree *binarySearchTreeFindMin(BSTree *root);
BSTree *binarySearchTreeFindMax(BSTree *root);
bool binarySearchTreeIsEmpty(BSTree *root);
int binarySearchTreeItem(BSTree *root);
bool binarySearchTreeItemExists(int item, BSTree *root);
int binarySearchTreeTotalNodes(BSTree *root);
int binarySearchTreeHeight(BSTree *root);
int binarySearchTreeIsBalanced(BSTree *root);
int binarySearchTreeTotalLeafs(BSTree *root);
void binarySearchTreeDestroy(BSTree *root);

AVLTree *AVLTreeInit();
AVLTree *AVLTreeCreateNode(int item);
AVLTree *AVLTreeSearch(int item, AVLTree *root);
int AVLTreeHeight(AVLTree *root);
AVLTree *AVLTreeInsertNode(AVLTree *node, AVLTree *root);
AVLTree *AVLTreeRemoveNode(int item, AVLTree *root);
void AVLTreeDestroy(AVLTree *root);

RBTree *redBlackTreeInit();
RBTree *redBlackTreeCreateNode(int item);
RBTree *redBlackTreeInsertNode(RBTree *node, RBTree *root);
RBTree *redBlackTreeRemoveMin(RBTree *root);
RBTree *redBlackTreeFindMin(RBTree *root);
RBTree *redBlackTreeRemoveNode(int item, RBTree *root);
RBTree *redBlackTreeSearch(int item, RBTree *root);
int redBlackTreeTotalNodes(RBTree *root);
int redBlackTreeHeight(RBTree *root);
int redBlackTreeTotalLeafs(RBTree *root);
bool redBlackTreeStatus(RBTree *root) ;
bool redBlackTreeIsEmpty(BSTree *root);
void redBlackTreeDestroy(RBTree *root);

List *linkedListCreate();
List *linkedListHead(List *list);
List *linkedListTail(List *list);
List *linkedListSearch(int item, List *list);
void linkedListInsertItemBegin(int item, List *list);
void linkedListInsertItemEnd(int item, List *list);
void linkedListDisplay(List *list);
void linkedListReverseDisplay(List *list);
int linkedListItem(List *index);
int linkedListSize(List *list);
bool linkedListIsEmpty(List *list);
void linkedListRemove(int item, List *list);
void linkedListDestroy(List *list);

Set *setCreate(int max);
Set *setUnion(Set *A, Set *B);
Set *setIntersection(Set *A, Set *B);
Set *setDifference(Set *A, Set *B);
int *heapSort(int *set, int size);
void setInsert(int item, Set *set);
void setRemove(int item, Set *set);
int setSize(Set *set);
int setHighestValue(Set *set);
int setLowestValue(Set *set);
bool setIsEmpty(Set *set);
int *setSearch(int item, Set *set);
void setDisplay(Set *set);
void setDestroy(Set *set);

PrioQ *priorityQueueCreate();
void priorityQueueInsert(int value, PrioQ *queue);
void priorityQueueRemoveHighestPrio(PrioQ *queue);
int priorityQueueFirst(PrioQ *queue);
bool priorityQueueIsEmpty(PrioQ *queue);
bool priorityQueueIsFull(PrioQ *queue);
int priorityQueueSize(PrioQ *queue);
void priorityQueueDestroy(PrioQ *queue);

Graph *graphCreate(int maxVertex, int maxDegree, bool isWeighted);
int graphInsertEdge(int initial, int terminal, int weight, bool isDigraph, Graph *graph);
int graphRemoveEdge(int initial, int terminal, int weight, bool isDigraph, Graph *graph);
void graphBreadthFirstSearch (int initial, Graph *graph);
void graphDepthFirstSearch(int initial, Graph *graph);
int graphMaxVertex(Graph *graph);
void graphDisplay(bool isVisited, Graph *graph);
void graphDestroy(Graph *graph);
#endif