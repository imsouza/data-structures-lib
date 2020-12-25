#include <string.h>

#define next(element) (element = (element + 1) % index->max)
#define SIZE 25

typedef struct stack {
  int max;
  int top;
  char *item;
} *Stack;


typedef struct queue {
  int max;
  int count;
  int first;
  int last;
  char *item;
} *Queue;


typedef struct tree {
  char node;
  struct tree *left;
  struct tree *right;
} BSTree;


typedef struct list {
  int item;
  struct list *next;
} *List;


typedef struct map {
  int key;
  char value[SIZE];
  struct map *next;
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


Stack stack (int max) {
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


int fullStack (Stack index) {
  if (index->top == index->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void stackPush (char element, Stack index) {
  if (fullStack(index)) {
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


Queue queue (int max) {
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


int fullQueue (Queue index) {
  return (index->count == index->max);
}


void enqueue (char element, Queue index) {
  if (fullQueue(index)) {
    printf("%s", messages[3]);
    abort();
  } else {
    index->item[index->last] = element;
    next(index->last);
    index->count++;
  }
}


char dequeue (Queue index) {
  if (queueIsEmpty(index)) {
    printf("%s", messages[4]);
    abort();
  } else {
    char element = index->item[index->first];
    next(index->first);
    index->count--;
    return element;
  }
}


int queueSize (Queue index) {
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


List list (int element, List index) {
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
  return list(index->item, cloneList(index->next));
}


int listSize (List index) {
  if (index == NULL) { return 0; }
  return 1 + listSize(index->next);
} 


int listIsEmpty (List index) {
  if (listSize(index) > 0) { return 0; }
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


Map nodeMap (int key, char *value, Map index) {
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
    *index = nodeMap(key, value, *index);
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