cmake_minimum_required(VERSION 3.14)
project(dataStructAndArgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(dataStructAndArgorithm main.cpp)
add_executable(DuLinkList struct/list/DuLinkList.cpp)
add_executable(staticLinkedList struct/list/staticLinkedList.cpp)
add_executable(cLinkedList struct/list/cLinkedList.cpp)
add_executable(linkedList struct/list/linkedList.cpp)
add_executable(polynomial struct/list/argorithm/polynomial.cpp)