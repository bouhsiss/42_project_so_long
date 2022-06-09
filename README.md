# 42_project_so_long
This project is a very small 2D game. using a tiny graphics 42 library which allows you to do most basic things for rendering something in screens without any knowledge of X-Window and Cocoa.
## why is this project useful ?
it makes you work with textures, sprites, and some other very basic gameplay, and it also helps get familiar with tiles, tilesets, sprite, and sprite sheets
and you'll improve your skills in : window management, create images and deal with keyboard and mouse events.

## Usage
clone the repo, execute ```make``` or (```make bonus``` to have an extra feature : enemy and movement counts displayed on the screen).<br/>
and then execute ./so_long or (so_long_bonus) followed by as a paramater a map description file ending with the .ber extension 
## the game
• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.<br/>
• The W, A, S, and D keys must be used to move the main character.<br/>
• The player should be able to move in these 4 directions: up, down, left, right.<br/>
• The player should not be able to move into walls.<br/>
• At every move, the current number of movements must be displayed in the shell.<br/>

## graphic management
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
## Map 
• The map has to be constructed with 3 components: walls, collectibles, and free
space.<br/>
• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.<br/>
• The map must contain at least 1 exit, 1 collectible, and 1 starting position.<br/>
• The map must be rectangular.<br/>
• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.<br/>
• the program must be able to parse any kind of map, as long as it respects the above rules.<br/>
