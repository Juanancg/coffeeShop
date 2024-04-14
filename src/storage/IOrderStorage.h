#ifndef COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H
#define COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H

#include <vector>
#include <map>
#include <string>

#include "../types/Order.h"

namespace storage
{

    class IOrderStorage
    {
    public:
        virtual ~IOrderStorage() {}
        virtual bool SetSourceDestination(const std::string &dest) = 0;

        virtual int StoreOrder(const Order &order) = 0;
        virtual bool RemoveOrder(const int index) = 0;

    protected:
        inline static int order_curr_idx_ = 0; // Current index
    };

}

#endif // COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H