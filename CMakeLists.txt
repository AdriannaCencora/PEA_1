cmake_minimum_required(VERSION 3.10)
project(PEA_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PEA_1 main.cpp MatrixGraph.cpp MatrixGraph.h FileHandler.cpp FileHandler.h BruteForce.cpp BruteForce.h BranchAndBound.cpp BranchAndBound.h DynamicProgramming.cpp DynamicProgramming.h Application.cpp Application.h Algorithm.h)