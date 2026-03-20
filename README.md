# Matrix Transform Toy/Visualizer

This is a mixed FLTK/SDL program that lets one play with matrix transforms and
see how such mathematical operations affect graphics.

You will need the following extra packages (along with whatever they depend on)
in WSL to build this. You can also install the Windows versions of the libraries
and try to build with MinGW, though I have not tested this myself. These should
be installed through your package manager so that dependencies are handled for
you.

- FLTK version 1.3.X; I build with 1.3.8, but the latest is 1.3.11
- SDL2; `sdl2-config` reports `2.30.0` when run with the argument `--version` on
my system

[CMake](https://cmake.org/download/) is required to build this software. If you
wish to use the supplied `build2` script, you will also need Bash.
