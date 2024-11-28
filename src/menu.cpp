#include "menu.h"
#include "coffee_machine.h"
#include "recipe.h"

std::string Menu::searchName(std::vector<Recipe> &r, int &input)
{
    return r[input - 1].getName();
}

void Print::printMap(std::map<std::string, unsigned> ingredients)
{
    for (auto ingredient : ingredients)
    {
        std::cout << ingredient.first << " " << ingredient.second << ", ";
    }
    std::cout << std::endl;
}

void Print::printVector(std::vector<Recipe> r)
{
    for (size_t i = 0; i < r.size(); i++)
    {
        std::cout << i + 1 << ". " << r[i].getName() << std::endl;
    }
}

void Menu::start(std::vector<Recipe> r, CoffeeMachine &cm)
{
    while (true)
    {
        // printVector(std::vector<Recipe> r);
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+" << std::endl;
        std::cout << "|                                                       Добро пожаловать!                                             |" << std::endl;
        std::cout << "| С помощью нашей кофемашины вы можете сварить себе кофе по уже известному рецепту, либо же попробовать что-то новое! |" << std::endl;
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+" << std::endl;

        std::string off;
        std::cout << "Продолжить (1/0)?\n";
        std::cin >> off;

        if (off == "0")
        {
            std::cout << "Машина выключена.";
            break;
        }
        else if (off == "1")
        {
            continue;
        }
        else
        {
            std::cout << "Хватит баловаться!";
            break;
        }
        for (int i = 0; i < r.size(); ++i)
        {
            cm.prepareCoffee(r[i]);
            // cm.CheckRecipe(recipe[i], r[i]);
        }
    }
}