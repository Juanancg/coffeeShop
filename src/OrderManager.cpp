#include "OrderManager.h"

#include <iostream>

OrderManager::OrderManager() : alltime_order_idx_(0)
{
    storage_ = storage::OrderStorageFactory::CreateStorage(storage::OrderStorageFactory::StorageType::DISK);

    if (storage_->SetSourceDestination("/opt/coffeeShop/build/orders.txt"))
    {
        alltime_order_idx_ = storage_->GetCurrentIdx();
    }
}

OrderManager::~OrderManager()
{
}

void OrderManager::RegisterOrder(std::unique_ptr<Beverage> drink)
{
    std::shared_ptr<Order> order = std::make_shared<Order>(std::move(drink));
    orders_.push_back(order);
    storage_->StoreOrder(order);
}

void OrderManager::CancelOrder(size_t index)
{
    if (index < orders_.size())
    {
        orders_.erase(orders_.begin() + index);

        // try to delete from storage
        storage_->RemoveOrder(alltime_order_idx_ + index);
    }
    else
    {
        std::cout << "Error: Invalid order index." << std::endl;
    }
}

void OrderManager::PrintOrders() const
{
    for (const auto &order : orders_)
    {
        order->Print();
    }
}