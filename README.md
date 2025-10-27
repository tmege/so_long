# so_long

## Description
Here is my take on the so_long project from 42 cursus. The aim of this project is to get an understanding of the school graphical library : the minilibx (usually called mlx).
This is a basic 2D game (can be either scroll or top-down, I went with top-down), with one character needing to retrieve all the collectibles available of the map before exiting the map. When the character exits, the game window is destroyed and the game ends. 

## How to play
Clone this repository, execute the makefile, execute the program with a map as argument.
You have several maps in the maps/ directory, some of them being error cases.
for instance, you could use:
./so_long maps/ex01.ber

## Usage
You can create your own maps if you like ! They are simple text files. For a map to be valid, it needs:
 - to have a .ber extension
 - to be rectangular (all lines have the same length)
 - to be fully enclosed with walls
 - to include 1 hero, 1 exit, and at least one collectible ; collectibles and exits must be reachable (i.e. not behind a wall)
 - to use the following characters : '1' for walls, '0' for floor, 'P' for the hero, 'E' for the exit, 'C' for the collectibles

## Bonus
The bonus part of this project include:
- ennemy patrol(s) that can kill on contact
- sprite animation
- counting steps within game window, and not just in terminal

However I did not implement the ennemies, for lack of time. Only the door is animated (even on basic version), I wish I had time to do more... maybe later on !

