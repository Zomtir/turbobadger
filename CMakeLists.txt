project(TurboBadger)
cmake_minimum_required(VERSION 2.8)

option(TB_BUILD_DEMO "Build the Demo application. Depends on glfw." ON)

if(CMAKE_COMPILER_IS_GNUCXX)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-exceptions -fno-rtti")
endif(CMAKE_COMPILER_IS_GNUCXX)

# Add glfw include path - Needed only for the demo and optional platform
# implementations using glfw. Not a requirement for tb itself.
include_directories("${PROJECT_SOURCE_DIR}/Demo/thirdparty/glfw/include")

# Add TurboBadgerLib project
include_directories("${PROJECT_SOURCE_DIR}/src/tb")
add_subdirectory(src/tb)

# Add Demo project
if(TB_BUILD_DEMO)
 add_subdirectory(Demo)
endif(TB_BUILD_DEMO)