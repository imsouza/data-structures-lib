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
#include <limits.h>
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


struct bstree {
  int item;
  struct bstree *left;
  struct bstree *right;
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


struct pvalue {
  int prio;
};


struct prioq {
  int first;
  int last;
  int qty;
  struct pvalue pvalue_t[SIZE];
};


const char * const messages[] = {
    "[!] Stack overflow!\n",  // 0
    "[!] Stack underflow!\n", // 1
    "[!] Empty stack!\n",     // 2
    "[!] The queue is full!\n", // 3
    "[!] The queue is empty!\n",// 4
    "[!] The tree is empty!\n", // 5
    "[!] Node not found in the tree!\n", // 6 
    "[!] The list is empty!\n",          // 7
    "[!] Error allocating memory!\n",    // 8
    "[!] Element not found!\n",          // 9
    "[!] Key not found!\n",              // 10
};


Stack 
*stackCreate (int max) {
  Stack *stack = malloc(sizeof(struct stack));

  if (stack != NULL) {
    stack->max  = max;
    stack->top  = -1;
    stack->item = malloc(max * sizeof(char));

    if (stack->item == NULL) {
      free(stack);
      printf("%s", messages[8]);
      exit(1);
    }

    return stack;
  } else {
    printf("%s", messages[8]);
    exit(1);
  }
}


int 
stackIsEmpty (Stack *stack) {
  if (stack->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int 
stackIsFull (Stack *stack) {
  if (stack->top == stack->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void 
stackPush (char element, Stack *stack) {
  if (stackIsFull(stack)) {
    printf("%s", messages[0]);
    abort();
  } else {
    stack->top++;
    stack->item[stack->top] = element;
  }
}


char 
stackPop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = stack->item[stack->top];
    stack->top--;
    return element;
  }
}


char 
stackTop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return stack->item[stack->top];
  }
}


int 
stackSize (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return stack->top + 1;
  }
}


void 
stackDisplay (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= stack->top; i++) {
      printf("%i\n", stack->item[i]);
    }
  }
}


void 
stackDestroy (Stack *stack) {
  free(stack->item);
  free(stack);
  stack = NULL;
}


Queue 
*queueCreate (int max) {
  Queue *queue  = malloc(sizeof(struct queue));
  queue->max   = max;
  queue->count = 0;
  queue->first = 0;
  queue->last  = 0;
  queue->item  = malloc(sizeof(max * sizeof(char)));
  return queue;
}


int 
queueIsEmpty (Queue *queue) {
  return (queue->count == 0);
}


int 
queueIsFull (Queue *queue) {
  return (queue->count == queue->max);
}


void 
queueEnqueue (char element, Queue *queue) {
  if (queueIsFull (queue)) {
    printf("%s", messages[3]);
    abort();
  } else {
    queue->item[queue->last] = element;
    NEXT(queue->last);
    queue->count++;
  }
}


char 
queueDequeue (Queue *queue) {
  if (queueIsEmpty(queue)) {
    printf("%s", messages[4]);
    abort();
  } else {
    char element = queue->item[queue->first];
    NEXT(queue->first);
    queue->count--;
    return element;
  }
}


int 
queueSize (Queue *queue) {
  if (queueIsEmpty(queue)) {
    printf("%s", messages[4]);
    abort();
  } else {
    return queue->count;
  }
}


void 
queueDisplay (Queue *queue) {
  if (queueIsEmpty(queue)) {
    printf("%s", messages[4]);
    abort();
  } else {
    for (int i = queue->first; i < queue->max; i++) {
      printf("%i\n", queue->item[i]);
    }
  }
}


void 
queueDestroy (Queue *queue) {
  free(queue->item);
  free(queue);
  queue = NULL;
}


BSTree 
*binarySearchTreeCreateNode (int item) {
  BSTree *node = malloc(sizeof(BSTree));
  node->item  = item;
  node->left  = NULL;
  node->right = NULL;
  return node;
}


BSTree
*binarySearchTreeInsertNode (BSTree *newNode, BSTree *root) {
  if(root == NULL) {
    return newNode;
  } if (root->item > newNode->item) {
    root->left = binarySearchTreeInsertNode(newNode, root->left);
  } else {
    root->right = binarySearchTreeInsertNode(newNode, root->right);
  }

  return root;
}


BSTree 
*binarySearchTreeRemoveNode (int key, BSTree *root) {
  BSTree *father = NULL;
  BSTree *temp   = root;

  while (temp != NULL && temp->item != key) {
    father = temp;
    if (temp->item > key) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if(temp == NULL) {
    printf("%s", messages[10]);
    return root;
  }

  if (temp->right == NULL && temp->left == NULL) {
    if(temp != root) {
      if(father->left == temp) {
        father->left = NULL;
      } else {
        father->right = NULL;
      }
    } else {
      root = NULL;
    }

    free(temp);
  } 

  else if (temp->right == NULL) {
    if (temp != root) {
      if (father->left == temp) {
        father->left = temp->left;
      } else {
        father->right = temp->left;
      }
    } else {
      root = temp->left;
    }

    free(temp);
  }

  else if (temp->left == NULL) {
    if (temp != root) { 
      if (father->left == temp) {
        father->left = temp->right;
      } else {
        father->right = temp->right; 
      }
    } else {
      root = temp->right;
    }

    free(temp);
  }

  else {
    BSTree *aux = temp->left;
    father = NULL;

    while (aux->right != NULL) {
      father = aux;
      aux = aux->right;
    }

    if (father != NULL) {
      father->right = aux->left;
    } else {
      temp->left = aux->left;
    }

    temp->item = aux->item;
    free(aux);
  }

  return root;
}


int 
binarySearchTreeIsEmpty (BSTree *root) {
  return (root == NULL);
}


void 
binarySearchTreeDisplayPreOrder (BSTree *root) {
  if (root) {
    printf("%i\n",root->item);
    binarySearchTreeDisplayPreOrder(root->left);
    binarySearchTreeDisplayPreOrder(root->right);
  }
}


void 
binarySearchTreeDisplayInOrder (BSTree *root) {
  if (root) {
    binarySearchTreeDisplayInOrder(root->left);
    printf("%i\n",root->item);
    binarySearchTreeDisplayInOrder(root->right);
  }
}


void 
binarySearchTreeDisplayPostOrder (BSTree *root) {
  if (root) {
    binarySearchTreeDisplayPostOrder(root->left);
    binarySearchTreeDisplayPostOrder(root->right);
    printf("%i\n",root->item);
  }
}


void 
binarySearchTreePadding (char ch, int n) {
  for (int i = 0; i < n; i++ ) {
    putchar(ch);
  }
}


void 
binarySearchTreeDisplayTree (int level, BSTree *root) {
  if (root == NULL) {
    binarySearchTreePadding('\t', level);
    puts("~");
  } else {
    binarySearchTreeDisplayTree(level + 1, root->right);
    binarySearchTreePadding('\t', level);
    printf("%d\n", root->item);
    binarySearchTreeDisplayTree(level + 1, root->left);
  }
}


int 
binarySearchTreeGetItem (BSTree *root) {
  return root->item;
}


int 
binarySearchTreeItemExists (int item, BSTree *root) {
  if (root == NULL) {
    return 0;
  } if(root->item == item) {
    return 1;
  } else if (binarySearchTreeItemExists(item, root->left)) {
    return 1;
  } else {
    return binarySearchTreeItemExists(item, root->right);
  }
}


BSTree 
*binarySearchTreeSearch (int key, BSTree *root) {
  if (root == NULL || root->item == key) { 
    return root; 
  }

  if (root->item > key) {
    return binarySearchTreeSearch(key, root->left);
  } else {
    return binarySearchTreeSearch(key, root->right);
  }
}


int 
binarySearchTreeTotalNodes (BSTree *root) {
  if (root == NULL) {
    return 0;
  } else  {
    return binarySearchTreeTotalNodes(root->left) + \
    binarySearchTreeTotalNodes(root->right) + 1;
  }
}


int 
binarySearchTreeHeight (BSTree *root) {
  if (root == NULL) {
    return -1;
  }

  int hSTL = binarySearchTreeHeight(root->left);
  int hSTR = binarySearchTreeHeight(root->right);

  if (hSTL > hSTR) {
    return hSTL + 1;
  } else {
    return hSTR + 1;
  }
}


int 
binarySearchTreeIsBalanced (BSTree *root) {
  if (root == NULL) { 
    return 1; 
  } else if (!binarySearchTreeIsBalanced(root->left)) {
    return 0;
  } else if (!binarySearchTreeIsBalanced(root->right)) {
    return 0;
  } else if (abs(binarySearchTreeHeight(root->left) - \
    binarySearchTreeHeight(root->right)) > 1) {
    return 0;
  }

  return 1;
}


int 
binarySearchTreeTotalLeafs (BSTree *root) {
  if (root == NULL) {
    return 0;
  } else if (root->left == NULL && root->right == NULL) { 
    return 1; 
  }

  return binarySearchTreeTotalLeafs(root->left) + \
  binarySearchTreeTotalLeafs(root->right);
}


BSTree 
*binarySearchTreeFindMin (BSTree *root) {
  if (root == NULL) { 
    return NULL; 
  } else if (root->left == NULL) { 
    return root; 
  } else { 
    return binarySearchTreeFindMin(root->left); 
  }
}


BSTree 
*binarySearchTreeFindMax (BSTree *root) {
  if (root == NULL) { 
    return NULL; 
  } else if (root->right == NULL) { 
    return root; 
  } else { 
    return binarySearchTreeFindMax(root->right); 
  }
}


void 
binarySearchTreeDestroy (BSTree *root) {
  if (root) {
    binarySearchTreeDestroy(root->left);
    binarySearchTreeDestroy(root->right);
    free(root);
    root = NULL;
  } 
}


List 
*linkedListCreate () {
  List *list = malloc (sizeof(List));
  list->head = NULL;
  list->head = list->tail =  NULL;
  list->qty = 0;
  return list; 
}


void 
linkedListInsertItemBegin (int item, List *list) {
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
linkedListInsertItemEnd (int item, List *list) {
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
linkedListDisplay (List *list) {
  Node *node = list->head;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->next;
  }

  printf("NULL\n");
}


void 
linkedListReverseDisplay (List *list) {
  Node *node = list->tail;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->prev;
  }

  printf("NULL\n");
}


Node
*linkedListHead (List *list) {
  return list->head;
}


Node
*linkedListTail (List *list) {
  return list->tail;
}


int
linkedListNode (Node *index) {
  if (index != NULL) {
    return index->item;
  }
}


Node
*linkedListSearch (int item, List *list) {
  if(linkedListIsEmpty(list)) { return NULL; }

  Node *node = list->head;

  while (node && node->item != item) {
    node = node->next;
  }
      
  return node;
}


int 
linkedListSize (List *list) {
  return list->qty;
} 


int 
linkedListIsEmpty (List *list) {
  return list->head == NULL;
}


void
linkedListRemove (int item, List *list) {
  if(linkedListIsEmpty(list)) { return; }

  Node *node = linkedListSearch(item, list);

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
linkedListDestroy (List *list) {
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
mapCreate (int key, char *value, Map index) {
  Map node = malloc(sizeof(struct map));
  node->key = key;
  strcpy(node->value, value);
  node->next = index;
  return node;
}


void 
mapInsert (int key, char *value, Map *index) {
  while (*index != NULL && (*index)->key < *value) {
    index = &(*index)->next;
  } if (*index != NULL && (*index)->key == *value) {
    strcpy((*index)->value, value);
  } else {
    *index = mapCreate(key, value, *index);
  }
}


int 
mapRemove (int key, Map *index) {
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
mapDisplay (Map index) {
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
mapDestroy (Map *index) {
  while ((*index) != NULL) {
    Map node = *index;
    *index = node->next;
    free(node);
  }
}


Hufftree 
hufftreeCreateNode (Hufftree left, char chr, int frq, Hufftree right) {
  Hufftree index = malloc(sizeof(struct htree));
  index->left  = left;
  index->chr   = chr;
  index->frq   = frq;
  index->right = right;
  return index;
}


int 
*hufftreeFrequency (char *string) {
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
hufftreeInsert (Hufftree tree, Hufftree *forest, int *qty) {
  int i = *qty;

  while(i > 0 && forest[i - 1]->frq < tree->frq) {
    forest[i] = forest[i - 1];
    i--;
  }

  forest[i] = tree;
  (*qty)++;
}


Hufftree 
hufftreeRemove (Hufftree *forest, int *qty) {
  if (*qty == 0) { abort(); }
  return forest[--(*qty)];
}


Hufftree 
hufftreeCreate (char *string) {
  Hufftree forest[FREQ];
  int qty = 0;
  int *leaf = hufftreeFrequency(string);

  for (int chr = 0; chr < FREQ; chr++) {
    if (leaf[chr] > 0) {
      hufftreeInsert(hufftreeCreateNode(NULL, chr, leaf[chr], NULL),
      forest, &qty);
    }
  }

  while (qty > 1) {
    Hufftree right = hufftreeRemove(forest, &qty);
    Hufftree left  = hufftreeRemove(forest, &qty);
    hufftreeInsert(hufftreeCreateNode(left, '-', left->frq + right->frq, right),
    forest, &qty);
  }

  return forest[0];
}


void 
hufftreeDisplay (Hufftree tree) {
  static int node = -1;

  if (tree == NULL) { return; }

  node++;

  hufftreeDisplay(tree->right);

  for (int i = 0; i < HCOL * node; i++) {
    putchar(' ');
  }

  printf("(%c, %i)\n", tree->chr, tree->frq);

  hufftreeDisplay(tree->left);

  node--;
}


void 
hufftreeDisplayLeaves (Hufftree tree) {
  static char array[FREQ], last = -1;

  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    printf("%c : %.*s\n", tree->chr, last + 1, array);
  } else {
    last++; 
    array[last] = '0'; hufftreeDisplayLeaves(tree->left);
    array[last] = '1'; hufftreeDisplayLeaves(tree->right);
    last--;
  }
}


void 
hufftreeCreateTable (Hufftree tree, char *T[]) {
  static char array[FREQ], last = -1;
  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    T[tree->chr] = strndup(array, last+1);
  } else {
    last++;
    array[last] = '0'; hufftreeCreateTable(tree->left, T);
    array[last] = '1'; hufftreeCreateTable(tree->right, T);
    last--;
  }
}


void 
hufftreeCompressString (char *string, Hufftree tree) {
  char *T[FREQ];

  for (int chr = 0; chr < FREQ; chr++) {
    T[chr] = NULL;
  }

  hufftreeCreateTable(tree, T);

  for (int i = 0; string[i]; i++) {
    printf("%s", T[string[i]]);
  }

  for (int chr = 0; chr < FREQ; chr++) {
    free(T[chr]);
  }
}


void 
hufftreeDecompressString (char *string, Hufftree tree) {
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
hufftreeDestroy (Hufftree tree) {
  if (tree) {
    hufftreeDestroy(tree->left);
    hufftreeDestroy(tree->right);
    free(tree);
  }
}


Set 
*setCreate (int max) {
  Set *set = malloc (sizeof(Set));
  set->values = malloc (max * sizeof(Set));
  set->size = 0;

  return set;
}


void 
setInsert (int item, Set *set) {
  if (setSearch(item, set) == -1) {
    set->values[set->size] = item;
    set->size++;
  } else {
    return;
  }
}


void 
setRemove (int item, Set *set) {
  if (setSearch(item, set) == -1 || setIsEmpty(set)) {
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
*setUnion (Set *A, Set *B) {
  Set *C = setCreate((A->size + B->size));

  for (int i = 0; i < A->size; i++) {
    setInsert(A->values[i], C);
  }

  for (int i = 0; i < B->size; i++) {
    setInsert(B->values[i], C);
  }

  return C;
}


Set 
*setIntersection (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = setCreate(max);

  for (int i = 0; i < max; i++) {
    if (setSearch(B->values[i], A) != -1) {
      C->values[C->size++] = B->values[i];
    }
  }

  return C;
}


Set 
*setDifference (Set *A, Set *B) {
  int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = setCreate(max);

  for (int i = 0; i < max; i++) {
    if (setSearch(A->values[i], B) == -1) {
      C->values[C->size++] = A->values[i];
    }
  }

  return C;
}


int 
setSize (Set *set) {
  return set->size;
}


int 
setHighestValue (Set *set) {
  int value = 0;

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] > value) {
      value = set->values[i];
    }
  }

  return value;
}


int 
setLowestValue (Set *set) {
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
setSearch (int item, Set *set) {
  for (int i = 0; i < set->size; i++) {
    if (set->values[i] == item) {
      return set->values[i];
    }
  }

  return -1;
}


void 
setDisplay (Set *set) {
  printf("{ ");
  for (int i = 0; i < set->size; i++) {
    printf("%i ", set->values[i]);
  }

  printf("}\n");
}


void 
setDestroy (Set *set) {
  free(set->values);
  free(set);

  set = NULL;
}


PrioQ 
*priorityQueueCreate () {
  PrioQ *queue = malloc (sizeof(PrioQ));
  queue->first = queue->last = queue->qty = 0;
  return queue;
}


void 
priorityQueueInsert (int value, PrioQ *queue) {
  if (queue == NULL) return;

  if (!priorityQueueIsFull(queue)) {
    int index = queue->qty - 1;
    while (index >= 0 && queue->pvalue_t[index].prio >= value) {
      queue->pvalue_t[index + 1] = queue->pvalue_t[index];
      index--;
    }

    queue->pvalue_t[index + 1].prio = value;
    queue->qty++;
  } else {
    printf("%s", messages[3]);
    exit(1);
  }
}


void 
priorityQueueRemoveHighestPrio (PrioQ *queue) {
  if (!priorityQueueIsEmpty(queue) || queue != NULL) {
   queue->qty--;
  }
}


int 
priorityQueueFirst (PrioQ *queue) {
  return queue->pvalue_t[queue->qty - 1].prio;
}


bool 
priorityQueueIsEmpty (PrioQ *queue) {
  return queue->qty == 0;
}


bool 
priorityQueueIsFull (PrioQ *queue) {
  return queue->qty == SIZE;
}


int 
priorityQueueSize (PrioQ *queue) {
  return queue->qty;
}


void 
priorityQueueDestroy (PrioQ *queue) {
  free(queue);
  queue = NULL;
}
