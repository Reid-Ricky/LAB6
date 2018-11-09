cmake_minimum_required(VERSION 3.12)
project(LAB6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LAB6
        card.cpp
        card.h
        card_demo.cpp
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
