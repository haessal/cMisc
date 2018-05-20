#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdlib.h>

extern "C"
{
#include "../main.h"
}

TEST(cmisc_main, no_parameters)
{
	int argc = 1;
	const char* argv[1] = {"cmisc"};
	int status;

	status = cmisc_main(argc, argv);
	ASSERT_EQ(EXIT_FAILURE, status);
}

TEST(cmisc_main, unsupported_subcommand)
{
	int argc = 2;
	const char* argv[2] = {"cmisc", "unsupported"};
	int status;

	status = cmisc_main(argc, argv);
	ASSERT_EQ(EXIT_FAILURE, status);
}
