<h1 align="center">
  <br>
  <a href="https://github.com/TalMizrahii/FLY-HIGH-game"><img src="https://img.icons8.com/color/344/c-plus-plus-logo.png" alt="C++" width="200"></a>
  <br>
  FLY HIGH
  <br>
</h1>

<h4 align="center">Video game based on SFML, written in CPP.


<p align="center">
  <a href="#description">Description</a> •
  <a href="#implementation">Implementation</a> •
  <a href="#dependencies">Dependencies</a> •
  <a href="#installing-and-executing">Installing And Executing</a> •
  <a href="#authors">Author</a> 
</p>

## Description


The purpose of the game is to fly as high as you can. The bird is controlled by the LEFT and RIGHT or A and D keys on the keyboard. As long as you fly higher, the gap 
between the pipes and the space between each pair of pipes is getting smaller, what makes the game harder.



![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/103560553/195300341-0b058240-58d1-4a41-a815-4aa8aa4448b0.gif)



<img width="593" alt="Capture11" src="https://user-images.githubusercontent.com/103560553/188944212-21a34071-8445-4602-b05d-9bb5c23306b8.PNG">
<img width="597" alt="Capture" src="https://user-images.githubusercontent.com/103560553/188943934-b60a060d-07ec-42db-932c-9298d5236dde.PNG">


## Implementation

The program contains 3 main categories:

* CollisionRelated - Mooving objects who needs to be detected for collision.
* Gameability - Responsible for the game's control flow and GUI.
* SpriteRelated - Sprite objects displayd to the screen.

The development was OOP-driven, using concepts such as polymorphism, encapsulation, design patterns, etc.

## Dependencies

I used SFML version 2.5.1 using <SFML/Graphics.hpp> library. The pipes are created randomly (I used srand() from cstdlib.h and rand() from random.h). Further 
information about the design and code can be found in the documentation.

## Installing And Executing

To clone and run this application, you can use [Git](https://git-scm.com). From your command line:

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/FLY-HIGH-game

# Go into the repository.
$ cd FLY-HIGH-game

# Enter the release folder into the repository.
$ cd FlyHigh release

# Run the program
$ FlyHigh
```

## Author
* [@Tal Mizrahi](https://github.com/TalMizrahii)
* Taltalon1927@gmail.com



