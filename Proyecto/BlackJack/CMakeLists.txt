cmake_minimum_required(VERSION 3.29)
project(BlackJack)

set(CMAKE_CXX_STANDARD 26)

add_executable(BlackJack card.cpp
        Main.cpp
        WINNER.h
        player.cpp
        deck.cpp
        DECK.h
        blackjack.cpp
        ENUMS.h
        CARD.h)
