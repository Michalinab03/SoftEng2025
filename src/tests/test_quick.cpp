
#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_quick, AddFunction)
{
    Sorter* sorter = new Sorter();

    SortData<int, std::vector> data;

    std::vector<int> L1{ 1, 233, 3, 87, 44, 255, 111, 11, 32 };

    const decltype(L1)::value_type* d = L1.data();
    data.add(d, L1.size());

    auto error = sorter->sort<int, std::vector, STT_QUICK>(data);

    const std::vector<int>& sorted_vec=data.data();

    for (size_t i=1; i < sorted_vec.size(); ++i)
    {
        assert(sorted_vec[i-1] <= sorted_vec[i]);
    }
    
    ASSERT_EQ(error, SE_SUCCESS);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
