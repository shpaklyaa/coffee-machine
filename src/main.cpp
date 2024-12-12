#include <iostream>
#include "coffee_machine.h"
#include "ingredients.h"
#include "recipes.h"
#include "order.h"
#include "parser.h"
#include "order_parser.h"
#include "menu.h"

using namespace std;

int main()
{
    Menu menu;
    TextRecipeParser parser;
    TextOrderParser orderParser;
    CoffeeMachine cm;
    std::vector<Recipe> r;
    std::vector<Order> o;

    parser.parse("recipes.txt", r);
    orderParser.parseOrder("order.txt", o);
    menu.start(r, cm, o);

    return 0;
}