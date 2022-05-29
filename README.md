# Snake game

Fisrt of all this is just ```TTOOBYAA``` (because why not)

## About this snake game
It's not like other snake games, because it was developed by me that's first, and second i used ```C``` to builted it up.

Other than that it's just a simple snake running around eating, avoiding death and of course getting bigger and bigger.

## How i did it
First of all, i make 4 ```XPM``` files, each one of them was representing either a player, ground, collectable or wall.

at this point, we have everything to set our ```environment``` to the place. (i started by that).

### Player movement
The snake is just a bunch of blocks following each other, every time that snake eat something a block get added to the group.
block is just an image (10px/10).

The player will be moving by itself, you just need to give the direction it should follow (up, down, left or right).

It's easy, each time the player moves, i put an image infront of it and i cover it's old position. and that simulates the movement of a snake.  

If the snake is big, i basically i cover the last element of the snake.

### Collectables
They appear randomly on the map, each time the snake ate one a new one appears and so on so fort.

## Difficulties
