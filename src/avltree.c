#include "dslib.h"

AVLTree 
*AVLTreeCreate () {
  AVLTree *node = NULL;
  return node;
}


AVLTree 
*AVLTreeCreateNode (int item) {
  AVLTree *node = mallocSafe (sizeof(AVLTree));
  node->item    = item;
  node->left    = NULL;
  node->right   = NULL;
  node->height  = 0;
  return node;
}


AVLTree
*AVLTreeSearch (int item, AVLTree *root) {
  if (root == NULL) {
    return root;
  } if (root->item > item) {
    return AVLTreeSearch(item, root->left);
  } else {
    return AVLTreeSearch(item, root->right);
  }
}


int
AVLTreeHeight (AVLTree *root) {
  if (root == NULL) {
    return -1;
  }

  return root->height;
}


int
AVLTreeMax (int a, int b) {
  return (a > b) ? a : b;
}


int
AVLTreeBalanceFactor (AVLTree *root) {
  return AVLTreeHeight(root->left) - AVLTreeHeight(root->right);
}


AVLTree 
*AVLTreeRightRotation (AVLTree *A) {
  AVLTree *B = A->left;

  A->left    = B->right;
  B->right   = A;

  A->height  = AVLTreeMax(AVLTreeHeight(A->left), \
                          AVLTreeHeight(A->right)) + 1;
  B->height  = AVLTreeMax(AVLTreeHeight(B->left), \
                          AVLTreeHeight(B->right)) + 1;

  return B;
}


AVLTree 
*AVLTreeLeftRotation (AVLTree *A) {
  AVLTree *B = A->right;

  A->right    = B->left;
  B->left     = A;

  A->height  = AVLTreeMax(AVLTreeHeight(A->left), \
                          AVLTreeHeight(A->right)) + 1;
  B->height  = AVLTreeMax(AVLTreeHeight(B->left), \
                          AVLTreeHeight(B->right)) + 1;

  return B;
}


AVLTree
*AVLTreeInsertNode (AVLTree *node, AVLTree *root) {
  if (root == NULL) {
    return node;
  } if(root->item > node->item) {
    root->left = AVLTreeInsertNode(node, root->left);
  } else {
    root->right = AVLTreeInsertNode(node, root->right);
  }

  root->height = AVLTreeMax(AVLTreeHeight(root->left), \
                            AVLTreeHeight(root->right)) + 1;

  int balanceFactor = AVLTreeBalanceFactor(root);

  if (balanceFactor > 1 && node->item < root->left->item) {
    return AVLTreeRightRotation(root);
  }

  if (balanceFactor < -1 && node->item > root->right->item) {
    return AVLTreeLeftRotation(root);
  }

  if (balanceFactor > 1 && node->item > root->left->item) {
    root->left = AVLTreeLeftRotation(root->left);
    return AVLTreeRightRotation(root);
  }

  if (balanceFactor < -1 && node->item < root->right->item) {
    root->right = AVLTreeRightRotation(root->right);
    return AVLTreeLeftRotation(root);
  }

  return root;
}


AVLTree 
*AVLTreeRemoveNode (int item, AVLTree *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->item > item) {
    root->left = AVLTreeRemoveNode(item, root->left);
  } else if (root->item < item) {
    root->right = AVLTreeRemoveNode(item, root->right);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    } else if (root->left == NULL) {
      AVLTree *t = root;
      root = root->right;
      free(t);
    } else if (root->right == NULL) {
      AVLTree *t = root;
      root = root->left;
      free(t);
    } else {
      AVLTree *f = root->left;

      while (f->right != NULL) {
        f = f->right;
      }

      root->item = f->item;
      f->item = item;

      root->left = AVLTreeRemoveNode(item, root->left);
    }
  }

  if (root == NULL) {
    return root; 
  }

  root->height = AVLTreeMax(AVLTreeHeight(root->left), \
                            AVLTreeHeight(root->right)) + 1;

  int balanceFactor = AVLTreeBalanceFactor(root);

  if (balanceFactor > 1 && AVLTreeBalanceFactor(root->left) >= 0) {
    return AVLTreeRightRotation(root);
  }

  if (balanceFactor < -1 && AVLTreeBalanceFactor(root->right) <= 0) {
    return AVLTreeLeftRotation(root);
  }

  if (balanceFactor > 1 && AVLTreeBalanceFactor(root->left) < 0) {
    root->left = AVLTreeLeftRotation(root->left);
    return AVLTreeRightRotation(root);
  }

  if (balanceFactor < -1 && AVLTreeBalanceFactor(root->right) > 0) {
    root->right = AVLTreeRightRotation(root->right);
    return AVLTreeLeftRotation(root);
  }

  return root;
}


void 
AVLTreeDestroy (AVLTree *root) {
  if (root) {
    AVLTreeDestroy(root->left);
    AVLTreeDestroy(root->right);
    free(root);
  }
}