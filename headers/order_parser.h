#ifndef ORDER_PARSER_H
#define ORDER_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

#include "order.h"

// Интерфейс парсера
class IOrderParser
{
public:
    virtual void parseOrder(std::string filename, std::vector<Order> &ords) = 0;
    virtual ~IOrderParser() {}
};

// Реализация парсера для файлов .txt
class TextOrderParser : public IOrderParser
{
public:
    void parseOrder(std::string filename, std::vector<Order> &ords) override;
};

#endif // PARSER_H