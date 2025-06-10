# STM32MPU135F LVGL Hello world programm via SDL2

This is a simple hello world project for using LVGL on the STM32MPU135F with Yocto and SDL2.  
  
This program has a button that changes its text when pressed.
it also includes a sub screen with a dot that moves back and forth on an arc, a message box, a bar that fills if you press the test button, and a button to exit the programm.

# Compiling

This is meant to work with Yocto, and it has a Yocto Recipe, you should not worry about compiling it manually.
Consult the Yocto Documentation if you want to know how to add a recipe.

# The recipe file

This repo includes a `.bb` file, this is a copy of the file that is one directory above this one, which is not tracked by git. The bb file is intended to me a directory above the git directory, so if you clone this, be sure to copy the bb file to the right place.
