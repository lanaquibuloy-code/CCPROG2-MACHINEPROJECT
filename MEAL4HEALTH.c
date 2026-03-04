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

/*
===============================
|         FUNCTIONS           |
===============================
*/
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
        
        scanf(" %c", nChoice);
        
        *ProgramRuns = 0;
        
        return;
        
    }
    
}

void chooseUpdate(char *user, char *pass, char *nChoice, int *ProgramRuns)
{
    
    printf("\nEnter username: ");
    scanf("%s", user);
    
    printf("Enter password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "ad1234") == 0)
         printf("\nEntering update mode.. ");
  
    else
    {
        printf("\nInvalid username or password");
        printf("\nReturning to main menu..\n\n");
        displayMainMenu(nChoice, ProgramRuns);
        *ProgramRuns = 1;
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
    char user[10], pass[10];

    while(ProgramRuns)
    {
        displayMainMenu(&nChoice, &ProgramRuns);
        
        switch(nChoice)
        {
            case 'U':
            case 'u':
                printf("Update mode...");
                chooseUpdate(user, pass, &nChoice, &ProgramRuns);
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
