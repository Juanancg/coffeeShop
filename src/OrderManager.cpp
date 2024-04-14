#include "OrderManager.h"

#include <iostream>

OrderManager::OrderManager()
{
    storage_ = storage::OrderStorageFactory::createParser(storage::OrderStorageFactory::StorageType::DISK);

    storage_->SetSourceDestination("/opt/coffeeShop/build/orders.txt");
}

OrderManager::~OrderManager()
{
}

void OrderManager::RegisterOrder(std::unique_ptr<Beverage> drink)
{
}

void OrderManager::CancelOrder(int index)
{
}