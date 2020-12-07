# Not windows paint

This program was written using openglut in c++.

This was created as a mini project for college, do not judge.

## Running:


#### Windows:

Simply run the `GL_Paint.exe` executable.


#### Linux:

Run the GL_Paint binary.

If it doesn't run, go to the file in your file manager, right click on the file, click on permissions and check the "Allow execution..." checkbox.

Alternatively, in the terminal, go to the directory containing the file and type this command:

``` sh
chmod +x GL_Paint
```

## Usage:

To draw, click the left mouse button and move the mouse, release to stop drawing.

Multiple brush shapes are accessible with right click menu.

The current brush color is displayed on the left side.

Keyboard shortcuts ( more like the only option ):

- **x** to clear the screen.
- **+** to increase the brush size.
- **-** to decrease the brush size.
- **h** toggle making the bush shape hollow or filled ( not useful if intend to draw strokes with that brush ).
- **s** save the image as screenshot.jpg.
- **0-6** move between different color presets.
- **r** increase the red value in the color.
- **R** decrease the red value in the color.
- **g** increase the green value in the color.
- **G** decrease the green value in the color.
- **b** increase the blue value in the color.
- **B** decrease the blue value in the color.

## Development:

### Dependencies:

- GCC compiler
- FreeGlut
- FreeImage ( Required for saving the image )

### Compiling:

#### Linux:

First get the repository, either download it as zip from github and extract it or git clone it:

``` sh
git clone https://github.com/Purgeme/GL_Paint 
```

Then go to the project directory and compile it with g++:

``` sh
g++ -o GL_Paint *.cpp -lglut -lGL -lGLU -lfreeimage
```

The GL_Paint file is the compiled program binary.

#### Windows:

Open the project in Visual Studio or your preferred program, make sure you add the dependecies in the program and compile.

