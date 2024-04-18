#ifndef COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H
#define COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H

#include "IOrderStorage.h"

namespace storage
{

    class DiskStorage : public IOrderStorage
    {
    public:
        virtual ~DiskStorage();

        /**
         * @brief Set the path of the destination of the file. Also updates the current_idx of orders to follow the same serie of previous sessions
         *
         * @param [in] dest path to the file
         *
         * @return true if the file exists and can be open
         * @return false if cant open the file
         */
        bool SetSourceDestination(const std::string &dest);

        /**
         * @brief Stores the order into the file and update the order idx
         *
         * @param [in] order Order to be saved in the file
         *
         * @return true if the file exists and can be open
         * @return false if cant open the file
         */
        bool StoreOrder(std::shared_ptr<Order> order);

        /**
         * @brief Removes the order from the file. It creates a .tmp file to copy all the content. Not updates the idx of the previous orders, so it could jumps in the idx of the file
         *
         * @param [in] index idx of the order to remove
         *
         * @return true if the file exists and can be open
         * @return false if cant open the file, or create the tmp file
         */
        bool RemoveOrder(const int index);

        /**
         * @brief Return the current idx of the last order added to the file. It search in the file until reach the last element
         *
         * @return int order idx
         */
        int GetCurrentIdx();

    private:
        std::string file_;
    };

}

#endif // COFFEESHOP_SRC_STORAGE_DISKSTORAGE_H