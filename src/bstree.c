#include "dslib.h"

BSTree 
*binarySearchTreeCreate () {
  BSTree *node = NULL;
  return node;
}


BSTree 
*binarySearchTreeCreateNode (int item) {
  BSTree *node = mallocSafe (sizeof(BSTree));
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
*binarySearchTreeRemoveNode (int item, BSTree *root) {
  BSTree *father = NULL;
  BSTree *temp   = root;

  while (temp != NULL && temp->item != item) {
    father = temp;
    if (temp->item > item) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if (temp == NULL) {
    return NULL;
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


bool 
binarySearchTreeIsEmpty (BSTree *root) {
  return (root == NULL);
}


int 
binarySearchTreeItem (BSTree *root) {
  return root->item;
}


bool 
binarySearchTreeItemExists (int item, BSTree *root) {
  if (root == NULL) {
    return false;
  } if(root->item == item) {
    return true;
  } else if (binarySearchTreeItemExists(item, root->left)) {
    return true;
  } else {
    return binarySearchTreeItemExists(item, root->right);
  }
}


BSTree 
*binarySearchTreeSearch (int item, BSTree *root) {
  if (root == NULL || root->item == item) { 
    return root; 
  }

  if (root->item > item) {
    return binarySearchTreeSearch(item, root->left);
  } else {
    return binarySearchTreeSearch(item, root->right);
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
  } else if (abs((int) binarySearchTreeHeight(root->left) - \
    (int)binarySearchTreeHeight(root->right)) > 1) {
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