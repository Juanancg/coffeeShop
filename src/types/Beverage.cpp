#include "Beverage.h"

Beverage::Beverage(const std::string &beverage, const std::string &type, const uint price, const std::vector<std::string> &extras)
    : beverage_(beverage), type_(type), price_(price), extras_(extras)
{
}

bool Beverage::IsValid() const
{
    // TODO
    return true;
}

void Beverage::Print() const
{
    // TODO
}