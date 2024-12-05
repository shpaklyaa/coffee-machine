#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include "ingredients.h"
#include "recipes.h"
#include "order.h"
#include "parser.h"
#include "order_parser.h"
#include <cstdlib>
#include <ctime>

// Класс кофемолка
class CoffeeGrinder
{
public:
    void grind(CoffeeBeans &c); // помол
};

// Класс "группа"
class Group
{
public:
    void boil(CoffeeBeans &c); // варкa
};

// Класс бойлер
class Boiler
{
public:
    void heat(Water &w); // нагрев
};

// Класс форсунок
class Nozzle
{
public:
    void heat(WetIngredient &ingredient); // нагрев
    void mix(DryIngredient &ingredient);  // размешать
};

// Класс кофемашины целиком
class CoffeeMachine
{
private:
    CoffeeGrinder grinder;
    Group group;
    Boiler boiler;
    Nozzle nozzle;

public:
    bool found = false;
    int prepareCoffee(const Recipe &r);
    //auto checkRecipe(Recipe &r, Order &o);
};

#endif
