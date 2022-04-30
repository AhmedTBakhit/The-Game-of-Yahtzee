#include "functions.h"

int dice_player1[5];
int dice_player2[5];
int score_card1[13];
int score_card2[13];
int comb1[13];
int comb2[13];
int turn;

void display_menu(void)
{

	printf("1. Display rules.\n ");
	printf("2. Play Yahtzee.\n ");
	printf("3. Exit\n ");

}



int get_option(void)
{

	int option = 0;

	scanf("%d", &option);

	return option;
}

int validate_menu_option(void)
{
	int option = 0;

	do

	{
		display_menu();
		option = get_option(); // we have user input
		// need to check and validate user input
		//condition should go here

	} while (option < DISPLAY_RULES || option > EXIT); //input validation loop

	return option;
}

void process_option(int option)
{


	switch (option)
	{
	case DISPLAY_RULES: print_game_rules();
		break;
	case PLAY: play_game();
		break;
	case EXIT: printf("Thank You for Playing\n");
		break;
	default: printf("invalid option.\n");
		break;

	}
	
}

/*
* Name:  print_game_rules()
* Description: displays the games rules
* History:
* Input: none
* Outputs: a printf statement
* Returns: void
* Precondition:
* Postcondition:
*/
void print_game_rules(void)

{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections\n. "); 
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63,\n");
	printf("then 35 more points are added to the players overall score as a bonus.\n");
	printf("The lower section contains a number of poker like combinations.\n");
}

/*
* Name:  roll_die()
* Description: rolss one die
* History:
* Input: void
* Outputs: a random value from 1 to 6
* Returns: integer
* Precondition:
* Postcondition:
*/

//int roll_die(void)
//{
//	int random = 0;
//	random = rand() % 6 + 1;
//	return random;
//}



void combination_list(int choice)
{
	int check = 0;

	do
	{
		// Prints all the combinations, or an X if it's been used
		switch (choice)
		{
		case 1:
			check = ones();
			break;
		case 2:
			check = twos();
			break;
		case 3:
			check = threes();
			break;
		case 4:
			check = fours();
			break;
		case 5:
			check = fives();
			break;
		case 6:
			check = sixes();
			break;
		case 7:
			check = three_of_a_kind();
			break;
		case 8:
			check = four_of_a_kind();
			break;
		case 9:
			check = full_house();
			break;
		case 10:
			check = sm_straight();
			break;
		case 11:
			check = lg_straight();
			break;
		case 12:
			check = yahtzee();
			break;
		case 13:
			check = chance();
			break;
		default:
			printf("Please enter a valid selection.\n\n");
			break;
		}
	} while (check == 0);
}

int ones()
{
	int dieIndex = 0, score = 0;
	int valid = 1;
	if (turn == 1)
	{
		if (comb1[0] == 0)
		{
			comb1[0] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 1)
				{
					score = score + 1;
				}
			}
			score_card1[0] = score;
		}
	}
	else
	{
		if (comb2[0] == 0)
		{
			comb2[0] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 1)
				{
					score = score + 1;
				}
			}
			score_card2[0] = score;
		}

	}
	
	return valid;
}

int twos()
{
	int dieIndex = 0, score = 0;
	int valid = 1;

	if (turn == 1)
	{
		if (comb1[1] == 0)
		{
			comb1[1] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 2)
				{
					score = score + 1;
				}
			}
			score_card1[1] = score*2;
		}
	}
	else
	{
		if (comb2[1] == 0)
		{
			comb2[1] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 2)
				{
					score = score + 1;
				}
			}
			score_card2[1] = score*2;
		}

	}
	return valid;
}

int threes()
{
	int dieIndex = 0, score = 0, valid = 0;

	if (turn == 1)
	{
		if (comb1[2] == 0)
		{
			comb1[2] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 3)
				{
					score = score + 1;
				}
			}
			score_card1[2] = score*3;
		}
	}
	else
	{
		if (comb2[2] == 0)
		{
			comb2[2] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 3)
				{
					score = score + 1;
				}
			}
			score_card2[2] = score*3;
		}

	}
	return valid;
}

int fours()
{
	int dieIndex = 0, score = 0, valid = 0;

	if (turn == 1)
	{
		if (comb1[3] == 0)
		{
			comb1[3] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 4)
				{
					score = score + 1;
				}
			}
			score_card1[3] = score*4;
		}
	}
	else
	{
		if (comb2[3] == 0)
		{
			comb2[3] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 4)
				{
					score = score + 1;
				}
			}
			score_card2[3] = score*4;
		}

	}
	return valid;
}

int fives()
{
	int dieIndex = 0, score = 0, valid = 0;

	if (turn == 1)
	{
		if (comb1[4] == 0)
		{
			comb1[4] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 5)
				{
					score = score + 1;
				}
			}
			score_card1[4] = score*5;
		}
	}
	else
	{
		if (comb2[4] == 0)
		{
			comb2[4] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 5)
				{
					score = score + 1;
				}
			}
			score_card2[4] = score*5;
		}

	}
	return valid;
}

int sixes()
{
	int dieIndex = 0, score = 0, valid = 0;

	if (turn == 1)
	{
		if (comb1[5] == 0)
		{
			comb1[5] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player1[dieIndex] == 6)
				{
					score = score + 1;
				}
			}
			score_card1[5] = score*6;
		}
	}
	else
	{
		if (comb2[5] == 0)
		{
			comb2[5] = 1;
			valid = 1;
			for (dieIndex = 0; dieIndex < 5; dieIndex++)
			{
				if (dice_player2[dieIndex] == 6)
				{
					score = score + 1;
				}
			}
			score_card2[5] = score*6;
		}

	}
	return valid;
}

int three_of_a_kind()
{
	int number = 0, result = 0, sum = 0;

	
	if (turn == 1)
	{
		if (comb1[6] == 0)
		{
			result = 1;
			comb1[6] = 1; 
			for (number = 1; number < 7; number++)
			{
				sum = 0;

				if (dice_player1[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[4] == number)
				{
					sum = sum + 1;
				}

				
				if (sum >= 3)
				{
					score_card1[6] = dice_player1[0] + dice_player1[1] + dice_player1[2] + dice_player1[3] + dice_player1[4];
					break;
				}
			}

		}
	}
	else
	{
		if (comb2[6] == 0)
		{
			result = 1;
			comb2[6] = 1;
			for (number = 1; number < 7; number++)
			{
				sum = 0;

				if (dice_player2[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[4] == number)
				{
					sum = sum + 1;
				}

				
				if (sum >= 3)
				{
					score_card2[6] = dice_player2[0] + dice_player2[1] + dice_player2[2] + dice_player2[3] + dice_player2[4];
					break;
				}
			}

		}

	}
	return result;
}

int four_of_a_kind()
{
	int number = 0, result = 0, sum = 0;

	
	if (turn == 1) {
		if (comb1[7] == 0)
		{
			comb1[7] = 1;  
			for (number = 1; number > 5; number++)
			{
				sum = 0;

				if (dice_player1[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[4] == number)
				{
					sum = sum + 1;
				}

				if (sum >= 4)
				{
					score_card1[7] = dice_player1[0] + dice_player1[1] + dice_player1[2] + dice_player1[3] + dice_player1[4];
					break;
				}
			}
			result = 1;
		}
	}
	else
	{
		if (comb2[7] == 0)
		{
			comb2[7] = 1;
			for (number = 1; number > 5; number++)
			{
				sum = 0;

				if (dice_player2[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[4] == number)
				{
					sum = sum + 1;
				}

				if (sum >= 4)
				{
					score_card2[7] = dice_player2[0] + dice_player2[1] + dice_player2[2] + dice_player2[3] + dice_player2[4];
					break;
				}
			}
			result = 1;
		}
	}
	return result;
}

int full_house()
{
	int number = 0, result = 0, sum1 = 0, sum2 = 0, three = 0, two = 0, number2 = 0;

	
	if (turn == 1)
	{
		if (comb1[8] == 0)
		{
			comb1[8] = 1; 
			result = 1;

			
			for (number = 1; number < 7; number++)
			{
				sum1 = 0;

				if (dice_player1[0] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player1[1] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player1[2] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player1[3] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player1[4] == number)
				{
					sum1 = sum1 + 1;
				}

				if (sum1 == 3)
				{
					break;
				}
			}

			for (number2 = 1; number2 < 7; number2++)
			{
				sum2 = 0;

				if (dice_player1[0] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player1[1] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player1[2] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player1[3] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player1[4] == number2)
				{
					sum2 = sum2 + 1;
				}

				
				if (number2 == number)
				{
					sum2 = 0;
				}

				if (sum2 == 2)
				{
					if (sum2 + sum1 == 5)
					{
						score_card1[8] = 25;
					}
					break;
				}
			}
		}
	}
	else
	{
		if (comb2[8] == 0)
		{
			comb2[8] = 1; 

		
			result = 1;

			
			for (number = 1; number < 7; number++)
			{
				sum1 = 0;

				if (dice_player2[0] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player2[1] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player2[2] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player2[3] == number)
				{
					sum1 = sum1 + 1;
				}
				if (dice_player2[4] == number)
				{
					sum1 = sum1 + 1;
				}

				if (sum1 == 3)
				{
					break;
				}
			}

			
			for (number2 = 1; number2 < 7; number2++)
			{
				sum2 = 0;

				if (dice_player2[0] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player2[1] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player2[2] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player2[3] == number2)
				{
					sum2 = sum2 + 1;
				}
				if (dice_player2[4] == number2)
				{
					sum2 = sum2 + 1;
				}

				
				if (number2 == number)
				{
					sum2 = 0;
				}

				if (sum2 == 2)
				{
					if (sum2 + sum1 == 5)
					{
						score_card2[8] = 25;
					}
					break;
				}
			}
		}
	}
	return result;

}

int sm_straight()
{
	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	
	if (turn == 1)
	{
		if (comb1[9] == 0)
		{
			result = 1;

			comb1[9] = 1;
			
			for (passes = 1; passes < 5; passes++)
			{
				for (index = 0; index < 5 - passes; index++)
				{
					if (dice_player1[index] > dice_player1[index + 1])
					{
						temp = dice_player1[index];
						dice_player1[index] = dice_player1[index + 1];
						dice_player1[index + 1] = temp;
					}
				}
			}

			
			for (index = 4; index > 0; index--)
			{
				if (dice_player1[index] == dice_player1[index - 1] + 1)
				{
					sum++;
				}

			}

			
			if (sum >= 3)
			{
				score_card1[9] = 30;
			}
		}
	}
	else
	{
		if (comb2[9] == 0)
		{
			result = 1;

			comb2[9] = 1;
			
			for (passes = 1; passes < 5; passes++)
			{
				for (index = 0; index < 5 - passes; index++)
				{
					if (dice_player2[index] > dice_player2[index + 1])
					{
						temp = dice_player2[index];
						dice_player2[index] = dice_player2[index + 1];
						dice_player2[index + 1] = temp;
					}
				}
			}

			
			for (index = 4; index > 0; index--)
			{
				if (dice_player2[index] == dice_player2[index - 1] + 1)
				{
					sum++;
				}

			}

			
			if (sum >= 3)
			{
				score_card2[9] = 30;
			}
		}
	}

	return result;
}

int lg_straight()
{
	int index = 0, temp = 0, passes = 0, sum = 0, result = 0;

	
	if (turn == 1) {
		if (comb1[10] == 0)
		{
			result = 1;
			comb1[10] = 1;
			
			for (passes = 1; passes < 5; passes++)
			{
				for (index = 0; index < 5 - passes; index++)
				{
					if (dice_player1[index] > dice_player1[index + 1])
					{
						temp = dice_player1[index];
						dice_player1[index] = dice_player1[index + 1];
						dice_player1[index + 1] = temp;
					}
				}
			}

			
			for (index = 4; index > 0; index--)
			{
				if (dice_player1[index] == dice_player1[index - 1] + 1)
				{
					sum++;
				}

			}

			
			if (sum >= 4)
			{
				score_card1[10] = 30;
			}
		}
	}
	else
	{
		if (comb2[10] == 0)
		{
			result = 1;
			comb2[10] = 1;
			
			for (passes = 1; passes < 5; passes++)
			{
				for (index = 0; index < 5 - passes; index++)
				{
					if (dice_player2[index] > dice_player2[index + 1])
					{
						temp = dice_player2[index];
						dice_player2[index] = dice_player2[index + 1];
						dice_player2[index + 1] = temp;
					}
				}
			}

			
			for (index = 4; index > 0; index--)
			{
				if (dice_player2[index] == dice_player2[index - 1] + 1)
				{
					sum++;
				}

			}

			
			if (sum >= 4)
			{
				score_card2[10] = 30;
			}
		}

	}

	return result;
}

int yahtzee()
{
	int number = 0, result = 0, sum = 0;

	if (turn == 1)
	{
		if (comb1[11] == 0)
		{
			comb1[11] = 1; 

			for (number = 0; number < 5; number++)
			{
				sum = 0;

				if (dice_player1[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player1[4] == number)
				{
					sum = sum + 1;
				}

				if (sum == 5)
				{
					score_card1[11] = 50;
				}
			}
			result = 1;
		}
	}
	else
	{
		if (comb2[11] == 0)
		{
			comb2[11] = 1; 

			for (number = 0; number < 5; number++)
			{
				sum = 0;

				if (dice_player2[0] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[1] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[2] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[3] == number)
				{
					sum = sum + 1;
				}
				if (dice_player2[4] == number)
				{
					sum = sum + 1;
				}

				if (sum == 5)
				{
					score_card2[11] = 50;
				}
			}
			result = 1;
		}

	}
	return result;
}

int chance()
{
	int result = 0, sum = 0;

	if (turn == 1)
	{
		if (comb1[12] == 0)
		{
			comb1[12] = 1;
			result = 1;
			sum = dice_player1[0] + dice_player1[1] + dice_player1[2] + dice_player1[3] + dice_player1[4];

			score_card1[12] = sum;
		}
	}
	else
	{
		if (comb2[12] == 0)
		{
			comb2[12] = 1;
			result = 1;
			sum = dice_player2[0] + dice_player2[1] + dice_player2[2] + dice_player2[3] + dice_player2[4];

			score_card2[12] = sum;
		}
	}


	return result;
}

void roll_dice()
{
	int i = 0, number = 0;

	printf("Please enter 1 to roll the 5 dice\n ");
	scanf("%d", &number);

	while (i < 5)
	{
		if(turn == 1){
			dice_player1[i] = rand() % 6 + 1;
		}
		else
			dice_player2[i] = rand() % 6 + 1;

		++i;
	}
}
//displays dice
void display_dice()
{
	if (turn == 1) {
		printf("Die 1: %d\n", dice_player1[0]);
		printf("Die 2: %d\n", dice_player1[1]);
		printf("Die 3: %d\n", dice_player1[2]);
		printf("Die 4: %d\n", dice_player1[3]);
		printf("Die 5: %d\n\n", dice_player1[4]);
	}
	else
	{
		printf("Die 1: %d\n", dice_player2[0]);
		printf("Die 2: %d\n", dice_player2[1]);
		printf("Die 3: %d\n", dice_player2[2]);
		printf("Die 4: %d\n", dice_player2[3]);
		printf("Die 5: %d\n\n", dice_player2[4]);

	}
	
}

void asking_loop()
{
	int  rolls = 0;
	char ans = '\0';

	while (rolls < 3 && ans != 'Y')
	{
		//roll the 5 dicesnumber = 0,
		roll_dice();
		// show the 5 dices;
		display_dice();
		//add 1 to the total number of rolls
		rolls++;
		printf("Do you want to use these rolls for one of the game combinations? (Y for Yes or N for N)\n");
		scanf(" %c", &ans);

	}
}

void print_combos()
{
	// Prints the combination

	if (turn == 1) {
		if (comb1[0] == 0)
		{
			printf("1. Sum of 1s\n");
		}
		else { printf("X. Sum of 1s\n"); }

		if (comb1[1] == 0)
		{
			printf("2. Sum of 2s\n");
		}
		else { printf("X. Sum of 2s\n"); }

		if (comb1[2] == 0)
		{
			printf("3. Sum of 3s\n");
		}
		else { printf("X. Sum of 3s\n"); }

		if (comb1[3] == 0)
		{
			printf("4. Sum of 4s\n");
		}
		else { printf("X. Sum of 4s\n"); }

		if (comb1[4] == 0)
		{
			printf("5. Sum of 5s\n");
		}
		else { printf("X. Sum of 5s\n"); }

		if (comb1[5] == 0)
		{
			printf("6. Sum of 6s\n");
		}
		else { printf("X. Sum of 6s\n"); }

		if (comb1[6] == 0)
		{
			printf("7. Three of a kind\n");
		}
		else { printf("X. Three of a kind\n"); }

		if (comb1[7] == 0)
		{
			printf("8. Four of a kind\n");
		}
		else { printf("X. Four of a kind\n"); }

		if (comb1[8] == 0)
		{
			printf("9. Full house\n");
		}
		else { printf("X. Full house\n"); }

		if (comb1[9] == 0)
		{
			printf("10. Small Straight\n");
		}
		else { printf("X. Small Straight\n"); }

		if (comb1[10] == 0)
		{
			printf("11. Large Straight\n");
		}
		else { printf("X. Large Straight\n"); }

		// Can be used an unlimited amount of times
		printf("12. YAHTZEE\n");

		if (comb1[12] == 0)
		{
			printf("13. Chance\n\n");
		}
		else { printf("Already Picked\n\n"); }
	}
	else
	{
		if (comb2[0] == 0)
		{
			printf("1. Sum of 1s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[1] == 0)
		{
			printf("2. Sum of 2s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[2] == 0)
		{
			printf("3. Sum of 3s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[3] == 0)
		{
			printf("4. Sum of 4s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[4] == 0)
		{
			printf("5. Sum of 5s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[5] == 0)
		{
			printf("6. Sum of 6s\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[6] == 0)
		{
			printf("7. Three of a kind\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[7] == 0)
		{
			printf("8. Four of a kind\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[8] == 0)
		{
			printf("9. Full house\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[9] == 0)
		{
			printf("10. Small Straight\n");
		}
		else { printf("Already Picked\n"); }

		if (comb2[10] == 0)
		{
			printf("11. Large Straight\n");
		}
		else { printf("Already Picked\n"); }

		
		printf("12. YAHTZEE\n");

		if (comb2[12] == 0)
		{
			printf("13. Chance\n\n");
		}
		else { printf("Already Picked\n\n"); }
	}
	
}

int combination_choice()

{
	int choice = 0;
	printf("Please select one of the following combination\n");
	print_combos();
	scanf("%d", &choice);
	combination_list(choice);
	return choice;
	
}


//Actual Gameplay
void play_game(void)
{
	
	for (int i = 0; i < 5; i++)
	{
		dice_player1[i] = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		dice_player2[i] = 0;
	}
	for (int i = 0; i < 26; i++) {
		if (i % 2 == 0) {
			turn = 1;
			printf("Player1 turn\n");
			Play_game();
		}
		else{
			turn = 2;
			printf("Player2 turn\n");
			Play_game();
		}
		 scores();
			
	}
	

	

}

void Play_game()
{

	asking_loop();

	combination_choice();
	
}
//print scores
void scores(void)
{
	int sum1 = 0, sum2 = 0;

	for (int index = 0; index < 5; index++)
	{
		sum1 = score_card1[index] + sum1;
	}
	for (int index = 0; index < 5; index++)
	{
		sum2 = score_card2[index] + sum2;
	}

	if ((score_card1[0] + score_card1[1] + score_card1[2] + score_card1[3] + score_card1[4] + score_card1[5]) > 63)
	{
		sum1 = sum1 + 35;
	}
	if ((score_card2[0] + score_card2[1] + score_card2[2] + score_card2[3] + score_card2[4] + score_card2[5]) > 63)
	{
		sum2 = sum2 + 35;
	}

	if (sum1 > sum2)
	{
		printf("\n\nPlayer 2 won with %d points!!!!!!!!!!\nPlayer 1 has %d points.\n\n", sum2, sum1);
	}


	if (sum2 > sum1)
	{
		printf("\n\nPlayer 1 won with %d points!!!!!!!\nPlayer 2 has %d points.\n\n", sum1, sum2);
	}

	
	if (sum1 == sum2)
	{
		printf("You both scored a tie! Both players have %d points.\n\n", sum1);
	}
}