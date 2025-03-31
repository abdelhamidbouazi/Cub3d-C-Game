# Cub3D

**Cub3D** is a graphical project at **42/1337 School**, designed to introduce students to the basics of graphics rendering using raycasting techniques, inspired by the famous 1992 game **Wolfenstein 3D**. The goal of this project is to create a simplified 3D first-person exploration experience using pure C, without relying on complex external libraries or engines.

---

## Project Overview

The project involves creating a dynamic view of a 3D maze where the player can move around, rotate, and interact with the environment. It covers important concepts such as raycasting, trigonometry, textures rendering, basic game loop mechanics, and event handling using the MiniLibX library.

---

## Key Features

- **Raycasting Engine**: Implementation of a raycasting algorithm to create a 3D illusion from a 2D map.
- **Textures**: Use of texture mapping to render walls and environment surfaces realistically.
- **Player Movement**: Allow player navigation through the map with forward/backward movement and rotation.
- **MiniLibX Integration**: Utilize MiniLibX to handle graphics rendering and user input events.
- **Collision Detection**: Implement wall collision to prevent players from moving through solid surfaces.

---

## Requirements

- **Operating System**: Linux/MacOS
- **Language**: C (using the GCC compiler)
- **Library**: MiniLibX library provided by 42/1337

---

## Installation

1. **Clone the repository:**
   ```shell
   git clone https://github.com/yourusername/cub3d.git
   cd cub3d
   ```

2. **Compile the project:**
   ```shell
   make
   ```

3. **Run the program:**
   ```shell
   ./cub3d path_to_map.cub
   ```

---

## Map Format (.cub file)

The map file contains textures paths, colors, and a map layout:

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0

111111
100001
100201
101001
111111
```

- `NO`, `SO`, `WE`, `EA`: Paths to wall textures (North, South, West, East).
- `F`, `C`: Floor and Ceiling colors in RGB format.
- Map Layout:
  - `1`: Wall
  - `0`: Empty space
  - `2`: Player starting position (exactly one required)

---

## Controls

- `W`: Move forward
- `S`: Move backward
- `A`: Rotate left
- `D`: Rotate right
- `ESC`: Exit the program

---

## Project Structure

```
cub3d/
├── Makefile
├── includes/
│   └── cub3d.h
├── srcs/
│   ├── main.c
│   ├── raycasting.c
│   ├── rendering.c
│   ├── parsing.c
│   └── utils.c
├── textures/
│   ├── north.xpm
│   ├── south.xpm
│   ├── west.xpm
│   └── east.xpm
└── maps/
    └── example.cub
```

---

## Credits

Project by abouazi at [42/1337 School](https://profile.intra.42.fr/users/abouazi).

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) file for details.

