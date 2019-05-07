#
# Creator 2019-05-07
#
project(SharedUnique LANGUAGES CXX)

add_subdirectory(src)

if (GTEST_ENABLE)
	add_subdirectory(test)
endif()
