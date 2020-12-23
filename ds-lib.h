#define next(element) (element = (element + 1) % this->max)

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


static const char * const messages[] = {
    "[!] Stack overflow!\n",
    "[!] Stack underflow!\n",
    "[!] Empty stack!\n",
    "[!] The queue is full!\n",
    "[!] The queue is empty!\n",
    "[!] The tree is empty!\n",
    "[!] Node not found in the tree\n"
};


Stack stack (int max) {
  Stack this = malloc(sizeof(struct stack));
  this->max  = max;
  this->top  = -1;
  this->item = malloc(max * sizeof(char));
  return this;
}


int emptyStack (Stack this) {
  if (this->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int fullStack (Stack this) {
  if (this->top == this->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void stackPush (char element, Stack this) {
  if (fullStack(this)) {
    printf("%s", messages[0]);
    abort();
  } else {
    this->top++;
    this->item[this->top] = element;
  }
}


char stackPop (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = this->item[this->top];
    this->top--;
    return element;
  }
}


char stackTop (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return this->item[this->top];
  }
}


int stackSize (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return this->top + 1;
  }
}


void displayStack (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= this->top; i++) {
      printf("%i\n", this->item[i]);
    }
  }
}


void deleteStack (Stack *this) {
  free((*this)->item);
  free(*this);
  *this = NULL;
}


Queue queue (int max) {
  Queue this  = malloc(sizeof(struct queue));
  this->max   = max;
  this->count = 0;
  this->first = 0;
  this->last  = 0;
  this->item  = malloc(sizeof(max * sizeof(char)));
  return this;
}


int emptyQueue (Queue this) {
  return (this->count == 0);
}


int fullQueue (Queue this) {
  return (this->count == this->max);
}


void enqueue (char element, Queue this) {
  if (fullQueue(this)) {
    printf("%s", messages[3]);
    abort();
  } else {
    this->item[this->last] = element;
    next(this->last);
    this->count++;
  }
}


char dequeue (Queue this) {
  if (emptyQueue(this)) {
    printf("%s", messages[4]);
    abort();
  } else {
    char element = this->item[this->first];
    next(this->first);
    this->count--;
    return element;
  }
}


int queueSize (Queue this) {
  if (emptyQueue(this)) {
    printf("%s", messages[4]);
    abort();
  } else {
    return this->count;
  }
}


void displayQueue (Queue this) {
  if (emptyQueue(this)) {
    printf("%s", messages[4]);
    abort();
  } else {
    for (int i = this->first; i < this->max; i++) {
      printf("%i\n", this->item[i]);
    }
  }
}


void deleteQueue (Queue *this) {
  free((*this)->item);
  free(*this);
  *this = NULL;
}


BSTree *generateEmptyTree () {
  return NULL;
}


void insert (BSTree **node, int key) {
  BSTree *temp = NULL;
  if (!(*node)) {
    temp = (BSTree *) malloc(sizeof(BSTree));
    temp->left = temp->right = NULL;
    temp->node = key;
    *node = temp;
  } if (key < (*node)->node) {
    insert(&(*node)->left, key);
  } else if (key > (*node)->node) {
    insert(&(*node)->right, key);
  }
}


int emptyTree (BSTree *node) {
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


char getRoot (BSTree *this) {
  return this->node;
}


int getNode (BSTree *this) {
  if (this) {
    return this->node;
  } else {
    printf("%s", messages[6]);
    abort();
  }
}


BSTree *search (BSTree **node, int key) {
  if (!(*node)) { return NULL; }
  if(key < (*node)->node) { search(&((*node)->left), key); }
  else if(key > (*node)->node) { search(&((*node)->right), key); }
  else if(key == (*node)->node) { return *node; }
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

