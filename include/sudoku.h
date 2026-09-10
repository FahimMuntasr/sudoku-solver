#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int SIZE_ROWS;
extern int SIZE_COLUMNS;
extern int UNSOLVED;

typedef struct Box{
  struct Square ** squares;
  int numbers;
  int possible[9];
  int solvable;
  struct Box * next;
} Box;

typedef struct Square{
  int number;

  int possible[9];
  int solvable;
  Box * box;
  int row;
  int column;
} Square;

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Square *** setUpPuzzle(int ** puzzle);
void checkPuzzle(Square *** sudoku);

void solveSquare(Square * square);
void updateSudoku(Square *** sudoku, int row, int column);

Box ** createBoxes();
void updateBoxes(Square *** sudoku, int row, int column);
#endif
