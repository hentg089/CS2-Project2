# Created by markh on 2/9/2023 5814125.

cmake_minimum_required(VERSION 3.24)
project(project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project2 main.cpp BagWithReceiptsInterface.h ArrayBagWithReceipts.cpp BagWithReceiptsInterface.h)
