#include "coffee_machine.h"

void CoffeeGrinder::GrindCoffeeBeans(CoffeeBeans &beans)
{
    std::cout << "Сколько порций кофе добавить?" << std::endl;
    std::cin >> coffeeDose;
    std::cout << "Помол кофе в процессе..." << std::endl;
    beans.setTime(beans.getTime() + (14 + rand() % (19 - 14 + 1)) * coffeeDose);
    beans.setStatus(true);
    beans.setAmount(coffeeDose);
    // for (int i = 0; i < coffeeDose; i++)
    // {
    //     machine.time_sum += 14 + rand() % (19 - 14 + 1);
    // }
    std::cout << "Помол кофе завершен!" << std::endl;
}

// void Group::ShowCoffeeDose(CoffeeGrinder &grinder){
//     int coffeeDose = grinder.coffeeDose;
// }

void Group::BrewCoffee(CoffeeBeans &beans)
{
    if (beans.getStatus())

    {
        std::cout << "Варка кофе в процессе..." << std::endl;
        beans.setTime(beans.getTime() + (19 + rand() % (24 - 19 + 1)) * beans.getAmount());
        // for (int i = 0; i < grinder.coffeeDose; i++)
        // {
        //     machine.time_sum += 19 + rand() % (24 - 19 + 1);
        // }
        std::cout << "Кофе готов!" << std::endl;
    }
    else
    {
        std::cout << "system error : code 1" << std::endl;
        return;
    }
}

void Boiler::HeatWater(Water &water)
{
    std::cout << "Сколько порций воды добавить?" << std::endl;
    std::cin >> waterDose;
    std::cout << "Нагрев воды до 100 градусов..." << std::endl;
    int toAdd = 100 - water.getTemp();
    water.setTemp(water.getTemp() + toAdd);
    water.setTime(water.getTime() + toAdd);
    water.setAmount(waterDose);
    std::cout << "Вода нагрета!" << std::endl;
}

void Nozzle::HeatWetIng(WetIngredient &wetIng)
{
    do
    {
        std::cout << "Выберите Молочную добавку:\n";
        std::cout << "1. Молоко\n";
        std::cout << "2. Сливки\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите свой выбор: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Вы выбрали молоко..." << std::endl;
            std::cout << "Сколько порций молока добавить?" << std::endl;
            std::cin >> wetDose;
            std::cout << "Нагрев молока до 65-70 градусов..." << std::endl;
            int toAdd = (65 + rand() % (70 - 65 + 1)) - wetIng.getTemp();
            wetIng.setTemp(wetIng.getTemp() + toAdd * wetDose);
            wetIng.setTime(wetIng.getTime() + toAdd * wetDose);
            wetIng.setAmount(wetDose);
            std::cout << "Молоко готово!" << std::endl;
            break;
        case 2:
            std::cout << "Вы выбрали сливки..." << std::endl;
            std::cout << "Сколько порций сливок добавить?" << std::endl;
            std::cin >> wetDose;
            std::cout << "Нагрев сливок до 65-70 градусов..." << std::endl;
            int toAdd = (65 + rand() % (70 - 65 + 1)) - wetIng.getTemp();
            wetIng.setTemp(wetIng.getTemp() + toAdd * wetDose);
            wetIng.setTime(wetIng.getTime() + toAdd * wetDose);
            wetIng.setAmount(wetDose);
            std::cout << "Молоко нагрелось!" << std::endl;
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }

        if (choice != 0)
        {
            std::cout << "Хотите сделать выбор снова? (1/0): ";
            std::cin >> repeat;
        }
        else
        {
            repeat = '0'; // Если выбрали выход, завершить цикл
        }

    } while (repeat == '1');
}

void Nozzle::MixDryIng(DryIngredient &dryIng)
{
    do
    {
        std::cout << "Выберите добавку:\n";
        std::cout << "1. Сахар\n";
        std::cout << "2. Корица\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите свой выбор: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Вы выбрали сахар..." << std::endl;
            std::cout << "Сколько порций сахара добавить?" << std::endl;
            std::cin >> dryDose;
            std::cout << "Растворение сахара..." << std::endl;
            dryIng.setTime(dryIng.getTime() + 10 * dryDose);
            dryIng.setAmount(dryDose);
            std::cout << "Сахар растворился!" << std::endl;
            break;
            break;
        case 2:
            std::cout << "Вы выбрали корицу..." << std::endl;
            std::cout << "Корица добавлена!" << std::endl;
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }

        if (choice != 0)
        {
            std::cout << "Хотите сделать выбор снова? (1/0): ";
            std::cin >> repeat;
        }
        else
        {
            repeat = '0'; // Если выбрали выход, завершить цикл
        }

    } while (repeat == '1');
}

auto CoffeeMachine::CheckRecipe(Recipe &recipe, Recipe &r)
{
    for (auto ingredient : r.getIngredients())
    {
        if (ingredient.first == "молоко" && ingredient.second == nozzle.wetDose &&
            ingredient.first == "сливки" && ingredient.second == nozzle.wetDose &&
            ingredient.first == "вода" && ingredient.second == boiler.waterDose &&
            ingredient.first == "кофе" && ingredient.second == grinder.coffeeDose &&
            ingredient.first == "ванильный сахар" && ingredient.second == nozzle.dryDose)
        {
            return recipe.getName();
        }
    }
}

int CoffeeMachine::prepareCoffee(Recipe &r)
{
    r.getIngredients();
    int allTime = 0;
    for (auto ingredient : r.getIngredients())
    {
        if (ingredient.first == "молоко" || ingredient.first == "сливки")
        {
            srand(time(NULL));
            for (int i = 0; i < ingredient.second; i++)
            {
                WetIngredient wetIng;
                nozzle.HeatWetIng(wetIng);
                allTime += wetIng.getTime();
            }
        }
        else if (ingredient.first == "кофе")
        {
            srand(time(NULL));
            for (int i = 0; i < ingredient.second; i++)
            {
                CoffeeBeans beans;
                grinder.GrindCoffeeBeans(beans);
                group.BrewCoffee(beans);
                allTime += beans.getTime();
            }
        }
        else if (ingredient.first == "вода")
        {
            for (int i = 0; i < ingredient.second; i++)
            {
                Water water;
                boiler.HeatWater(water);
                allTime += water.getTime();
            }
        }
        else if (ingredient.first == "ванильный сахар")
        {
            for (int i = 0; i < ingredient.second; i++)
            {
                DryIngredient sugar;
                nozzle.MixDryIng(sugar);
                allTime += sugar.getTime();
            }
        }
    }
    return allTime;
}