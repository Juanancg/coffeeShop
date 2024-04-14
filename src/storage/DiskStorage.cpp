#include "DiskStorage.h"

namespace storage
{

    DiskStorage::DiskStorage()
    {
    }

    DiskStorage::~DiskStorage()
    {
    }

    bool DiskStorage::SetSourceDestination(const std::string &dest)
    {
        file_ = dest;
    }

    int DiskStorage::StoreOrder(const Order &order)
    {

        // Save Order to file

        // if success
        order_curr_idx_++;

        return order_curr_idx_;
    }

    bool DiskStorage::RemoveOrder(const int index)
    {
        // remove order idx

        return true;
    }

}