cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)

# Добавьте исходные файлы проекта
add_executable(MyProject main.cpp)

# Найдите и подключите Google Test и Google Mock
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавьте тесты
enable_testing()
add_executable(runTests test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_test(NAME MyTest COMMAND runTests)

