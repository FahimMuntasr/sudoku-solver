#include "sudoku.h"

Sudoku * createSudoku(Square *** squares, Box ** boxes){
  Sudoku * sudoku;
  sudoku = malloc(sizeof(Sudoku));

  sudoku->squares = squares;
  sudoku->boxes = boxes;

  return sudoku;
}

Sudoku * copySudoku(Sudoku * original){
  Square *** squares;
  Box ** boxes;
  Sudoku * copy;
  int i, j, k;

  squares = malloc(sizeof(Square **) * SIZE_ROWS);

  for(i = 0; i < SIZE_ROWS; i++){
    squares[i] = malloc(sizeof(Square *) * SIZE_COLUMNS);

    for(j = 0; j < SIZE_COLUMNS; j++){
      squares[i][j] = malloc(sizeof(Square));

      *squares[i][j] = *original->squares[i][j];
    }
  }

  boxes = createBoxes();

  for(i = 0; i < SIZE_ROWS; i++){
    for(j = 0; j < SIZE_COLUMNS; j++){
      for(k = 0; k < 9; k++){
        if(original->boxes[k] == original->squares[i][j]->box){
          squares[i][j]->box = boxes[k];
          break;
        }
      }
    boxes[k]->squares[boxes[k]->numbers] = squares[i][j];
    boxes[k]->numbers++;
    }
  }

  copy = createSudoku(squares, boxes);
  return copy;
}

Sudoku * setUpPuzzle(int ** puzzle){
  Square *** sudoku;
  Box ** boxes;
  int i,j,k;
  int currentBox = 0;
  sudoku = (Square***)malloc(sizeof(Square **)*9);
  boxes = createBoxes();
  // loop through rows 
  for(i=0; i<SIZE_ROWS; i++){
    sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
    
    // loop through columns 
    for(j=0; j<SIZE_COLUMNS; j++){
      sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);

      sudoku[i][j]->number = puzzle[i][j];

      sudoku[i][j]->row = i;
      sudoku[i][j]->column = j;
      sudoku[i][j]->solvable = 9;

      boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
      sudoku[i][j]->box = boxes[currentBox];
      boxes[currentBox]->numbers++;

      for(k=0;k<SIZE_ROWS; k++){
        sudoku[i][j]->possible[k] = 0;
      }

      if(j == 2 || j == 5)
        currentBox++;
    }
    currentBox -= 2;
    if(i==2)
      currentBox = 3;
    if(i==5)
      currentBox = 6;
  }

  for(i=0;i<SIZE_ROWS;i++){
    for(j=0;j<SIZE_COLUMNS;j++){
      if(sudoku[i][j]->number!=0){
        sudoku[i][j]->solvable = 0;
        updateSudoku(sudoku, i, j);
        updateBoxes(sudoku, i, j);
        UNSOLVED--;
      }
    }
  }
  return createSudoku(sudoku,boxes);
}

void updateSudoku(Square *** sudoku, int row, int column){
  int i, number;
  number = sudoku[row][column]->number;

  for(i=0;i<SIZE_ROWS;i++){
    if(sudoku[i][column]->possible[number-1] == 0){
      sudoku[i][column]->solvable--;
    }
    sudoku[i][column]->possible[number-1]=1; 
  }
  for(i=0;i<SIZE_COLUMNS;i++){
    if(sudoku[row][i]->possible[number-1] == 0){
      sudoku[row][i]->solvable--;
    }
    sudoku[row][i]->possible[number-1]=1; 
  }
}

int checkPuzzle(Square *** sudoku, Box ** boxes){
  int i,j,k;

  for(i = 0;i < SIZE_ROWS;i++){
    for(j = 0;j < SIZE_COLUMNS;j++){
      if(sudoku[i][j]->solvable == 1){
        solveSquare(sudoku[i][j]);
        updateSudoku(sudoku, i, j);
        updateBoxes(sudoku, i, j);
        
        return 1;
      }
    }
  }

  if(boxSingles(sudoku, boxes)){
    return 1;
  }
  return checkRows(sudoku, boxes);
}

int isValid(int **puzzle, int row, int column, int number){
  int i;
  int boxRow;
  int boxColumn;

  for(i = 0; i < 9; i++){
    if(puzzle[row][i] == number)
      return 0;
    if(puzzle[i][column] == number)
      return 0;
  }

  boxRow = (row / 3) * 3;
  boxColumn = (column / 3) * 3;

  for(i = 0; i < 9; i++){
    int r = boxRow + i / 3;
    int c = boxColumn + i % 3;

    if(puzzle[r][c] == number)
      return 0;
  }

  return 1;
}

int fillPuzzle(int **puzzle, int row, int column){
  int numbers[9];
  int i, j, temp;
  int nextRow;
  int nextColumn;

  if(row == 9)
    return 1;

  nextRow = row;
  nextColumn = column + 1;

  if(nextColumn == 9){
    nextColumn = 0;
    nextRow++;
  }

  for(i = 0; i < 9; i++)
    numbers[i] = i + 1;

  for(i = 8; i > 0; i--){
    j = rand() % (i + 1);

    temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }

  for(i = 0; i < 9; i++){
    int number = numbers[i];

    if(isValid(puzzle, row, column, number)){
      puzzle[row][column] = number;

      if(fillPuzzle(puzzle, nextRow, nextColumn))
        return 1;

      puzzle[row][column] = 0;
     }
  }

  return 0;
}

int **generatePuzzle(){
  int **puzzle;
  int i, j;

  puzzle = malloc(sizeof(int *) * 9);

  for(i = 0; i < 9; i++){
    puzzle[i] = malloc(sizeof(int) * 9);

    for(j = 0; j < 9; j++)
      puzzle[i][j] = 0;
  }

  fillPuzzle(puzzle, 0, 0);

  /* Remove numbers */
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(rand() % 100 < 50)
        puzzle[i][j] = 0;
    }
  }

  return puzzle;
}

int ** createPuzzle(){

  int** puzzle;
  int i,j;

  puzzle = (int**)malloc(sizeof(int*)*9);
  
  printf("Enter sudoku numbers in left to right, top to bottom order:\n ");
  for( i = 0; i < SIZE_ROWS; i++){
    
    puzzle[i] = (int*)malloc(sizeof(int)*9);
       
    for(j = 0; j < SIZE_COLUMNS; j++){
      scanf("%d", &puzzle[i][j]);
    }

  }

  //printPuzzle(puzzle);
  return puzzle;
}

void printPuzzle(Sudoku * sudoku){
  
  Square *** puzzle;
  puzzle = sudoku->squares;
  
  int i,j;
  printf("-------------------------------\n");
  for (i=0; i<SIZE_ROWS; i++){
    for(j=0; j<SIZE_COLUMNS; j++){
      if((j)%3==0){
        printf("|");
      }
      printf(" %d ", puzzle[i][j]->number);
    }
    if((i+1)%3==0 && i!=8){
      printf("|\n|-----------------------------");
    }
    printf("|\n");
  }

  printf("-------------------------------\n");
}

int solve(Sudoku * sudoku){
  
  int progress;
  
  while (UNSOLVED > 0) {

    progress = checkPuzzle(sudoku->squares, sudoku->boxes);
    
    if(progress == 0){
      return 0;
    }
  }
  
  if(UNSOLVED == 0){
    return 1;
  }
}
