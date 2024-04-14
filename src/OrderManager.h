#ifndef COFFEESHOP_SRC_ORDERMANAGER_H
#define COFFEESHOP_SRC_ORDERMANAGER_H

#include <memory>
#include <vector>

#include "types/Order.h"
#include "types/Beverage.h"
#include "storage/OrderStorageFactory.h"

class OrderManager
{
public:
   OrderManager();
   ~OrderManager();

   void RegisterOrder(std::unique_ptr<Beverage> drink);
   void CancelOrder(int index);
   void PrintOrders() const;

private:
   std::unique_ptr<storage::IOrderStorage> storage_;
   std::vector<std::shared_ptr<Order>> orders_; // TODO Not sure about the property
};

#endif // endif COFFEESHOP_SRC_ORDERMANAGER_H