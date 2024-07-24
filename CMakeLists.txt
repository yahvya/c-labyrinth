cmake_minimum_required(VERSION 3.30.1)

project(c_labyrinth
    DESCRIPTION "Mini jeux 2D de labyrinthe"
    VERSION "24.07.24"
)

add_executable(game 
    src/game.c
    src/assets-manager/image-loader/image.h
    src/assets-manager/image-loader/image-loader.c
    src/assets-manager/image-loader/image-loader.h
    src/assets-manager/config-manager/config-manager.c
    src/assets-manager/config-manager/config-manager.h
    src/assets-manager/assets.h
)
