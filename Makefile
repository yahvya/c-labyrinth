#initialise le projet
init:
	mkdir -p build
	cd build && cmake .. -G "MinGW Makefiles"

# initialise le projet sous unix
init-unix:
	mkdir -p build
	cd build && cmake ..

# build du projet
build:
	cd build && cmake ..

# lancement du projet
launch:
	cd build && make -j && clear && drmemory -show_reachable -- ./game

# lancement le projet sous unix avec valgrind
launch-unix:
	cd build && make -j && clear && valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./game

.PHONY: init build
