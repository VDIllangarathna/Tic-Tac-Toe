#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** initialize_board(int n);
void display_board(char** board, int n);
int is_valid_move(char** board, int n, int row, int column);
int check_win(char** board, int n, char symbol);
int check_draw(char** board, int n);
void log_file(FILE* logfile, char** board, int n);
void computer_move(char** board, int n, int *row, int *column);

//game modes
void Two_Player_Game(int n);
void User_VS_Computer_Game(int n);
void Multiplayer_Game(int n);


int main (){

	int n;
	int game_mode;


        printf("*** Tic Tac Toe Game ***\n\n");

	printf("Enter Board Size n (3 <= n <= 10): ");
	scanf("%d", &n);
	if(n < 3 || n > 10){
		printf("Invalid Board Size!\n");
		return 0;
		}

	printf("\n* Game Modes * \n");
      	printf("1. Two Players (User VS User)\n");
	printf("2. User VS Computer\n");
	printf("3. Three Players\n");
	printf("Select Game Mode: ");
	scanf("%d", &game_mode);


   switch(game_mode){
	    case 1: Two_Player_Game(n);
	    break;
	    case 2: User_VS_Computer_Game(n);
	    break;
	    case 3: Multiplayer_Game(n);
	    break;
	    default:
	    printf("Invalid Mode! Please try again");
	}
}
	
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
        printf("  %d ", column);
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

//Create Game Modes

//1.Two Player Mode
void Two_Player_Game(int n){
    char** board = initialize_board(n);
    FILE* logFile = fopen("game.txt", "w");
    
    char symbol[2] = {'x', 'o'};
    int turn = 0;
    int row, column;
    int game_over = 0;
    
    while(!game_over){
        display_board(board, n);
        printf("Player %c, Enter your move (row column): ", symbol[turn]);
        scanf("%d %d", &row, &column);
        
        if(!is_valid_move(board, n, row, column)){
            printf("Invalid move! Try Again.\n");
            continue;
        }
        board[row][column] = symbol[turn];
        log_file(logFile, board, n);
        
        if(check_win(board, n, symbol[turn])){
            display_board(board, n);
            printf("Player %c wins\n", symbol[turn]);
            game_over = 1;
        }
        else if(check_draw(board, n)){
            display_board(board, n);
            printf("It's a draw\n");
            game_over = 1;
        }
        else{
            turn = 1-turn;
        }
    }
    
    fclose(logFile);
    for(int i=0; i<n; i++){
        free(board[i]);
    }
    free(board);
}

        
   void User_VS_Computer_Game(int n){
   }
   void Multiplayer_Game(int n){
  }
