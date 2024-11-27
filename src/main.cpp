#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipe.h"
#include "recipe_parser.h"

using namespace std;

int main()
{
    TextRecipeParser parser;
    CoffeeMachine cm;
    std::vector<Recipe> r;

    parser.parse("recipes.txt", r);

    return 0;
}