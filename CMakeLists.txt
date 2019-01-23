cmake_minimum_required(VERSION 3.13)
project(Stack_Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stack_Calculator main.cpp Data.hpp Instruction.hpp Program.hpp StackMachine.hpp)