cmake_minimum_required(VERSION 3.14)

project(AnimationGL3)

set(CMAKE_CXX_STANDARD 14)

find_package(OPENGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(BLAS REQUIRED)
find_package(ARMADILLO REQUIRED)

file(GLOB SRC Model/source/*.cpp)
file(GLOB HEAD Model/header/*.h)

list(APPEND SRC "main.cpp")

add_executable(${PROJECT_NAME} ${SRC} ${HEAD})

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS})

target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_LIBRARY}
        ${GLUT_LIBRARY}
        ${BLAS_LIBRARIES}
        ${ARMADILLO_LIBRARIES})
