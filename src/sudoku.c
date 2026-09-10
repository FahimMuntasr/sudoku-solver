#include <stdio.h>
#include "sudoku.h"

int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;
int UNSOLVED = 81;

int main(){
 
  srand(time(NULL));

  startUI();

  return 0;
}

void startUI(){
  int choice;
  Sudoku *sudoku;
  Sudoku *solved;
  int ** puzzle;
  int generated = 0;
  int isSolved = 0;
  int solvable = 0;
  while (1){
    printf("----------Sudoku Solver-------------\n");
    printf("Current Sudoku:\n");
    if(generated){
      printPuzzle(sudoku);
    }else{
      printf("No sudoku created yet.");
    }
    if(isSolved){
      if (solvable) {
        printf("Solution:\n");
        printPuzzle(solved);
      }else {
        printf("Not solvable\n");
      }
    }
    printf("\n1. Input Sudoku\n2. Generate Sudoku\n3. Solve Sudoku\n4. Exit\nChoose an option:");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        puzzle = createPuzzle();
        sudoku = setUpPuzzle(puzzle);
        generated = 1;
        isSolved = 0;
        break;
      case 2:
        puzzle = generatePuzzle();
        sudoku = setUpPuzzle(puzzle);
        generated = 1;
        isSolved = 0;
        break;
      case 3:
        // Solve
        if(generated){
          solved = copySudoku(sudoku);
          solvable = solve(solved);
          isSolved = 1;
        }else 
          printf("Input a sudoku first.\n");
        break;
      case 4:
        // exit 
        return;
      default:
        // invalid option 
        printf("Invalid Choice.....\n");
        break;
    }
    printf("------------------------------------\n");
  }
}
