# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required(VERSION 3.26)
project(Lab-3-Engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab-3-Engine main.cpp
        Engine.cpp
        Engine.h
        Subject.cpp
        Subject.h
        Wrapper.cpp
        Wrapper.h
)

