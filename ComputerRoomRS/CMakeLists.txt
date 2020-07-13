cmake_minimum_required(VERSION 3.16)
project(ComputerRoomRS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputerRoomRS main.cpp Management/Management.cpp Management/Management.h Header/Identity.h Admin/Admin.cpp Admin/Admin.h Student/Student.cpp Student/Student.h Teacher/Teacher.cpp Teacher/Teacher.h Header/Global.h Header/ComputerRoom.h Header/Time.h Order/Order.cpp Order/Order.h)