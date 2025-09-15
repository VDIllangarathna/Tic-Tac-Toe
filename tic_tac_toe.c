#include <stdio.h>
#include <stdlib.h>

char** initialize_board(int n);
void display_board(char** board, int n);
int is_valid_move(char** board, int n, int row, int column);
int check_win(char** board, int n, char symbol);
int check_draw(char** board, int n);
void log_file(FILE* logfile, char** board, int n);
void computer_move(char** board, int n, int *row, int column);

//game modes
void Two_Player_game(int n);
void user_vs_computer_game(int n);
void Multiplayer_game(int n);


int main(){

	int n;
	int game_mode;


        printf("*** Tic Tac Toe Game ***\n");

	printf("Enter Board Size n (3 <= n <= 10): ");
	scanf("%d", &n);
	if(n < 3 || n > 10){
		printf("Invalid Board Size!\3");
		return 0;
		}

	printf("* Game Modes *\n");
      	printf("1. Two Playersw (User VS User)\n");
	printf("2. User VS Computer\n");
	printf("3. Three Players\n");
	printf("Select Game Mode: \n");
	scanf("%d", &game_mode);
	return 0;
}

	



