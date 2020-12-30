/**********************************************************************************
 * MIT License                                                                    *
 *                                                                                *
 * Copyright (c) 2020 Mateus Almeida                                              *
 *                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          *
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in all *
 * copies or substantial portions of the Software.                                *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 * SOFTWARE.                                                                      *
 **********************************************************************************/

/**
 * @file ds-lib.c
 * @brief A library of data structures for academic purposes
 * @author Mateus Almeida
 * @version 1.0
 */

#include <string.h>

/**
 * Macro definitions.
 *
 * @warning Any changes made to the values ​​of the macros directly 
 * affect the processing of structures, avoid changes.
 */
#ifndef NEXT
#define NEXT(element) \
(element = (element + 1) % index->max)
#endif
#ifndef FREQ
#define FREQ 256    ///< Frequency constant
#endif
#ifndef SIZE
#define SIZE 25     ///< Define the size of the 'value' field
#endif
#ifndef HCOL
#define HCOL 5      ///< Define the number of columns that will be displayed
#endif

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



//! brief Static message array for error handling.
static const char * const messages[] = {
    "[!] Stack overflow!\n",
    "[!] Stack underflow!\n",
    "[!] Empty stack!\n",
    "[!] The queue is full!\n",
    "[!] The queue is empty!\n",
    "[!] The tree is empty!\n",
    "[!] Node not found in the tree\n",
    "[!] The list is empty\n",
};


/**
 * @brief This function creates a stack.
 *
 * This function allocates the area of ​​memory where the stack 
 * structure will be created, in case of error NULL will be returned. 
 * Then, the 'max' field pointed to by 'index' will receive the value 
 * of the corresponding parameter. In the next line, the 'top' field 
 * is indicated by 'index' and the value -1 is assigned, indicating 
 * that there are no items at the top of the stack and that the stack 
 * is empty. Finally, the 'item' field pointed to by 'index' is accessed 
 * and assigned to the address of a dynamic vector that stores a 'max' 
 * number of items.
 *
 * @param max Maximum number of items in the stack.
 */
Stack 
createStack (int max) {
  Stack index = malloc(sizeof(struct stack));
  index->max  = max;
  index->top  = -1;
  index->item = malloc(max * sizeof(char));
  return index;
}


/**
 * @brief This function checks whether the stack is empty or not.
 *
 * The logic is simple, if the 'upper' field accessed by 'index' 
 * is equal to -1, it means that the stack is empty because there 
 * are no elements at the top.
 *
 * @param index Receives a stack type structure.
 */
int 
stackIsEmpty (Stack index) {
  if (index->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


/**
 * @brief This function checks if the stack is full.
 *
 * It will be checked if the top of the stack is equal to the 
 * maximum capacity, if true 1 will be returned, otherwise 0 
 * will be returned.
 *
 * @param index Receives a stack type structure.
 */
int 
stackIsFull (Stack index) {
  if (index->top == index->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


/**
 * @brief This function inserts an item into the stack.
 *
 * To insert an item in the stack, you must first check that the stack 
 * is not full. If true, an error message will be displayed and processing 
 * will be aborted. If the stack has space, the item will be inserted at 
 * the top of the stack based on the increment of the 'top' field, 
 * so the new value of this field will be used to access the position of the 
 * 'index-> ​​item' field where the new item will be stored.
 *
 * @param element Item to be inserted.
 * @param index Receives a stack type structure.
 */
void 
stackPush (char element, Stack index) {
  if (stackIsFull(index)) {
    printf("%s", messages[0]);
    abort();
  } else {
    index->top++;
    index->item[index->top] = element;
  }
}


/**
 * @brief This function removes an item from the stack.
 *
 * To remove an item from the stack, you must first verify 
 * that the stack is not empty. If true, an error message will be 
 * displayed and processing will be aborted. If the stack is not empty, 
 * the top item must be removed and returned. This is done by assigning 
 * the return of access to the fields 'index-> ​​item [index-top]' to a variable. 
 * Then, the top is decremented so that the item is removed from the stack.
 *
 * @param index Receives a stack type structure.
 */
char 
stackPop (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = index->item[index->top];
    index->top--;
    return element;
  }
}


/**
 * This function access to the top of the stack.
 *
 * @param index Receives a stack type structure.
 */
char 
stackTop (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->item[index->top];
  }
}


/**
 * This function returns the number of elements in the stack.
 *
 * @param index Receives a stack type structure.
 */
int 
stackSize (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->top + 1;
  }
}


/**
 * This function displays the stack on the screen.
 *
 * @param index Receives a stack type structure.
 */
void 
displayStack (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= index->top; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}


/**
 * This function clears the stack and frees the memory.
 *
 * @warning The function call 'deleteStack' must be made 
 * with the address of the corresponding pointer.
 *
 * @param index Receives a stack structure by reference.
 */
void 
deleteStack (Stack *index) {
  free((*index)->item);
  free(*index);
  *index = NULL;
}


/**
 * @brief This function creates a queue.
 *
 * This function allocates a memory area where a queue 
 * structure will be created. The 'item' field pointed to 
 * by 'index' is assigned to an address of a dynamic array 
 * and, finally, the address of the queue structure is returned.
 *
 * @param max Maximum number of items in the stack.
 */
Queue 
createQueue (int max) {
  Queue index  = malloc(sizeof(struct queue));
  index->max   = max;
  index->count = 0;
  index->first = 0;
  index->last  = 0;
  index->item  = malloc(sizeof(max * sizeof(char)));
  return index;
}


/**
 * This function checks whether the queue is empty.
 *
 * @param index Receives a queue type structure.
 */
int 
queueIsEmpty (Queue index) {
  return (index->count == 0);
}


/**
 * This function checks whether the queue is full.
 *
 * @param index Receives a queue type structure.
 */
int 
queueIsFull (Queue index) {
  return (index->count == index->max);
}


/**
 * @brief This function insert an item in the queue.
 *
 * First, it is checked whether the queue is full, if true, 
 * processing will be aborted. Otherwise, the item must be 
 * inserted at the end of the queue with the code 
 * 'index-> ​​item [index-> ​​last]', then it will be advanced 
 * circularly to the index' index-> ​​last 'and will be increased 
 * in the counting field.
 *
 * @param element Item that will be inserted at the end of the queue.
 * @param index Receives a queue type structure.
 */
void 
enqueue (char element, Queue index) {
  if (queueIsFull (index)) {
    printf("%s", messages[3]);
    abort();
  } else {
    index->item[index->last] = element;
    NEXT(index->last);
    index->count++;
  }
}


/**
 * @brief This function removes an item in the queue.
 *
 * Otherwise, the item at the beginning of the 
 * queue must be removed and copied to an auxiliary 
 * variable, in this case, 'element'. Then the index 
 * 'index-> ​​first' will be circularly advanced and the 
 * field 'count' decremented and finally the auxiliary 
 * variable will be returned.
 *
 * @param index Receives a queue type structure.
 */
char 
dequeue (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    char element = index->item[index->first];
    NEXT(index->first);
    index->count--;
    return element;
  }
}


/**
 * This function gets the size of the queue.
 *
 * @param index Receives a queue type structure.
 */
int 
getQueueSize (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    return index->count;
  }
}


/**
 * This function displays the queue on the screen.
 *
 * @param index Receives a queue type structure.
 */
void 
displayQueue (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    for (int i = index->first; i < index->max; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}



/**
 * This function clears the queue and frees the memory.
 *
 * @warning The function call 'deleteQueue' must be made 
 * with the address of the corresponding pointer.
 *
 * @param index Receives a queue structure by reference.
 */
void 
deleteQueue (Queue *index) {
  free((*index)->item);
  free(*index);
  *index = NULL;
}


/**
 * This function generates an empty tree.
 */
BSTree 
*generateEmptyTree () {
  return NULL;
}


/**
 * @brief This function checks if the node exists.
 *
 * The insertion process starts by initializing an auxiliary 
 * structure with a NULL pointer and checking that the node 
 * is not present in the tree. If true, the auxiliary variable 
 * will be allocated and the fields will be initialized and assigned 
 * to the respective values. If the key is smaller than the current node, 
 * it means that the item will be added on the left, otherwise it will 
 * be added on the right.
 *
 * @param key Key that will be inserted in the tree.
 * @param node Double pointer to a node.
 * @warning When calling the 'insertNode' function, 
 * the node must be initialized with a null pointer and
 * only then passed as an argument.
 */
void 
insertNode (int key, BSTree **node) {
  BSTree *temp = NULL;
  if (!(*node)) {
    temp = (BSTree *) malloc(sizeof(BSTree));
    temp->left = temp->right = NULL;
    temp->node = key;
    *node = temp;
  } if (key < (*node)->node) {
    insertNode(key, &(*node)->left);
  } else if (key > (*node)->node) {
    insertNode(key, &(*node)->right);
  }
}


/**
 * This function checks if the tree is empty.
 *
 * @param node Receives a node structure by reference.
 */
int 
treeIsEmpty (BSTree *node) {
  return (node == NULL);
}


/**
 * This function displays a tree in pre-order on the screen.
 *
 * @param node Receives a node structure by reference.
 */
void 
displayPreOrder (BSTree *node) {
  if (node) {
    printf("%i\n",node->node);
    displayPreOrder(node->left);
    displayPreOrder(node->right);
  }
}


/**
 * This function displays a tree in order on the screen.
 *
 * @param node Receives a node structure by reference.
 */
void 
displayInOrder (BSTree *node) {
  if (node) {
    displayInOrder(node->left);
    printf("%i\n",node->node);
    displayInOrder(node->right);
  }
}


/**
 * This function displays a tree in post-order on the screen.
 *
 * @param node Receives a node structure by reference.
 */
void 
displayPostOrder (BSTree *node) {
  if (node) {
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    printf("%i\n",node->node);
  }
}


/**
 * This function returns the root of the tree.
 *
 * @param node Receives a node structure by reference.
 */
char 
getRoot (BSTree *index) {
  return index->node;
}


/**
 * This function checks if the tree is empty.
 *
 * @param node Receives a node structure by reference.
 */
int 
getNode (BSTree *index) {
  if (index) {
    return index->node;
  } else {
    printf("%s", messages[6]);
    abort();
  }
}


/**
 * This function checks if the node exists.
 *
 * @param node Receives a node structure by reference.
 */
int 
nodeExists (BSTree *index) {
  if (index != NULL) {
    return 1;
  } else {
    return 0;
  }
}


/**
 * This function checks if the node exists and returns 1 
 * in a true case and 0 in a false case.
 *
 * @param key Key that will be searched.
 * @param node Double pointer to a node.
 */
int 
search (int key, BSTree **node) {
  if (!(*node)) { return 0; }
  if(key < (*node)->node) { search(key, &((*node)->left)); }
  else if(key > (*node)->node) { search(key, &((*node)->right)); }
  else if(key == (*node)->node) { return nodeExists(*node); }
}


/**
 * This function searches for the smallest node 
 * and returns it.
 *
 * @param node Receives a node structure by reference.
 */
BSTree 
*findMin (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->left == NULL) { return node; }
  else { return findMin(node->left); }
}


/**
 * This function searches for the largest node 
 * and returns it.
 *
 * @param node Receives a node structure by reference.
 */
BSTree 
*findMax (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->right == NULL) { return node; }
  else { return findMax(node->right); }
}


/**
 * This function clears the tree and frees the memory.
 *
 * @param node Receives a node structure by reference.
 */
void 
deleteTree (BSTree *node) {
  if (node) {
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
    node = NULL;
  } 
}


/**
 * @brief This function creates a list.
 *
 * This function allocates a memory area for the node. 
 * Assign the received values ​​and return the address of the 
 * memory area in which it was created.
 *
 * @param element Element that will be inserted in the list.
 * @param index Receives a list type structure.
 */
List 
createList (int element, List index) {
  List node = malloc(sizeof(struct list));
  node->item = element;
  node->next = index;
  return node; 
}


/**
 * This function displays the list elements on the screen.
 *
 * @param index Receives a list type structure.
 */
void 
displayList (List index) {
  while (index != NULL) {
    printf("%i ", index->item);
    index = index->next;
  }
}


/**
 * This function displays the list elements on the screen 
 * in reverse order.
 *
 * @param index Receives a list type structure.
 */
void 
displayReverseList (List index) {
  if (index == NULL) { return; }
  displayReverseList(index->next);
  printf("%i ", index->item);
}


/**
 * This function concatenates a list at the end of the other.
 *
 * The function 'concatList' takes the address of two lists as 
 * a parameter by reference. When the function is called, it is 
 * checked if any of the two lists is NULL, if true, the list 
 * itself will be returned. Then there will be a loop where each 
 * value of 'B' will be assigned at the end of the 'A' list.
 *
 * @param A Receives a list type structure by reference.
 * @param B Receives a list type structure by reference.
 */
List 
*concatList (List *A, List *B) {
  List *temp;

  if (A == NULL) { return B; }
  if (B == NULL) { return A; }

  temp = A;

  while ((*temp)->next != NULL) {
    temp = &(*temp)->next;
  }

  (*temp)->next = *B;

  return A;
}


/**
 * This function clones a list and generates a new list.
 *
 * @param index Receives a list type structure.
 */
List 
cloneList (List index) {
  if (index == NULL) { return NULL; }
  return createList(index->item, cloneList(index->next));
}


/**
 * This function gets the number of elements in the list.
 *
 * @param index Receives a list type structure.
 */
int 
getListSize (List index) {
  if (index == NULL) { return 0; }
  return 1 + getListSize(index->next);
} 


/**
 * This function checks whether the list is empty or not.
 *
 * @param index Receives a list type structure.
 */
int 
listIsEmpty (List index) {
  if (getListSize(index) > 0) { return 0; }
  else { return 1; }
}


/**
 * This function gets the first item inserted in the list.
 *
 * @param index Receives a list type structure.
 */
int 
getHead (List index) {
  if (listIsEmpty(index) == 1 || index == NULL) {
    abort();
  }

  return index->item;
}


/**
 * This function checks whether an item exists in the list.
 *
 * @param index Receives a list type structure.
 */
int 
itemExists (int item, List index) {
  if (index == NULL) { return 0; }
  if (item == index->item) { return 1; }
  return itemExists(item, index->next);
}


/**
 * This function clears the list and frees the memory.
 *
 * @param index Receives a list type structure by reference.
 */
void 
deleteList (List *index) {
  while (*index != NULL) {
    List temp = *index;
    *index = temp->next;
    free(temp);
    temp = NULL;
  }
}


/**
 * @brief This function creates a map.
 *
 * This function allocates a memory area for mapping and assigns
 * the respective parameter values ​​for the fields.
 *
 * @param key Key that will be inserted in the mapping.
 * @param value Value passed by reference that will be inserted 
 * in the mapping.
 * @param index Receives a map type structure.
 */
Map 
createMap (int key, char *value, Map index) {
  Map node = malloc(sizeof(struct map));
  node->key = key;
  strcpy(node->value, value);
  node->next = index;
  return node;
}


/**
 * @brief This function inserts a key and a value in the mapping.
 *
 * Repeat starts to move the 'index' pointer to
 * that points to a null pointer or that points to a
 * larger key equal to the 'key' parameter. So, if the pointed key 
 * is equal to the 'key' parameter the value associated with the 
 * key is changed to the 'value' parameter.
 * Otherwise, a new node is created.
 *
 * @param key Key that will be inserted in the mapping.
 * @param value Value passed by reference that will be inserted 
 * in the mapping.
 * @param index Receives a map type structure by reference.
 */
void 
insertMap (int key, char *value, Map *index) {
  while (*index != NULL && (*index)->key < *value) {
    index = &(*index)->next;
  } if (*index != NULL && (*index)->key == *value) {
    strcpy((*index)->value, value);
  } else {
    *index = createMap(key, value, *index);
  }
}


/**
 * @brief This function removes a key from the mapping.
 *
 * The repetition begins to move the 'index' pointer so 
 * that it points to a null pointer or that it points to a 
 * larger key equal to the 'key' parameter. At the end of 
 * the repetition, if the pointer pointed to by 'index' is 
 * null or pointing to a key greater than the 'key' parameter, 
 * 0 is returned indicating that the key does not exist. 
 * Otherwise, the node is deallocated and returned 1.
 *
 * @param key Key that will be inserted in the mapping.
 * @param index Receives a map type structure by reference.
 */
int 
removeMap (int key, Map *index) {
  while (*index != NULL && (*index)->key < key) {
    index = &(*index)->next;
  } if (*index == NULL || (*index)->key > key) {
    return 0;
  }

  Map node = *index;
  *index = node->next;
  free(node);
  return 1;
}


/**
 * This function checks if a key exists in the mapping.
 *
 * @param key Search key.
 * @param index Receives a map type structure.
 */
int 
keyExists (int key, Map index) {
  while (index != NULL && index->key < key) {
    index = index->next;
  }

  return (index != NULL && index->key == key);
}


/**
 * This function displays the mapping on the screen.
 *
 * @param index Receives a map type structure.
 */
void 
displayMap (Map index) {
  printf("{\n");
  while(index != NULL) {
    printf("[%i, %s]", index->key, index->value);
    if (index->next != NULL) {
      printf(",\n");
    }

    index = index->next;
  }

  printf("\n}\n");
}


/**
 * This function clears the map and frees the memory.
 *
 * @param index Receives a map type structure by reference.
 */
void 
deleteMap (Map *index) {
  while ((*index) != NULL) {
    Map node = *index;
    *index = node->next;
    free(node);
  }
}


Hufftree 
createHufftreeNode (Hufftree left, char chr, int frq, Hufftree right) {
  Hufftree index = malloc(sizeof(struct htree));
  index->left  = left;
  index->chr   = chr;
  index->frq   = frq;
  index->right = right;
  return index;
}


int 
*frequency (char *string) {
  static int array[FREQ];

  for (int i = 0; i < FREQ; i++) {
    array[i] = 0;
  } 

  for (int i = 0; string[i]; i++) {
    array[string[i]]++;
  }

  return array;
}


void 
insertTree (Hufftree tree, Hufftree *forest, int *qty) {
  int i = *qty;

  while(i > 0 && forest[i - 1]->frq < tree->frq) {
    forest[i] = forest[i - 1];
    i--;
  }

  forest[i] = tree;
  (*qty)++;
}


Hufftree 
removeTree (Hufftree *forest, int *qty) {
  if (*qty == 0) { abort(); }
  return forest[--(*qty)];
}


Hufftree 
createHufftree (char *string) {
  Hufftree forest[FREQ];
  int qty = 0;
  int *leaf = frequency(string);

  for (int chr = 0; chr < FREQ; chr++) {
    if (leaf[chr] > 0) {
      insertTree(createHufftreeNode(NULL, chr, leaf[chr], NULL),
      forest, &qty);
    }
  }

  while (qty > 1) {
    Hufftree right = removeTree(forest, &qty);
    Hufftree left  = removeTree(forest, &qty);
    insertTree(createHufftreeNode(left, '-', left->frq + right->frq, right),
    forest, &qty);
  }

  return forest[0];
}


void 
displayHufftree (Hufftree tree) {
  static int node = -1;

  if (tree == NULL) { return; }

  node++;

  displayHufftree(tree->right);

  for (int i = 0; i < HCOL * node; i++) {
    putchar(' ');
  }

  printf("(%c, %i)\n", tree->chr, tree->frq);

  displayHufftree(tree->left);

  node--;
}


void 
displayLeaves (Hufftree tree) {
  static char array[FREQ], last = -1;

  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    printf("%c : %.*s\n", tree->chr, last + 1, array);
  } else {
    last++; 
    array[last] = '0'; displayLeaves(tree->left);
    array[last] = '1'; displayLeaves(tree->right);
    last--;
  }
}


void 
createTable (Hufftree tree, char *T[]) {
  static char array[FREQ], last = -1;
  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    T[tree->chr] = strndup(array, last+1);
  } else {
    last++;
    array[last] = '0'; createTable(tree->left, T);
    array[last] = '1'; createTable(tree->right, T);
    last--;
  }
}


void 
compressString (char *string, Hufftree tree) {
  char *T[FREQ];

  for (int chr = 0; chr < FREQ; chr++) {
    T[chr] = NULL;
  }

  createTable(tree, T);

  for (int i = 0; string[i]; i++) {
    printf("%s", T[string[i]]);
  }

  for (int chr = 0; chr < FREQ; chr++) {
    free(T[chr]);
  }
}


void 
decompressString (char *string, Hufftree tree) {
  if (tree == NULL) { return; }
  Hufftree root = tree;

  for (int i = 0; string[i]; i++) {
   if (string[i] == '0') {
    root = root->left;
   } else {
    root = root->right;
   }

   if (root->left == NULL && root->right == NULL) {
    printf("%c", root->chr);
    root = tree;
   }
  }
}