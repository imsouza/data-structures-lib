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
 * @brief A library of generic data structures for academic purposes
 * @author Mateus Almeida
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dslib.h"


struct stack {
  int max;
  int top; 
  char *item;
};


struct queue {
  int max;
  int count;
  int first;
  int last;
  char *item;
};


struct tree {
  char node;
  struct tree *left;
  struct tree *right;
};


struct htree {
  struct htree *left;
  char chr;
  int  frq;
  struct htree *right;
};


struct list {
  Node *head;
  Node *tail;
  int qty;
};


struct map {
  int key;
  char value[SIZE];
  struct map *next;
};


struct set {
  int *values;
  int size;
};


const char * const messages[] = {
    "[!] Stack overflow!\n",
    "[!] Stack underflow!\n",
    "[!] Empty stack!\n",
    "[!] The queue is full!\n",
    "[!] The queue is empty!\n",
    "[!] The tree is empty!\n",
    "[!] Node not found in the tree!\n",
    "[!] The list is empty!\n",
    "[!] Error allocating memory!\n",
    "[!] Element not found!\n"
};


Stack 
*createStack (int max) {
  Stack *index = malloc(sizeof(struct stack));

  if (index != NULL) {
    index->max  = max;
    index->top  = -1;
    index->item = malloc(max * sizeof(char));

    if (index->item == NULL) {
      free(index);
      printf("%s", messages[8]);
      exit(1);
    }

    return index;
  } else {
    printf("%s", messages[8]);
    exit(1);
  }
}


int 
stackIsEmpty (Stack *index) {
  if (index->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int 
stackIsFull (Stack *index) {
  if (index->top == index->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void 
stackPush (char element, Stack *index) {
  if (stackIsFull(index)) {
    printf("%s", messages[0]);
    abort();
  } else {
    index->top++;
    index->item[index->top] = element;
  }
}


char 
stackPop (Stack *index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = index->item[index->top];
    index->top--;
    return element;
  }
}


char 
stackTop (Stack *index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->item[index->top];
  }
}


int 
getStackSize (Stack *index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return index->top + 1;
  }
}


void 
displayStack (Stack *index) {
  if (stackIsEmpty(index)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= index->top; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}


void 
deleteStack (Stack *index) {
  free(index->item);
  free(index);
  index = NULL;
}


Queue 
*createQueue (int max) {
  Queue *index  = malloc(sizeof(struct queue));
  index->max   = max;
  index->count = 0;
  index->first = 0;
  index->last  = 0;
  index->item  = malloc(sizeof(max * sizeof(char)));
  return index;
}


int 
queueIsEmpty (Queue *index) {
  return (index->count == 0);
}


int 
queueIsFull (Queue *index) {
  return (index->count == index->max);
}


void 
enqueue (char element, Queue *index) {
  if (queueIsFull (index)) {
    printf("%s", messages[3]);
    abort();
  } else {
    index->item[index->last] = element;
    NEXT(index->last);
    index->count++;
  }
}


char 
dequeue (Queue *index) {
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


int 
getQueueSize (Queue *index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    return index->count;
  }
}


void 
displayQueue (Queue *index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    for (int i = index->first; i < index->max; i++) {
      printf("%i\n", index->item[i]);
    }
  }
}


void 
deleteQueue (Queue *index) {
  free(index->item);
  free(index);
  index = NULL;
}


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


int 
treeIsEmpty (BSTree *node) {
  return (node == NULL);
}


void 
displayPreOrder (BSTree *node) {
  if (node) {
    printf("%i\n",node->node);
    displayPreOrder(node->left);
    displayPreOrder(node->right);
  }
}


void 
displayInOrder (BSTree *node) {
  if (node) {
    displayInOrder(node->left);
    printf("%i\n",node->node);
    displayInOrder(node->right);
  }
}


void 
displayPostOrder (BSTree *node) {
  if (node) {
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    printf("%i\n",node->node);
  }
}


char 
getRoot (BSTree *index) {
  return index->node;
}


int 
getNode (BSTree *index) {
  if (index) {
    return index->node;
  } else {
    printf("%s", messages[6]);
    abort();
  }
}


int 
nodeExists (BSTree *index) {
  if (index != NULL) {
    return 1;
  } else {
    return 0;
  }
}


int 
search (int key, BSTree **node) {
  if (!(*node)) { return 0; }
  if(key < (*node)->node) { search(key, &((*node)->left)); }
  else if(key > (*node)->node) { search(key, &((*node)->right)); }
  else if(key == (*node)->node) { return nodeExists(*node); }
}


BSTree 
*findMin (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->left == NULL) { return node; }
  else { return findMin(node->left); }
}


BSTree 
*findMax (BSTree *node) {
  if (node == NULL) { return NULL; }
  else if (node->right == NULL) { return node; }
  else { return findMax(node->right); }
}


void 
deleteTree (BSTree *node) {
  if (node) {
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
    node = NULL;
  } 
}


List 
*createLinkedList () {
  List *list = malloc (sizeof(List));
  list->head = NULL;
  list->head = list->tail =  NULL;
  list->qty = 0;
  return list; 
}


void 
insertItemBeginLinkedList(int item, List *list) {
  Node *node = malloc (sizeof(Node));
  node->item = item;
  node->next = list->head;

  if (list->tail == NULL) {
    list->tail = node;
  } else {
    list->head->prev = node;
  }

  list->head = node;
  list->qty++;
}


void 
insertItemEndLinkedList(int item, List *list) {
  Node *node = malloc (sizeof(Node));
  node->item = item;
  node->next = NULL;
  node->prev = list->tail;

  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  list->qty++;
}


void 
displayLinkedList (List *list) {
  Node *node = list->head;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->next;
  }

  printf("NULL\n");
}


void 
displayReverseLinkedList (List *list) {
  Node *node = list->tail;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->prev;
  }

  printf("NULL\n");
}


Node
*getLinkedListHead (List *list) {
  return list->head;
}


Node
*getLinkedListTail (List *list) {
  return list->tail;
}


int
getLinkedListNodeItem (Node *index) {
  if (index != NULL) {
    return index->item;
  }
}


Node
*searchLinkedListItem (int item, List *list) {
  if(linkedListIsEmpty(list)) { return NULL; }

  Node *node = list->head;

  while (node && node->item != item) {
    node = node->next;
  }
      
  return node;
}


int 
getLinkedListSize (List *list) {
  return list->qty;
} 


int 
linkedListIsEmpty (List *list) {
  return list->head == NULL;
}


void
removeLinkedListItem (int item, List *list) {
  if(linkedListIsEmpty(list)) { return; }

  Node *node = searchLinkedListItem(item, list);

  if (node == NULL) {
    return;
  } if (node == list->head) {
    list->head = node->next;
  } else {
    node->prev->next = node->next;
  } if (node == list->tail) {
    list->tail = node->prev;
  } else {
    node->next->prev = node->prev;
  }

  list->qty--;
  free(node);
  node = NULL;
}


void 
deleteLinkedList (List *list) {
  Node *node = list->head;

  while (node != NULL) {
    Node *temp = node->next;
    free(node);
    node = temp;
  }

  free(list);
  list = NULL;
}


Map 
createMap (int key, char *value, Map index) {
  Map node = malloc(sizeof(struct map));
  node->key = key;
  strcpy(node->value, value);
  node->next = index;
  return node;
}


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


int 
mapKeyExists (int key, Map index) {
  while (index != NULL && index->key < key) {
    index = index->next;
  }

  return (index != NULL && index->key == key);
}


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


void 
deleteHufftree (Hufftree tree) {
  if (tree) {
    deleteHufftree(tree->left);
    deleteHufftree(tree->right);
    free(tree);
  }
}


Set 
*createEmptySet (int max) {
  Set *set = malloc (sizeof(Set));
  set->values = malloc (max * sizeof(Set));
  set->size = 0;

  return set;
}


void 
insertItemSet (int item, Set *set) {
  if (searchItemSet(item, set) == -1) {
    set->values[set->size] = item;
    set->size++;
  } else {
    return;
  }
}


void 
removeItemSet (int item, Set *set) {
  if (searchItemSet(item, set) == -1 || setIsEmpty(set)) {
    printf("%s", messages[9]);
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
      printf("%s", messages[9]);
      return;
    }
  }
}


Set 
*unionSet (Set *A, Set *B) {
  Set *C = createEmptySet((A->size + B->size));

  for (int i = 0; i < A->size; i++) {
    insertItemSet(A->values[i], C);
  }

  for (int i = 0; i < B->size; i++) {
    insertItemSet(B->values[i], C);
  }

  return C;
}


Set 
*intersectionSet (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = createEmptySet(max);

  for (int i = 0; i < max; i++) {
    if (searchItemSet(B->values[i], A) != -1) {
      C->values[C->size++] = B->values[i];
    }
  }

  return C;
}


Set 
*differenceSet (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = createEmptySet(max);

  for (int i = 0; i < max; i++) {
    if (searchItemSet(A->values[i], B) == -1) {
      C->values[C->size++] = A->values[i];
    }
  }

  return C;
}


int 
getSetSize (Set *set) {
  return set->size;
}


int 
getHighestSetValue (Set *set) {
  int value = 0;

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] > value) {
      value = set->values[i];
    }
  }

  return value;
}


int 
getLowestSetValue (Set *set) {
  int value = 1;

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] < value) {
      value = set->values[i];
    }
  }

  return value;
}


int 
setIsEmpty (Set *set) {
  return (set->size == 0);
}


int 
searchItemSet (int item, Set *set) {
  for (int i = 0; i < set->size; i++) {
    if (set->values[i] == item) {
      return set->values[i];
    }
  }

  return -1;
}


void 
displaySet (Set *set) {
  printf("{ ");
  for (int i = 0; i < set->size; i++) {
    printf("%i ", set->values[i]);
  }

  printf("}\n");
}


void 
deleteSet (Set *set) {
  free(set->values);
  free(set);

  set = NULL;
}
