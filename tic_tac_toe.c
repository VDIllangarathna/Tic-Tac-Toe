#include "tic_tac_toe.h"

//Initializied the board

char** initialize_board(int n){

    char** board = (char**)malloc(n * sizeof(char*));
    for(int i=0; i<n; i++){
        board[i] = (char*)malloc(n * sizeof(char));
        for(int j=0; j<n; j++) {
            board[i][j] = ' ';
        }
    }
   return board;
}

//Display the board

void display_board(char** board, int n) {
    printf("  ");
    for(int column=0; column<n; column++){
        printf("   %d", column);
    }
    printf("\n");
    for(int row=0; row<n; row++){
     printf(" %d ", row);
     for(int column=0; column<n; column++){
         if(board[row][column] == ' '){
             printf("|---");
         }
         else{
             printf("| %c ",board[row][column]);
                      }
     }
     printf("|\n");
}
printf("\n");
}

//check validated moves
int is_valid_move(char** board, int n, int row, int column){
    if(row  < 0 || row >= n || column < 0 || column >= n){
        return 0;
    }
    if(board[row][column] != ' '){
        return 0;
    }
    return 1;
    }

    //Check win codination
    int check_win(char** board, int n, char symbol){

        //Chech rows
        for(int i=0; i<n; i++){
            int win = 1;
            for(int j=0; j<n; j++){
                if(board[i][j] != symbol){
                    win = 0;
                    break;
                }
            }
            if(win) return 1;
        }


    //Check columns
    for(int j=0; j<n; j++){
            int win = 1;
            for(int i=0; i<n; i++){
                if(board[i][j] != symbol){
                    win = 0;
                    break;
                }
            }
            if(win) return 1;
        }

    //Check diagonal - top right to bottom left
    int win = 1;
    for(int i=0; i<n; i++){
        if(board[i][n-1-i] != symbol){
            win = 0;
            break;
        }
    }
    if(win) return 1;

    //Check diagonal - top left to bottom right
    win = 1;
    for(int i=0; i<n; i++){
        if(board[i][i] != symbol){
            win = 0;
            break;
        }
    }
    return win;
    }

    //Check Draw
    int check_draw(char** board, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == ' '){
                    return 0;
                }
            }
        }
        return 1;
    }

    //Log game state to file
    void log_file(FILE* logFile, char** board, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fprintf(logFile, "%c ", board[i][j]);
            }
            fprintf(logFile, "\n");
        }
    fprintf(logFile, "--------------\n");
}

//Generate computer move
void computer_move(char** board, int n, int *row, int *column){
    do{
        *row = rand() % n;
        *column = rand() % n;
    }while(!is_valid_move(board, n, *row, *column));
}
