#include "Order.h"

Order::Order(std::unique_ptr<Beverage> drink) : beverage_(std::move(drink))
{
}

void Order::Print() const
{
    // TODO
    beverage_->Print();
}

bool Order::IsValid() const
{
    // TODO
    return beverage_->IsValid();
}