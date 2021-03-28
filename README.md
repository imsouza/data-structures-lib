# Data Structures Lib

[![License](https://img.shields.io/badge/license-MIT-blue)](./license) [![Docs](https://img.shields.io/badge/docs-complete-green)](https://github.com/imsouza/data-structures-lib) [![time tracker](https://wakatime.com/badge/github/imsouza/data-structures-lib.svg)](https://wakatime.com/badge/github/imsouza/data-structures-lib)

A library of data structures for academic purposes

## Features

- Efficient 
- Flexible
- Open source

## Usage

```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  ...
}
```

#### Demonstrations

- Binary Search Tree
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  BSTree *root = NULL;
  BSTree *searched;
  BSTree *max;
  BSTree *min;

  insertNode(9, &root);
  insertNode(2, &root);
  insertNode(3, &root);
  insertNode(15, &root);
  insertNode(4, &root);
  insertNode(1, &root);
  insertNode(3, &root);
  insertNode(7, &root);
  insertNode(8, &root);

  displayPreOrder(root);
  displayInOrder(root);
  displayPostOrder(root);
  
  printf("%i\n", search(545, &root));

  printf("%i\n", getRoot(root));

  max = findMax(root);
  printf("%i\n", getNode(max));

  min = findMin(root);
  printf("%i\n", getNode(min));

  printf("%i\n", treeIsEmpty(root));

  deleteTree(root);

  return 0;
}
```

- Hufftree
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  Hufftree H1 = createHufftree("WORD");
  displayHufftree(H1);
  putchar('\n');

  Hufftree H2 = createHufftree("DRIVE");
  displayLeaves(H2);
  putchar('\n');

  char *string = "TEST";
  Hufftree H3 = createHufftree(string);
  compressString(string, H3);

  putchar('\n');

  Hufftree H4 = createHufftree(string);
  decompressString("010110", H4);
  putchar('\n');

  deleteHufftree(H1);
  deleteHufftree(H2);
  deleteHufftree(H3);
  deleteHufftree(H4);
}
```

- Linked List
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  List A = \
  createNodeList(3, \
  createNodeList(1, \
  createNodeList(5, NULL)));

  printf("%i\n", getListSize(A));

  displayList(A);

  putchar('\n');

  displayReverseList(A);

  putchar('\n');

  printf("%i\n", listIsEmpty(A));

  printf("%i\n", getHead(A));


  List B = \
  createNodeList(2, \
  createNodeList(6, \
  createNodeList(5, \
  createNodeList(8, NULL))));

  //deleteList(&A);
  //deleteList(&B);

  List C = *concatList(&A, &B);
  displayList(C);

  putchar('\n');
  printf("%i\n", itemExists(10, C));

  List D = cloneList(C);

  deleteList(&C);

  displayList(D);
  deleteList(&D);
}
```

- Map
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  Map M = createMap(145, "Test Drive", NULL);

  displayMap(M);

  insertMap(122, "Test 2", &M);
  insertMap(4, "Test 3", &M);
  insertMap(3, "Test 4", &M);
  insertMap(99, "Test 5", &M);

  removeMap(4, &M);

  printf(">>> FIND KEY\n");
  if (keyExists(3, M)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  deleteMap(&M);

  return 0;
}
```

- Queue
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  Queue Q = createQueue(3);

  enqueue(1, Q);
  enqueue(5, Q);
  enqueue(7, Q);

  displayQueue(Q);

  printf("%i\n", getQueueSize(Q));

  dequeue(Q);

  deleteQueue(&Q);

  return 0;
}
```

- Stack
```
#include <stdio.h>
#include <stdlib.h>
#include "dslib.h"

int main () {
  Stack S = createStack(3);

  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  displayStack(S);

  printf("%i\n", getStackSize(S));

  stackPop(S);

  displayStack(S);

  printf("%i\n", getStackSize(S));
  
  deleteStack(&S);

  return 0;
}
``` 

## Test

```$ make && make run ```

Valgrind:

```$ make memcheck ```

## TODO

- Data Structures
  - [ ] Avl tree
  - [x] Binary search tree
  - [ ] Circular linked list
  - [ ] Graph
  - [ ] Hash table
  - [ ] Heap
  - [x] Huffman coding
  - [x] Linked list
  - [x] Map
  - [x] Queue
  - [ ] Set
  - [ ] Sorted linked list
  - [x] Stack

- Extra
  - [x] Configure preprocessor directives
  - [x] Successfully passed the tests
  - [x] Fix memory leaks

## Author

Mateus Almeida

## Contributing

Feel free to make pull requests for code improvements

## License

This project is licensed under the [MIT](https://github.com/imsouza/data-structures-lib/blob/main/LICENSE) License.
