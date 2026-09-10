
# Sudoku Solver

A Sudoku solver written from scratch in **C**.

The project implements Sudoku board management, constraint tracking, and a command-line interface for solving Sudoku puzzles. The solver uses custom data structures to represent individual squares, rows, columns, and 3×3 boxes.

## Features

* Input Sudoku puzzles manually
* Solve Sudoku puzzles
* Detect when the solver cannot make further progress
* Track possible values for each square
* Track 3×3 Sudoku boxes
* Command-line interface
* Modular C implementation
* Dynamic memory allocation
* Makefile-based build system
* Debian `.deb` package support

## How It Works

### Sudoku Representation

The Sudoku board is represented using custom structures:

* `Sudoku` — represents the complete puzzle
* `Square` — represents an individual cell
* `Box` — represents a 3×3 box

Each square stores information about:

* Its current number
* Its row and column
* Its associated 3×3 box
* Possible values
* Whether it can currently be solved

### Solving

The solver repeatedly searches for values that can be determined from the current constraints.

It checks:

1. Squares with only one possible value
2. Unique candidates within a 3×3 box
3. Unique candidates within a row

Whenever a value is determined, the corresponding row, column, and box constraints are updated.

The solver continues until either:

* The Sudoku is completely solved, or
* No further progress can be made using the implemented solving techniques.

> The solver currently uses constraint-based solving and does not implement recursive backtracking.

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
├── packaging/
│   └── sudoku-solver/
│       ├── DEBIAN/
│       │   └── control
│       └── usr/
│           └── bin/
│               └── sudoku
├── Makefile
└── README.md
```

## Requirements

* GCC
* Make
* ncurses
* Debian/Ubuntu-based Linux distribution for `.deb` packaging

On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential libncurses-dev dpkg-dev
```

## Building From Source

Clone the repository:

```bash
git clone https://github.com/FahimMuntasr/sudoku-solver.git
cd sudoku-solver
```

Build the program:

```bash
make
```

Run it:

```bash
./sudoku
```

You can also build and run it with:

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
2. Solve Sudoku
3. Exit

Choose an option:
```

### Input Sudoku

Select the input option and enter the Sudoku values from left to right and top to bottom.

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

### Solve Sudoku

Select the solve option to attempt to solve the current puzzle.

If the solver can determine all values, the completed Sudoku is displayed.

If no further deductions can be made, the program reports that the puzzle could not be solved using the implemented techniques.

## Example

```text
----------Sudoku Solver-------------
Current Sudoku:
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

## Debian Package

The project can be packaged as a Debian `.deb` package.

Build the package with:

```bash
make package
```

This produces:

```text
sudoku-solver_1.0.0_amd64.deb
```

Install it with:

```bash
sudo apt install ./sudoku-solver_1.0.0_amd64.deb
```

After installation, the program can be launched from anywhere using:

```bash
sudoku
```

To uninstall:

```bash
sudo apt remove sudoku-solver
```

## What I Learned

This project was built to practice low-level programming and algorithmic problem solving in C.

Key concepts explored:

* C structures
* Pointers and pointer-to-pointer structures
* Dynamic memory allocation
* Multi-file C projects
* Header files
* Makefiles
* Constraint propagation
* Sudoku solving algorithms
* Modular program design
* Command-line interfaces
* Linux development
* Debian package creation
* Debugging memory and logic errors

## Future Improvements

* Implement recursive backtracking
* Improve puzzle validation
* Add stronger solving techniques
* Improve input handling
* Add automated tests
* Improve memory management and cleanup
* Improve the terminal interface using `ncurses`
* Add difficulty analysis

