#include "Order.h"

Order::Order(std::unique_ptr<Beverage> drink) : beverage_(std::move(drink))
{
}

std::string Order::ToString() const
{
    return beverage_->ToString();
}

void Order::Print() const
{
    beverage_->Print();
}
