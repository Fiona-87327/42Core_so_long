#  🎮 so_long

Small 2D game project for 42 (Core Curriculum). The player must collect all collectibles and then reach the exit.

## Requirements

- Language: C
- Graphics: MLX42
- Build: `make`
- (Optional) Uses `libft` (if your project does)

## Build

```bash
make
```

(Optional, only if available)
```bash
make clean
make fclean
make re

## Usage

```bash
./so_long <map.ber>
```

Example:
```bash
./so_long maps/map.ber
```

## Controls

- `W`, `A`, `S`, `D` (or arrow keys): move
- `ESC`: quit
- Window close button: quit

## Map Format (`.ber`)

The map must be a text file with the `.ber` extension and a rectangular shape.

Allowed tiles:
- `1`: wall
- `0`: empty space
- `P`: player start (exactly 1)
- `E`: exit (exactly 1)
- `C`: collectible (at least 1)

## Map Validation

The program must reject maps that do not follow the rules, including (non-exhaustive):

- The map is not rectangular.
- The map is not surrounded by walls (`1`).
- Missing or invalid number of required elements (`P`, `E`, `C`).
- The map contains invalid characters.
- The map is not solvable (player cannot reach all collectibles and the exit).

