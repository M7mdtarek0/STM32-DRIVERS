/*
 * USART_program.c
 *
 *  Created on: July 29, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "RCC_interface.h"

void USART1_voidInit(void)
{
    /*Getting clock frequence of APB2*/
    u32 Local_u32Clock = RCC_u32GetClockFrequency(RCC_APB2);

    /*Setting up the Baud Rate*/
    u16 Local_u16DivMantissa = ((Local_u32Clock) / (USART1_BAUDRATE * 16));
    u16 Local_u16DivFraction = ((Local_u32Clock * 1000) (USART1_BAUDRATE * 16)) - Local_u16DivMantissa * 1000;
    Local_u16DivFraction = (Local_u16DivFraction * 16) / 1000;
    USART1 -> BRR = (Local_u16DivMantissa << 4) | Local_u16DivFraction;

    /*Parity control enable and selection*/
    #if (USART1_PARITY_CONTROL == USART_PARITY_CONTROL_ENABLED) && (USART1_PARITY_SELECTION == USART_ODD_PARITY)
        SET_BIT(USART1 -> CR1, 10);
        SET_BIT(USART1 -> CR1, 9);
    #elif (USART1_PARITY_CONTROL == USART_PARITY_CONTROL_DISABLED) && (USART1_PARITY_SELECTION == USART_EVEN_PARITY)
        SET_BIT(USART1 -> CR1, 10);
        CLR_BIT(USART1 -> CR1, 9);
    #else
        CLR_BIT(USART1 -> CR1, 10);
    #endif

    /*Stop bits*/
    #if     USART1_STOP_BITS == USART_1_STOP_BIT
    CLR_BIT(USART1 -> CR2, 12);
    CLR_BIT(USART1 -> CR2, 13);
    #elif   USART1_STOP_BITS == USART_0_5_STOP_BIT
    SET_BIT(USART1 -> CR2, 12);
    CLR_BIT(USART1 -> CR2, 13);
    #elif   USART1_STOP_BITS == USART_2_STOP_BIT
    CLR_BIT(USART1 -> CR2, 12);
    SET_BIT(USART1 -> CR2, 13);
    #elif   USART1_STOP_BITS == USART_1_5_STOP_BIT
    SET_BIT(USART1 -> CR2, 12);
    SET_BIT(USART1 -> CR2, 13);
    #endif

    /* Clock control */
#if     USART1_CLOCK_CONTROL == USART_1_CLOCK_ENABLED
    SET_BIT(USART1 -> CR2, 11);
#elif   USART1_CLOCK_CONTROL == USART_1_CLOCK_DISABLED
    CLR_BIT(USART1 -> CR2, 11);
#endif

/* Clock polarity */
#if     USART1_CLOCK_POLARITY == USART_CLK_1_WHEN_IDLE
    SET_BIT(USART1 -> CR2, 10);
#elif   USART1_CLOCK_POLARITY == USART_CLK_0_WHEN_IDLE
    CLR_BIT(USART1 -> CR2, 10);
#endif

/* Clock phase */
#if     USART1_CLOCK_PHASE == USART_SECOND_CLOCK_FIRST_CAPTURE
    SET_BIT(USART1 -> CR2, 9);
#elif   USART1_CLOCK_PHASE == USART_FIRST_CLOCK_FIRST_CAPTURE
    CLR_BIT(USART1 -> CR2, 9);
#endif

    SET_BIT(USART1 -> CR1, 2 ); /* RX enable                */
    SET_BIT(USART1 -> CR1, 3 ); /* TX enable                */
    SET_BIT(USART1 -> CR1, 13); /* USART enable             */
    USART1 -> SR = 0;           /* Clear status register    */
}

void USART_voidTransmit(u8 arr[])
{
    u8 Local_u8Counter = 0;
    while (arr[Local_u8Counter] != '\0')
    {
        USART1 -> DR =  arr[Local_u8Counter];
        while (GET_BIT(USART1 -> SR, 6) == 0);  /*Wait till transmission is complete*/
        Local_u8Counter++;
    }
}

u8 USART_u8Recieve(void)
{
    u8 Local_u8Result;
    while (GET_BIT(USART1 -> SR, 5) == 0); /*Wait till recieving is complete*/
    Local_u8Result = (USART1 -> DR) && 0xFF; /*0xFF to be sure that i will recieve only 8bits so i anded with 0xFF its called MASKING*/
    return Local_u8Result;
}

void USART_voidEnableClock(void)
{
    RCC_voidEnableClock(RCC_APB2, USART1EN)
}