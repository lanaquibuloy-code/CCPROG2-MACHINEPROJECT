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
|         MENU SCREENs       |
===============================

*/
 displayMainMenu displays the main menu and accepts user input to navigate through main menu.
 
 @param nChoice - address where the user option will be stored
 
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
 
 @param nChoice - address where the user option will be stored
 
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
 
 @param nChoice - address where the user option will be stored
 
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
    
    printf("||%-33s||\n", " R. Exit Menu");
    printf("+===================================+\n");
    
    printf("> ");
    scanf(" %c", nChoice);
}

/*
 displayModifyRecipe displays the modify recipe box and accepts user input.
 
 @param nChoice - address where the user option will be stored
 
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
    printf("| %-5s | %-10s | %-20s |\n", "Qty", "Unit", "Ingredient");
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
        
        printf("\nEnter Quantity: ");
        scanf("%lf", &recipe->ingredientsList[nIngre].Qty);
        
        printf("Enter unit of measurement: ");
        getchar();
        readInput(recipe->ingredientsList[nIngre].UnitofMeas, 16);
        
        printf("Enter food item: ");
        readInput(recipe->ingredientsList[nIngre].FoodItem,21);
        
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
    int nStep;
    
    if(recipe->stepCount < MAX_STEPS)
    {
        nStep = recipe->stepCount;
        
        printf("\n\n-----ENTER INSTRUCTIONS-----\n");
        getchar();
        readInput(recipe->stepsList[nStep].directions,71);
        
        recipe->stepCount++;
        
        printf("\nSuccess! New Step added.\n");
        displaySteps(*recipe);
    }
    else
    {
        printf("\nStop! The instructions are too long!\n");
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
    
    if(recipe->ingreCount == 0)
    {
        printf("\nAll ingredients are good!\n");
        
    }
    else
    {
        printf("Enter Ingredient to be deleted (1 to %d): ", recipe->ingreCount);
        scanf("%d", &nIngre);
        
        if (nIngre >= 1 && nIngre <= recipe->ingreCount)
        {
            for (i = nIngre - 1; i < recipe->ingreCount - 1; i++)
            {
                recipe->ingredientsList[i] = recipe->ingredientsList[i + 1];
            }
            recipe->ingreCount--;
            
            printf("\nSuccesfully removed Ingredient!\n");
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
    
    if(recipe->stepCount == 0)
    {
        printf("\nAll steps are sufficient.\n");
    }
    else
    {
        printf("Enter step number to be deleted (1 to %d): ", recipe->stepCount);
        scanf("%d", &nStepNum);
        
        
        if (nStepNum >= 1 && nStepNum <= recipe->stepCount)
        {
            //shifts the list to the left
            for(i = nStepNum - 1; i < recipe->stepCount - 1; i++)
            {
                recipe->stepsList[i] = recipe->stepsList[i + 1];
            }
            
            recipe->stepCount--;
            
            printf("\nStep has been succesfully deleted!\n");
        }
        else {
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

    printf("\nFood item added successfully!\n\n");

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
            
    printf("\nEnter filename('.txt' included): ");
    scanf("%20s", filename);
    
    fp=fopen(filename,"w");

    if (fp!=NULL)
    {
        if(foodCount!=0)
        {
            if(strlen(filename) >= 4 && strcmp(filename + strlen(filename) - 4, ".txt") == 0)
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
                printf("\nSaving Food Information Success!\n\n");
            }
            else
            {
                printf("\nPlease include the .txt extension.\n\n");
            }
        }
        else
        {
            printf("\nNo food item available for saving.\n\n");

        }
    }
    else
    {
        printf("FILE OPENING ERROR.\n");
    }
}

/*
 loadFoodInfo reads a text file inputted by the user and adds it in the foodList array
 
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - address where the number of food items will be stored

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
 writeRecipe writes a recipe’s information to a text file
 
 @param fp - pointer to an open FILE where the recipe will be written
 @param recipe - recipe whose information will be written in the file

 Pre-condition: fp is non null and recipe contains valid data
*/
void 
writeRecipe(FILE *fp, 
            nRecipe recipe)
{
    int i;
    
    //RECIPE NAME
    fprintf(fp, "%s\n", recipe.nDishName);
    
    //SERVING SIZE + CLASSIFICATION
    fprintf(fp, "%d %s\n", recipe.servingSize, recipe.nClassification);
    
    //INGREDIENTS COUNT
    fprintf(fp, "Ingredients %d\n", recipe.ingreCount);
    
    //LIST OF INGREDIENTS
    for (i = 0; i < recipe.ingreCount; i++)
    {
        fprintf(fp, "%.2lf %s %s\n",
        recipe.ingredientsList[i].Qty,
        recipe.ingredientsList[i].UnitofMeas,
        recipe.ingredientsList[i].FoodItem);
    }
    
    //STEPS COUNTER
    fprintf(fp, "STEPS %d\n", recipe.stepCount);
    
    //STEPS LIST
    for(i = 0; i < recipe.stepCount; i++)
    {
        fprintf(fp, "%s\n", recipe.stepsList[i].directions);
    }
}

/*
 readRecipe loads the information from the text file to the nRecipe structure
 
 @param fp - pointer to an open FILE containing the recipe data
 @param recipe - pointer to an nRecipe structure where the data will be stored

 Pre-condition: fp is non null
*/
void 
readRecipe(FILE *fp, 
           nRecipe *recipe)
{
    int j;
    
    //RECIPE NAME
    fscanf(fp, " %[^\n]\n", recipe->nDishName);
    
    //SERVING SIZE + CLASSIFICATION
    fscanf(fp, "%d %s\n", &recipe->servingSize, recipe->nClassification);
    
    //INGREDIENTS COUNT
    fscanf(fp, "%d", &recipe->ingreCount);
    
    //LIST OF INGREDIENTS
    for(j = 0; j < recipe->ingreCount; j++)
    {
        fscanf(fp, "%lf %s %[^\n]\n",
        &recipe->ingredientsList[j].Qty,
        recipe->ingredientsList[j].UnitofMeas,
        recipe->ingredientsList[j].FoodItem);
    }
    
    //STEPS COUNTER
    fscanf(fp, "STEPS %d\n", &recipe->stepCount);
    
    //LIST OF STEPS
    for (j = 0; j < recipe->stepCount; j++)
    {
        fscanf(fp, "%[^\n]\n", recipe->stepsList[j].directions);
    }
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
   
   char FinalName[100];
   
   strcpy(FinalName, filename);
   int len = strlen(FinalName);
   
   if(len < 4 || strcmp(&FinalName[len - 4], ".txt") != 0)
   {
       strcat(FinalName, ".txt");
   }
   
   fp = fopen(FinalName, "w");
   
   if(fp != NULL)
   {
       for (i = 0; i < recipeCount; i++)
       {
           fprintf(fp, "%s\n", recipeList[i].nDishName); //DISH NAME
        fprintf(fp, "%d %s\n", recipeList[i].servingSize, recipeList[i].nClassification); //SERVING SIZE + CLASSIFICATION
        
        fprintf(fp, "%d\n", recipeList[i].ingreCount);
        
        for (j = 0; j < recipeList[i].ingreCount; j++)
        {
            fprintf(fp, "%lf %s %s\n",
              recipeList[i].ingredientsList[j].Qty,
              recipeList[i].ingredientsList[j].UnitofMeas,
              recipeList[i].ingredientsList[j].FoodItem);
       }
       
       fprintf(fp, "%d\n", recipeList[i].stepCount);
       
       for(j = 0; j < recipeList[i].stepCount; j ++)
       {
           fprintf(fp, "%s\n", recipeList[i].stepsList[j].directions);
       }
   }
   
   fclose(fp);
   printf("File has been succesfully exported!\n\n");
    }
    else
    {
        printf("Try again. An error occured exporting the file.\n\n");
    }
}

/*
 importRecipe loads the information from the text file to the nRecipe structure
 
 @param recipeList - array of nRecipe structures where imported data will be stored
 @param recipeCount - int pointer to the current number of recipes which will be updated
 @param filename - name of the file the user wants to import
 
 Pre-condition: there is at least one or more valid recipe and text file exists and follows the correct recipe formatting
*/
void 
importRecipe(nRecipe recipeList[], 
             int *recipeCount, 
             char filename[])
{
    FILE *fp;
    int j;
    
    char FinalName[100];
   
   strcpy(FinalName, filename);
   int len = strlen(FinalName);
   
   if(len < 4 || strcmp(&FinalName[len - 4], ".txt") != 0)
   {
       strcat(FinalName, ".txt");
   }
   
   fp = fopen(FinalName, "r");

    if(fp != NULL)
    {
        while(fscanf(fp, " %20[^\n]\n", recipeList[*recipeCount].nDishName) == 1)
        {
            fscanf(fp, "%d %15s\n",
                   &recipeList[*recipeCount].servingSize,
                   recipeList[*recipeCount].nClassification);

            fscanf(fp, "%d\n", &recipeList[*recipeCount].ingreCount);

            for(j = 0; j < recipeList[*recipeCount].ingreCount; j++)
            {
                fscanf(fp, "%lf %s %s\n",
                       &recipeList[*recipeCount].ingredientsList[j].Qty,
                       recipeList[*recipeCount].ingredientsList[j].UnitofMeas,
                       recipeList[*recipeCount].ingredientsList[j].FoodItem);
            }

            fscanf(fp, "%d\n", &recipeList[*recipeCount].stepCount);

            for(j = 0; j < recipeList[*recipeCount].stepCount; j++)
            {
                fscanf(fp, " %70[^\n]\n",
                       recipeList[*recipeCount].stepsList[j].directions);
            }

            (*recipeCount)++;
        }
        fclose(fp);
        printf("File has been imported succesfully!\n\n");
    }
    else {
        printf("Try again! An error occurred with importing the file.\n\n");
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
         int recipeCount, 
         int servings)
{
    int j;
    int idx;
    
    
    str20 dishName;
    double newQty; // change quantity based on the serving size for the recipe
    
    //USER FIRST PUTS THE NAME OF THE RECIPE
    printf("Enter Recipe Name: ");
    scanf("%20[^\n]", dishName);
    
    //FIND RECIPE USING THE SEARCH RECIPE FUNCTION
    searchRecipe(recipeList,recipeCount,dishName, &idx);
    
    //checks if recipe exists
    if(idx != -1)
    {
        printf("--- SHOPPING LIST---");
        
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
        
        printf("\nBased on %d servings.\n", servings);
    }
    else
    {
        printf("\nRecipe Not Found.\n\n");
    }
}

/*
 AscanRecIngre asks user for an ingredient and shows the recipe information of all recipes its part of
 
 @param recipeList - array of nRecipe structures containing the  recipes
 @param recipeCount - number of recipes
 @param ingredient - string of the ingredient name to search
 
 Pre-condition: at least one valid recipe and ingredient
*/
void 
AscanRecIngre(nRecipe recipeList[], 
              int recipeCount, 
              char ingredient[])
{
    int i;
    int j;
    int foundRecipe = 0; //checks if recipe is there
    int foundIngre;
    
    for(i = 0; i < recipeCount; i++)
    {
         foundIngre = 0;
         
        //runs through the ingredients in the recipe list
        for (j = 0; j < recipeList[i].ingreCount && foundIngre == 0; j++)
        {
            if(strcmp(recipeList[i].ingredientsList[j].FoodItem, ingredient) == 0)
            {
                foundIngre = 1;
            }
            
        }
        
        //ingredient is found in the recipe,
        if(foundIngre == 1)
        {
            printf("%s\n", recipeList[i].nDishName);
            foundRecipe = 1;
        }
    }
    
    //the recipe does not contain the ingredient
    if(foundRecipe == 0)
    {
        printf("No Ingredient is found in the recipe/\n");
    }
}


int 
giveRandomInt(int recipeCount)
{
    int random;
    
    random= rand() % recipeCount;
    
    return random;
}

void 
Arecommend(nRecipe recipeList[], 
           int recipeCount, 
           nFoodInfo foodList[], 
           int foodCount)
{
    int i, j, k;
    int totalCal, cal, found, calIntake;
    int validIdx[recipeCount];
    int validCount = 0;
    int num;

    if (recipeCount == 0)
    {
        printf("\nNo recipes available.\n");
    }
    else
    {
        printf("Enter target calorie intake: ");
        scanf("%d", &calIntake);

        // find main course recipes that's < target calories
        validCount = 0;
        for (i = 0; i < recipeCount; i++)
        {
            totalCal = 0;
            if (strcmp(recipeList[i].nClassification, "main") == 0)
            {
                for (j = 0; j < recipeList[i].ingreCount; j++)
                {
                    cal = 0;
                    found = 0;
                    for (k = 0; k < foodCount && found == 0; k++)
                    {
                        if (strcmp(recipeList[i].ingredientsList[j].FoodItem, foodList[k].FoodItem) == 0)
                        {
                            cal = (recipeList[i].ingredientsList[j].Qty / foodList[k].Qty) * foodList[k].Calories;
                            found = 1;
                        }
                    }
                    totalCal += cal;
                }

                if (totalCal <= calIntake)
                {
                    validIdx[validCount] = i;
                    validCount++;
                }
            }
        }

        if (validCount == 0)
        {
            printf("\nNo main courses available under target calories.\n");
        }
        else
        {
            // choose one random main course
            num = validIdx[giveRandomInt(validCount)];
            totalCal = 0;

            // calculate total cal
            for (j = 0; j < recipeList[num].ingreCount; j++)
            {
                cal = 0;
                found = 0;
                for (k = 0; k < foodCount && found == 0; k++)
                {
                    if (strcmp(recipeList[num].ingredientsList[j].FoodItem, foodList[k].FoodItem) == 0)
                    {
                        cal = (recipeList[num].ingredientsList[j].Qty / foodList[k].Qty) * foodList[k].Calories;
                        found = 1;
                    }
                }
                totalCal += cal;
            }

            // display recipe
            printf("\n=====================================\n");
            printf("%s %d servings %d calories\n", recipeList[num].nDishName, recipeList[num].servingSize, totalCal);

            printf("\nIngredients:\n");
            for (j = 0; j < recipeList[num].ingreCount; j++)
            {
                cal = 0;
                found = 0;
                for (k = 0; k < foodCount && found == 0; k++)
                {
                    if (strcmp(recipeList[num].ingredientsList[j].FoodItem, foodList[k].FoodItem) == 0)
                    {
                        cal = (recipeList[num].ingredientsList[j].Qty / foodList[k].Qty) * foodList[k].Calories;
                        found = 1;
                    }
                }

                printf("%.0lf %s %-15s %d calories\n",
                       recipeList[num].ingredientsList[j].Qty,
                       recipeList[num].ingredientsList[j].UnitofMeas,
                       recipeList[num].ingredientsList[j].FoodItem,
                       cal);
            }

            printf("\nProcedure:\n");
            for (j = 0; j < recipeList[num].stepCount; j++)
            {
                printf("%d. %s\n", j + 1, recipeList[num].stepsList[j].directions);
            }
        }
    }
}


/*
===============================
|            BONUS            |
===============================
*/

/*
 AsortRecipe sorts recipe in descending alphabetical order based on its classification
 
 @param recipeList - array of nRecipe structures containing the recipes
 @param recipeCount - number of recipes
 
 Pre-condition: there is at least one or more valid recipe
*/
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

/*
 AlistviewRecipe asks user whether to list or view recipes based on its classification
 
 @param recipeList - array of nRecipe structures containing the recipes information
 @param recipeCount - number of recipes
 @param foodList - array of nFoodInfo structures that contains food item information
 @param foodCount - number of food items

 Pre-condition: there is at least one or more valid recipe and food information
*/
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



/*
===============================
|         MAIN PROG           |
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
                                case '1':// Add food calorie info
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
                                        int nRep; //the recipe to be modified
                                        char NewChoice;
                                        int inModifyChoice = 1;
                                        
                                        printf("\n----- MODIFY RECIPE -----\n");
                                        printf("RECIPE NAME: ");
                                        scanf(" %20[^\n]", dishName);
                                        
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
                                                                printf("\nAdd another ingredient? (Y or N) ");
                                                                scanf(" %c", &nChoice);
                                                            }
                                                            else
                                                            {
                                                                printf("\nIngredients list has reached it's max!. Stop!\n");
                                                                nChoice = 'N';
                                                            }
                                                            
                                                        }
                                                        
                                                    }
                                                break;
                                                    
                                                    case '2': //DELETE INGRE
                                                       deleteIngre(&recipeList[nRep]);
                                                       break;
                                                    
                                                    case '3': //ADD STEP
                                                    {
                                                        char nChoice = 'Y';
                                                        while ((nChoice == 'Y' || nChoice == 'y') && recipeList[nRep].stepCount < MAX_STEPS)
                                                        {
                                                            addStep(&recipeList[nRep]);
                                                            
                                                            if(recipeList[nRep].stepCount < MAX_STEPS)
                                                            {
                                                                printf("\nAdd another step? (Y or N)\n");
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
                                       else
                                       {
                                           printf("\nRecipe is not here.\n");
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
                                    
                                    //EXPORT RECIPE
                                case 'E':
                                case 'e':
                                    {
                                        char filename[50];
                                        
                                        printf("Enter filename to export: ");
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
                            {
                                int servings;
                                
                                printf("Enter Serving Size: ");
                                scanf("%d", &servings);
                                
                                AgenList(recipeList, recipeCount, servings);
                            }
                                break;
                                
                            case '5': //SCAN RECIPE BY INGREDIENT
                            {
                                char ingredient[21];
                                
                                printf("Enter Ingredient Name: ");
                                scanf(" %20[^\n]", ingredient);
                                
                                AscanRecIngre(recipeList, recipeCount, ingredient);
                            }
                                printf("WALA PA\n");
                                break;
                                
                            case '6': //RECOMMEND MENU
                                srand((unsigned int)time(NULL));
                                Arecommend(recipeList, recipeCount, foodList, foodCount);
                                break;
                            
                            case 'L':
                            case 'l':
                                AlistviewRecipee(recipeList, recipeCount, foodList, foodCount);
                                
                            case 'R': // RETURN BACK TO MAIN MENU
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
