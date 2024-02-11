# CMakeList.txt : CMake project for KDTree, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (KDTree  "main.cpp" 
				"include/KDTree.h" "KDTree.cpp" 
				"include/Point.h" 
				"include/Node.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET KDTree PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
