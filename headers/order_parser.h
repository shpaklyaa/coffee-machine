#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>

#include "order.h"

// Интерфейс парсера
class IOrderParser {
public:
    virtual void parse(std::string filename, std::vector<Order>& recipes) = 0;
    virtual ~IOrderParser() {}
};

// Реализация парсера для файлов .txt
class TextOrderParser : public IOrderParser {
public:
    void parse(std::string filename, std::vector<Order>& recipes) override;
};

#endif // PARSER_H