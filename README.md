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
The only difficulty that i faced, is how to keep track of the last `element` of the snake.

Cause we need to cover the last element each time the snake moves forward.

### How i solved that one
I basically let the linked list magic do the job.

I created a double one (linked list), so i can go forward and backward.

Every node represents the position of a snake element, the coordinates of where that element is in the map.

So the head of the snake is the head of the list, and the tail of snake is the tail of the list.

And each time the snake moves ahead, a new node get created and added to the front of the list, and the last element of the list gets deleted, after we cover it on the map of course. (easy)...