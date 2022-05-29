cmake_minimum_required(VERSION 3.20)
project(Flottenkampf)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flottenkampf main.cpp Dice/Dice.cpp Dice/Dice.h Ships/Jaeger.cpp Ships/Jaeger.h Ships/Zerstoerer.cpp Ships/Zerstoerer.h Schiff.cpp Schiff.h Ships/Kreuzer.cpp Ships/Kreuzer.h Flotte.cpp Flotte.h Game/Game.cpp Game/Game.h Field.cpp Field.h)
