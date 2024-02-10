# CMakeList.txt : CMake project for QuadTree, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (QuadTree  "main.cpp" 
						"include/QuadTree.h" "QuadTree.cpp"
						"include/Point.h" 
						"include/Rectangle.h" "Rectangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QuadTree PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

