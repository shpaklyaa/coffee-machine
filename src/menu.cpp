#include "menu.h"

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

bool Menu::canPrepareRecipe(const Order &order, const Recipe &recipe)
{
    auto recipeIngredients = recipe.getIngredients();
    auto orderIngredients = order.getIngredients();

    // Проверяем, что все ингредиенты рецепта есть в заказе и в нужном количестве
    for (const auto &ingredient : recipeIngredients)
    {
        const std::string &name = ingredient.first;
        unsigned requiredAmount = ingredient.second;

        // Проверяем, есть ли ингредиент в заказе
        if (orderIngredients.find(name) == orderIngredients.end())
        {
            return false;
        }

        // Проверяем, соответствует ли количество ингредиента
        unsigned availableAmount = orderIngredients.at(name);
        if (availableAmount != requiredAmount)
        {
            return false;
        }
    }

    // Проверяем, что в заказе нет лишних ингредиентов
    for (const auto &ingredient : orderIngredients)
    {
        const std::string &name = ingredient.first;
        if (recipeIngredients.find(name) == recipeIngredients.end())
        {
            return false;
        }
    }

    return true;
}

void Menu::start(std::vector<Recipe> r, CoffeeMachine &cm, std::vector<Order> o)
{
    std::cout << "+-------------------------------------------------------------------+" << std::endl;
    std::cout << "|                          Добро пожаловать!                        |" << std::endl;
    std::cout << "| С помощью нашей кофемашины вы можете сварить себе вкуснейший кофе!|" << std::endl;
    std::cout << "|                             d( > _・ )                            |" << std::endl;
    std::cout << "+-------------------------------------------------------------------+" << std::endl;

    std::string off;
    std::cout << "+---------------+" << std::endl;
    std::cout << "| Начать (1/0)? |\n";
    std::cout << "+---------------+" << std::endl;
    std::cin >> off;
    for (const Order &order : o)
    {
        std::cout << "+-------------------------------------------------------------------+" << std::endl;
        std::cout << "|            Ваш заказ содержит следующие ингредиенты:              |" << std::endl;
        std::cout << "+-------------------------------------------------------------------+" << std::endl;
        for (const auto &ingredient : order.getIngredients())
        {
            std::cout << " - " << ingredient.first << " (" << ingredient.second << ")" << std::endl;
        }

        bool recipeFound = false;
        for (const Recipe &recipe : r)
        {
            if (canPrepareRecipe(order, recipe))
            {
                std::cout << "+-------------------------------------------------------------------+" << std::endl;
                std::cout << "|                Название рецепта: " << recipe.getName() << std::endl;
                std::cout << "+-------------------------------------------------------------------+" << std::endl;
                std::cout << "Ингредиенты рецепта:" << std::endl;
                for (const auto &ingredient : recipe.getIngredients())
                {
                    std::cout << " - " << ingredient.first << " (" << ingredient.second << ")" << std::endl;
                }

                int totalPreparationTime = cm.prepareCoffee(recipe);
                std::cout << "+-------------------------------------------------------------------+" << std::endl;
                std::cout << "Приготовление: " << recipe.getName()
                          << " (Итоговое время: " << totalPreparationTime
                          << " секунд)." << std::endl;
                std::cout << "+-------------------------------------------------------------------+" << std::endl;
                recipeFound = true;
                break;
            }
        }

        if (!recipeFound)
        {
            std::cout << "Ошибка: такой рецепт неизвестен или недостаточно ингредиентов." << std::endl;
        }
    }
}
