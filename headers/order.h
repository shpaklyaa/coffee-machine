#ifndef ORDER_H
#define ORDER_H

#include <map>
#include <string>


class Order
{
private:
    std::string name;
    std::map<std::string, unsigned> ingredients;

public:
    void setName(std::string n);
    std::string getName() const;
    void setIngredients(std::map<std::string, unsigned> &newIngredients);
    std::map<std::string, unsigned> getIngredients() const;
};

#endif // 
