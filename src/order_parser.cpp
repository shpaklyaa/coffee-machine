#include "order_parser.h"

void TextOrderParser::parseOrder(std::string filename, std::vector<Order> &o)
{
    std::ifstream file;
    file.open(filename);
    std::string line;

    while (std::getline(file, line))
    {
        Order order;
        std::map<std::string, unsigned> ingredients;

        line = line.substr(line.find(':') + 1, line.size());
        std::string name_ing;
        std::string count_ing;
        std::map<std::string, unsigned> ing;
        int count = std::count(line.begin(), line.end(), ',');
        for (int i = 0; i < count + 1; i++)
        {
            name_ing = line.substr(0, line.find('('));
            line = line.substr(line.find('(') + 1, line.size());
            count_ing = line.substr(0, line.find(')'));
            int n = std::stoi(count_ing);
            ing[name_ing] = n;
            if (i < count)
            {
                line = line.substr(line.find(')') + 2, line.size());
            }
        }
        order.setIngredients(ing);
        o.push_back(order);
    }
    file.close();
}