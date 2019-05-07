#
# Creator 2019-05-07
#

add_executable(SharedUniqueTEST SharedUnique.cpp)

target_include_directories(SharedUniqueTEST PUBLIC
	"${CMAKE_SOURCE_DIR}/common/include" 
	"${GTEST_INCLUDE_DIR}")

target_link_libraries(SharedUniqueTEST gtest_main gtest pthread)

cxx_install_multiple_bin(SharedUniqueTEST)
