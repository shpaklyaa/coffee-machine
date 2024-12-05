    #ifndef MENU_H
    #define MENU_H

    #include <string>
    #include <vector>
    #include <iostream>
    #include <map>

    #include "recipes.h"
    #include "order.h"
    #include "coffee_machine.h"

    // Класс вывода структур данных на экран
    class Print {
    public:
        void printMap(std::map<std::string, unsigned> ingredients);
        void printVector(std::vector<Recipe> r);
    };

    // Класс меню приложения
    class Menu {
    public:
        int numberName();
        std::string searchName(std::vector<Recipe>& r, int& input);
        void start(std::vector<Recipe> r, CoffeeMachine& cm);
    private:
        bool canPrepareRecipe(const Order& order, const Recipe& recipe);
    };

    #endif // MENU_H
