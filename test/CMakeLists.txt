add_executable(i2c_test test.cpp)

target_link_libraries(i2c_test gtest_main I2C_driver Platform_Types)

include(GoogleTest)
gtest_discover_tests(i2c_test)