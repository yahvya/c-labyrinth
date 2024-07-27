#initialise le projet
init:
	mkdir build
	cd build && cmake .. -G "MinGW Makefiles"

# build du projet
build:
	cd build && cmake .. && make && clear

# lancement du projet
launch: build
	cd build && ./game

.PHONY: init build
