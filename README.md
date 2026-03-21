# Matrix Transform Toy/Visualizer

This is a mixed FLTK/SDL program that lets one play with matrix transforms and
see how such mathematical operations affect graphics.

You will need the following extra packages (along with whatever they depend on)
in WSL to build this. You can also install the Windows versions of the libraries
and try to build with MSYS2, though I have not tested this myself. These should
be installed through your package manager so that dependencies are handled for
you.

**NOTE:** the `+` markers indicated compatibility with later versions *in
the same family*. For FLTK this means using the older 1.3 line (latest version
is 1.3.11) instead of the more modern 1.4 release or 1.5 development lines. 
Similarly for SDL, this means that any version of SDL2 after 2.30 is supported
(the latest at time of writing is SDL 2.32.8).

- Fast Lightweight ToolKit, version 1.3.8+
- Simple DirectMedia Layer, version 2.30+

The following command will let you install all the necessary libraries and
development packages at once, provided your WSL instance is Ubuntu:
```sh
sudo apt install libfltk1.3t64 \
                 libfltk1.3-dev \
                 fluid \
                 libfltk-cairo1.3t64 \
                 libfltk-forms1.3t64 \
                 libfltk-gl1.3t64 \
                 libfltk-images1.3t64 \
                 libsdl2-2.0-0 \
                 libsdl2-dev \
                 libsdl2-image-2.0-0 \
                 libsdl2-image-dev \
                 libsdl2-mixer-2.0-0 \
                 libsdl2-net-2.0-0 \
                 libsdl2-ttf-2.0-0 \
                 libsdl2-ttf-dev
```

[CMake](https://cmake.org/download/) is required to build this software. If you
wish to use the supplied `build2` script, you will also need Bash.
