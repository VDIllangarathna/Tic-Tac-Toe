#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Functions
char** initialize_board(int n);
void display_board(char** board, int n);
int is_valid_move(char** board, int n, int row, int column);
int check_win(char** board, int n, char symbol);
int check_draw(char** board, int n);
void log_file(FILE* logfile, char** board, int n);
void computer_move(char** board, int n, int *row, int *column);


//Game Modes
void Two_Player_Game(int n);
void User_VS_Computer_Game(int n);
void Multiplayer_Game(int n);

#endif
