cmake_minimum_required (VERSION 3.22)

project (I2C_driver
    DESCRIPTION "I2C driver"
    VERSION 1.0.0
    LANGUAGES C )

add_library(I2C_driver)

target_sources( I2C_driver PRIVATE
    I2c.c
)

target_include_directories( I2C_driver PUBLIC
    .
)

target_link_libraries( I2C_driver PRIVATE
    Platform_Types
)