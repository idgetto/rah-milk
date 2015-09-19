#include "gtest/gtest.h"

class FirstTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            x = 5;
        }

/*
        virtual void TearDown() {
            std::cout << "Bye!" << "\n";
        }
*/
    
    int x;
};
