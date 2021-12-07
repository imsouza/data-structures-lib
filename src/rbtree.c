#include "dslib.h"

RBTree 
*redBlackTreeCreate () {
  RBTree *node = NULL;
  return node;
}


RBTree 
*redBlackTreeCreateNode (int item) {
  RBTree *node = mallocSafe (sizeof(RBTree));
  node->item   = item;
  node->left   = NULL;
  node->right  = NULL;
  node->color  = red;
  node->status = false;
  return node;
}


tColor 
redBlackTreeColor (RBTree *root) {
  if (root == NULL) {
    return black;
  } else {
    return root->color;
  }
}


void
redBlackTreeSwapColor (RBTree *root) {
  root->color = !root->color;

  if (root->left != NULL) {
    root->left->color = !root->left->color;
  }

  if (root->right != NULL) {
    root->right->color = !root->right->color;
  }
}


RBTree
*redBlackTreeLeftRotation (RBTree *root) {
  RBTree *node = root->right;
  root->right  = node->left;
  node->left   = root;
  node->color  = root->color;
  root->color  = red;
  return node;
}


RBTree
*redBlackTreeRightRotation (RBTree *root) {
  RBTree *node = root->left;
  root->left   = node->right;
  node->right  = root;
  node->color  = root->color;
  root->color  = red;
  return node;
}


RBTree
*redBlackTreeMoveRedNodeLeft (RBTree *root) {
  redBlackTreeSwapColor(root);

  if (redBlackTreeColor(root->right->left) == red) {
    root->right = redBlackTreeRightRotation(root->right);
    root = redBlackTreeLeftRotation(root);
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeMoveRedNodeRight (RBTree *root) {
  redBlackTreeSwapColor(root);

  if (redBlackTreeColor(root->left->left) == red) {
    root = redBlackTreeRightRotation(root);
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeBalance (RBTree *root) {
  if (redBlackTreeColor(root->right) == red) {
    root = redBlackTreeLeftRotation(root);
  }

  if (root->left != NULL && \
      redBlackTreeColor(root->right) == red && \
      redBlackTreeColor(root->left->left) == red) {
    root = redBlackTreeRightRotation(root);
  }

  if (redBlackTreeColor(root->left) == red && \
      redBlackTreeColor(root->right) == red) {
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeInsertNode (RBTree *node, RBTree *root) {
  if (root == NULL) {
    node->status = true;
    return node;
  } if (node == NULL) {
    node->status = false;
    return NULL;
  }

  if (node->item == root->item) {
    node->status = false;
  } else {
    if (node->item < root->item) {
      root->left = redBlackTreeInsertNode(node, root->left);
    } else {
      root->right = redBlackTreeInsertNode(node, root->right);
    }
  }

  if (redBlackTreeColor(root->right) == red && \
      redBlackTreeColor(root->left) == black) {
    root = redBlackTreeLeftRotation(root);
  }

  if (redBlackTreeColor(root->left) == red && \
      redBlackTreeColor(root->left->left) == red) {
    root = redBlackTreeRightRotation(root);
  }

  if (redBlackTreeColor(root->left) == red && \
      redBlackTreeColor(root->right) == red) {
    redBlackTreeSwapColor(root);
  }

  if (root != NULL) {
    root->color = black;
  }

  return root;
}


bool
redBlackTreeStatus (RBTree *root) {
  return root->status;
}


void 
redBlackTreeDestroy (RBTree *root) {
  if (root) {
    redBlackTreeDestroy(root->left);
    redBlackTreeDestroy(root->right);
    free(root);
  }
}