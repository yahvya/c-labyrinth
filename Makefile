#initialise le projet
init:
	mkdir build
	cd build && cmake .. -G "MinGW Makefiles"

# build du projet
build:
	cd build && cmake .. && make

# lancement du projet
launch: build
	./build/game

.PHONY: init build
