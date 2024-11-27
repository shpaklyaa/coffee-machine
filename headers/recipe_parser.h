#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

#include "recipe.h"

// class Recipe;

// Интерфейс парсера
class IRecipeParser
{
public:
    virtual void parse(std::string filename, std::vector<Recipe> &recipes) = 0;
    virtual ~IRecipeParser() {}
};

// Реализация парсера для файлов .txt
class TextRecipeParser : public IRecipeParser
{
public:
    void parse(std::string filename, std::vector<Recipe> &recipes) override;
};

#endif