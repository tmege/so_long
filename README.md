# so_long

A small 2D game built with the MiniLibX graphical library as part of the 42 school curriculum. Developed during Halloween, so the game has a Halloween theme — spooky sprites, eerie maps, and a haunted atmosphere.

## Description

so_long is a Halloween-themed top-down 2D game where the player navigates a haunted map, collects all items, and reaches the exit. The project focuses on window management, event handling, and basic 2D rendering using the MiniLibX library.

## Features

- Map validation (rectangular shape, closed borders, required elements)
- Flood-fill path checking to ensure the map is completable
- Player movement with keyboard input (WASD / arrow keys)
- Move counter displayed in the terminal
- Clean exit on `ESC` or window close button
- **Bonus:** on-screen move counter, additional sprites

## Project Structure

```
so_long/
├── inc/              # Header files (mandatory)
├── inc_bonus/        # Header files (bonus)
├── src/              # Source files (mandatory)
├── src_bonus/        # Source files (bonus)
├── obj/              # Compiled object files (generated)
├── obj_bonus/        # Compiled bonus object files (generated)
├── libft/            # Custom C library
├── minilibx-linux/   # MiniLibX graphical library
├── assets/           # XPM sprites
├── maps/             # Example and test maps
└── Makefile
```

## Map Format

Maps use the `.ber` extension and are made up of the following characters:

| Character | Meaning     |
|-----------|-------------|
| `0`       | Empty floor |
| `1`       | Wall        |
| `C`       | Collectible |
| `E`       | Exit        |
| `P`       | Player start|

Rules:
- The map must be rectangular and fully enclosed by walls.
- There must be exactly one player (`P`), at least one collectible (`C`), and exactly one exit (`E`).
- A valid path must exist from the player to all collectibles and the exit.

## Usage

**Compile:**
```bash
make
```

**Run:**
```bash
./so_long maps/ex01.ber
```

**Bonus version:**
```bash
make bonus
./so_long_bonus maps/ex01.ber
```

**Clean:**
```bash
make clean    # Remove object files
make fclean   # Remove object files and binaries
make re       # Full rebuild
```

## Dependencies

- **MiniLibX** — included in `minilibx-linux/`, requires `libXext` and `libX11`
- **Libft** — custom C library included in `libft/`

## Notes

- Touching the `Makefile` triggers a full recompilation of all source files.
- The project compiles with `-Wall -Wextra -Werror`.
