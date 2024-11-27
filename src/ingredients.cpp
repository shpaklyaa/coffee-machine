#include <iostream>
#include "ingredients.h"

void Ingredient::setAmount(const int newAmount)
{
    amount = newAmount;
}

int Ingredient::getAmount()
{
    return amount;
}

void Ingredient::setTemp(const int newTemperature)
{
    temperature = newTemperature;
}

int Ingredient::getTemp()
{
    return temperature;
}

void Ingredient::setTime(const int newTime)
{
    time = newTime;
}

int Ingredient::getTime()
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