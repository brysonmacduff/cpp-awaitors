// from this project
#include "shape.h"

// from standard library
#include <iostream>

// from external
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <spdlog/spdlog.h>

using namespace Geometry;

namespace ShapeTesting
{   
class MockShape : public Shape
{
public:
    MOCK_METHOD(int, GetSideCount,());
};

class ShapeTestFixture : public ::testing::Test
{
protected:
    // Setup code executed before each test
    void SetUp() override {
        // Initialize resources here
        spdlog::debug("ShapeTestFixture::SetUp()");
    }

    // Teardown code executed after each test
    void TearDown() override {
        // Clean up resources here
        spdlog::debug("ShapeTestFixture::TearDown()");
    }
};
}

using namespace ShapeTesting;

// GOOGLE TESTS

TEST(ShapeTestFixture,side_count_constructor_test)
{
    const int sides = 3;
    ASSERT_NO_FATAL_FAILURE(Shape s = Shape(sides));
}

TEST(shape_tests,angles_constructor_test)
{
    std::vector<float> angles = {90,90,90,90};
    ASSERT_NO_FATAL_FAILURE(Shape s = Shape(angles));
    Shape s = Shape(angles);
    ASSERT_EQ(s.GetSideCount(),4);

    for(auto it = s.AnglesBegin(); it != s.AnglesEnd(); ++it)
    {
        EXPECT_EQ(*it,90);
    }
}

TEST(shape_tests,mock_get_side_count)
{
    // initialize mocked shape instance
    ShapeTesting::MockShape mock_shape = ShapeTesting::MockShape(3);
    // set the return value of the mocked GetSideCount()
    EXPECT_CALL(mock_shape,GetSideCount()).Times(1).WillOnce(testing::Return(3));
    // call the mocked GetSideCount()
    int sides = mock_shape.GetSideCount();
    ASSERT_EQ(sides,3);
}

TEST(shape_tests,equal_operator_test)
{   
    const int sides = 3;
    const Shape s1 = Shape(sides);
    const Shape s2 = Shape(sides);
    bool result = s1 == s2;
    EXPECT_TRUE(result);
}

TEST(shape_tests,equal_assignment_test)
{   
    const int sides = 3;
    const Shape s1 = Shape(sides);
    const Shape s2 = s1;

    // verify that data was copied and also that the copy is stored at a different address
    EXPECT_NE(&s2,&s1);
    EXPECT_TRUE(s1 == s2);
}

TEST(shape_tests,copy_constructor_test)
{   
    Shape original = Shape(5);
    auto copy_shape = [](Shape copy) -> void
    {
        EXPECT_EQ(copy.GetSideCount(),5);
        for(auto it = copy.AnglesBegin(); it != copy.AnglesEnd(); ++it)
        {
            EXPECT_EQ(*it,72);
        }
    };

    copy_shape(original);
}
