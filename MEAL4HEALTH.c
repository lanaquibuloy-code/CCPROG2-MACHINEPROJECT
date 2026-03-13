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

/*
===============================
|         STRUCTURES          |
===============================
*/
typedef struct {
	double Qty;
	str15 UnitofMeas;
	str20 FoodItem;
} nIngredients;

typedef struct {
	str70 directions;
}nInstructions;

typedef struct {
	str20 nDishName; 
	str15 nClassification;
	int servingSize;
	
	nIngredients ingredientsList[MAX_INGREDIENTS];
	int ingreCount;
	
	nInstructions stepsList[MAX_STEPS];
	int stepCount;
}nRecipe;

typedef struct {
	str20 FoodItem;
	double Qty;
	str15 UnitofMeas;
	int Calories;
}nFoodInfo;

typedef struct {
	str20 user;
	str20 pass;
} nAdminLogin;

/*
===============================
|         MENU SCREEN        |
===============================
*/
void displayMainMenu(char *nChoice)
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
		
		scanf(" %c", nChoice);
	
}

void chooseUpdate(nAdminLogin *login, int *nSuccess)
{
    printf("\nEnter username: ");
    scanf("%20s", login->user);
    
    printf("Enter password: ");
    scanf("%20s", login->pass);

    if (strcmp(login->user, "admin") == 0 && strcmp(login->pass, "ad1234") == 0)
    {
    	printf("\nEntering update mode.. \n\n");
    	*nSuccess = 1;
	}
  
    else
    {
        printf("\nInvalid username or password");
        printf("\nReturning to main menu..\n\n");
        *nSuccess = 0;
    }
}

void displayUpdateRecipeBox(char *nChoice)
{
	printf("+===================================+\n");
	printf("||%-33s||\n", "     UPDATE RECIPE BOX");
	printf("+===================================+\n");
	printf("||%-33s||\n", "       CALORIE DATABASE");
	printf("+===================================+\n");
	printf("||%-33s||\n", " 1. Add Food-Calorie Info");
	printf("||%-33s||\n", " 2. View Food-Calorie Chart");
	printf("||%-33s||\n", " 3. Save Calorie Info");
	printf("||%-33s||\n", " 4. Load Calorie Info");
	
	printf("+===================================+\n");
	printf("||%-33s||\n", "        RECIPE DATABASE");
	printf("+===================================+\n");
	printf("||%-33s||\n", " 5. Add Recipe");
	printf("||%-33s||\n", " 6. Modify Recipe");
	printf("||%-33s||\n", " 7. Delete Recipe");
	printf("||%-33s||\n", " 8. List Recipe Titles");
	printf("||%-33s||\n", " 9. Scan Recipes");
	printf("||%-33s||\n", " S. Search Recipe by Title");
	printf("||%-33s||\n", " E. Export Recipes");
	printf("||%-33s||\n", " I. Import Recipes");
	printf("+===================================+\n");
	printf("||%-33s||\n", " R. Exit Menu");
	printf("+===================================+\n");
	printf("> "); 
	
	scanf(" %c", nChoice);
}

void displayModifyRecipe(char *nChoice)
{
	printf("+===================================+\n");
	printf("||%-33s||\n", "     MODIFY RECIPE");
	printf("+===================================+\n");
	printf("||%-33s||\n", " 1. Add Ingredients");
	printf("||%-33s||\n", " 2. Delete Ingredient");
	printf("||%-33s||\n", " 3. Add Step");
	printf("||%-33s||\n", " 4. Delete Step");
	
	printf("||%-33s||\n", " R. Return to Update Menu");
	printf("+===================================+\n");
	
	printf("> ");
	scanf(" %c", nChoice);
}

void displayAccessRecipeBox(char *nChoice)
{
	printf("+===================================+\n");
	printf("||%-33s||\n", "     ACCESS RECIPE BOX");
	printf("+===================================+\n");
	printf("||%-33s||\n", " 1. Import Recipes");
	printf("||%-33s||\n", " 2. Scan Recipes");
	printf("||%-33s||\n", " 3. Search Recipe by Title");
	printf("||%-33s||\n", " 4. Generate Shopping List");
	printf("||%-33s||\n", " 5. Scan Recipes by Ingredient");
	printf("||%-33s||\n", " 6. Recommend Menu");
	
	printf("||%-33s||\n", " R. Exit Menu");
	printf("+===================================+\n");
	
	printf("> ");
	scanf(" %c", nChoice);
}


void addIngre(nRecipe *recipe)
{
	int nIngre;
	
	if (recipe->ingreCount < MAX_INGREDIENTS) {
		
		nIngre = recipe->ingreCount;
		
		printf("\n-----ENTER QUANTITY-----\n");
		scanf("%lf", &recipe->ingredientsList[nIngre].Qty);
		
		printf("\n-----ENTER UNIT OF MEASUREMENT-----\n");
		scanf(" %15[^\n]", recipe->ingredientsList[nIngre].UnitofMeas);
		
		printf("\n-----ENTER FOOD ITEM-----\n");
		scanf(" %20[^\n]", recipe->ingredientsList[nIngre].FoodItem);
		
		recipe->ingreCount++;
		
		printf("\nIngredients Added succesfully!\n");
	}
	else {
		printf("\nIngredients list has reached its max!\n");
	}
	
}

void addStep(nRecipe *recipe)
{
	int nStep; 
	
	if(recipe->stepCount < MAX_STEPS)
	{
		nStep = recipe->stepCount;
		
		printf("\n-----ENTER INSTRUCTIONS-----\n");
		scanf(" %70[^\n]", recipe->stepsList[nStep].directions);
		
		recipe->stepCount++;
		
		printf("\nSuccess! New Step added.\n");
	}
	else 
	{
		printf("\nStop! The instructions are too long!\n");
	}
	
}

void searchRecipe(nRecipe recipeList[], int recipeCount, char dishName[], int *nFound)
{
	int i;
	*nFound = -1;
	
	for(i = 0; i < recipeCount; i++)
	{
		if(strcmp(recipeList[i].nDishName, dishName) == 0)
		{
			*nFound = i;
		}
   }  
}
/*
===============================
|         MAIN PROG           |
===============================
*/
int main(void)
{
	int ProgramRuns = 1;
	char nChoice;
	
	while(ProgramRuns) 
	{
		displayMainMenu(&nChoice);
		
		switch(nChoice)
		{	
		//CHOOSING UPDATE RECIPE 
			case 'U':
			case 'u':
				{
					nAdminLogin login;
					int loginSuccess;
					
					chooseUpdate(&login, &loginSuccess);
					
					if(loginSuccess) //if login is succesful
					{
						char NewChoice;
						int InUpdateChoice = 1;
						
						while(InUpdateChoice)
						{
							displayUpdateRecipeBox(&NewChoice);
							
							switch(NewChoice)
							{
								case '1':
									printf("WALA PA\n");
									break;
								
								case '2':
									printf("WALA PA\n");
									break;
								case '3':
									printf("WALA PA\n");
									break;
								case '4':
									printf("WALA PA\n");
									break;
								case '5':
									printf("WALA PA\n");
									break;
								case '6':
									{
										char NewChoice;
										int inModifyChoice = 1;
										
										nRecipe tempRecipe;
										tempRecipe.ingreCount = 0;
										tempRecipe.stepCount = 0;
										
										while(inModifyChoice)
										{   
										displayModifyRecipe(&NewChoice);
										
											switch(NewChoice)
											{
												case '1':
													{
														char nChoice = 'Y';
														while (nChoice == 'Y' || nChoice == 'y')
														{
															addIngre(&tempRecipe);
															
															printf("\nAdd another ingredient?\n");
															scanf(" %c", &nChoice);
														}
														
													}
												break;		
													
												case '2':
													printf("\nDelete Ingredient\n");
													break;
												case '3':
													{
														char nChoice = 'Y';
														while (nChoice == 'Y' || nChoice == 'y')
														{
															addStep(&tempRecipe);
															
															printf("\nAdd another step?\n");
															scanf(" %c", &nChoice);
														}
														
													}
												     break;
											    case '4':
												    printf("\nDelete Step\n");
											        break;
												case 'R':
												case 'r':
													inModifyChoice = 0;
													break;
												default:
													printf("\nINVALID\n");
											}
											}
										}
										break;
									
								case '7':
									printf("WALA PA\n");
									break;
								case '8':
									printf("WALA PA\n");
									break;
								case '9':
									printf("WALA PA\n");
									break;
								case 'S':
								case 'S':
								case 's':
									{
										char dishName[21];
										int nRep;
										
											nRecipe recipeList[MAX_RECIPES];
											int recipeCount = 0;
										
										printf("\n-----SEARCH RECIPE-----\n");
										printf("RECIPE NAME: ");
										scanf(" %20[^\n]", dishName);
										
										searchRecipe(recipeList, recipeCount, dishName, &nRep);
										
										if(nRep != -1)
										{
											printf("\nRecipe Found!");
										}
										else 
										{
											printf("\nRecipe Is not here.\n");
										}
									}
									
									break;
								case 'E':
								case 'e':
									printf("WALA PA\n");
									break;
								case 'I':
								case 'i':
									printf("WALA PA\n");
									break;
									
									//RETURN TO MENU
								case 'R':
								case 'r':
									InUpdateChoice = 0; 
									break;
									
								default:
									printf("Invalid Option.\n");
									break;
							}
						}
					}
				}
				break;
				
				//CHOOSING ACCESS RECIPE
			case 'A': 
			case 'a':
				{
					char NewChoice;
					int InAccessChoice = 1;
					
					while(InAccessChoice)
					{
						displayAccessRecipeBox(&NewChoice);
						
						switch(NewChoice)
						{
							case '1':
								printf("WALA PA\n");
								break;
							case '2':
								printf("WALA PA\n");
								break;
							case '3':
								printf("WALA PA\n");
								break;
							case '4':
								printf("WALA PA\n");
								break;
							case '5':
								printf("WALA PA\n");
								break;
							case '6':
								printf("WALA PA\n");
								break;
								
							case 'R':
							case 'r':
								InAccessChoice = 0;
								break;
							
							default:
								printf("INVALID");
								break;
						}
					}
				}
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

