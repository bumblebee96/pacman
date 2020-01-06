# pacman

A complete repository for writing, compiling and flashing code for the TI Stellaris, along with a sample project. Based on a completely open-source toolchain, without the need to rely on cumbersome development environments.

![TM4C123GXL](https://github.com/jishminor/ee445l-linux/blob/master/TivaWare/.metadata/images/TivaWare.png)

Tested on OS X and Ubuntu 16.04. Should work on most GNU/Linux/POSIX environments.

## Requirements

 - [ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)
 - [lm4tools](https://github.com/utzig/lm4tools)
 - [TI Stellaris TM4C123GXL dev board](http://www.ti.com/tool/EK-TM4C123GXL)
 - Joystick
 - LCD

Follow the instructions in the next section to install the required packages.

## Installing

1. Create a duplicate of this repository for you own local development by doing the following:
    1. Create a bare clone of the repository:
        ```
        $ git clone https://github.com/jishminor/pacman.git
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

## Setting up Hardware

| LCD Pin       | TM4C Port     |
|:-------------:|:-------------:|
| 1 GND | GND |
| 2 VCC | 3.3V |
| 3 RESET | PA7 |
| 4 D/C | PA6 |
| 5 CARD_CS | n/a |
| 6 TFT_CS | PA3 |
| 7 MOSI | PA5 |
| 8 SCK | PA2 |
| 9 MISO | n/a |
| 10 Backlight | 3.3V |


| Joystick Pin       | TM4C Port     |
|:-------------:|:-------------:|
| GND | GND |
| 5V | 5V |
| VRx | PE1 |
| VRy | PE2 |
| SW | PE0 |

## Setting up Software

Hook up an unlocked TM4C via USB on the debug port (top).
Move to the src directory then build the project and flash by running:
```
$ cd src
$ make flash
```
If all goes correctly, the start menu should load!

## Usage
To build project in current directory:
```
$ make
```

To flash the TM4C:
    
For OS X:
    ```
    $ make flash
    ```
    
For Linux:
    ```
    $ sudo make flash
    ```

To clean up the directory:
```
$ make clean
```

## Authors

* **Josh Minor** - [jishminor](https://github.com/jishminor)
* **Sean Kirmani** - [kirmani](https://github.com/kirmani)

## Acknowledgments

* Thanks to Christian Jann for his tutorial https://www.jann.cc/2012/12/11/getting_started_with_the_ti_stellaris_launchpad_on_linux.html
