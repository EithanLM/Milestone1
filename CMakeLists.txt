cmake_minimum_required(VERSION 3.19)
project(ex1)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex1 main.cpp Data.cpp Data.h CSVtoData.cpp CSVtoData.h KNNClassifier.cpp
        KNNClassifier.h CSVPrinter.cpp CSVPrinter.h)