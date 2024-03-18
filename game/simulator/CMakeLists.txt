project(simulator)

aux_source_directory(. SIM_FILES)
add_library(simulator OBJECT ${SIM_FILES})

target_include_directories(simulator PUBLIC ${GAME_SRC}/simulator/include)
target_include_directories(simulator PUBLIC ${GAME_SRC}/include)