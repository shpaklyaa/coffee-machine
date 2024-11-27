#ifndef RECIPE_H
#define RECIPE_H

#include <map>
#include <string>

class Recipe
{
private:
    std::string name;
    std::map<std::string, int> ingredients;

public:
    void setName(std::string newName);
    std::string getName();

    void setIngredients(std::map<std::string, int> newIngredients);
    auto getIngredients();
};

#endif