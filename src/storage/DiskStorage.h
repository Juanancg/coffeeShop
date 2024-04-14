#ifndef COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H
#define COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H

#include "IOrderStorage.h"

namespace storage
{

    class DiskStorage : public IOrderStorage
    {
    public:
        DiskStorage();
        ~DiskStorage();

        bool SetSourceDestination(const std::string &dest);

        int StoreOrder(const Order &order);
        bool RemoveOrder(const int index);

    private:
        std::string file_;
    };

}

#endif // COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H