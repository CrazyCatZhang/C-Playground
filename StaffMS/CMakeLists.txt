cmake_minimum_required(VERSION 3.16)
project(StaffMS)

set(CMAKE_CXX_STANDARD 20)

add_executable(StaffMS main.cpp Header/WorkerManagement.h Source/WorkerManagement.cpp Header/Worker.h Header/Employee.h Source/Employee.cpp Header/Manager.h Source/Manager.cpp Header/Boss.h Source/Boss.cpp)