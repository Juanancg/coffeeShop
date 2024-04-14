#include "Order.h"

Order::Order(std::unique_ptr<Beverage> drink) : beverage_(std::move(drink))
{
}

void Order::Print() const
{
    beverage_->Print();
}

bool Order::IsValid() const
{
    return beverage_->IsValid();
}