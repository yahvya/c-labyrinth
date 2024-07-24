cmake_minimum_required(VERSION 3.30.1)

project(c_labyrinth
    DESCRIPTION "Mini jeux 2D de labyrinthe"
    VERSION "24.07.24"
)

add_executable(game 
    src/game.c
)
