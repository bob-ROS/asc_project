cmake_minimum_required(VERSION 2.8.3)
project(asc_startup)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs genmsg)

## Declare a catkin package
catkin_package()


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(wakeup src/wakeup.cpp)
target_link_libraries(wakeup ${catkin_LIBRARIES})
##add_dependencies(wakeup ${catkin_EXPORTED_TARGETS})
