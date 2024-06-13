#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.cpp"

// Mock класс для B
class MockB : public B {
public:
    MOCK_METHOD(int, multiply, (int x, int y), (override));
};

// Тестовый случай
TEST(ATest, CallsMultiply) {
    MockB mockB;
    A a(mockB);

    EXPECT_CALL(mockB, multiply(3, 4))
        .Times(1)
        .WillOnce(testing::Return(12));

    a.f1(3, 4);
}

// Функция запуска тестов
int test_main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

