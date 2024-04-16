#include "DiskStorage.h"

namespace storage
{

    // DiskStorage::DiskStorage()
    // {
    // }

    DiskStorage::~DiskStorage()
    {
    }

    bool DiskStorage::SetSourceDestination(const std::string &dest)
    {
        file_ = dest;
        // TODO check if you can open or create file
        return true;
    }

    int DiskStorage::StoreOrder(const Order &order)
    {

        // TODO Save Order to file

        // if success
        order_curr_idx_++;

        return order_curr_idx_;
    }

    bool DiskStorage::RemoveOrder(const int index)
    {
        // TODO
        // remove order idx

        return true;
    }

}