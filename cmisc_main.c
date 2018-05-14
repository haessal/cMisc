#include "cmisc_main.h"

int cmisc_main(int argc, const char **argv)
{
	int ret = 0;
	if (argc == 3) {
		ret = argc;
	} else {
		ret = 1;
	}
	return ret;
}
