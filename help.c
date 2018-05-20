#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"

int cmd_help(int argc, const char **argv)
{
	int i;

	printf("[help]\n");
	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	return EXIT_SUCCESS;
}
