#include "gtest/gtest.h"
#include "gmock/gmock.h"

extern "C"
{
#include "../cmisc_main.h"
}

TEST(cmisc_main, multiargs)
{
	int argc = 3;
	const char* argv[3] = {"cmisc", "aaa", "bbb"};
	int ret;

	ret = cmisc_main(argc, argv);
	ASSERT_EQ(3, ret);
}

TEST(cmisc_main, noargs)
{
	int argc = 0;
	const char* argv[1] = {0};
	int ret;

	ret = cmisc_main(argc, argv);
	ASSERT_EQ(0, ret);
}
