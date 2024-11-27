#include <iostream>
#include <map>
#include <string>

#include "recipe.h"

void Recipe::setName(std::string newName)
{
    name = newName;
}

std::string Recipe::getName()
{
    return name;
}

void Recipe::setIngredients(std::map<std::string, int> newIngredients)
{
    ingredients = newIngredients;
}

auto Recipe::getIngredients()
{
    return ingredients;
}