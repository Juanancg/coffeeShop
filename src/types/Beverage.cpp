#include "Beverage.h"

#include <sstream>
#include <iostream>

Beverage::Beverage(const std::string &beverage, const std::string &type, const double price, const std::vector<std::string> &extras)
    : beverage_(beverage), type_(type), price_(price), extras_(extras)
{
}

std::string Beverage::ToString() const
{
    std::stringstream ss;
    ss << beverage_ << ";" << type_ << ";";
    for (const auto &extra : extras_)
    {
        ss << extra << "-";
    }
    ss << ";" << price_;
    return ss.str();
}

void Beverage::Print() const
{
    std::cout << beverage_ << ";" << type_ << ";";
    for (const auto &extra : extras_)
    {
        std::cout << extra << "-";
    }

    std::cout << ";" << price_ << std::endl;
}