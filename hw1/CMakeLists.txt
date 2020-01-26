cmake_minimum_required(VERSION 3.15)
project(2303HW1 C)

set(CMAKE_C_STANDARD 99)

add_executable(2303HW1 src/tests.c src/HW1.c src/production.c src/TMSName.h src/TimothyGoon.h src/PatrickHoulihan.h src/Search.h src/House.h src/Layout.h src/Room.h src/Search.c src/House.c src/Layout.c src/Room.c)
add_executable(Starter src/2020HW1starter.c)