#ifndef COFFEESHOP_SRC_TYPES_BEVERAGE_H
#define COFFEESHOP_SRC_TYPES_BEVERAGE_H

#include <string>
#include <vector>

class Beverage
{
public:
    Beverage(const std::string &beverage, const std::string &type, const double price, const std::vector<std::string> &extras);
    ~Beverage() = default;

    /**
     * @brief Convert to std::string follow by ; the info of the beverage
     *
     * @return std::string
     */
    std::string ToString() const;

    /**
     * @brief Print the contents of the beverage
     */
    void Print() const;

    std::string GetBeverageMain() const { return beverage_; }
    std::string GetBeverageVariety() const { return type_; }
    double GetPrice() const { return price_; }
    std::vector<std::string> GetExtras() const { return extras_; }
    std::vector<std::string> GetRawRules() const { return rawrules_; }

private:
    std::string beverage_;
    std::string type_;
    double price_;
    std::vector<std::string> extras_;
    std::vector<std::string> rawrules_;
};

#endif // COFFEESHOP_SRC_TYPES_BEVERAGE_H