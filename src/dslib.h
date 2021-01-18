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


  Stack 
  createStack (int max);
  int 
  stackIsEmpty (Stack index);
  int 
  stackIsFull (Stack index);
  void 
  stackPush (char element, Stack index);
  char 
  stackPop (Stack index);
  char 
  stackTop (Stack index);
  int 
  getStackSize (Stack index);
  void 
  displayStack (Stack index);
  void 
  deleteStack (Stack *index);
  Queue 
  createQueue (int max);
  int 
  queueIsEmpty (Queue index);
  int 
  queueIsFull (Queue index);
  void 
  enqueue (char element, Queue index);
  char 
  dequeue (Queue index);
  int 
  getQueueSize (Queue index);
  void 
  displayQueue (Queue index);
  void 
  deleteQueue (Queue *index);
  BSTree 
  *generateEmptyTree ();
  void 
  insertNode (int key, BSTree **node);
  int 
  treeIsEmpty (BSTree *node);
  void 
  displayPreOrder (BSTree *node);
  void 
  displayInOrder (BSTree *node);
  void 
  displayPostOrder (BSTree *node);
  char 
  getRoot (BSTree *index);
  int 
  getNode (BSTree *index);
  int 
  nodeExists (BSTree *index);
  int 
  search (int key, BSTree **node);
  BSTree 
  *findMin (BSTree *node);
  BSTree 
  *findMax (BSTree *node);
  void 
  deleteTree (BSTree *node);
  List 
  createList (int element, List index);
  void 
  displayList (List index);
  void 
  displayReverseList (List index);
  List 
  *concatList (List *A, List *B);
  List 
  cloneList (List index);
  int 
  getListSize (List index);
  int 
  listIsEmpty (List index);
  int 
  getHead (List index);
  int 
  itemExists (int item, List index);
  void 
  deleteList (List *index);
  Map 
  createMap (int key, char *value, Map index);
  void 
  insertMap (int key, char *value, Map *index);
  int 
  removeMap (int key, Map *index);
  int 
  keyExists (int key, Map index);
  void 
  displayMap (Map index);
  void 
  deleteMap (Map *index);
  Hufftree 
  createHufftreeNode (Hufftree left, char chr, int frq, Hufftree right);
  int 
  *frequency (char *string);
  void 
  insertTree (Hufftree tree, Hufftree *forest, int *qty);
  Hufftree 
  removeTree (Hufftree *forest, int *qty);
  Hufftree 
  createHufftree (char *string);
  void 
  displayHufftree (Hufftree tree);
  void 
  displayLeaves (Hufftree tree);
  void 
  createTable (Hufftree tree, char *T[]);
  void 
  compressString (char *string, Hufftree tree);
  void 
  decompressString (char *string, Hufftree tree);
#endif