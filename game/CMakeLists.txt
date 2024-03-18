project(game)

add_subdirectory(simulator)
aux_source_directory(${GAME_SRC} GAME_FILES)
add_library(game OBJECT ${GAME_FILES})

target_link_libraries(game simulator)

# add_library(game OBJECT 
#     board.cpp
#     card.cpp
#     deck.cpp
#     display.cpp
#     hand.cpp
#     handtype.cpp
#     player.cpp
#     poker.cpp
# )