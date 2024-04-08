cmake_minimum_required(VERSION 3.1)

project(window)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB ${PROJECT_NAME}_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
file(RELATIVE_PATH ${PROJECT_NAME}_sources ${CMAKE_CURRENT_SOURCE_DIR} ${${PROJECT_NAME}_sources})
message(" lol ${CMAKE_CURRENT_SOURCE_DIR}")
message(" lol ${${PROJECT_NAME}_sources}")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_sources})

target_link_libraries(${PROJECT_NAME} glfw OpenGL)
