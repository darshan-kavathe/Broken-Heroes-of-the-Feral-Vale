cmake_minimum_required(VERSION 3.9)
project(BrokenHeroes)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic -g")

set(BROKEN_HEROES_SOURCE_FILES
        src/main.cpp
        src/game/battle.cpp
        src/game/squad.cpp
        src/hero/fighter.cpp
        src/hero/healer.cpp
        src/hero/hero.cpp
        src/hero/heroes.cpp
        src/hero/role.cpp
        src/hero/tank.cpp
        src/hero/team.cpp
        src/util/queue.cpp
        src/util/random.cpp)

set(TEST_SQUAD_SOURCE_FILES
        src/test_queue.cpp
        src/game/squad.cpp
        src/hero/fighter.cpp
        src/hero/healer.cpp
        src/hero/hero.cpp
        src/hero/heroes.cpp
        src/hero/role.cpp
        src/hero/tank.cpp
        src/hero/team.cpp
        src/util/queue.cpp
        src/util/random.cpp)

add_executable(BrokenHeroes ${BROKEN_HEROES_SOURCE_FILES})

add_executable(TestSquad ${TEST_SQUAD_SOURCE_FILES})
