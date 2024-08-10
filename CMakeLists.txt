cmake_minimum_required(VERSION 3.13)
project(poker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(APP_SRC ${PROJECT_SOURCE_DIR}/app)
set(GAME_SRC ${PROJECT_SOURCE_DIR}/game)

add_subdirectory( ${APP_SRC} )
add_subdirectory( ${GAME_SRC} )

add_executable( main 
    main.cpp
)

target_link_libraries(main game)
target_link_libraries(main simulator)

target_link_libraries(main app)