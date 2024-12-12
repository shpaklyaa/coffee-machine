#include "order_parser.h"

void TextOrderParser::parseOrder(std::string filename, std::vector<Order> &o)
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
            continue; // Пропуск пустых строк

        Order order;
        std::map<std::string, unsigned> ingredients;

        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos)
            continue;

        line = line.substr(colonPos + 1); // Убираем название "Заказ:"
        std::istringstream ss(line);
        std::string ingredientPair;

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

        order.setIngredients(ingredients);
        o.push_back(order);
    }
    file.close();
}