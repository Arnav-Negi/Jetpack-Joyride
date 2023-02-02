# Mario In Space (Jetpack Joyride)

This is the submission for Computer Graphics assignment - 1.

- Name :   Arnav Negi
- Roll : 2021101112

## Requirements

The game uses `GLAD, GLFW and GLM` libraries which are included in the folder.

The `Freetype library` is required to be installed to run the game.

## How to Build

Go to the assignment folder named `ass1` and run the following command:

```console
~$ mkdir build; cd build
~$ sudo cmake ..
~$ sudo make
~$ ./app
```

This should run the game.

## Instructions to play

The game consists of 3 levels, press any button to thrust Mario. The game ends when you win 
or collide with a zapper (lose). Your score is number of coins you collect.

## Notes

Levels increase in difficulty due to increase in `obstacle velocity, zapper length and level length`
