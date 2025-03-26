# Learn C++ by Example – Code

This repository contains code I’ve written while working through [*Learn C++ by Example*](https://www.manning.com/books/learn-c-plus-plus-by-example) by Frances Buontempo.

The goal of this repo is to document my learning journey as I explore modern C++ through practical examples. Each directory or file corresponds to a specific chapter, section, or concept covered in the book.

## Build
Meson is used as the build system. Navigate to the desired project directory and run the following commands to configure Meson and compile the project.
```console
$ meson setup build
$ meson compile -C ./build
```
You can find the resulting executable file in the build directory.