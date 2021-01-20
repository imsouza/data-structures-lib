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

  extern const char * const messages[];

  /**
   * @brief Stack structure definition.
   *
   * The stack is defined as a pointer that points to
   * a structure with three fields and a vector of characters.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct stack {
    int max;      /**< Stack capacity. */  
    int top;      /**< Top stack position. */  
    char *item;   /**< Stack items. */  
  } *Stack;


  /**
   * @brief Queue structure definition.
   *
   * The queue is defined as a pointer that points to a structure with 
   * four integer fields and a vector of characters.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct queue {
    int max;      /**< Queue capacity. */ 
    int count;    /**< Top queue position. */ 
    int first;    /**< Queue start position. */ 
    int last;     /**< Last queue position. */ 
    char *item;   /**< Queue items. */ 
  } *Queue;


  /**
   * @brief Binary Search Tree structure definition.
   *
   * The binary search tree is defined with
   * a character field and two other internal structures of the same type.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct tree {
    char node;            /**< Tree items. */ 
    struct tree *left;    /**< Left node structure. */ 
    struct tree *right;   /**< Right node structure. */ 
  } BSTree;


  /**
   * @brief Huffman Coding structure definition.
   *
   * The hufftree is defined as a pointer that points to a structure with
   * the definition of two structures of the same type and 
   * two other fields of type char and int.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct htree {
    struct htree *left;   /**< Left huffman tree. */ 
    char chr;             /**< Character. */ 
    int  frq;             /**< Frequency. */ 
    struct htree *right;  /**< Right huffman tree. */ 
  } *Hufftree;


  /**
   * @brief List structure definition.
   *
   * The list is defined as a pointer that points to a structure with an entire 
   * field and the definition of a structure of the same type.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct list {
    int item;            /**< List items. */
    struct list *next;   /**< Structure for the next node in the list. */
  } *List;


  /**
   * @brief Map structure definition.
   *
   * The mapping is defined as a pointer that points to a structure with 
   * an entire key field, a character-type field defined by the constant 
   * that represents the value, and a structure definition of the same type.
   *
   * @warning the fields should never be accessed directly by the program. 
   * All manipulation of data structure should be done 
   * only by the functions implemented.
   */
  typedef struct map {
    int key;            /**< Key. */ 
    char value[SIZE];   /**< List of values. */ 
    struct map *next;   /**< Structure for the next node in the map. */
  } *Map;


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