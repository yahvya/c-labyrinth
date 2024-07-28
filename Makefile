#initialise le projet
init:
	mkdir build
	cd build && cmake .. -G "MinGW Makefiles"

# initialise le projet sous unix
init-unix:
	mkdir build
	cd build && cmake ..

# build du projet
build:
	cd build && cmake .. && make && clear

# lancement du projet
launch: build
	cd build && ./game

# lancement le projet sous unix avec valgrind
launch-unix: build
	cd build && valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./game

.PHONY: init build
