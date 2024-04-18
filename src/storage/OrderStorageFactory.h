#ifndef COFFEESHOP_SRC_STORAGE_ORDERSTORAGEFACTORY_H
#define COFFEESHOP_SRC_STORAGE_ORDERSTORAGEFACTORY_H

#include <memory>

#include "IOrderStorage.h"
#include "DiskStorage.h"

namespace storage
{

    class OrderStorageFactory
    {
    public:
        enum class StorageType
        {
            DISK,
            NONE
        };

        static std::unique_ptr<IOrderStorage> CreateStorage(StorageType type)
        {
            switch (type)
            {
            case StorageType::DISK:
                return std::make_unique<DiskStorage>();
            // Add cases for additional parser types
            default:
                return nullptr;
            }
        }
    };

}

#endif // COFFEESHOP_SRC_STORAGE_ORDERSTORAGEFACTORY_H