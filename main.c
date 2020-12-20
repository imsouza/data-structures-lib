#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
	Stack S = stack(2);
	push(1, S);
	push(2, S);
	push(3, S);
	printf("%i\n", access(S));
	return 0;
}