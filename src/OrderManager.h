#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

class OrderManager {
   public:
    OrderManager();
    ~OrderManager();

    void RegisterOrder();

    void CancelOrder(int index);

   private:
};

#endif