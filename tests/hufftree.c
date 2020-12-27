#include <stdio.h>
#include <stdlib.h>
#include "../src/ds-lib.h"

int main () {
  printf("Hufftree ------------------\n");

  printf(">>> DISPLAY + CREATE:\n");
  displayHufftree(createHufftree("WORD"));
  putchar('\n');

  printf(">>> DISPLAY LEAVES + CREATE:\n");
  displayLeaves(createHufftree("DRIVE"));
  putchar('\n');

  printf(">>> COMPRESS + CREATE:\n");
  char *string = "TEST";
  compressString(string, createHufftree(string));

  putchar('\n');

  printf(">>> DECOMPRESS + CREATE:\n");
  decompressString("010110", createHufftree(string));
  putchar('\n');

  return 0;
}