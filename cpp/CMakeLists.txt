cmake_minimum_required(VERSION 3.15)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp
        main.cpp
        constants.h
        constants.cpp
        models.h
        models.cpp
        checker.h
        checker.cpp
        util.h
        util.cpp
        annealing.h
        annealing_simulator.h
        solution.h
        solution.cpp solver.cpp solver.h)
