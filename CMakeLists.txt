cmake_minimum_required(VERSION 3.13)
project(poker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")
set(GAME_SRC ${PROJECT_SOURCE_DIR}/game)

add_subdirectory( ${GAME_SRC} )

add_executable( main main.cpp )
target_link_libraries(main game)
target_link_libraries(main simulator)