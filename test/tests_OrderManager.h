#ifndef TESTS_ORDERMANAGER_H
#define TESTS_ORDERMANAGER_H

// #include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/OrderManager.h"

// using ::testing::_;
// using ::testing::AtLeast;
// using ::testing::Return;

// class MockRng : public RngAbstract {
//    public:
//     ~MockRng(){

//     };
//     MOCK_METHOD2(generate, double(double, double));
// };

class tests_OrderManager : public ::testing::Test {
   protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {}
};

#endif  // endif TESTS_ORDERMANAGER_H