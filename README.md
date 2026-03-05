# CCPROG2-MACHINEPROJECT
This will be used for the machine project "Meals for Health" in ccprog 

MEMBERS: 
LANA QUIBULOY
KEIONNA JARAMILLO

/*
===============================
|         CONSTANTS            |
===============================
*/
MAX CHARACTERS FOR EACH DISH: 20 CHARACTERS
MAX_INGREDIENTS 20
MAX_STEPS 15

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
|   Preliminary outline of    |
|   functions to be created   |
===============================
*/

// UPDATE
void addFoodInfo(nFoodInfo foodList[], int *foodCount);
void viewFoodInfo(nFoodInfo foodList[], int foodCount);
void saveFoodInfo(nFoodInfo foodList[], int foodCount, char filename[]);
void loadFoodInfo(nFoodInfo foodList[], int *foodCount);
void addRecipe(nRecipe recipeList[], int *recipeCount);
void addIngre(nRecipe *recipe);
void deleteIngre(nRecipe *recipe);
void addStep(nRecipe *recipe);
void deleteStep(nRecipe *recipe);
void modifyRecipe(nRecipe recipeList[], int recipeCount);
void delRecipe(nRecipe recipeList[], int *recipeCount);
void listRecipe(nRecipe recipeList[], int recipeCount);
void scanRecipe(nRecipe recipeList[], int recipeCount, nFoodInfo foodList[], int foodCount);
void searchRecipe(nRecipe recipeList[], int recipeCount, char dishName[], int *nFound);
void exportRecipe(nRecipe recipeList[], int recipeCount, char filename[]);
void importRecipe(nRecipe recipeList[], int *recipeCount, char filename[]);

// ACCESS
void AimportRecipe(nRecipe recipeList[], int *recipeCount, char filename[]);
void AlistRecipe(nRecipe recipeList[], int recipeCount);
void AscanRecipe(nRecipe recipeList[], int recipeCount, nFoodInfo foodList[], int foodCount);
void AsearchRecipe(nRecipe recipeList[], int recipeCount, nFoodInfo foodList[], int foodCount);
void AgenList(nRecipe recipeList[], int recipeCount, int servings);
void AscanRecIngre(nRecipe recipeList[], int recipeCount, char ingredient[]);
void Arecommend(nRecipe recipeList[], int recipeCount, nFoodInfo foodList[], int foodCount, int calIntake);

