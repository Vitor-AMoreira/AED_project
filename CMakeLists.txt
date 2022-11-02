cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Class.cpp ReadClasses.cpp ReadStudent.cpp Student.cpp StudentsTree.cpp Animal.cpp)
