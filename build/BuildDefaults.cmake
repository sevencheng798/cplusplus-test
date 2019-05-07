# Commmon build settings across all Cplusplus test modules.

# Append custom CMake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# Setup build options variables.
#include(BuildOption)

# Setup googletest variables.
include(Gtest)
