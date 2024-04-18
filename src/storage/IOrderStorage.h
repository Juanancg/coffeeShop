#ifndef COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H
#define COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "../types/Order.h"

namespace storage
{

    class IOrderStorage
    {
    public:
        virtual ~IOrderStorage() {}
        virtual bool SetSourceDestination(const std::string &dest) = 0;

        virtual bool StoreOrder(const std::shared_ptr<Order> order) = 0;
        virtual bool RemoveOrder(const int index) = 0;
        virtual int GetCurrentIdx() = 0;

    protected:
        int currentIdx_ = 0;
    };

}

#endif // COFFEESHOP_SRC_STORAGE_IORDERSTORAGE_H