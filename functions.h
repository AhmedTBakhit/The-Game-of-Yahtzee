/*This code would not be possible without the help of Hiba & Amna who i own  a debt of gratidue and money.*/ 

#ifndef function_h
#define function_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h> //rand() , scrand()
#include <time.h> //srand  --> time()

#define DISPLAY_RULES 1
#define PLAY 2
#define EXIT 3

void display_menu(void);
int get_option(void);
int validate_menu_option(void);
void process_option(int option);
void print_game_rules(void);
//int roll_die(void);
void Play_game(void);
void combination_list(void);
void play_game(void);
void display_dice(void);
void roll_dice(void);
void validate_choice(int choice);
void asking_loop(void);
void print_combos(void);
void scores(void);
#endif