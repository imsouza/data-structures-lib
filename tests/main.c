#include <stdio.h>
#include <stdlib.h>
#include "../ds-lib.h"

int main () {
	Stack S = stack(2);
	stackPush(1, S);
	printf("%i\n", stackSize(S));
	displayStack(S);
	displayReverseStack(S);
	return 0;
}