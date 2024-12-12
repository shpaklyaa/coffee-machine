#include "parser.h"

void TextRecipeParser::parse(std::string filename, std::vector<Recipe> &r)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos)
            continue;

        Recipe recipe;
        std::string recipeName = line.substr(0, colonPos);
        recipeName.erase(std::remove_if(recipeName.begin(), recipeName.end(), ::isspace), recipeName.end());
        recipe.setName(recipeName);

        line = line.substr(colonPos + 1);
        std::istringstream ss(line);
        std::string ingredientPair;

        std::map<std::string, unsigned> ingredients;
        while (std::getline(ss, ingredientPair, ','))
        {
            size_t nameEnd = ingredientPair.find('(');
            size_t amountEnd = ingredientPair.find(')');

            if (nameEnd == std::string::npos || amountEnd == std::string::npos)
                continue;

            std::string name = ingredientPair.substr(0, nameEnd);
            std::string count = ingredientPair.substr(nameEnd + 1, amountEnd - nameEnd - 1);

            name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
            count.erase(std::remove_if(count.begin(), count.end(), ::isspace), count.end());

            try
            {
                int n = std::stoi(count);
                ingredients[name] = n;
            }
            catch (const std::exception &)
            {
            }
        }

        recipe.setIngredients(ingredients);
        r.push_back(recipe);
    }
    file.close();
}