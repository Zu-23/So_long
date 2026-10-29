# So_long

A small tile-based 2D game written in C for the 42 curriculum. Move through a map, collect its collectibles, and reach the exit using MiniLibX graphics.

## Features

- XPM sprites for walls, ground, the player, collectibles, and the exit.
- Movement, wall collision checks, collectible tracking, and a move counter.
- `.ber` map loading and checks for rectangular layout, boundary walls, and map elements.
- Keyboard and window-close event handling.

## Requirements and build

The supplied Makefile targets **macOS**: it links MiniLibX with the OpenGL and AppKit frameworks and uses macOS key codes. Requires GCC/Clang, Make, `ar`, and a compatible MiniLibX installation with `mlx.h` and `libmlx` visible to the compiler/linker. MiniLibX is not bundled in this repository.

```sh
make
./so_long maps/map.ber
```

Run from the repository root so the relative paths to [img](img) resolve. The Makefile also provides `clean`, `fclean`, and `re`. Building on Linux requires adapting the graphics dependencies, linker flags, and key mappings.

## Controls

| Key | Action |
| --- | --- |
| W / A / S / D | Move up / left / down / right |
| Escape | Close the game |
| Window close button | Close the game |

## Maps

The included example is [maps/map.ber](maps/map.ber).

| Symbol | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Ground |
| `P` | Player start |
| `C` | Collectible |
| `E` | Exit |

Use a rectangular, wall-enclosed map with one player, one exit, and at least one collectible. The current checks do not establish that every collectible and the exit are reachable.

## Concepts practiced

Event-driven programming, graphics-library integration, map parsing, collision checks, game state, and resource management.
