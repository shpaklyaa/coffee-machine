#include "menu.h"

int Menu::numberName()
{
    int input;
    std::cout << "Введите номер напитка: ";
    std::cin >> input;
    return input;
}

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

bool Menu::canPrepareRecipe(const Order& order, const Recipe& recipe) {
    auto recipeIngredients = recipe.getIngredients();
    auto orderIngredients = order.getIngredients();
    for (const auto& ingredient : recipeIngredients) {
        const auto& name = ingredient.first;
        unsigned requiredAmount = ingredient.second;

        if (orderIngredients.find(name) == orderIngredients.end() || orderIngredients[name] < requiredAmount) {
            return false;
        }
    }
    return true;
}
void Menu::start(std::vector<Recipe> r, CoffeeMachine &cm)
{
    while (true)
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

        std::cout << "+-------------------------------------------------------------------+" << std::endl;
        for (size_t i = 0; i < r.size(); i++)
        {
            std::cout << "| " << i + 1 << ". " << r[i].getName() << std::endl;
        };
        std::cout << "+-------------------------------------------------------------------+" << std::endl;

        Order order;
        bool recipeFound = false;
        for (const Recipe& recipe : r) {
            if (canPrepareRecipe(order, recipe)) {
                int totalPreparationTime = cm.prepareCoffee(recipe);
                std::cout << "Приготовление: " << recipe.getName() 
                          << " (Итоговое время: " << totalPreparationTime 
                          << " секунд)" << std::endl;
                recipeFound = true;
                break;
            }
        }

        if (!recipeFound) {
            std::cout << "Ошибка: такой рецепт неизвестен или недостаточно ингредиентов." << std::endl;
        }  
        // std::cout << "+------------------+" << std::endl;
        // std::cout << "| Выберете напиток:|" << std::endl;
        // std::cout << "+------------------+" << std::endl;
        // int input;
        // std::cin >> input;

        // if (input < 1 && input > r.size())
        // {
        //     break;
        // }
        // std::string name = searchName(r, input);
        // std::cout << "+-------------------------------------------------------------------+" << std::endl;
        // std::cout << "| Вы выбрали: " << name << std::endl;
        // std::cout << "| Время изготовления: " << cm.prepareCoffee(r[input - 1]) << " сек" << std::endl;
        // std::cout << "+-------------------------------------------------------------------+" << std::endl;

        // std::cout << "+-------------------+" << std::endl;
        // std::cout << "| Повторить (1/0)?  |\n";
        // std::cout << "+-------------------+" << std::endl;
        // std::cin >> off;

        // if (off == "0")
        // {
        //     std::cout << "+-------------------+" << std::endl;
        //     std::cout << "|  Машина выключена.|" << std::endl;
        //     std::cout << "+-------------------+" << std::endl;
        //     break;
        // }
        // else if (off == "1")
        // {
        //     continue;
        // }
        // else
        // {
        //     std::cout << "+-------------------+" << std::endl;
        //     std::cout << "|      Ошибка!      |" << std::endl;
        //     std::cout << "+-------------------+" << std::endl;
        //     break;
        // }
    }
}