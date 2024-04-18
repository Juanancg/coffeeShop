#ifndef COFFEESHOP_SRC_TYPES_ORDER_H
#define COFFEESHOP_SRC_TYPES_ORDER_H

#include <memory>

#include "Beverage.h"

class Order
{
public:
    Order(std::unique_ptr<Beverage> drink);
    ~Order() = default;

    /**
     * @brief Convert to std::string follow by ; the info of the beverage of the order
     *
     * @return std::string
     */
    std::string ToString() const;

    /**
     * @brief Print the contents of the beverage
     */
    void Print() const;

private:
    std::unique_ptr<Beverage> beverage_;
};

#endif // COFFEESHOP_SRC_TYPES_ORDER_H