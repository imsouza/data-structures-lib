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
 * @file dslib.c
 * @brief A library of data structures for academic purposes
 * @author Mateus Almeida
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dslib.h"

/**
 * @brief Stack structure definition.
 */
struct stack {
  int max;      /**< Stack capacity. */  
  int top;      /**< Top stack position. */  
  char *item;   /**< Stack items. */  
};


/**
 * @brief Queue structure definition.
 */
struct queue {
  int max;      /**< Queue capacity. */ 
  int count;    /**< Top queue position. */ 
  int first;    /**< Queue start position. */ 
  int last;     /**< Last queue position. */ 
  char *item;   /**< Queue items. */ 
};


/**
 * @brief Binary Search Tree structure definition.
 */
struct tree {
  char node;            /**< Tree items. */ 
  struct tree *left;    /**< Left node structure. */ 
  struct tree *right;   /**< Right node structure. */ 
};


/**
 * @brief Huffman Coding structure definition.
 */
struct htree {
  struct htree *left;   /**< Left huffman tree. */ 
  char chr;             /**< Character. */ 
  int  frq;             /**< Frequency. */ 
  struct htree *right;  /**< Right huffman tree. */ 
};


/**
 * @brief List structure definition.
 */
struct list {
  int item;            /**< List items. */
  struct list *next;   /**< Structure for the next node in the list. */
};


/**
 * @brief Map structure definition.
 */
struct map {
  int key;            /**< Key. */ 
  char value[SIZE];   /**< List of values. */ 
  struct map *next;   /**< Structure for the next node in the map. */
};


struct set {
  int *values;
  int size;
};


//! brief Static message array for error handling.
const char * const messages[] = {
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
getStackSize (Stack index) {
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
 * @param element Element that will be inserted in the list.
 * @param index Receives a list type structure.
 */
List 
createNodeList (int element, List index) {
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
  return createNodeList(index->item, cloneList(index->next));
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


/**
 * @brief This function creates a huffman tree node.
 *
 * @param left Left hufftree.
 * @param chr Fharacter.
 * @param frq Frequency.
 * @param left Right hufftree.
 */
Hufftree 
createHufftreeNode (Hufftree left, char chr, int frq, Hufftree right) {
  Hufftree index = malloc(sizeof(struct htree));
  index->left  = left;
  index->chr   = chr;
  index->frq   = frq;
  index->right = right;
  return index;
}


/**
 * This function gets the frequency of ASCII characters in 
 * a string.
 *
 * @param string String that should be passed as an argument.
 */
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


/**
 * @brief This function inserts an ordered tree in the forest.
 * 
 * @param tree Receive a tree.
 * @param forest Receive a forest by reference.
 * @param qty Receives the size of the forest by reference.
 */
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


/**
 * @brief This function removes the lightest tree in the forest.
 * 
 * @param forest Receive a forest by reference.
 * @param qty Receives the size of the forest by reference.
 */
Hufftree 
removeTree (Hufftree *forest, int *qty) {
  if (*qty == 0) { abort(); }
  return forest[--(*qty)];
}


/**
 * @brief This function creates a huffman tree for a string.
 * 
 * @param string String that should be passed as an argument.
 */
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


/**
 * This function displays a huffman tree on the screen.
 *
 * @param tree Receives a hufftree type structure.
 */
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


/**
 * This function displays the tree leaves on the screen.
 *
 * @param tree Receives a hufftree type structure.
 */
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


/**
 * This function creates a table of huffman codes.
 *
 * @note The 'strndup ()' function of the 'string.h' 
 * library is used to make a copy of the string before 
 * saving it to T.
 *
 * @param tree Receives a hufftree type structure.
 * @param T Vector for storage.
 */
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


/**
 * This function compresses a string.
 *
 * @param string String that should be passed as an argument.
 * @param tree Receives a hufftree type structure.
 */
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


/**
 * This function decompresses a string.
 *
 * @param string String that should be passed as an argument.
 * @param tree Receives a hufftree type structure.
 */
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


void 
deleteHufftree (Hufftree tree) {
  if (tree) {
    deleteHufftree(tree->left);
    deleteHufftree(tree->right);
    free(tree);
  }
}


Set *createEmptySet (int max) {
  Set *set = malloc (sizeof(Set));
  set->values = malloc (max * sizeof(Set));
  set->size = 0;

  return set;
}


void insertItemSet (Set *set, int item) {
  if (searchItemSet(set, item) == -1) {
    set->values[set->size] = item;
    set->size++;
  } else {
    return;
  }
}


void removeItemSet (Set *set, int item) {
  if (searchItemSet(set, item) == -1 || setIsEmpty(set)) {
    printf("Element not found");
    return;
  } else {
    int index = -1;
    for (int i = 0; i < set->size; i++) {
      if (set->values[i] == item) {
        index = i;
        break;
      }
    } 

    if (index != -1) {
      for (int i = index; i < set->size - 1; i++) {
        set->values[i] = set->values[i + 1];
      }

      set->size--;
    } else {
      printf("Element not found\n");
      return;
    }
  }
}


Set *unionSet (Set *A, Set *B) {
  Set *C = createEmptySet((A->size + B->size));

  for (int i = 0; i < A->size; i++) {
    insertItemSet(C, A->values[i]);
  }

  for (int i = 0; i < B->size; i++) {
    insertItemSet(C, B->values[i]);
  }

  return C;
}


Set *intersectionSet (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = createEmptySet(max);

  for (int i = 0; i < max; i++) {
    if (searchItemSet(A, B->values[i]) != -1) {
      C->values[C->size++] = B->values[i];
    }
  }

  return C;
}


Set *differenceSet (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = createEmptySet(max);

  for (int i = 0; i < max; i++) {
    if (searchItemSet(B, A->values[i]) == -1) {
      C->values[C->size++] = A->values[i];
    }
  }

  return C;
}


int setSize (Set *set) {
  return set->size;
}


int highestSetValue (Set *set) {
  int value = 0;

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] > value) {
      value = set->values[i];
    }
  }

  return value;
}


int lowestSetValue (Set *set) {
  int value = 1;

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] < value) {
      value = set->values[i];
    }
  }

  return value;
}


int setIsEmpty (Set *set) {
  return (set->size == 0);
}


int searchItemSet (Set *set, int item) {
  for (int i = 0; i < set->size; i++) {
    if (set->values[i] == item) {
      return set->values[i];
    }
  }

  return -1;
}


void displaySet (Set *set) {
  printf("{ ");
  for (int i = 0; i < set->size; i++) {
    printf("%i ", set->values[i]);
  }

  printf("}\n");
}


void deleteSet (Set *set) {
  free(set->values);
  free(set);
}
