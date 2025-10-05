#include "tic_tac_toe.h"


int main (){

	int n;
	int game_mode;

//Welcome Message
        printf("*** Tic Tac Toe Game ***\n\n");

//Get Board Size
	printf("Enter Board Size n (3 <= n <= 10): ");
	scanf("%d", &n);
	if(n < 3 || n > 10){
		printf("Invalid Board Size!\n");
		return 0;
		}
//Coose Game Mode
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
   return 0;
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

        
  
//2. User VS Computer Mode

   void User_VS_Computer_Game(int n){
    char** board = initialize_board(n);
    FILE* logFile = fopen("game.txt", "w");

    char symbol[2] = {'x', 'o'};
    int turn = 0;
    int row, column;
    int game_over = 0;

    while(!game_over){
        display_board(board, n);
        if(turn == 0){
            printf("Enter your move (row column): ");
            scanf("%d %d", &row, &column);

            if(!is_valid_move(board, n, row, column)){
            printf("Invalid move! Try Again.\n");
            continue;
        }
    }
    else{
        computer_move(board, n, &row, &column);
        printf("Computer playes at (row column):  %d %d\n", row, column);
    }

    board[row][column] = symbol[turn];
    log_file(logFile, board, n);

    if(check_win(board, n, symbol[turn])){
            display_board(board, n);
            if(turn == 0){
                printf("You Win\n");
            }
            else{
                printf("Computer Win\n");
            }
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
   void Multiplayer_Game(int n){
	   char** board = initialize_board(n);
    FILE* logFile = fopen("game.txt", "w");

    char symbol[3] = {'x', 'o', 'z'};
    int human_or_computer[3] = {0, 0, 0}; //0-human, 1-computer
    int turn = 0;
    int row, column;
    int game_over = 0;

    //Player 1 must be human and Ask for Player  2 and Player 3
    human_or_computer[0] = 0;

    printf("\nIs Player 2 a Human or Computer (0-Human, 1-Computer): ");
    scanf("%d", &human_or_computer[1]);
    printf("Is Player 3 a Human or Computer (0-Human, 1-Computer): ");
    scanf("%d", &human_or_computer[2]);

    while(!game_over){
        display_board(board, n);

        //Human Move
        if(human_or_computer[turn] == 0){
   printf("\n Player %c, enter your move (row column): ", symbol[turn]);
            scanf("%d %d", &row, &column);

            if(!is_valid_move(board, n, row, column)){
                printf("\nInvalid move! Try Again.\n");
                continue;
            }
        }

    //Computer Move
       else{
        computer_move(board, n, &row, &column);
        printf("Computer %c Playes at (row column): %d %d\n", symbol[turn], row, column);
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
        printf("It's Draw\n");
        game_over = 1;
    }
    else{
        turn = (turn+1)%3;
       }
    }
    fclose(logFile);
    for(int i=0; i<n; i++){
        free(board[i]);
    }
    free(board);
}

  
