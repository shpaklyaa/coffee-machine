#include "coffee_machine.h"

void CoffeeGrinder::grind(CoffeeBeans &c)
{
    int time = 14 + rand() % (19 - 14 + 1);
    c.setTime(c.getTime() + time);
    c.setStatus(true);
}

void Group::boil(CoffeeBeans &c)
{
    if (c.getStatus())
    {
        int time = 19 + rand() % (24 - 19 + 1);
        c.setTime(c.getTime() + time);
    }
    else
    {
        return;
    }
}

void Boiler::heat(Water &w)
{
    int toAdd = 100 - w.getTemperature();
    w.setTemperature(w.getTemperature() + toAdd);
    w.setTime(w.getTime() + toAdd);
}

void Nozzle::heat(WetIngredient &wi)
{
    int toAdd = (65 + rand() % (70 - 65 + 1)) - wi.getTemperature();
    wi.setTemperature(wi.getTemperature() + toAdd);
    wi.setTime(wi.getTime() + toAdd);
}

void Nozzle::mix(DryIngredient &di)
{
    di.setTime(di.getTime() + 10);
}

int CoffeeMachine::prepareCoffee(const Recipe &r)
{
    r.getIngredients();
    int allTime = 0;
    for (auto ingredient : r.getIngredients())
    {
        if (ingredient.first == "milk" || ingredient.first == "cream")
        {
            srand(time(NULL));
            for (int i = 0; i < ingredient.second; i++)
            {
                Milk milk;
                nozzle.heat(milk);
                allTime += milk.getTime();
            }
        }
        else if (ingredient.first == "coffee")
        {
            srand(time(NULL));
            for (int i = 0; i < ingredient.second; i++)
            {
                CoffeeBeans cb;
                grinder.grind(cb);
                group.boil(cb);
                allTime += cb.getTime();
            }
        }
        else if (ingredient.first == "water")
        {
            for (int i = 0; i < ingredient.second; i++)
            {
                Water w;
                boiler.heat(w);
                allTime += w.getTime();
            }
        }
        else if (ingredient.first == "sugar")
        {
            for (int i = 0; i < ingredient.second; i++)
            {
                DryIngredient sugar;
                nozzle.mix(sugar);
                allTime += sugar.getTime();
            }
        }
    }
    return allTime;
}

//  auto checkRecipe(Recipe &r, Order &o) {
//         for (auto ingredient : r.getIngredients()) {
//             for (auto ing : o.getIngredients()) {
//                 if (ingredient.first == "молоко" && ingredient.second == ing.second ||
//                     ingredient.first == "сливки" && ingredient.second == ing.second ||
//                     ingredient.first == "кофе" && ingredient.second == ing.second ||
//                     ingredient.first == "вода" && ingredient.second == ing.second ||
//                     ingredient.first == "сахар" && ingredient.second == ing.second) {
//                         bool flag = true;
//                         return r.getName();
//                 }
//             }
//         }
//     }

// auto checkRecipe(<Recipe>& r, Order &o) {
//     for (size_t i = 0; i < recipes.size(); ++i) {
//         //const Recipe &r = recipes[i];
//         bool flag = true;

//         for (auto ingredient : r.getIngredients()) {
//             bool found = false;
//             for (auto ing : o.getIngredients()) {
//                 if (ingredient.first == ing.first && ingredient.second <= ing.second) {
//                     found = true;
//                     break;
//                 }
//             }
//             if (!found) {  // Если ингредиент не найден
//                 flag = false;
//                 break;
//             }
//         }

//         if (flag) {
//             return i;  // Возвращаем индекс найденного рецепта
//         }
//     }

//     return -1;  // Возвращаем -1, если рецепт не найден
// }
