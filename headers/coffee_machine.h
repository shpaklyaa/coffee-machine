#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include "ingredients.h"
#include "recipe.h"
#include "parser.h"

class CoffeeGrinder
{
public:
    int coffeeDose = 0;
    CoffeeMachine machine;
    void GrindCoffeeBeans(CoffeeBeans &beans);
};

class Group
{
public:
    CoffeeMachine machine;
    // void ShowCoffeeDose(CoffeeGrinder &grinder);
    void BrewCoffee(CoffeeBeans &beans);
};

class Boiler
{
private:
    Water water;

public:
    int waterDose = 0;
    CoffeeMachine machine;
    int currentWaterTemperature;
    void HeatWater(Water &water);
};

class Nozzle
{
public:
    int choice = 0;
    char repeat;
    CoffeeMachine machine;
    int currentTemperature;
    int wetDose = 0;
    int dryDose = 0;
    void HeatWetIng(WetIngredient &wetIng);
    void MixDryIng(DryIngredient &dryIng);
};

class CoffeeMachine
{
private:
    CoffeeGrinder grinder;
    Group group;
    Boiler boiler;
    Nozzle nozzle;

public:
    auto CheckRecipe(Recipe &recipe, Recipe &r);
    int prepareCoffee(Recipe &r);
};

#endif