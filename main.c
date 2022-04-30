#include "functions.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	int option = 0;
	

	do
	{
		option = validate_menu_option();


		 process_option(option);
	} while (option != EXIT);




	return 0;
}