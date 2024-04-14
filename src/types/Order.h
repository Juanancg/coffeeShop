#ifndef COFFEESHOP_SRC_TYPES_ORDER_H
#define COFFEESHOP_SRC_TYPES_ORDER_H

#include <memory>

#include "Beverage.h"

class Order
{
public:
    Order(std::unique_ptr<Beverage> drink);

    ~Order() = default;
    void Print() const;
    bool IsValid() const;

private:
    std::unique_ptr<Beverage> beverage_;
};

#endif // COFFEESHOP_SRC_TYPES_ORDER_H