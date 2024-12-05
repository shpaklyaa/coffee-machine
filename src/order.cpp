#include "order.h"

void Order::setName(std::string n)
{
    name = n;
}

std::string Order::getName() const
{
    return name;
}

void Order::setIngredients(std::map<std::string, unsigned> &newIngredients)
{
    ingredients = newIngredients;
}

std::map<std::string, unsigned> Order::getIngredients() const
{
    return ingredients;
}
