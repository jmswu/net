#include "gtest/gtest.h"

namespace
{

    class dummy_test : public ::testing::Test
    {
    public:
    private:
    protected:
        dummy_test() {}

        virtual void SetUp()
        {
        }

        virtual void TearDown()
        {
        }

        TEST_F(dummy_test, dummy)
        {
            ASSERT_EQ(42, 42);
        }
    };
}