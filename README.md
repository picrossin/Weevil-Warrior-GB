# Weevil Warrior
This project was created for Cornhacks 2022, the theme being *retro*. To go with this theme, we wanted to make a game for the original gameboy that we could flash onto an actual gameboy cartridge and play handheld, not just emulated. 

## Story
You play as Herbie Husker - traverse your way through the grain silo infested by peskie Weevils! You are attempting to reclaim the corn that the pests have been filching - you can find one special corn in each level! Play through 6 different zones of the grain silo as you work to escape the creatures and reclaim your precious corn

## ZGB
This project utilizes ZGB, which is described as a Game Boy / Game Boy Color engine that lets you write your own games in C or asm. It is built on top of GBDK, a popular Gameboy development kit. We chose the ZGB engine because of the flexibility it provided in development, and the compiling into assembly from C code which we are more familiar with.

### Resources Utilized
This project relied heavily upon the [ZGB wiki page](https://github.com/Zal0/ZGB/wiki/Game-Boy-Color), Zalo's (the primary developer of ZGB) [GitHub page](https://github.com/Zal0), specifically using the[ Pretty Princess Castle Escape](https://github.com/Zal0/Pretty-Princess-Castle-Escape) to figure out scenes and maps in zgb

### Directories

#### bin/
contains the main gameboy rom

#### include\
contains the main ZGB '.h' file

#### res\
contains the resources of the game, being the properly formatted sound files, map files, tile sheets, and sprite sheets.

#### src\
contains all of the C source files, where we do most of the coding for our game

## Judging Criteria Explanations

### Problem Solved
The problem that this project seeks to solve is the lack of continued support and development of Gameboy games. Gameboys are the third best selling video game console of all time. There is still a market for Gameboy games out there, and we are attempting to fill a need where we see fit.

Another problem we are attempting to solve is that ZGB specifically is underdeveloped and inadequately documented. By creating a game using this open source library, we are able to contribute to finding bugs and increasing support for the tool. 

### Innovation and Creativity
This project required innovation in that we can apply modern game design sensibilities to hardware that is over twenty years old. These sensibilities might include not making games extremely difficult, not basing games off of pre-existing arcade cabinets, and applying more fun platformer movement options than many old gameboy games. This project required creativity as we wanted to fit the *retro* theme of Cornhacks. In order to do this, we had to learn how to develop these Gameboy games with the C language, which we are somewhat unfamiliar with (at least when compared to something like C#)

### difficulty of implementation under time constraint
There were a few key areas that were very difficult to implement under the time constraint. Perfecting the music was difficult as we only had a limited number of channels to utilize, and only a limited number of sounds that the gameboy is capable of making. Gameboy games only have so much memory, which is then divided between rendering game components and playing the music. We had to perform a balancing act between fun gameplay, good music, and good performance. Doing all of these within the allotted time was extremely tricky, but in the end we perservered. 

### solution completeness
The solution is complete in that we accomplished our vision for what the game would be - a platformer with a few levels, a start screen and end screen, and many hijinks in between. 

### solution quality
We believe that this solution is high quality as we pushed against the limitations of the old-school hardware to make a fun game. Our goal was to make a game that would be fun if it were made with any other modern game engine. We believe that we met this goal, meaning that we have a high quality solution for the problems mentioned above.

### software engineering
Several software engineering practices were followed during development. The developers would commit code frequently, communicating with each other about what was being done where. DRY violations were avoided whenever possible - but there are some limitations with the gameboy hardware that prevent us from getting by without having some repetition

### project presentation
The project presentation will involved explaining the above as we let the judges just get their hands on the game and have fun playing it.