#ifndef INGREDIENTS_H
#define INGREDIENTS_H

// Класс ингредиентов
class Ingredient {
private:
    int temperature; // температура
    int amount; // количество
    int time; // время, которое они требуют
public:
    Ingredient() : temperature(24), amount(0), time(0) {}
    void setTemperature(int t);
    int getTemperature() const;
    void setAmount(int a);
    int getAmount() const;
    void setTime(int t);
    int getTime() const;
};

// Класс мокрых ингредиентов
class WetIngredient : public Ingredient {
    //
};

// Класс сухих ингредиентов
class DryIngredient : public Ingredient {
    //
};

// Класс кофейных зёрен
class CoffeeBeans : public DryIngredient {
private:
    bool is_grinded;
public:
    CoffeeBeans() : is_grinded(false) {}
    void setStatus(bool s);
    bool getStatus() const;
};

// Класс сахар
class Sugar : public DryIngredient {
    // 
};

// Класс молоко
class Milk : public WetIngredient {
    // 
};

// Класс вода
class Water : public WetIngredient {
    // 
};

#endif // INGREDIENTS_H