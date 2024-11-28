#include "ingredients.h"

void Ingredient::setTemperature(int newTemperature)
{
    temperature = newTemperature;
}

int Ingredient::getTemperature() const
{
    return temperature;
}

void Ingredient::setAmount(int newAmount)
{
    amount = newAmount;
}

int Ingredient::getAmount() const
{
    return amount;
}

void Ingredient::setTime(int newTime)
{
    time = newTime;
}

int Ingredient::getTime() const
{
    return time;
}

void CoffeeBeans::setStatus(bool s)
{
    is_grinded = s;
}

bool CoffeeBeans::getStatus() const
{
    return is_grinded;
}