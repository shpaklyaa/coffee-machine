#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <iostream>
#include <string>

class Ingredient
{
private:
    int amount;
    int temperature;
    int time;

public:
    Ingredient() : amount(0), temperature(24), time(0) {}

    void setAmount(const int newAmount);
    int getAmount();

    void setTemp(const int newTemperature);
    int getTemp();

    void setTime(const int newTime);
    int getTime();
};

class DryIngredient : public Ingredient
{
};

class WetIngredient : public Ingredient
{
};

class Milk : public WetIngredient
{
};

class Cream : public WetIngredient
{
};

class Water : public WetIngredient
{
};

class Sugar : public DryIngredient
{
};

class CoffeeBeans : public DryIngredient
{
private:
    bool is_grinded;

public:
    CoffeeBeans() : is_grinded(false) {}
    void setStatus(bool s);
    bool getStatus() const;
};

#endif