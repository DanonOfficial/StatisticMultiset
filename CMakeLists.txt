cmake_minimum_required(VERSION 3.8)
project(Updated_Multiset)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp StaticsticMultiset.hpp StatisticMultiset.h exceptions/NoFileError.h exceptions/WrongAppend.h)
add_executable(Updated_Multiset ${SOURCE_FILES})