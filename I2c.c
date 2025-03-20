
/*****************************************************************************************************************************
 * FILE NAME:   I2c.c
 * AUTHOR:      morthaurios
 * DESCRIPTION: Dummy I2C driver.
 *****************************************************************************************************************************/

/*****************************************************************************************************************************
 * INCLUDES
 *****************************************************************************************************************************/

#include "I2c.h"

/*****************************************************************************************************************************
 * MACROS
 *****************************************************************************************************************************/


/*****************************************************************************************************************************
 * TYPE DEFINITIONS
 *****************************************************************************************************************************/


/*****************************************************************************************************************************
 * GLOBAL VARIABLES
 *****************************************************************************************************************************/


/*****************************************************************************************************************************
 * LOCAL VARIABLES
 *****************************************************************************************************************************/
volatile static uint8_t u8DummyTxRegister;
volatile static uint8_t u8DummyRxRegister;

static bool bInitialized = false;

/*****************************************************************************************************************************
 * FUNCTION DECLARATIONS
 *****************************************************************************************************************************/

static inline uint8_t CalculateAddress(const uint8_t u8Address, const bool bRW);

/*****************************************************************************************************************************
 * FUNCTION DEFINITIONS
 *****************************************************************************************************************************/

/*****************************************************************************************************************************
 * FUNCTION:        I2C_Init
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
 Platform_Return_t I2C_Init(void)
{
    /* Set some registers. */

    bInitialized = true;

    return E_OK;
}

/*****************************************************************************************************************************
 * FUNCTION:        I2C_Transmit
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
Platform_Return_t I2C_Transmit(const uint8_t u8Address, const uint8_t * const pu8Buffer, const uint16_t u16BufferLength)
{
    Platform_Return_t eRetVal = E_NOT_OK;
    uint16_t u16Index;

    if( (NULL != pu8Buffer) && (u16BufferLength > 0U) )
    {
        if(true == bInitialized)
        {
            u8DummyTxRegister = CalculateAddress(u8Address, false);

            for(u16Index = 0U; u16Index < u16BufferLength; u16Index++)
            {
                /* Write to some register. */
                u8DummyTxRegister = pu8Buffer[u16Index];

                /* Wait until byte is clocked out. */
            }

            eRetVal = E_OK;
        }
    }

    return eRetVal;
}

/*****************************************************************************************************************************
 * FUNCTION:        I2C_Receive
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
Platform_Return_t I2C_Receive(const uint8_t u8Address, uint8_t * const pu8Buffer, const uint16_t u16BufferLength)
{
    uint16_t u16Index;
    Platform_Return_t eRetVal = E_NOT_OK;

    if( (NULL != pu8Buffer) && (u16BufferLength > 0U) )
    {
        if(true == bInitialized)
        {
            u8DummyTxRegister = CalculateAddress(u8Address, true);

            for(u16Index = 0U; u16Index < u16BufferLength; u16Index++)
            {
                /* Write to some register. */
                pu8Buffer[u16Index] = u8DummyRxRegister;

                /* Wait until byte is clocked out. */
            }

            eRetVal = E_OK;
        }
    }

    return eRetVal;
}

/*****************************************************************************************************************************
 * FUNCTION:        CalculateAddress
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
static inline uint8_t CalculateAddress(const uint8_t u8Address, const bool bRW)
{
    uint8_t u8ShiftedAddress;

    u8ShiftedAddress = (u8Address & 0x7FU) << 1;

    if(true == bRW)
    {
        u8ShiftedAddress |= 0x01U;
    }

    return u8ShiftedAddress;
}