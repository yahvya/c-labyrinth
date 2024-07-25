cmake_minimum_required(VERSION 3.30.1)

project(c_labyrinth
    DESCRIPTION "Mini jeux 2D de labyrinthe"
    VERSION "24.07.24"
)

add_compile_options(-UNDEBUG)

add_subdirectory("libs/libyaml")

add_executable(game 
    src/game.c
    src/assets-manager/assets.h
    src/assets-manager/config-manager/config-manager.c
    src/assets-manager/config-manager/config-manager.h
    src/assets-manager/config-manager/tills-manager.c
    src/assets-manager/config-manager/tills-manager.h
    src/assets-manager/config-manager/image-config-manager.c
    src/assets-manager/config-manager/image-config-manager.h
    src/utils/generic-list/generic-list.c
    src/utils/generic-list/generic-list.h
)

target_link_libraries(game yaml)

add_custom_command(
    TARGET game PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/resources"
    "${CMAKE_BINARY_DIR}/resources"
)
