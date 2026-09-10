
# Sudoku Solver

A Sudoku solver and puzzle generator written from scratch in **C**.

The project implements Sudoku board management, constraint tracking, puzzle generation, and solving using custom data structures and algorithms. The program runs through a simple command-line interface.

## Features

* Input a Sudoku puzzle manually
* Solve Sudoku puzzles
* Detect when the solver cannot make further progress
* Track possible values for each square
* Track 3×3 Sudoku boxes
* Command-line interface
* Modular C implementation using multiple source files
* Randomized Sudoku generation using backtracking

## How It Works

### Sudoku Representation

The Sudoku board is represented using custom structures:

* `Sudoku` — represents the complete puzzle
* `Square` — represents an individual cell
* `Box` — represents a 3×3 box

Each square keeps track of:

* Its current number
* Its row and column
* Its associated 3×3 box
* Possible values
* Whether it can currently be solved

### Solving

The solver repeatedly looks for cells where the answer can be determined from the current constraints.

It checks:

1. Individual square possibilities
2. Unique candidates within a 3×3 box
3. Unique candidates within a row

When a value is found, the corresponding row, column, and box constraints are updated.

### Puzzle Generation

The generator first creates a complete valid Sudoku using randomized backtracking.

It then removes numbers from the completed board to create a playable puzzle.

Because the puzzle starts from a valid completed Sudoku, the generated puzzle has at least one valid solution.

> The generator does not guarantee that the resulting puzzle has a unique solution.

## Project Structure

```text
sudoku-solver/
├── include/
│   └── sudoku.h
├── src/
│   ├── box.c
│   ├── main.c
│   ├── puzzle.c
│   ├── row.c
│   ├── square.c
│   └── sudoku.c
├── Makefile
└── README.md
```

## Requirements

* GCC
* Make
* ncurses

On Ubuntu/Debian:

```bash
sudo apt install build-essential libncurses-dev
```

## Installation

Clone the repository:

```bash
git clone https://github.com/FahimMuntasr/sudoku-solver.git
cd sudoku-solver
```

Compile the project:

```bash
make
```

Run:

```bash
./sudoku
```

You can also use the Makefile's run command if available:

```bash
make run
```

## Usage

When the program starts, the following menu is displayed:

```text
----------Sudoku Solver-------------
Current Sudoku:
No sudoku created yet.

1. Input Sudoku
2. Generate Sudoku
3. Solve Sudoku
4. Exit

Choose an option:
```

### Input Sudoku

Select option `1` and enter the Sudoku values from left to right and top to bottom.

Use `0` for an empty cell.

Example:

```text
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

### Generate Sudoku

Select option `2` to generate a random Sudoku puzzle.

### Solve Sudoku

Select option `3` to attempt to solve the current puzzle.

The solution is displayed separately from the original puzzle.

## Example Output

```text
-------------------------------
| 5  3  0 | 0  7  0 | 0  0  0 |
| 6  0  0 | 1  9  5 | 0  0  0 |
| 0  9  8 | 0  0  0 | 0  6  0 |
|-----------------------------|
| 8  0  0 | 0  6  0 | 0  0  3 |
| 4  0  0 | 8  0  3 | 0  0  1 |
| 7  0  0 | 0  2  0 | 0  0  6 |
|-----------------------------|
| 0  6  0 | 0  0  0 | 2  8  0 |
| 0  0  0 | 4  1  9 | 0  0  5 |
| 0  0  0 | 0  8  0 | 0  7  9 |
-------------------------------

Solution:

-------------------------------
| 5  3  4 | 6  7  8 | 9  1  2 |
| 6  7  2 | 1  9  5 | 3  4  8 |
| 1  9  8 | 3  4  2 | 5  6  7 |
|-----------------------------|
| 8  5  9 | 7  6  1 | 4  2  3 |
| 4  2  6 | 8  5  3 | 7  9  1 |
| 7  1  3 | 9  2  4 | 8  5  6 |
|-----------------------------|
| 9  6  1 | 5  3  7 | 2  8  4 |
| 2  8  7 | 4  1  9 | 6  3  5 |
| 3  4  5 | 2  8  6 | 1  7  9 |
-------------------------------
```

## What I Learned

This project was built to practice low-level programming and algorithmic problem solving in C.

Key concepts explored:

* Dynamic memory allocation
* Pointers and pointer-to-pointer structures
* Structures
* Modular C programming
* Header files
* Makefiles
* Sudoku constraint propagation
* Backtracking
* Randomized algorithms
* CLI application design
* Debugging memory and logic errors

## Future Improvements

Possible improvements include:

* Implement full Sudoku backtracking in the solver
* Guarantee a unique solution during puzzle generation
* Add difficulty levels
* Improve input validation
* Add better error handling
* Add puzzle statistics
* Improve the terminal UI using `ncurses`
* Add automated tests
* Improve memory cleanup and resource management

