#ifndef DSLIB_H_
#define DSLIB_H_
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

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

  extern const char * const messages[];

  Stack createStack();
  int stackIsEmpty();
  int stackIsFull();
  void stackPush(char element, Stack index);
  char stackPop();
  char stackTop();
  int getStackSize();
  void displayStack();
  void deleteStack();
  Queue createQueue();
  int queueIsEmpty();
  int queueIsFull();
  void enqueue(char element, Queue index);
  char dequeue ();
  int getQueueSize ();
  void displayQueue ();
  void deleteQueue ();
  BSTree *generateEmptyTree ();
  void insertNode();
  int treeIsEmpty();
  void displayPreOrder();
  void displayInOrder();
  void displayPostOrder();
  char getRoot();
  int getNode();
  int nodeExists();
  int search();
  BSTree *findMin();
  BSTree *findMax();
  void deleteTree();
  List createList();
  void displayList();
  void displayReverseList();
  List *concatList();
  List cloneList();
  int getListSize();
  int listIsEmpty();
  int getHead();
  int itemExists();
  void deleteList();
  Map createMap();
  void insertMap();
  int removeMap();
  int keyExists();
  void displayMap();
  void deleteMap();
  Hufftree createHufftreeNode(Hufftree left, char chr, 
  int frq, Hufftree right);
  int *frequency();
  void insertTree();
  Hufftree removeTree();
  Hufftree createHufftree();
  void displayHufftree();
  void displayLeaves();
  void createTable();
  void compressString();
  void decompressString();
#endif