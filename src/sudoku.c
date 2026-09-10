#include <stdio.h>
#include "sudoku.h"

int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;
int UNSOLVED = 81;
int main(){
  
  int ** puzzle;
  Square *** sudoku;

  puzzle = createPuzzle();
  
  
  sudoku = setUpPuzzle(puzzle);
  printPuzzle(sudoku);
  checkPuzzle(sudoku);
  printPuzzle(sudoku);
  return 0;
}
