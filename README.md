# Embedded Systems Pac-Man

[The Pac-Man Dossier](https://www.gamasutra.com/view/feature/3938/the_pacman_dossier.php?print=1)

1980 Arcade style Pac-Man for TI-TM4C

![Pac-Man](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR2LtvSZQrzrpwTm1Vj9hFkszC5tDw4SJuj-ig0DP4JCYnLpVN7&s)

Tested on Ubuntu 16.04. Should work on most GNU/Linux/POSIX environments.

## Requirements

 - [ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)
 - [lm4tools](https://github.com/utzig/lm4tools)
 - [TI Stellaris TM4C123GXL dev board](http://www.ti.com/tool/EK-TM4C123GXL)
 - [Joystick](https://www.adafruit.com/product/512)
 - [LCD](https://www.adafruit.com/product/358)

Follow the instructions in the next section to install the required packages.

## Installing

1. Create a duplicate of this repository for you own local development by doing the following:
    ```
    $ git clone https://github.com/bumblebee96/pacman.git
    ```
2. In the root directory of your repo, run
    
    For OS X:
    ```
    $ bash setup-osx.sh
    ```
    For Linux:
    ```
    $ bash setup-linux.sh
    ```
    to install all dependencies.
3. If prompted to override rwxr-xr-x  root/admin for /usr/local/bin/lm4flash, enter y and press enter.

## Run Test Project

Hook up an unlocked TM4C via USB on the debug port (top).
Move to the TestProject directory then build the project and flash by running:
```
$ cd TestProject
$ make flash
```
If all goes correctly, the blue LED should come on and you're up and running!

## Uploading Pacman Project

Once you've run the Test Project and confirmed that the compile toolchain is working
move to the src directory then build the project and flash it by running:
```
$ cd ..
$ cd src
$ make flash
```

## Setting up Hardware

![Breadboard Image](https://github.com/bumblebee96/pacman/blob/master/KeilProject/Resources/pacman_breadboard_bb.png)
[Hardware Ports](https://github.com/bumblebee96/pacman/blob/master/KeilProject/Resources/hardware_ports.md)

## Play

![menu](https://github.com/bumblebee96/pacman/blob/master/KeilProject/Resources/start_menu.png)

At the main menu, press the button to start a new game.

![new game](https://github.com/bumblebee96/pacman/blob/master/KeilProject/Resources/new_game.bmp)

Move the joystick when you are ready to start.

## Acknowledgments

* Thanks to Josh Minor and Sean Kirmani for creating the [linux command line tool](https://github.com/jishminor/ee445l-linux)
* This [article](https://www.gamasutra.com/view/feature/3938/the_pacman_dossier.php?print=1) has a lot of interesting information about the inner workings of the game
