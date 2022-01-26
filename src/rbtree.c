#include "dslib.h"

RBTree 
*redBlackTreeInit () {
  RBTree *node = NULL;
  return node;
}


RBTree 
*redBlackTreeCreateNode (int item) {
  RBTree *node = mallocSafe (sizeof(RBTree));
  node->item   = item;
  node->left   = NULL;
  node->right  = NULL;
  node->status = false;
  return node;
}


tColor 
redBlackTreeColor (RBTree *root) {
  if (root == NULL) {
    return BLACK;
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
*redBlackTreeLeftRotation (RBTree *A) {
  RBTree *B = A->right;
  A->right  = B->left;
  B->left   = A;
  B->color  = A->color;
  A->color  = RED;
  return B;
}


RBTree
*redBlackTreeRightRotation (RBTree *A) {
  RBTree *B = A->left;
  A->left   = B->right;
  B->right  = A;
  B->color  = A->color;
  A->color  = RED;
  return B;
}


RBTree
*redBlackTreeMoveRedNodeLeft (RBTree *root) {
  redBlackTreeSwapColor(root);

  if (redBlackTreeColor(root->right->left) == RED) {
    root->right = redBlackTreeRightRotation(root->right);
    root = redBlackTreeLeftRotation(root);
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeMoveRedNodeRight (RBTree *root) {
  redBlackTreeSwapColor(root);

  if (redBlackTreeColor(root->left->left) == RED) {
    root = redBlackTreeRightRotation(root);
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeBalance (RBTree *root) {
  if (redBlackTreeColor(root->right) == RED) {
    root = redBlackTreeLeftRotation(root);
  }

  if (root->left != NULL && \
      redBlackTreeColor(root->right) == RED && \
      redBlackTreeColor(root->left->left) == RED) {
    root = redBlackTreeRightRotation(root);
  }

  if (root->left != NULL && \
      redBlackTreeColor(root->left) == RED && \
      redBlackTreeColor(root->left->left) == RED) {
    root = redBlackTreeRightRotation(root);
  }

  if (redBlackTreeColor(root->left) == RED && \
      redBlackTreeColor(root->right) == RED) {
    redBlackTreeSwapColor(root);
  }

  return root;
}


RBTree
*redBlackTreeInsertNode (RBTree *node, RBTree *root) {
  if (root == NULL) {
    if (node == NULL) {
      node->status = false;
      return node;
    }

    node->status = true;
    node->color  = RED;
    return node;
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

  if (redBlackTreeColor(root->right) == RED && \
      redBlackTreeColor(root->left) == BLACK) {
    root = redBlackTreeLeftRotation(root);
  }

  if (redBlackTreeColor(root->left) == RED && \
      redBlackTreeColor(root->left->left) == RED) {
    root = redBlackTreeRightRotation(root);
  }

  if (redBlackTreeColor(root->left) == RED && \
      redBlackTreeColor(root->right) == RED) {
    redBlackTreeSwapColor(root);
  }

  if (root == NULL) {
    root->color = BLACK;
  }

  return root;
}


RBTree 
*redBlackTreeRemoveNode (int item, RBTree *root) {  
  if (redBlackTreeSearch(item, root)) {
    if (item < root->item) {
      if (redBlackTreeColor(root->left) == BLACK && \
          redBlackTreeColor(root->left->left) == BLACK) {
        root = redBlackTreeMoveRedNodeLeft(root);
      }

      root->left = redBlackTreeRemoveNode(item, root->left);
    } else {
      if (redBlackTreeColor(root->left) == RED) {
        root = redBlackTreeRightRotation(root);
      }

      if (item == root->item && root->right == NULL) {
        free(root);
        return NULL;
      }

      if (redBlackTreeColor(root->right) == BLACK && \
          redBlackTreeColor(root->right->left) == BLACK) {
        root = redBlackTreeMoveRedNodeRight(root);
      }

      if (item == root->item) {
        RBTree *temp = redBlackTreeFindMin(root->right);
        root->item = temp->item;
        root->right = redBlackTreeRemoveMin(root->right);
      } 
      
      else {
        root->right = redBlackTreeRemoveNode(item, root->right);
      }
    }

    if (root == NULL) {
      root->color = BLACK;
    }

    root = redBlackTreeBalance(root);

    root->status = true;
    return root;
  } else {
    root->status = false;
    return root;
  }
}


RBTree
*redBlackTreeRemoveMin (RBTree *root) {
  if (root->left == NULL) {
    free(root);
    return NULL;
  }

  if (redBlackTreeColor(root->left) == BLACK && \
      redBlackTreeColor(root->left->left) == BLACK) {
    root = redBlackTreeMoveRedNodeLeft(root);
  }

  root->left = redBlackTreeRemoveMin(root->left);
  return redBlackTreeBalance(root);
}


RBTree
*redBlackTreeSearch (int item, RBTree *root) {
  if (root == NULL || root->item == item) {
    return root;
  } if (root->item > item) {
    return redBlackTreeSearch(item, root->left);
  } else {
    return redBlackTreeSearch(item, root->right);
  }
}


RBTree
*redBlackTreeFindMin (RBTree *root) {
  RBTree *temp1 = root;
  RBTree *temp2 = root->left;

  while (temp2 != NULL) {
    temp1 = temp2;
    temp2 = temp2->left;
  }

  return temp1;
}


bool
redBlackTreeStatus (RBTree *root) {
  return root->status;
}


int 
redBlackTreeTotalNodes(RBTree *root) {
  if (root == NULL) {
    return 0;
  } else  {
    return redBlackTreeTotalNodes(root->left) + \
    redBlackTreeTotalNodes(root->right) + 1;
  }
}


int 
redBlackTreeHeight (RBTree *root) {
  if (root == NULL) {
    return -1;
  }

  int hSTL = redBlackTreeHeight(root->left);
  int hSTR = redBlackTreeHeight(root->right);

  if (hSTL > hSTR) {
    return hSTL + 1;
  } else {
    return hSTR + 1;
  }
}


int 
redBlackTreeTotalLeafs (RBTree *root) {
  if (root == NULL) {
    return 0;
  } else if (root->left == NULL && root->right == NULL) { 
    return 1; 
  }

  return redBlackTreeTotalLeafs(root->left) + \
  redBlackTreeTotalLeafs(root->right);
}


bool 
redBlackTreeIsEmpty (RBTree *root) {
  return (root == NULL);
}


void 
redBlackTreeDestroy (RBTree *root) {
  if (root) {
    redBlackTreeDestroy(root->left);
    redBlackTreeDestroy(root->right);
    free(root);
    root = NULL;
  }
}