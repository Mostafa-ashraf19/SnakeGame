# SnakeGame

Snake Game builded using modern Cpp and SDL library, idea of game based on main basic games principle 
![idea](
https://github.com/Mostafa-ashraf19/SnakeGame/blob/master/Images/game-loop-simple.png?raw=true
)

## Game view 

![gameGif](
https://github.com/Mostafa-ashraf19/SnakeGame/blob/master/Images/game.gif?raw=true
)



## Class Diagram 
  UML class diagram
  ![diagram](
https://github.com/Mostafa-ashraf19/SnakeGame/blob/master/Images/Snake%20ClassDiagram.png?raw=true
)


## New Features
* Pause
  * Game can be **paused** by pressing `ESC` button and **resumed** by pressing `C` button.  

* There is a **wall** option available. 
  * can select mode of play from messagebox by select play **with/without** wall. 
  * If select wall and Snake touch wall will die. 

* add Modal box
  * When Snake die, a small dialog box appears and shows score and size informations also can select play agin. Console output is still available

* Play again
  * when Snake die you can play again without needed to rerun game another time or can terminate game. 

* Toxic Foods
  * There is a red toxic food.
  * when Snake eat it, the Snake speed decrease and  loss size.
  
* new feature  
  * will add background sound using threads.
  * soon.
 
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Deployment
  - Soon
