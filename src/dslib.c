#include "dslib.h"

#define ERROR(msg) fprintf(stderr, "[!]: %s\n", #msg)
#define WARNING(msg) fprintf(stdout, "[!]: %s\n", #msg)

void 
*mallocSafe (size_t nbytes) {
  void *ptr = malloc (nbytes);
  
  if (ptr == NULL) {
    ERROR(error allocating memory.);
    exit(EXIT_FAILURE);
  }

  return ptr;
}


void 
displayTreePreOrder (struct node *root) {
  if (root) {
    printf("%i\n",root->item);
    displayTreePreOrder(root->left);
    displayTreePreOrder(root->right);
  }
}


void 
displayTreeInOrder (struct node *root) {
  if (root) {
    displayTreeInOrder(root->left);
    printf("%i\n",root->item);
    displayTreeInOrder(root->right);
  }
}


void 
displayTreePostOrder (struct node *root) {
  if (root) {
    displayTreePostOrder(root->left);
    displayTreePostOrder(root->right);
    printf("%i\n",root->item);
  }
}


void 
displayTree (int level, struct node *root) {
  if (root == NULL) {
    treePadding('\t', level);
    puts("~");
  } else {
    displayTree(level + 1, root->right);
    treePadding('\t', level);
    printf("%i\n", root->item);
    displayTree(level + 1, root->left);
  }
}


void 
treePadding (char ch, int n) {
  if (n > 0) {
    treePadding(ch, n - 1);
    putchar(ch);
  }
}


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