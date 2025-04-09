# C labyrinth

> C labyrinth game in old style

## Important informations

**Licence** : Licene MIT
**Creation date** : 24.07.2024

## Team

- Bathily Yahaya : Developer

## GitHub Structure

### Branch

- master (complete versions) - PROTECTED BY PULL REQUEST
- dev (developed features) - PROTECTED BY PULL REQUEST
- documentation (developed documentation) - PROTECTED BY PULL REQUEST
- features/<branch_name>/<feature_name>

### Folder structure

- dev (application code)
- documentation (documentation elements)
- versions (application versions)
- devtools (custom development tools)
- .github/workflows (github action configs)

### GitHub Flow

- main : the main branch merge elements from (dev, documentation)
- (dev, documentation) : these branches merge elements from feature branches
- features/<branch_name>/<feature_name> : features branches are created from the <branch_name> branch

### Commit norm

Each commit line is prefixed by :

ADD : for new code
FIX : for changes due to a problem
MODIFY : for changes
DELETE : for deletion

## Prerequisites

- Git
- Make
- C
- CMake 3.30.1
- Raylib

## Technologies

- GitHub : Code version manager
- Make : Quick commands for utilities
- Docker

## Quick launch process

### For the project

- Launch the makefile command "project-print-init"

### For the game

- Use the makefile commands or cmake config in your ide

## Util links 

- [GitHub Project](https://github.com/users/yahvya/projects/16)

## Assets

[Lien des assets](https://devilsworkshop.itch.io/low-poly-2d-arcade-maze-based-game-assets)

## Game configuration

> Association IDs should ideally be integers ordered at intervals of 1, starting from 1 to X

### Type of assets:

    - 1 : Static image
    - 2 : Image sequence for continuous animation
    - 3 : Image sequence for animation triggered by an action

### Character

#### Possible positions

- back-walk (walking upward)
- front-walk (walking downward)
- left-walk (walking to the left)
- right-walk (walking to the right)

#### Possible animations

- back-animation (back view animation)
- front-animation (front view animation)
- left-animation (left profile animation)
- right-animation (right profile animation)
- death-animation (falling/death animation)
