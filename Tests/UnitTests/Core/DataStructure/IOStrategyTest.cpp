#include "Device/Data/OutputData.h"
#include "Device/InputOutput/OutputDataReadStrategy.h"
#include "Device/InputOutput/OutputDataWriteStrategy.h"
#include "Tests/GTestWrapper/google_test.h"

class IOStrategyTest : public ::testing::Test
{
protected:
    IOStrategyTest();

    OutputData<double> m_model_data;
};

IOStrategyTest::IOStrategyTest()
{
    FixedBinAxis axis1("x", 5, 1.0, 5.0);
    FixedBinAxis axis2("y", 10, 6.0, 7.0);
    m_model_data.addAxis(axis1);
    m_model_data.addAxis(axis2);
    for (size_t i = 0, size = m_model_data.getAllocatedSize(); i < size; ++i)
        m_model_data[i] = static_cast<double>(i);
}

TEST_F(IOStrategyTest, TestINTStrategies)
{
    std::stringstream ss;
    OutputDataWriteINTStrategy write_int_strategy;
    write_int_strategy.writeOutputData(m_model_data, ss);
    OutputDataReadINTStrategy read_int_strategy;
    auto result = std::unique_ptr<OutputData<double>>(read_int_strategy.readOutputData(ss));

    auto compare_axis = [this, &result](size_t index) {
        EXPECT_EQ(m_model_data.axis(index).size(), result->axis(index).size());
        EXPECT_EQ(m_model_data.axis(index).lowerBound(), result->axis(index).lowerBound());
        EXPECT_EQ(m_model_data.axis(index).upperBound(), result->axis(index).upperBound());
    };

    EXPECT_EQ(m_model_data.rank(), result->rank());
    EXPECT_EQ(m_model_data.getAllSizes(), result->getAllSizes());
    compare_axis(0);
    compare_axis(1);
    for (size_t i = 0, size = m_model_data.getAllocatedSize(); i < size; ++i)
        EXPECT_EQ(m_model_data[i], (*result)[i]);
}

TEST_F(IOStrategyTest, TestNumpyTXTStrategies)
{
    std::stringstream ss;
    OutputDataWriteNumpyTXTStrategy write_txt_strategy;
    write_txt_strategy.writeOutputData(m_model_data, ss);

    OutputDataReadNumpyTXTStrategy read_txt_strategy;
    auto result = std::unique_ptr<OutputData<double>>(read_txt_strategy.readOutputData(ss));
    EXPECT_EQ(m_model_data.rank(), result->rank());
    EXPECT_EQ(m_model_data.getAllSizes(), result->getAllSizes());
    for (size_t i = 0, size = m_model_data.getAllocatedSize(); i < size; ++i)
        EXPECT_EQ(m_model_data[i], (*result)[i]);
}

#ifdef BORNAGAIN_TIFF_SUPPORT

TEST_F(IOStrategyTest, TestTIFFStrategies)
{
    std::stringstream ss;
    OutputDataWriteTiffStrategy write_tiff_strategy;
    write_tiff_strategy.writeOutputData(m_model_data, ss);

    OutputDataReadTiffStrategy read_tiff_strategy;
    auto result = std::unique_ptr<OutputData<double>>(read_tiff_strategy.readOutputData(ss));
    EXPECT_EQ(m_model_data.rank(), result->rank());
    EXPECT_EQ(m_model_data.getAllSizes(), result->getAllSizes());
    for (size_t i = 0, size = m_model_data.getAllocatedSize(); i < size; ++i)
        EXPECT_EQ(m_model_data[i], (*result)[i]);
}

#endif // BORNAGAIN_TIFF_SUPPORT
