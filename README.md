# Jeux de labyrinthe

> Mini jeux de labyrinthe 2D

## Technologies

- C
- CMake 3.30.1
- Raylib

## Assets

[Lien des assets](https://devilsworkshop.itch.io/low-poly-2d-arcade-maze-based-game-assets)

## Lancement du projet

> **Utilisez les commandes du fichier Makefile**

## Configuration

> Les ids d'association sont au possible, des entiers ordonnées à intervalle de 1, partant de 1 à X

### Type d'assets:

    - 1 : Image fixe
    - 2 : Liste d'images pour animation continu
    - 3 : Liste d'images pour animation suite à une action

### Personnage

#### Positions possibles

- back-walk (marche vers le haut)
- front-walk (marche vers le bas)
- left-walk (marche vers la gauche)
- right-walk (marche vers la droite)

#### Animations possibles

- back-animation (animation de dos)
- front-animation(animation de face)
- left-animation(animation de profil vers la gauche)
- right-animation(animation de profil vers la droite)
- death-animation (animation de tombe)
