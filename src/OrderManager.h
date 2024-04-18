#ifndef COFFEESHOP_SRC_ORDERMANAGER_H
#define COFFEESHOP_SRC_ORDERMANAGER_H

#include <memory>
#include <vector>

#include "types/Order.h"
#include "types/Beverage.h"
#include "storage/OrderStorageFactory.h"

/**
 * @brief Core of the management of the orders. It represents the orders of the CURRENT session
 */
class OrderManager
{
public:
   OrderManager();
   ~OrderManager();

   /**
    * @brief Register the beverage as an order in the internal vector.
    *
    * @param [in] drink unique_ptr beverage
    */
   void RegisterOrder(std::unique_ptr<Beverage> drink);

   /**
    * @brief Cancel one of the orders of the current session. CANT cancel an order of previous sessions
    *
    * @param [in] index
    *
    */
   void CancelOrder(size_t index);

   /**
    * @brief Prints all the orders of the current session
    */
   void PrintOrders() const;

private:
   std::unique_ptr<storage::IOrderStorage> storage_; // Storage where to save the orders
   std::vector<std::shared_ptr<Order>> orders_;      // Vector of orders
   int alltime_order_idx_;                           // Idx of storage
};

#endif // endif COFFEESHOP_SRC_ORDERMANAGER_H