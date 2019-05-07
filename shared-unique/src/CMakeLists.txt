#
# Creator 2019-05-07
#

set(SharedUnique_SOURCES)
LIST(APPEND SharedUnique_SOURCES SharedUnique.cpp)

add_executable(SharedUnique ${SharedUnique_SOURCES})
add_executable(Helloworld HelloWorld.cpp)

target_include_directories(SharedUnique PUBLIC 
	"${CMAKE_SOURCE_DIR}/common/include"
	"${SharedUnique_SOURCES_DIR}/include")

target_link_libraries(SharedUnique )

# Install all bins
LIST(APPEND BINS SharedUnique)
LIST(APPEND BINS Helloworld)

#cxx_install_bin()
cxx_install_multiple_bin("${BINS}")
