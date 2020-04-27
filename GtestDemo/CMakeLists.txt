#
# Creator 2019-05-07
#
project(GtestDemo LANGUAGES CXX)

if (GTEST_ENABLE)
#	add_subdirectory(src)
	add_subdirectory(test)
endif()
