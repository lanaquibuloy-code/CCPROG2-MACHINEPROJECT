/*
MEALS FOR HEALTH 
MEMBERS: 
LANA QUIBULOY
KEIONNA JARAMILLO
*/
#include <stdio.h>
#include <string.h>
/*
===============================
|         CONSTANTS            |
===============================
*/

// LIMITS FOR RECIPES
#define MAX_RECIPES              50
#define MAX_INGREDIENTS          20
#define MAX_STEPS                15

//CHARACTER LIMITATIONS
typedef char str20[21]; //NAME OF DISH & NAME OF ITEN USED 
typedef char str15[16]; // UNITS OF MEASUREMENT
typedef char str70[71]; // INSTRUCSTIONS

void displayMainMenu(char *nChoice, int *ProgramRuns)
{
	
	while (*ProgramRuns)
	{
		printf("+===================================+\n");
		printf("||%-33s||\n", "     Meals for Health");
		printf("+===================================+\n");
		printf("||%-33s||\n", " What would you like to do?");
		printf("+===================================+\n");
		printf("||%-33s||\n", " U. Update Recipe Box");
		printf("||%-33s||\n", " A. Access Recipe Box");
		printf("||%-33s||\n", " E. Exit Menu");
		printf("+===================================+\n");
		printf("> "); 
		
		scanf("%c", nChoice);
		
		*ProgramRuns = 0;
		
		return;
		
	}
	
}

int main(void)
{
	int ProgramRuns = 1;
	char nChoice;
	
	while(ProgramRuns) 
	{
		displayMainMenu(&nChoice, &ProgramRuns);
		
		switch(nChoice)
		{	
			case 'U':
			case 'u':
				printf("Update mode...");
				ProgramRuns = 0;
				break;
			
			case 'A': 
			case 'a':
				printf("Accessing mode...\n");
				ProgramRuns = 0;
				break;
			
			case 'E':
			case 'e':
				printf("Exiting...\n");
				ProgramRuns = 0;
				break; 
				
			default:
				printf("Invalid Option. Try again.\n\n");
				ProgramRuns = 1; // goes back to menu
				break;
		
		}
		
	}
	
	return 0;
	
}