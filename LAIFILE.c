/*
 This is to certify that this project is our own work, based on our personal efforts in studying and applying the concepts learned.
 We have constructed the functions and their respective algorithms and corresponding code by myself. The program was run, tested,
 and page 5 debugged by my own efforts. We further certify that we have not copied in part or whole or otherwise plagiarized the
 work of other students and/or persons, nor did we employ the use of AI in any part of the deliverable.

                                                                                Keionna Marie C. Jaramillo, DLSU ID#12507237
                                                                                Lana Mikaela P. Quibuloy, DLSU ID#12542199
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
===============================
|         CONSTANTS            |
===============================
*/

// LIMITS FOR RECIPES
#define MAX_RECIPES              50
#define MAX_FOOD_ITEMS           50
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

//WILL BE USED FOR BONUS FUCNTION
typedef struct {
	str20 dishName;
	int totalRating;
	int ratingCount;
}nRating;

/*
===============================
|         MENU SCREENs       |
===============================
*/

/*
 displayMainMenu displays the main menu and accepts user input to navigate through main menu.
 
 @param nChoice - char pointer where the user option will be stored
 
 Pre-condition: nChoice is not null and not an integer
*/
void 
displayMainMenu(char *nChoice)
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

/*
 chooseUpdate validates if the username and password is correct
 
 @param login - a pointer to the nAdminLogin struct storing the strings user and pass
 @param nSuccess - an int pointer that sets to 1 if login succeeds, and 0 if it fails

 Pre-condition: login and nSuccess are valid
*/
void
chooseUpdate(nAdminLogin *login,
             int *nSuccess)
{
    printf("\nEnter username: ");
    scanf("%20s", login->user);
    
    printf("Enter password: ");
    scanf("%20s", login->pass);

    if (strcmp(login->user, "admin") == 0 && strcmp(login->pass, "ad1234") == 0)
    {
        printf("\nEntering update mode...\n\n");
        *nSuccess = 1;
    }
  
    else
    {
        printf("\nInvalid username or password.");
        printf("\nReturning to main menu...\n\n");
        *nSuccess = 0;
    }
}

/*
 displayUpdateRecipeBox displays the update recipe box and accepts user input.
 
 @param nChoice - char pointer where the user option will be stored
 
 Pre-condition: nChoice is not null
*/
void 
displayUpdateRecipeBox(char *nChoice)
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

/*
 displayAccessRecipeBox displays the access recipe box and accepts user input.
 
 @param nChoice - char pointer where the user option will be stored
 
 Pre-condition: nChoice is not null
*/
void 
displayAccessRecipeBox(char *nChoice)
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
    printf("||%-33s||\n", " L. List/View by Category");
    printf("+===================================+\n");
    printf("||%-33s||\n", "        RATINGS");
    printf("+===================================+\n");
    printf("||%-33s||\n", " 7. Rate a Recipe");
    printf("||%-33s||\n", " 8. View Ratings");
    printf("||%-33s||\n", " 9. Show Top Recipe");
    
    printf("||%-33s||\n", " R. Exit Menu");
    printf("+===================================+\n");
    
    printf("> ");
    scanf(" %c", nChoice);
}

/*
 displayModifyRecipe displays the modify recipe box and accepts user input.
 
 @param nChoice - char pointer where the user option will be stored
 
 Pre-condition: nChoice is not null
*/
void 
displayModifyRecipe(char *nChoice)
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

/*
===============================
|   USED IN BOTH FUNCTIONS    |
===============================
*/

/*
 readInput reads a line of input from the user and stores it in a string
 
 @param str - character array where the input string will be stored
 @param nSize - maximum size of the string including the null terminator

 Pre-condition: str has enough allocated space and nSize is valid
 */

void 
readInput(char str[], 
          int nSize)
{
    int i = 0;
    char ch;
    
    ch = getchar ();
    
    while (ch != '\n' && ch != EOF)
    {
        if ( i < nSize - 1)
        {
            str[i++] = ch;
        }
        ch = getchar();
    }
    
    str[i] = '\0';
}

/*
 displayIngre displays the ingredient list of the recipe.
 
 @param recipe - recipe whose ingredients will be displayed
 
 Pre-condition: recipe.ingreCount is between 0 and MAX_INGREDIENTS
                recipe.ingredientsList contains valid data 
*/
void 
displayIngre(nRecipe recipe)
{
    int i;
    
    printf("\n==================================================\n");
    printf("| %-5s | %-10s | %-20s |", "Qty", "Unit", "Ingredient");
    printf("\n==================================================\n");
    
    for (i = 0; i < recipe.ingreCount; i++)
    {
        printf("| %-5.2lf | %-10s | %-20s |\n",
        recipe.ingredientsList[i].Qty,
        recipe.ingredientsList[i].UnitofMeas,
        recipe.ingredientsList[i].FoodItem);
    }
    
    printf("\n==================================================\n");
}

/*
 displayIngre displays the instructions of the recipe.
 
 @param recipe - recipe whose instructions will be displayed
 
 Pre-condition: recipe.stepCount is between 0 and MAX_STEPS,
                recipe.stepsList contains valid strings
*/
void 
displaySteps(nRecipe recipe)
{
    int i;
    
    printf("\n==================================================\n");
    printf("                     PROCEDURES\n");
    printf("\n==================================================\n");
    
    for(i = 0; i< recipe.stepCount; i++)
    {
        printf("%d. %s\n", i + 1, recipe.stepsList[i].directions);
    }
    
    printf("\n==================================================\n");
}

/*
 sortRecipe sorts the recipes alphabetically by its dish name
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - number of recipes

 Pre-condition: recipeList contains valid recipe data
*/

void 
sortRecipe(nRecipe recipeList[], 
           int recipeCount)
{
    int i, j, min;
    nRecipe temp;
    
    for(i = 0; i < recipeCount - 1; i++)
    {
        min = i;
        
        for(j = i + 1; j < recipeCount; j++)
        {
            if(strcmp(recipeList[min].nDishName, recipeList[j].nDishName) > 0)
            {
                min = j;
            }
        }
        
        if(i != min)
        {
            temp = recipeList[i];
            recipeList[i] = recipeList[min];
            recipeList[min] = temp;
        }
    }  
}

/*
 scanRecipe displays one recipe at a time and computes the number of calories based on the ingredients
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - number of recipes
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - number of food items

 Pre-condition: recipeList and foodList contains valid recipe data
*/

void 
scanRecipe(nRecipe recipeList[], 
           int recipeCount, 
           nFoodInfo foodList[], 
           int foodCount)
{
    int i=0, j, k;
    int totalCal, found;
    double cal;
    char choice = 'N';
    
    sortRecipe(recipeList, recipeCount);

    while(i >= 0 && i < recipeCount && (choice == 'N' || choice == 'n' || choice == 'P' || choice == 'p'))
        {
            totalCal = 0;

            for(j = 0; j < recipeList[i].ingreCount; j++)
            {
                cal = 0;
                found = 0;

                for(k = 0; k < foodCount && found == 0; k++)
                {
                    if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                              foodList[k].FoodItem) == 0)
                    {
                        cal = (recipeList[i].ingredientsList[j].Qty /
                               foodList[k].Qty) * foodList[k].Calories;

                        found = 1;
                    }
                }

                totalCal += cal;
            }
            
            printf("\n=======================================\n");
            printf("%s %d servings %d calories\n",
                   recipeList[i].nDishName,
                   recipeList[i].servingSize,
                   totalCal);
            printf("\n=======================================\n");
            
            /*
            displayIngre(recipeList[i]);
            displaySteps(recipeList[i]);
            */

            printf("\nIngredients:\n");
            for(j = 0; j < recipeList[i].ingreCount; j++)
            {
                cal = 0;
                found = 0;

                for(k = 0; k < foodCount && found == 0; k++)
                {
                    if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                              foodList[k].FoodItem) == 0)
                    {
                        cal = (recipeList[i].ingredientsList[j].Qty /
                               foodList[k].Qty) * foodList[k].Calories;

                        found = 1;
                    }
                }

                printf("%.0lf %s %-15s %.0lf calories\n",
                       recipeList[i].ingredientsList[j].Qty,
                       recipeList[i].ingredientsList[j].UnitofMeas,
                       recipeList[i].ingredientsList[j].FoodItem,
                       cal);
            }

            printf("\nProcedure:\n");
            for(j = 0; j < recipeList[i].stepCount; j++)
            {
                printf("%d. %s\n", j + 1, recipeList[i].stepsList[j].directions);
            }

            printf("\nPress N to view next recipe. ");
            printf("\nPress P to view previous recipe.");
            printf("\nPress X to exit.");
            printf("\nEnter: ");
            scanf(" %c", &choice);

            if(choice == 'N' || choice == 'n')
            {
                if(i < recipeCount - 1)
                    i++;
                else
                    printf("This is the last recipe!\n\n");
            }
            else if(choice == 'P' || choice == 'p')
            {
                if(i > 0)
                    i--;
                else
                    printf("This is the first recipe!\n\n");
            }
            
        }
}

/*
 searchRecipe asks user which recipe to view
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - number of recipes
 @param dishName - dish name to search for
 @param nFound - int pointer where the number of found recipes will be stored

 Pre-condition: at least one valid recipe
*/

void 
searchRecipe(nRecipe recipeList[], 
             int recipeCount, 
             char dishName[], 
             int *nFound)
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
|         MODIFY SCREEN      |
===============================
*/

/*
 addIngre asks user for the recipe ingredients information
 
 @param recipe - address of the nRecipe structure where the ingredient will be stored
 
 Pre-condition: user inputs appropriate and same data type
*/

void 
addIngre(nRecipe *recipe)
{
    int nIngre;
    
    if (recipe->ingreCount < MAX_INGREDIENTS) {
        
        nIngre = recipe->ingreCount;
        
        printf("Enter food item: ");
        getchar();
        readInput(recipe->ingredientsList[nIngre].FoodItem,21);
        
        printf("\nEnter Quantity: ");
        scanf("%lf", &recipe->ingredientsList[nIngre].Qty);
        
        printf("Enter unit of measurement: ");
        getchar();
        readInput(recipe->ingredientsList[nIngre].UnitofMeas, 16);
        
        recipe->ingreCount++;
        
        printf("\nIngredients Added succesfully!\n");
    }
    else {
        printf("\nIngredients list has reached its max!\n");
    }
    
}

/*
 addStep asks user for the recipe instructions
 
 @param recipe - address of the nRecipe structure where the instructions will be stored
 
 Pre-condition: user inputs appropriate and same data type
*/

void 
addStep(nRecipe *recipe)
{
    int nStepPos;
    int i;
    
    if(recipe->stepCount >= MAX_STEPS)
    {
        printf("\nStop! The instructions are too long!\n");
    }
    else
    {
        displaySteps(*recipe);
        printf("Enter Position of the added Step (1 to %d): ", recipe->stepCount + 1);
        scanf("%d", &nStepPos);
        
        if(nStepPos >= 1 && nStepPos <= recipe->stepCount + 1)
        {
            for (i = recipe->stepCount; i >= nStepPos; i--)
            {
                recipe->stepsList[i] = recipe->stepsList[i - 1];
            }

            printf("Enter New Instruction: ");
            getchar();
            readInput(recipe->stepsList[nStepPos - 1].directions, 71);
            
            recipe->stepCount++;
            
            printf("\nSuccess! New Step has been added.\n");
            displaySteps(*recipe);
        }
        else
        {
            printf("\nINVALID POSITION.\n");
        }
    }
}

/*
 deleteIngre deletes the ingredient the user wants to remove
 
 @param recipe - pointer to the nRecipe structure from which the ingredient will be removed
 
 Pre-condition: recipe contains at least one valid ingredient
*/

void 
deleteIngre(nRecipe *recipe)
{
    int i;
    int nIngre;
    
    if(recipe->ingreCount <= 1)
    {
        printf("\nCannot Delete Ingredient. There should be at least 1 left.\n");
    }
    else
    {
        displayIngre(*recipe);
        printf("Enter Ingredient to be deleted (1 to %d): ", recipe->ingreCount);
        scanf("%d", &nIngre);
        
        if (nIngre >= 1 && nIngre <= recipe->ingreCount)
        {
            for (i = nIngre - 1; i < recipe->ingreCount - 1; i++)
            {
                recipe->ingredientsList[i] = recipe->ingredientsList[i + 1];
            }
            recipe->ingreCount--;
            
            printf("\nSuccessfully removed Ingredient!\n");
        }
        else
        {
            printf("\nInvalid Ingredient. Try Again.\n");
        }
    }
}

/*
 deleteStep deletes the instruction the user wants to remove
 
 @param recipe - pointer to the nRecipe structure from which the instruction will be removed
 
 Pre-condition: recipe contains at least one valid instruction
*/

void 
deleteStep(nRecipe *recipe)
{
    int i;
    int nStepNum;
    
    if(recipe->stepCount <= 1)
    {
        printf("\nCannot delete step. There should be at least 1 left.\n");
    }
    else
    {
        displaySteps(*recipe);
        printf("Enter step number to be deleted (1 to %d): ", recipe->stepCount);
        scanf("%d", &nStepNum);
        
        if (nStepNum >= 1 && nStepNum <= recipe->stepCount)
        {
            for(i = nStepNum - 1; i < recipe->stepCount - 1; i++)
            {
                recipe->stepsList[i] = recipe->stepsList[i + 1];
            }
            
            recipe->stepCount--;
            
            printf("\nStep has been successfully deleted!\n");
        }
        else
        {
            printf("\nInvalid Step Number, Check number of steps again.\n");
        }
    }
}

/*
===============================
| UPDATE RECIPE BOX FUNCTIONS |
===============================
*/

/*
 addFoodInfo asks user for the food item information
 
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - address where the number of food items will be stored

 Pre-condition: user inputs appropriate and same data type
*/
void 
addFoodInfo(nFoodInfo foodList[], 
            int *foodCount)
{
    printf("Enter Food Item: ");
    scanf(" %20[^\n]", foodList[*foodCount].FoodItem);

    printf("Enter Quantity: ");
    scanf("%lf", &foodList[*foodCount].Qty);

    printf("Enter Unit: ");
    scanf(" %15[^\n]", foodList[*foodCount].UnitofMeas);

    printf("Enter Calorie Count: ");
    scanf("%d", &foodList[*foodCount].Calories);

    printf("Food item added successfully!\n\n");

    (*foodCount)++;
}

/*
 viewFoodInfo displays 10 food items at a time
 
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - number of food items

 Pre-condition: foodList contains valid data and user inputs appropriate and same data type
*/

void 
viewFoodInfo(nFoodInfo foodList[], 
             int foodCount)
{
    int i = 0;
    int ctr;
    char choice = 'N';

    while(i < foodCount && (choice == 'N' || choice == 'n'))
    {
        printf("+----------------------------------------------------+\n");
        printf("| Food Item        | Quantity | Unit       | Calories|\n");
        printf("+----------------------------------------------------+\n");

        ctr = 0;

        while(i < foodCount && ctr < 10)
        {
            printf("| %-15s | %-8.2lf | %-10s | %-8d |\n",
                   foodList[i].FoodItem,
                   foodList[i].Qty,
                   foodList[i].UnitofMeas,
                   foodList[i].Calories);

            i++;
            ctr++;
        }

        printf("+----------------------------------------------------+\n");

        if(i < foodCount)
        {
            printf("Press N to view next 10 items or X to exit: ");
            scanf(" %c", &choice);
        }
    }
}

/*
 saveFoodInfo writes the information of the food items into a text file
 
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - number of food items

 Pre-condition: file is already in the correct format
*/

void 
saveFoodInfo(nFoodInfo foodList[], 
             int foodCount)
{
    int i;
    char filename[21];
    
    FILE*fp;

    printf("Enter filename('.txt' included): ");
    scanf("%20s", filename);
    
    fp=fopen(filename,"w");
    
    if (fp!=NULL)
    {
        for(i=0;i<foodCount;i++)
        {
            fprintf(fp, "%s \n%.0lf %s %d calories \n",
                    foodList[i].FoodItem,
                    foodList[i].Qty,
                    foodList[i].UnitofMeas,
                    foodList[i].Calories);
        }
        
        fclose(fp);
        printf("Saving Food Information Success!\n");
    }
    else
    {
        printf("FILE OPENING ERROR.\n");
    }
}

/*
 loadFoodInfo reads a text file inputted by the user and adds it in the foodList array
 
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - stores how many food items are already present

 Pre-condition: file is already in the correct format
*/
void 
loadFoodInfo(nFoodInfo foodList[], 
             int *foodCount)
{
    int i, found, replace;
    char filename[21];
   
    FILE*fp;

    printf("Enter filename('.txt' included): ");
    scanf("%20s", filename);
    
    fp=fopen(filename,"r");

    if(fp!=NULL)
    {
        while(fscanf(fp, " %20[^\n]\n%lf %15s %d calories\n",
                      foodList[*foodCount].FoodItem,
                      &foodList[*foodCount].Qty,
                      foodList[*foodCount].UnitofMeas,
                      &foodList[*foodCount].Calories) == 4)
        {
            found = -1;

            for (i = 0; i < *foodCount; i++)
            {
                if (strcmp(foodList[i].FoodItem, foodList[*foodCount].FoodItem) == 0)
                {
                    found = i;
                }
            }

            if (found != -1)
            {
                printf("\nFood item \"%s\" already exists.\n", foodList[*foodCount].FoodItem);
                printf("[1] Yes\n");
                printf("[2] No\n");
                printf("Replace existing data?: ");
                scanf("%d", &replace);

                if (replace == 1)
                {
                    foodList[found] = foodList[*foodCount];
                }
            }
            else
            {
                (*foodCount)++;
            }
        }
        
        fclose(fp);
        printf("Success! Returning to main menu..\n");
    }
    else
    {
        printf("ERROR OPENING FILE.\n");
    }
}


/*
 addRecipe asks user for a unique recipe
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - int pointer to the current number of recipes

 Pre-condition: recipeList has enough space to store a recipe, and the inputs from the user are valid
 */

void 
addRecipe(nRecipe recipeList[], 
          int *recipeCount)
{
    int choice;
    int isUnique;

    recipeList[*recipeCount].ingreCount = 0;
    recipeList[*recipeCount].stepCount = 0;

    
    if(*recipeCount<MAX_RECIPES)
    {
        do {
            printf("Enter Dish Name: ");
            scanf(" %20[^\n]", recipeList[*recipeCount].nDishName);

            isUnique = 1; // assume the name is unique

            for(int i = 0; i < *recipeCount; i++) {
                if(strcmp(recipeList[i].nDishName, recipeList[*recipeCount].nDishName) == 0) {
                    printf("Dish name already exists. Please enter a different name.\n");
                    isUnique = 0; // found duplicate
                }
            }

        } while(isUnique == 0); // repeat until the name is unique
        
        do
        {
            printf("Enter Classification (starter/main/dessert): ");
            scanf(" %15s", recipeList[*recipeCount].nClassification);
            
            if(strcmp(recipeList[*recipeCount].nClassification,"starter")!=0 &&
               strcmp(recipeList[*recipeCount].nClassification,"main")!=0 &&
               strcmp(recipeList[*recipeCount].nClassification,"dessert")!=0)
            {
                printf("Invalid Classification.\n");
            }
            
        }while(strcmp(recipeList[*recipeCount].nClassification,"starter")!=0 &&
               strcmp(recipeList[*recipeCount].nClassification,"main")!=0 &&
               strcmp(recipeList[*recipeCount].nClassification,"dessert")!=0);
        
        printf("Enter Serving Size: ");
        scanf("%d", &recipeList[*recipeCount].servingSize);
        
        do
        {
            if(recipeList[*recipeCount].ingreCount < MAX_INGREDIENTS)
            {
                printf("\n-----ENTER INGREDIENT-----\n");
                addIngre(&recipeList[*recipeCount]);

                printf("\n[1] Yes");
                printf("\n[2] No");
                printf("\nAdd another ingredient? ");

                
                scanf("%d", &choice);
            }
            else
            {
                printf("Cannot add more ingredients.\n");
                choice = 2;
            }

        } while(choice == 1);
        
        do
        {
            if(recipeList[*recipeCount].stepCount < MAX_STEPS)
            {
                addStep(&recipeList[*recipeCount]);

                printf("\n[1] Yes");
                printf("\n[2] No");
                printf("\nAdd another step? ");
                
                scanf("%d", &choice);
            }
            else
            {
                printf("Cannot add more steps.\n");
                choice = 2;
            }

        } while(choice == 1);
        
        (*recipeCount)++;
    }
    else
        printf("Cannot add more recipes.");
}


/*
 listRecipe lists all recipe titles in alphabetical order
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - number of recipes

 Pre-condition: there is at least one valid recipe
 */

void 
listRecipe(nRecipe recipeList[], 
           int recipeCount)
{
    int i;
    
    sortRecipe(recipeList, recipeCount);

    printf("\nRecipe Titles:\n");
    
    for(i = 0; i < recipeCount; i++)
    {
        printf("%s\n", recipeList[i].nDishName);
    }
    
    printf("\n");
}

/*
 delRecipe removes a recipe the user inputs to delete
 
 @param recipeList - array of nRecipe structures that contains recipe information
 @param recipeCount - int pointer to the current number of recipes and will be decremented

 Pre-condition: there is at least one recipe in the recipeList to delete
*/
void 
delRecipe(nRecipe recipeList[], 
          int *recipeCount)
{
    int i;
    int found=0;
    str20 del;
    
    listRecipe(recipeList, *recipeCount);
    
    do {
        found = 0;
        
        printf("Enter recipe you wish to delete: ");
        scanf(" %20[^\n]", del);
        
        for(i = 0; i < *recipeCount && found == 0; i++)
        {
            if(strcmp(del, recipeList[i].nDishName) == 0)
            {
                recipeList[i] = recipeList[*recipeCount - 1];
                (*recipeCount)--;
                printf("Recipe successfully deleted!\n");
                found = 1;
            }
        }
        
        if(found == 0)
        {
            printf("Recipe is not in the list\n");
            printf("Check for possible spelling error.\n\n");
        }
        
    } while(found == 0);
}

/*
 exportRecipe writes the list of recipes to a text file
 
 @param recipeList - array of nRecipe structures that contains recipe information to export
 @param recipeCount - number of recipes
 @param filename - name of the file to export
 
 Pre-condition: there is at least one or more valid recipe
*/

void 
exportRecipe(nRecipe recipeList[], 
             int recipeCount, 
             char filename[])
{
    FILE *fp;
    int i;
    int j;
    int len;
    int validFile = 1;

    len = strlen(filename);

    if(recipeCount == 0)
    {
        printf("There are no recipes to export.\n\n");
    }
    else
    {
        if(len < 4 || strcmp(&filename[len - 4], ".txt") != 0)
        {
            printf("Error: Please include .txt in the filename.\n\n");
            validFile = 0;
        }

        if(validFile == 1)
        {
            fp = fopen(filename, "w");

            if(fp != NULL)
            {
                for(i = 0; i < recipeCount; i++)
                {
                    fprintf(fp, "%s\n", recipeList[i].nDishName);
                    fprintf(fp, "%d %s\n",
                            recipeList[i].servingSize,
                            recipeList[i].nClassification);

                    fprintf(fp, "Ingredients %d\n", recipeList[i].ingreCount);

                    for(j = 0; j < recipeList[i].ingreCount; j++)
                    {
                        fprintf(fp, "%.2lf %s %s\n",
                                recipeList[i].ingredientsList[j].Qty,
                                recipeList[i].ingredientsList[j].UnitofMeas,
                                recipeList[i].ingredientsList[j].FoodItem);
                    }

                    fprintf(fp, "Steps %d\n", recipeList[i].stepCount);

                    for(j = 0; j < recipeList[i].stepCount; j++)
                    {
                        fprintf(fp, "%s\n",
                                recipeList[i].stepsList[j].directions);
                    }
                }

                fclose(fp);
                printf("All recipes have been successfully exported!\n\n");
            }
            else
            {
                printf("Try again. An error occurred exporting the file.\n\n");
            }
        }
    }
}

/*
 importRecipe loads the information from the text file to the nRecipe structure
 
 @param recipeList - array of nRecipe structures where imported data will be stored
 @param recipeCount - int pointer to the current number of recipes which will be updated
 @param filename - name of the file the user wants to import
 
 Pre-condition: 
 There is at least one or more valid recipe and text file exists and follows the correct recipe formatting
 The filename must include the ".txt" extension
 The file must follow the required format 
 <Recipe Title1><next line>
<Serving Size><space><Classification><next line>
Ingredients<space><ingredient count><next line>
<Quantity><space><Unit><space><Item1><next line>
<Quantity><space><Unit><space><Item2><next line>

Post-condition:
If there is a duplicate found in the user is then given choices
[S] -> ignore imported recipe
[R] -> overwrite it
[X] -> stop import all together
*/

void 
importRecipe(nRecipe recipeList[], 
             int *recipeCount, 
             char filename[])
{
    FILE *fp;
    int i;
    int j;
    int len;
    int validFile = 1;
    int formatOK = 1;
    int duplicateRep;
    int duplicateIdx;
    int stopImport = 0;
    char choice;
    char label[20];
    str20 tempDishName;
    nRecipe tempRecipe;

    len = strlen(filename);
    
    // user will need to add .txt extension with the file name
    if(len < 4 || strcmp(&filename[len - 4], ".txt") != 0)
    {
        printf("Error: Please include .txt in the filename.\n\n");
        validFile = 0;
    }

//checks if file is the correct format
    if(validFile == 1)
    {
        fp = fopen(filename, "r");

        if(fp != NULL)
        {
            while(*recipeCount < MAX_RECIPES &&
                  formatOK == 1 &&
                  stopImport == 0 &&
                  fscanf(fp, " %20[^\n]\n", tempDishName) == 1)
            {
                duplicateRep = 0;
                duplicateIdx = -1;

                for(i = 0; i < *recipeCount && duplicateRep == 0; i++)
                {
                    if(strcmp(recipeList[i].nDishName, tempDishName) == 0)
                    {
                        duplicateRep = 1;
                        duplicateIdx = i;
                    }
                }

                strcpy(tempRecipe.nDishName, tempDishName);

                if(fscanf(fp, "%d %15s\n",
                          &tempRecipe.servingSize,
                          tempRecipe.nClassification) != 2)
                {
                    formatOK = 0;
                }

                if(formatOK == 1)
                {
                    if(fscanf(fp, "%19s %d\n",
                              label,
                              &tempRecipe.ingreCount) != 2)
                    {
                        formatOK = 0;
                    }
                    else if(strcmp(label, "Ingredients") != 0)
                    {
                        formatOK = 0;
                    }
                }

                if(formatOK == 1)
                {
                    for(j = 0; j < tempRecipe.ingreCount; j++)
                    {
                        if(fscanf(fp, "%lf %15s %20s\n",
                                  &tempRecipe.ingredientsList[j].Qty,
                                  tempRecipe.ingredientsList[j].UnitofMeas,
                                  tempRecipe.ingredientsList[j].FoodItem) != 3)
                        {
                            formatOK = 0;
                            j = tempRecipe.ingreCount;
                        }
                    }
                }

                if(formatOK == 1)
                {
                    if(fscanf(fp, "%19s %d\n",
                              label,
                              &tempRecipe.stepCount) != 2)
                    {
                        formatOK = 0;
                    }
                    else if(strcmp(label, "Steps") != 0)
                    {
                        formatOK = 0;
                    }
                }

                if(formatOK == 1)
                {
                    for(j = 0; j < tempRecipe.stepCount; j++)
                    {
                        if(fscanf(fp, " %70[^\n]\n",
                                  tempRecipe.stepsList[j].directions) != 1)
                        {
                            formatOK = 0;
                            j = tempRecipe.stepCount;
                        }
                    }
                }

                if(formatOK == 1)
                {
                    if(duplicateRep == 1)
                    {
                        printf("\nRecipe \"%s\" already exists.\n", tempRecipe.nDishName);
                        printf("[S] Skip\n");
                        printf("[R] Replace\n");
                        printf("[X] Stop\n");
                        printf("Enter choice: ");
                        scanf(" %c", &choice);

                        if(choice == 'S' || choice == 's')
                        {
                            printf("Recipe has been skipped.\n");
                        }
                        else if(choice == 'R' || choice == 'r')
                        {
                            recipeList[duplicateIdx] = tempRecipe;
                            printf("Recipe replaced successfully.\n");
                        }
                        else if(choice == 'X' || choice == 'x')
                        {
                            stopImport = 1;
                        }
                        else
                        {
                            printf("Invalid choice. Recipe skipped.\n");
                        }
                    }
                    else
                    {
                        recipeList[*recipeCount] = tempRecipe;
                        (*recipeCount)++;
                    }
                }
            }

            fclose(fp);

            if(formatOK == 1)
            {
                if(stopImport == 1)
                {
                    printf("\nImport stopped by user.\n\n");
                }
                else
                {
                    printf("File has been imported successfully!\n\n");
                }
            }
            else
            {
                printf("Error: File format is invalid. Please follow the required import format.\n\n");
            }
        }
        else
        {
            printf("Try again! An error occurred with importing the file.\n\n");
        }
    }
}

/*
===============================
|     ACCESS RECIPE BOX       |
===============================
*/

/*
 AgenList asks which recipe to generate a shopping list and the number of servings
 
 @param recipeList - array of nRecipe structures containing the available recipes
 @param recipeCount - number of recipes
 @param servings - number of servings the user will cook for
 
 Pre-condition: there is at least one or more valid recipe
*/
void 
AgenList(nRecipe recipeList[], 
         int recipeCount)
{
    int j;
    int idx;
    int servings;
    str20 dishName;
    double newQty; // change quantity based on the serving size for the recipe
    
    if(recipeCount == 0)
    {
    	printf("\nNo recipes available.\n");
	}
	else
	{
		//list of all the recipes(titles only
		listRecipe(recipeList, recipeCount);
		
		//USER FIRST PUTS THE NAME OF THE RECIPE
		printf("Enter Recipe Name: ");
		getchar();
		readInput(dishName, 21);
		
		//Serving size for amount of people
		printf("How many will be eating?: ");
		scanf("%d", &servings);
		
		//Looks for said recipe
		searchRecipe(recipeList,recipeCount,dishName, &idx);
		
		if(idx != -1)
    {
        printf("\n--- SHOPPING LIST---\n");
        printf("Recipe: %s\n", recipeList[idx].nDishName);
        printf("Original Serving Size: %d\n", recipeList[idx].servingSize);
        printf("Adjusted: %d servings\n\n", servings);
        
        for(j = 0; j < recipeList[idx].ingreCount; j++)
        {
            //adjust quantity based on how many servings the user wants
            newQty = (recipeList[idx].ingredientsList[j].Qty * servings) / recipeList[idx].servingSize;
            
            //displays everything
            printf("%.2lf %s of %s\n",
            newQty,
            recipeList[idx].ingredientsList[j].UnitofMeas,
            recipeList[idx].ingredientsList[j].FoodItem);
        }
        
        printf("Returning to Access Mode Menu....\n\n");
    }
    else 
    {
    	printf("Recipe not in database.\n\n");
	}
    
	}
}

/*
 AscanRecIngre asks user for an ingredient and shows the recipe information of all recipes its part of
 
 @param recipeList - array of nRecipe structures containing the  recipes
 @param recipeCount - number of recipes
 @param ingredient - string of the ingredient name to search
 
 Pre-condition: at least one valid recipe and ingredient
 Post-condition: matching recipes are displayed
*/

void 
AscanRecIngre(nRecipe recipeList[], 
              int recipeCount, 
              char ingredient[],
              nFoodInfo foodList[],
              int foodCount)
{
    int i, j, k;
    int matchedIdx[MAX_RECIPES];
    int matchCount = 0;
    int currentRep = 0;
    int foundIngre;
    int found;
    int totalCal;
    double cal;
    char choice = 'N';

    if(recipeCount == 0)
    {
        printf("\nNo recipes available.\n");
    }
    else
    {
        sortRecipe(recipeList, recipeCount);

        // finds all recipes containing the ingredient 
        for(i = 0; i < recipeCount; i++)
        {
            foundIngre = 0;

            for(j = 0; j < recipeList[i].ingreCount && foundIngre == 0; j++)
            {
                if(strcmp(recipeList[i].ingredientsList[j].FoodItem, ingredient) == 0)
                {
                    foundIngre = 1;
                }
            }

            if(foundIngre == 1)
            {
                matchedIdx[matchCount] = i;
                matchCount++;
            }
        }

        if(matchCount == 0)
        {
            printf("\nNo recipe contains that ingredient.\n");
        }
        else
        {
            printf("\nThere are %d recipe/s containing %s.\n", matchCount, ingredient);

            while(currentRep >= 0 && currentRep < matchCount &&
                  (choice == 'N' || choice == 'n' || choice == 'P' || choice == 'p'))
            {
                i = matchedIdx[currentRep];
                totalCal = 0;

                for(j = 0; j < recipeList[i].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;

                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[i].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }

                    totalCal += cal;
                }

                printf("\n=======================================\n");
                printf("Recipe %d of %d\n", currentRep + 1, matchCount);
                printf("%s\n", recipeList[i].nDishName);
                printf("Serving Size: %d\n", recipeList[i].servingSize);
                printf("Classification: %s\n", recipeList[i].nClassification);
                printf("Total Calories: %d\n", totalCal);
                printf("=======================================\n");

                printf("\nIngredients:\n");
                for(j = 0; j < recipeList[i].ingreCount; j++)
                {
                    printf("%.2lf %s %s\n",
                           recipeList[i].ingredientsList[j].Qty,
                           recipeList[i].ingredientsList[j].UnitofMeas,
                           recipeList[i].ingredientsList[j].FoodItem);
                }

                printf("\nProcedure:\n");
                for(j = 0; j < recipeList[i].stepCount; j++)
                {
                    printf("%d. %s\n", j + 1, recipeList[i].stepsList[j].directions);
                }

                printf("\nPress N to view next recipe.");
                printf("\nPress P to view previous recipe.");
                printf("\nPress X to exit.");
                printf("\nEnter: ");
                scanf(" %c", &choice);

                if(choice == 'N' || choice == 'n')
                {
                    if(currentRep < matchCount - 1)
                        currentRep++;
                    else
                    {
                        printf("\nThis is the last matching recipe.\n");
                        choice = 'X';
                    }
                }
                else if(choice == 'P' || choice == 'p')
                {
                    if(currentRep > 0)
                        currentRep--;
                    else
                        printf("\nThis is the first matching recipe.\n");
                }
            }
        }
    }
}

// RECOMMEND MENU
int 
giveRandomInt(int recipeCount)
{
    int random;
    
    random= rand() % recipeCount;
    
    return random;
}

void 
Arecommend(nRecipe recipeList[], int recipeCount, nFoodInfo foodList[], int foodCount)
{
    int i, j, k;
    int totalCal, cal, found, calIntake;
    
    int validMainIdx[MAX_RECIPES];
    int validStarterIdx[MAX_RECIPES];
    int validDessertIdx[MAX_RECIPES];
    
    int validMainCount = 0;
    int validStarterCount = 0;
    int validDessertCount = 0;
    
    int mainRecomm = -1;
    int starterRecomm = -1;
    int dessertRecomm = -1;
    
    int mainCal = 0;
    int starterCal = 0;
    int dessertCal = 0;

    if(recipeCount == 0)
    {
        printf("\nNo recipes available.\n");
    }
    else
    {
        printf("Enter target calorie intake: ");
        scanf("%d", &calIntake);

        /* FIND ALL VALID MAIN COURSES */
        for(i = 0; i < recipeCount; i++)
        {
            totalCal = 0;
            
            if(strcmp(recipeList[i].nClassification, "main") == 0)
            {
                for(j = 0; j < recipeList[i].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[i].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }
                    
                    totalCal += cal;
                }

                if(totalCal <= calIntake)
                {
                    validMainIdx[validMainCount] = i;
                    validMainCount++;
                }
            }
        }

        if(validMainCount == 0)
        {
            printf("\nNo main courses available under target calories.\n");
        }
        else
        {
            /* RANDOM MAIN COURSE */
            mainRecomm = validMainIdx[giveRandomInt(validMainCount)];

            mainCal = 0;
            for(j = 0; j < recipeList[mainRecomm].ingreCount; j++)
            {
                cal = 0;
                found = 0;
                
                for(k = 0; k < foodCount && found == 0; k++)
                {
                    if(strcmp(recipeList[mainRecomm].ingredientsList[j].FoodItem,
                              foodList[k].FoodItem) == 0)
                    {
                        cal = (recipeList[mainRecomm].ingredientsList[j].Qty /
                               foodList[k].Qty) * foodList[k].Calories;
                        found = 1;
                    }
                }
                
                mainCal += cal;
            }

            /* FIND VALID STARTERS */
            for(i = 0; i < recipeCount; i++)
            {
                totalCal = 0;
                
                if(strcmp(recipeList[i].nClassification, "starter") == 0)
                {
                    for(j = 0; j < recipeList[i].ingreCount; j++)
                    {
                        cal = 0;
                        found = 0;
                        
                        for(k = 0; k < foodCount && found == 0; k++)
                        {
                            if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                      foodList[k].FoodItem) == 0)
                            {
                                cal = (recipeList[i].ingredientsList[j].Qty /
                                       foodList[k].Qty) * foodList[k].Calories;
                                found = 1;
                            }
                        }
                        
                        totalCal += cal;
                    }

                    if(mainCal + totalCal <= calIntake)
                    {
                        validStarterIdx[validStarterCount] = i;
                        validStarterCount++;
                    }
                }
            }

            if(validStarterCount > 0)
            {
                starterRecomm = validStarterIdx[giveRandomInt(validStarterCount)];

                starterCal = 0;
                for(j = 0; j < recipeList[starterRecomm].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[starterRecomm].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[starterRecomm].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }
                    
                    starterCal += cal;
                }
            }

            /* FIND VALID DESSERTS */
            for(i = 0; i < recipeCount; i++)
            {
                totalCal = 0;
                
                if(strcmp(recipeList[i].nClassification, "dessert") == 0)
                {
                    for(j = 0; j < recipeList[i].ingreCount; j++)
                    {
                        cal = 0;
                        found = 0;
                        
                        for(k = 0; k < foodCount && found == 0; k++)
                        {
                            if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                      foodList[k].FoodItem) == 0)
                            {
                                cal = (recipeList[i].ingredientsList[j].Qty /
                                       foodList[k].Qty) * foodList[k].Calories;
                                found = 1;
                            }
                        }
                        
                        totalCal += cal;
                    }

                    if(mainCal + starterCal + totalCal <= calIntake)
                    {
                        validDessertIdx[validDessertCount] = i;
                        validDessertCount++;
                    }
                }
            }

            if(validDessertCount > 0)
            {
                dessertRecomm = validDessertIdx[giveRandomInt(validDessertCount)];

                dessertCal = 0;
                for(j = 0; j < recipeList[dessertRecomm].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[dessertRecomm].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[dessertRecomm].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }
                    
                    dessertCal += cal;
                }
            }

            printf("\nRECOMMENDED MENU:\n");
            printf("Target Calories: %d\n", calIntake);
            printf("Total Menu Calories: %d\n", starterCal + mainCal + dessertCal);

            /* DISPLAY STARTER FIRST */
            if(starterRecomm != -1)
            {
                printf("\n=====================================\n");
                printf("STARTER\n");
                printf("%s %d servings %d calories\n",
                       recipeList[starterRecomm].nDishName,
                       recipeList[starterRecomm].servingSize,
                       starterCal);

                printf("\nIngredients:\n");
                for(j = 0; j < recipeList[starterRecomm].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[starterRecomm].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[starterRecomm].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }

                    printf("%.0lf %s %-15s %d calories\n",
                           recipeList[starterRecomm].ingredientsList[j].Qty,
                           recipeList[starterRecomm].ingredientsList[j].UnitofMeas,
                           recipeList[starterRecomm].ingredientsList[j].FoodItem,
                           cal);
                }

                printf("\nProcedure:\n");
                for(j = 0; j < recipeList[starterRecomm].stepCount; j++)
                {
                    printf("%d. %s\n", j + 1,
                           recipeList[starterRecomm].stepsList[j].directions);
                }
            }

            /* DISPLAY MAIN SECOND */
            if(mainRecomm != -1)
            {
                printf("\n=====================================\n");
                printf("MAIN COURSE\n");
                printf("%s %d servings %d calories\n",
                       recipeList[mainRecomm].nDishName,
                       recipeList[mainRecomm].servingSize,
                       mainCal);

                printf("\nIngredients:\n");
                for(j = 0; j < recipeList[mainRecomm].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[mainRecomm].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[mainRecomm].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }

                    printf("%.0lf %s %-15s %d calories\n",
                           recipeList[mainRecomm].ingredientsList[j].Qty,
                           recipeList[mainRecomm].ingredientsList[j].UnitofMeas,
                           recipeList[mainRecomm].ingredientsList[j].FoodItem,
                           cal);
                }

                printf("\nProcedure:\n");
                for(j = 0; j < recipeList[mainRecomm].stepCount; j++)
                {
                    printf("%d. %s\n", j + 1,
                           recipeList[mainRecomm].stepsList[j].directions);
                }
            }

            /* DISPLAY DESSERT THIRD */
            if(dessertRecomm != -1)
            {
                printf("\n=====================================\n");
                printf("DESSERT\n");
                printf("%s %d servings %d calories\n",
                       recipeList[dessertRecomm].nDishName,
                       recipeList[dessertRecomm].servingSize,
                       dessertCal);

                printf("\nIngredients:\n");
                for(j = 0; j < recipeList[dessertRecomm].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    
                    for(k = 0; k < foodCount && found == 0; k++)
                    {
                        if(strcmp(recipeList[dessertRecomm].ingredientsList[j].FoodItem,
                                  foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[dessertRecomm].ingredientsList[j].Qty /
                                   foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }

                    printf("%.0lf %s %-15s %d calories\n",
                           recipeList[dessertRecomm].ingredientsList[j].Qty,
                           recipeList[dessertRecomm].ingredientsList[j].UnitofMeas,
                           recipeList[dessertRecomm].ingredientsList[j].FoodItem,
                           cal);
                }

                printf("\nProcedure:\n");
                for(j = 0; j < recipeList[dessertRecomm].stepCount; j++)
                {
                    printf("%d. %s\n", j + 1,
                           recipeList[dessertRecomm].stepsList[j].directions);
                }
            }
        }
    }
}


/*
===============================
|            BONUS            |
===============================
*/
//	KEIONNA
void 
AsortRecipe(nRecipe recipeList[], 
            int recipeCount)
{
    int i, j, max;
    nRecipe temp;
    
    for(i = 0; i < recipeCount - 1; i++)
    {
        max = i;
        
        for(j = i + 1; j < recipeCount; j++)
        {
            if(strcmp(recipeList[max].nClassification, recipeList[j].nClassification) < 0)
            {
                max = j;
            }
        }
        
        if(i != max)
        {
            temp = recipeList[i];
            recipeList[i] = recipeList[max];
            recipeList[max] = temp;
        }
    }
}

void 
AlistviewRecipee(nRecipe recipeList[], 
                 int recipeCount, nFoodInfo foodList[], 
                 int foodCount)
{
    int i=0, j, k;
    int choice1;
    int totalCal, found, foundRecipe=0;
    int page=0;
    double cal;
    char choice = 'N';

        
    printf("\n[1] List all recipes by category");
    printf("\n[2] View recipes by category");
    printf("\nEnter: ");
    scanf("%d", &choice1);
    
    if(choice1==1)
    {
        AsortRecipe(recipeList, recipeCount);
        printf("\nALL RECIPES BY CATEGORY");

        if(foundRecipe==1)
        {
            for(i = 0; i < recipeCount; i++)
            {
                printf("\n%s: %s\n", recipeList[i].nClassification, recipeList[i].nDishName);
            }
        }
        
        if(foundRecipe == 0)
        {
            printf("\nNo recipes available.\n");
        }

    }
    else if(choice1==2)
    {
        while(page >= 0 && page <= 2 && (choice == 'N' || choice == 'n' || choice == 'P' || choice == 'p'))
        {
            printf("\n=====================================\n");
            
            if (page == 0)
                printf("STARTER RECIPES\n");
            else if (page == 1)
                printf("MAIN COURSES\n");
            else
                printf("DESSERT RECIPES\n");
            
            printf("=====================================\n");
            
            foundRecipe = 0;
            
            for (i = 0; i < recipeCount; i++)
            {
                if ((page == 0 && strcmp(recipeList[i].nClassification, "starter") == 0) ||
                    (page == 1 && strcmp(recipeList[i].nClassification, "main") == 0) ||
                    (page == 2 && strcmp(recipeList[i].nClassification, "dessert") == 0))
                {
                    foundRecipe = 1;
                    totalCal = 0;
                    
                    for(j = 0; j < recipeList[i].ingreCount; j++)
                    {
                        cal = 0;
                        found = 0;
                        
                        for(k = 0; k < foodCount && found == 0; k++)
                        {
                            if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                      foodList[k].FoodItem) == 0)
                            {
                                cal = (recipeList[i].ingredientsList[j].Qty /
                                       foodList[k].Qty) * foodList[k].Calories;
                                found = 1;
                            }
                        }
                        
                        totalCal += cal;
                    }
                    
                    printf("\n%s %d servings %d calories\n",
                           recipeList[i].nDishName,
                           recipeList[i].servingSize,
                           totalCal);
                    
                    printf("\nIngredients:\n");
                    for(j = 0; j < recipeList[i].ingreCount; j++)
                    {
                        cal = 0;
                        found = 0;
                        
                        for(k = 0; k < foodCount && found == 0; k++)
                        {
                            if(strcmp(recipeList[i].ingredientsList[j].FoodItem,
                                      foodList[k].FoodItem) == 0)
                            {
                                cal = (recipeList[i].ingredientsList[j].Qty /
                                       foodList[k].Qty) * foodList[k].Calories;
                                found = 1;
                            }
                        }
                        
                        printf("%.0lf %s %-15s %.0lf calories\n",
                               recipeList[i].ingredientsList[j].Qty,
                               recipeList[i].ingredientsList[j].UnitofMeas,
                               recipeList[i].ingredientsList[j].FoodItem,
                               cal);
                    }
                    
                    printf("\nProcedure:\n");
                    for(j = 0; j < recipeList[i].stepCount; j++)
                    {
                        printf("%d. %s\n", j + 1,
                               recipeList[i].stepsList[j].directions);
                    }
                    
                    printf("\n=====================================\n");
                }
            }
            
            if (foundRecipe == 0)
            {
                printf("\nNo recipes available in this category.\n");
            }

            printf("\nPress N to view next category.");
            printf("\nPress P to view previous category.");
            printf("\nPress X to exit.");
            printf("\nEnter: ");
            scanf(" %c", &choice);
            
            if(choice == 'N' || choice == 'n')
            {
                if(page < 2)
                    page++;
                else
                    printf("\nTHIS IS THE LAST CATEGORY!\n");
            }
            else if(choice == 'P' || choice == 'p')
            {
                if(page > 0)
                    page--;
                else
                    printf("\nTHIS IS THE FIRST CATEGORY!\n");
            }
        }
    }
    else
    {
        printf("\n\nINVALID OPTION.");
    }
    
    printf("\n");
}

//LANA 

/*
 ratingIndex searches for a dish in the rating list
 
 @param ratingList - array of nRating containing rating records
 @param ratingCount - number of ratings stored
 @param dishName - name of the dish to search
 
 @return index of the dish if found, otherwise -1
 
 Pre-condition: ratingList contains valid data
*/
int ratingIndex (nRating ratingList[], int ratingCount, char dishName[])
{
	int i;
	int idx = -1;
	
	for (i = 0; i < ratingCount; i++)
	{
		if(strcmp(ratingList[i].dishName, dishName) == 0)
		{
			idx = i;
		}
	}
	return idx;
}

/*
 getAvgRating computes the average rating of a dish
 
 @param rating - nRating structure containing total rating and count
 
 @return average rating (double)
 
 Pre-condition: rating contains valid rating data
*/

double getAvgRating(nRating rating)
{
	double avg;
	
	if(rating.ratingCount == 0)
	{
		avg = 0.0;
	}
	else 
	{
		avg = (double)rating.totalRating / rating.ratingCount;
	}
	
	return avg;
}

/*
 rateRecipe allows the user to rate a selected recipe
 
 @param recipeList - array of recipes
 @param recipeCount - number of recipes
 @param ratingList - array storing rating data
 @param ratingCount - pointer to number of ratings
 
 Pre-condition: recipeList contains at least one recipe
 Post-condition: rating is added or updated in ratingList
*/
void 
rateRecipe(nRecipe recipeList[], int recipeCount, nRating ratingList[], int *ratingCount)
{
	str20 dishName;
	int idx;
	int rIdx;
	int rating;
	
	if(recipeCount == 0)
	{
		printf("\nNo recipes recorded.\n");
	}
	else
	{
		listRecipe(recipeList, recipeCount);
		
		printf("\nEnter Recipe Name for Rating: ");
		getchar();
		readInput(dishName, 21);
		
		searchRecipe(recipeList, recipeCount, dishName, &idx);
		
		if(idx == -1)
		{
			printf("\nRecipe not found.\n");
		}
		else
		{
			do
			{
				printf("How was the recipe (1 to 5): ");
				scanf("%d", &rating);
				
				if (rating < 1 || rating > 5)
				{
					printf("Invalid Rating.\n");
				}
			} while (rating < 1 || rating > 5);
			
			rIdx = ratingIndex(ratingList, *ratingCount, dishName);
			
			if(rIdx == -1)
			{
				strcpy(ratingList[*ratingCount].dishName, dishName);
				ratingList[*ratingCount].totalRating = rating;
				ratingList[*ratingCount].ratingCount = 1;
				
				(*ratingCount)++;
			}
			else 
			{
				ratingList[rIdx].totalRating += rating;
				ratingList[rIdx].ratingCount++;
			}
			printf("\nRecipe has been successfully recorded!\n");
		}
		
	}
}

/*
 viewRatings displays all recipes with their average rating and count
 
 @param ratingList - array of ratings
 @param ratingCount - number of ratings stored
 
 Pre-condition: ratingList contains valid data
*/

void 
viewRatings(nRating ratingList[], int ratingCount)
{
	int i;
	double avg;
	
	if(ratingCount == 0)
	{
		printf("\nNo ratings yet.\n");
	}
	else 
	{
		printf("\n=====================================================\n");
		printf("| %-20s | %-10s | %-10s |\n", "Dish", "Average", "Count");
		printf("=====================================================\n");
		
		for(i = 0; i < ratingCount; i++)
		{
			avg = getAvgRating(ratingList[i]);
			
			printf("| %-20s | %-10.2lf | %-10d |\n", 
				   ratingList[i].dishName,
				   avg,
				   ratingList[i].ratingCount);
		}
		
		printf("=====================================================\n");
	}
}

/*
 topRated finds and displays the dish with the highest average rating
 
 @param ratingList - array of ratings
 @param ratingCount - number of ratings
 
 Pre-condition: ratingList contains valid data
*/

void topRated(nRating ratingList[], int ratingCount)
{
	int i;
	int best = 0;
	int found = 0;
	double bestAvg = 0.0;
	double curr; //the current rating of a dish/recipe
	
	if(ratingCount == 0)
	{
		printf("No ratings yet.\n");
	}
	else
	{
		for(i = 0; i < ratingCount; i++)
		{
			curr = getAvgRating(ratingList[i]);
			
			if(found == 0 || curr > bestAvg)
			{
				bestAvg = curr;
				best = i;
				found = 1;
			}
		}
		if(found == 0)
		{
			printf("\nNo ratings yet.\n");
		}
		else
		{
			printf("\nTop Rated Dish: %s\n", ratingList[best].dishName);
			printf("Average Rating: %.2lf\n", bestAvg);
			printf("Number of Ratings: %d\n", ratingList[best].ratingCount);
		}
   }
} 

/*
===============================
|          MAIN PROG          |
===============================
*/

int 
main(void)
{
    int ProgramRuns = 1;
    char nChoice;
    nFoodInfo foodList[100];
    int foodCount = 0;
    
    nRecipe recipeList[MAX_RECIPES];
    int recipeCount = 0;
    
    nRating ratingList[MAX_RECIPES];
    int ratingCount = 0;
    
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
                            case '1': // Add food calorie info
                                addFoodInfo(foodList, &foodCount);
                                break;
                                
                            case '2': // View food calorie
                                viewFoodInfo(foodList, foodCount);
                                break;
                                
                            case '3': //Save Calorie info
                                saveFoodInfo(foodList, foodCount);
                                break;
                                
                            case '4': //Load Calorie info
                                loadFoodInfo(foodList, &foodCount);
                                break;
                                
                            case '5': //Add recipe
                                addRecipe(recipeList, &recipeCount);
                                break;
                                
                            case '6': // MODIFY RECIPE MENU
                            {
                                str20 dishName;
                                int nRep;
                                char NewChoice;
                                int inModifyChoice = 1;
                                
                                if (recipeCount == 0)
                                {
                                    printf("\nNo recipes Available.\n\n");
                                }
                                else
                                {
                                    listRecipe(recipeList, recipeCount);
                                    printf("\n----- MODIFY RECIPE -----\n");
                                    printf("RECIPE NAME: ");
                                    getchar();
                                    readInput(dishName, 21);
                                    
                                    searchRecipe(recipeList, recipeCount, dishName, &nRep);
                                    
                                    if(nRep != -1)
                                    {
                                        while(inModifyChoice)
                                        {
                                            displayModifyRecipe(&NewChoice);
                                            
                                            switch(NewChoice)
                                            {
                                                case '1': // ADD INGREDIENTS
                                                {    
                                                    char nChoice = 'Y';
                                                    while ((nChoice == 'Y' || nChoice == 'y') && recipeList[nRep].ingreCount < MAX_INGREDIENTS)
                                                    {       
                                                        addIngre(&recipeList[nRep]);
                                                        
                                                        if(recipeList[nRep].ingreCount < MAX_INGREDIENTS)
                                                        {
                                                            printf("\nAdd another ingredient? (Y or N): ");
                                                            scanf(" %c", &nChoice);
                                                        }
                                                        else
                                                        {
                                                            printf("\nIngredients list has reached its max! Stop!\n");
                                                            nChoice = 'N';
                                                        }
                                                    }
                                                } 
                                                break;
                                                
                                                case '2': // DELETE INGREDIENT
                                                    deleteIngre(&recipeList[nRep]);
                                                    break;
                                                
                                                case '3': // ADD STEP
                                                {
                                                    char nChoice = 'Y';
                                                    while ((nChoice == 'Y' || nChoice == 'y') && recipeList[nRep].stepCount < MAX_STEPS)
                                                    { 
                                                        addStep(&recipeList[nRep]);
                                                        
                                                        if(recipeList[nRep].stepCount < MAX_STEPS)
                                                        { 
                                                            printf("\nAdd another step? (Y or N): ");
                                                            scanf(" %c", &nChoice);
                                                        }
                                                        else
                                                        { 
                                                            printf("\nToo many steps added! Limit has been reached!\n");
                                                            nChoice = 'N';
                                                        }
                                                    } 
                                                }
                                                break;
                                                
                                                case '4': // DELETE STEP
                                                    deleteStep(&recipeList[nRep]);
                                                    break;
                                                
                                                case 'R':
                                                case 'r':
                                                    inModifyChoice = 0;
                                                    break;
                                                
                                                default:
                                                    printf("\nINVALID! Try again.\n");
                                                    break;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                            
                            case '7': //DELETE RECIPE
                                delRecipe(recipeList,&recipeCount);
                                break;
                                
                            case '8': //LIST RECIPE TITLES
                                listRecipe(recipeList, recipeCount);
                                break;
                                
                            case '9': // SCAN RECIPES
                                sortRecipe(recipeList, recipeCount);
                                scanRecipe(recipeList, recipeCount, foodList, foodCount);
                                break;
                                
                            //SEARCH RECIPE FUNCTION
                            case 'S':
                            case 's':
                            {
                                str20 dishName;
                                int nRep;
                                int i;
                                
                                printf("\n-----SEARCH RECIPE-----\n");
                                listRecipe(recipeList, recipeCount); 
                                
                                printf("RECIPE NAME: ");
                                getchar();
                                readInput(dishName, 21);
                                
                                searchRecipe(recipeList, recipeCount, dishName, &nRep);
                                
                                if(nRep != -1)
                                {
                                    printf("\n=====================================\n");
                                    printf("Recipe Name/s: %s\n", recipeList[nRep].nDishName);
                                    printf("Serving Size: %d\n", recipeList[nRep].servingSize);
                                    printf("Classification: %s\n", recipeList[nRep].nClassification);
                                    
                                    printf("\nIngredients: %d\n", recipeList[nRep].ingreCount);
                                    for (i = 0; i < recipeList[nRep].ingreCount; i++)
                                    {
                                        printf("%2.lf %s %s\n",
                                               recipeList[nRep].ingredientsList[i].Qty,
                                               recipeList[nRep].ingredientsList[i].UnitofMeas,
                                               recipeList[nRep].ingredientsList[i].FoodItem);
                                    }
                                    printf("\nSteps: %d\n", recipeList[nRep].stepCount);
                                    for(i = 0; i < recipeList[nRep].stepCount; i++)
                                    {
                                        printf("%d. %s\n", i + 1, recipeList[nRep].stepsList[i].directions);
                                    }
                                    
                                    printf("\n=====================================\n");
                                }
                                else
                                {
                                    printf("\nRecipe is not here.\n");
                                }
                            }
                            break;
                            
                            //EXPORT RECIPE
                            case 'E':
                            case 'e':
                            {
                            	listRecipe(recipeList, recipeCount);
                            	char filename[50];
								printf("Name filename to export: ");
								
								getchar();
								readInput(filename, 50);
								
								exportRecipe(recipeList, recipeCount, filename);
                            }
                            break;
                            
                            //IMPORT RECIPE
                            case 'I':
                            case 'i':
                            {
                                char filename[50];
                                
								printf("Enter filename to import: ");
								getchar();
								readInput(filename, 50);
								
								importRecipe(recipeList, &recipeCount, filename);
                            }
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
                        case '1': //IMPORT RECIPE
                        {
                            char filename[50];
                                
							printf("Enter filename to import: ");
							getchar();
							readInput(filename, 50);
								
							importRecipe(recipeList, &recipeCount, filename);
                        }
                        break;
                        
                        case '2': //SCAN RECIPE
                            sortRecipe(recipeList, recipeCount);
                            scanRecipe(recipeList, recipeCount, foodList, foodCount);
                            break;
                        
                        case '3': //SEARCH RECIPE BY TITLE
                        {
                            str20 dishName;
                            int nRep;
                            
                            printf("\n-----SEARCH RECIPE-----\n");
                            printf("RECIPE NAME: ");
                            scanf(" %20[^\n]", dishName);
                            
                            searchRecipe(recipeList, recipeCount, dishName, &nRep);
                            
                            if(nRep != -1)
                            {
                                printf("\nRecipe Found!\n");
                            }
                            else
                            {
                                printf("\nRecipe Is not here.\n");
                            }
                        }
                        break;
                        
                        case '4': //GENERATE SHOPPING LIST
					    	AgenList(recipeList, recipeCount);
						    break;
                        
                        case '5': //SCAN RECIPE BY INGREDIENT
                        {
                            char ingredient[21];
                            
                            printf("Enter Ingredient Name: ");
                            getchar();
                            readInput(ingredient, 21);
                            
                            AscanRecIngre(recipeList, recipeCount, ingredient, foodList, foodCount);
                        }
                        break;
                        
                        case '6': //RECOMMEND MENU
                            //srand((unsignd int)time(NULL));
                            Arecommend(recipeList, recipeCount, foodList, foodCount);
                            break;
                        
                        case 'L':
                        case 'l':
                            AlistviewRecipee(recipeList, recipeCount, foodList, foodCount);
                            break;
                        
                        case '7':
                            rateRecipe(recipeList, recipeCount, ratingList, &ratingCount);
                            break;
                            
                        case '8':
                            viewRatings(ratingList, ratingCount);
                            break;
                            
                        case '9':
                            topRated(ratingList, ratingCount);
                            break;
                        
                        case 'R': // RETURN BACK TO MAIN MENU
                        case 'r':
                            InAccessChoice = 0;
                            break;
                        
                        default:
                            printf("INVALID\n\n");
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
