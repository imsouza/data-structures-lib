#include "dslib.h"

struct htree {
  struct htree *left;
  char chr;
  int frq;
  struct htree *right;
};


Hufftree 
hufftreeCreateNode (Hufftree left, char chr, int frq, Hufftree right) {
  Hufftree index = mallocSafe (sizeof(struct htree));
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