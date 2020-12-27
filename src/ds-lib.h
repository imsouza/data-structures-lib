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
 * @brief Macro definitions.
 *
 * @warning Any changes made to the values ​​of the macros directly 
 * affect the processing of structures, avoid changes.
 */
#ifndef NEXT
#define NEXT(element) (element = (element + 1) % index->max)
#endif
#ifndef FREQ
#define FREQ 256
#endif
#ifndef SIZE
/**
 * Constant used to define the size of the 'value' 
 * field of the Map structure.
 */
#define SIZE 25
#endif
#ifndef HCOL
#define HCOL 5
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


Stack createStack (int max) {
  Stack index = malloc(sizeof(struct stack));
  index->max  = max;
  index->top  = -1;
  index->item = malloc(max * sizeof(char));
  return index;
}


int stackIsEmpty (Stack index) {
  if (index->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int stackIsFull (Stack index) {
  if (index->top == index->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void stackPush (char element, Stack index) {
  if (stackIsFull(index)) {
    printf("%s", messages[0]);
    abort();
  } else {
    index->top++;
    index->item[index->top] = element;
  }
}


char stackPop (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = index->item[index->top];
    index->top--;
    return element;
  }
}


char stackTop (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->item[index->top];
  }
}


int stackSize (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->top + 1;
  }
}


void displayStack (Stack index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= index->top; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}


void deleteStack (Stack *index) {
  free((*index)->item);
  free(*index);
  *index = NULL;
}


Queue createQueue (int max) {
  Queue index  = malloc(sizeof(struct queue));
  index->max   = max;
  index->count = 0;
  index->first = 0;
  index->last  = 0;
  index->item  = malloc(sizeof(max * sizeof(char)));
  return index;
}


int queueIsEmpty (Queue index) {
  return (index->count == 0);
}


int queueIsFull (Queue index) {
  return (index->count == index->max);
}


void enqueue (char element, Queue index) {
  if (queueIsFull (index)) {
    printf("%s", messages[3]);
    abort();
  } else {
    index->item[index->last] = element;
    NEXT(index->last);
    index->count++;
  }
}


char dequeue (Queue index) {
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


int getQueueSize (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    return index->count;
  }
}


void displayQueue (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    for (int i = index->first; i < index->max; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}


void deleteQueue (Queue *index) {
  free((*index)->item);
  free(*index);
  *index = NULL;
}


BSTree *generatetreeIsEmpty () {
  return NULL;
}


void insertNode (int key, BSTree **node) {
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


int treeIsEmpty (BSTree *node) {
  return (node == NULL);
}


void displayPreOrder (BSTree *node) {
  if (node) {
    printf("%i\n",node->node);
    displayPreOrder(node->left);
    displayPreOrder(node->right);
  }
}


void displayInOrder (BSTree *node) {
  if (node) {
    displayInOrder(node->left);
    printf("%i\n",node->node);
    displayInOrder(node->right);
  }
}


void displayPostOrder (BSTree *node) {
  if (node) {
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    printf("%i\n",node->node);
  }
}


char getRoot (BSTree *index) {
  return index->node;
}


int getNode (BSTree *index) {
  if (index) {
    return index->node;
  } else {
    printf("%s", messages[6]);
    abort();
  }
}


int nodeExists (BSTree *index) {
  if (index != NULL) {
    return 1;
  } else {
    return 0;
  }
}


int search (int key, BSTree **node) {
  if (!(*node)) { return 0; }
  if(key < (*node)->node) { search(key, &((*node)->left)); }
  else if(key > (*node)->node) { search(key, &((*node)->right)); }
  else if(key == (*node)->node) { return nodeExists(*node); }
}


BSTree *findMin (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->left == NULL) { return node; }
  else { return findMin(node->left); }
}


BSTree *findMax (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->right == NULL) { return node; }
  else { return findMax(node->right); }
}


void deleteTree (BSTree *node) {
  if (node) {
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
    node = NULL;
  } 
}


List createList (int element, List index) {
  List node = malloc(sizeof(struct list));
  node->item = element;
  node->next = index;
  return node; 
}


void displayList (List index) {
  while (index != NULL) {
    printf("%i ", index->item);
    index = index->next;
  }
}


void displayReverseList (List index) {
  if (index == NULL) { return; }
  displayReverseList(index->next);
  printf("%i ", index->item);
}


List *concatList (List *A, List *B) {
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


List cloneList (List index) {
  if (index == NULL) { return NULL; }
  return createList(index->item, cloneList(index->next));
}


int getListSize (List index) {
  if (index == NULL) { return 0; }
  return 1 + getListSize(index->next);
} 


int listIsEmpty (List index) {
  if (getListSize(index) > 0) { return 0; }
  else { return 1; }
}


int getHead (List index) {
  if (listIsEmpty(index) == 1 || index == NULL) {
    abort();
  }

  return index->item;
}


int itemExists (int item, List index) {
  if (index == NULL) { return 0; }
  if (item == index->item) { return 1; }
  return itemExists(item, index->next);
}


void deleteList (List *index) {
  while (*index != NULL) {
    List temp = *index;
    *index = temp->next;
    free(temp);
    temp = NULL;
  }
}


Map createMap (int key, char *value, Map index) {
  Map node = malloc(sizeof(struct map));
  node->key = key;
  strcpy(node->value, value);
  node->next = index;
  return node;
}


void insertMap (int key, char *value, Map *index) {
  while (*index != NULL && (*index)->key < *value) {
    index = &(*index)->next;
  } if (*index != NULL && (*index)->key == *value) {
    strcpy((*index)->value, value);
  } else {
    *index = createMap(key, value, *index);
  }
}


int removeMap (int key, Map *index) {
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


int keyExists (int key, Map index) {
  while (index != NULL && index->key < key) {
    index = index->next;
  }

  return (index != NULL && index->key == key);
}


void displayMap (Map index) {
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


void deleteMap (Map *index) {
  while ((*index) != NULL) {
    Map node = *index;
    *index = node->next;
    free(node);
  }
}


Hufftree createHufftreeNode (Hufftree left, char chr,
int frq, Hufftree right) {
  Hufftree index = malloc(sizeof(struct htree));
  index->left  = left;
  index->chr   = chr;
  index->frq   = frq;
  index->right = right;
  return index;
}


int *frequency (char *string) {
  static int array[FREQ];

  for (int i = 0; i < FREQ; i++) {
    array[i] = 0;
  } 

  for (int i = 0; string[i]; i++) {
    array[string[i]]++;
  }

  return array;
}


void insertTree (Hufftree tree, Hufftree *forest, int *qty) {
  int i = *qty;

  while(i > 0 && forest[i - 1]->frq < tree->frq) {
    forest[i] = forest[i - 1];
    i--;
  }

  forest[i] = tree;
  (*qty)++;
}


Hufftree removeTree (Hufftree *forest, int *qty) {
  if (*qty == 0) { abort(); }
  return forest[--(*qty)];
}


Hufftree createHufftree (char *string) {
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


void displayHufftree (Hufftree tree) {
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


void displayLeaves (Hufftree tree) {
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


void createTable (Hufftree tree, char *T[]) {
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


void compressString (char *string, Hufftree tree) {
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


void decompressString (char *string, Hufftree tree) {
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