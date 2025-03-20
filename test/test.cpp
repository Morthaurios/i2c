#include <gtest/gtest.h>

extern "C" {
#include "I2c.h"
#include "Platform_Types.h"
}

TEST(I2C, Check_Init) {
    uint8_t au8Buffer[100];

    (void) I2C_Init();

    EXPECT_EQ(E_OK, I2C_Transmit(0x20U, au8Buffer, 100U));
}