#ifndef COFFEESHOP_SRC_TYPES_BEVERAGE_H
#define COFFEESHOP_SRC_TYPES_BEVERAGE_H

#include <string>
#include <vector>

class Beverage
{
public:
    Beverage(const std::string &beverage, const std::string &type, const uint price, const std::vector<std::string> &extras);
    ~Beverage() = default;

    bool IsValid() const;

    void Print() const;

    std::string GetBeverageMain() const { return beverage_; }
    std::string GetBeverageVariety() const { return type_; }
    uint GetPrice() const { return price_; }
    std::vector<std::string> GetExtras() const { return extras_; }
    std::vector<std::string> GetRawRules() const { return rawrules_; }

private:
    std::string beverage_;
    std::string type_;
    uint price_;
    std::vector<std::string> extras_;
    std::vector<std::string> rawrules_;

    typedef bool (Beverage::*Rulefnc)(const std::string &);
    std::vector<Rulefnc> rules_; // Not sure
};

#endif // COFFEESHOP_SRC_TYPES_BEVERAGE_H