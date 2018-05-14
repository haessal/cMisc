#include "gtest/gtest.h"
#include "gmock/gmock.h"

extern "C"
{
#include "../main.h"
}

TEST(cmisc_main, no_parameters)
{
	int argc = 1;
	const char* argv[1] = {"cmisc"};
	int ret;

	ret = cmisc_main(argc, argv);
	ASSERT_EQ(0, ret);
}
