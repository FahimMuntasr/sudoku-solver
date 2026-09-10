#include <stdio.h>
#include "sudoku.h"

int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;
int UNSOLVED = 81;
int main(){
  
  int ** puzzle;
  Sudoku * sudoku;

  puzzle = createPuzzle();
  
  
  sudoku = setUpPuzzle(puzzle);
  printPuzzle(sudoku->squares);
  checkPuzzle(sudoku->squares,sudoku->boxes);
  printPuzzle(sudoku->squares);

  return 0;
}
