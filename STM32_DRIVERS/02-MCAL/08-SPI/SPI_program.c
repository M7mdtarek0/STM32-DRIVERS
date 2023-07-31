/*
 * SPI_program.c
 *
 *  Created on: July 28, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "AFIO_interface.h"


void SPI1_voidEnableClock(void)
{
    RCC_voidEnableClock(RCC_APB2, SPI1EN);
}

void SPI1_voidInitMaster(void)
{
    /*
        Software slave managment enabled
        SPI Enable
        Master configuration
        Prescaler = CLK/2
        Frame Format: MSB First
        Clock Polarity: CK to 1 when idle
        Clock Phase: The second clock transition is the first data capture edge
    */
   SPI1 -> CR1 = 0x0347; /*CPOL = 0, CPHA = 1, Prescaller = CLK/2, SPI Enable, MSB First*/

   SPI1_voidSetBaudRatePrescaler(SPI1_BAUDRATE_PRESCALER);

    #if  SPI1_DATA_ORDER == SPI_LSB_FIRST
        SET_BIT(SPI1 -> CR1, 7);
    #endif
    #if SPI1_CLK_PHASE == SPI_FIRST_CLOCK_FIRST_CAPTURE
        CLR_BIT(SPI1 -> CR1, 0);
    #endif
    #if  SPI1_CLK_POLARITY == SPI_CK_0_WHEN_IDLE
        CLR_BIT(SPI1 -> CR1, 1);
    #endif
    #if  SPI1_PINS == SPI_PINS_A4_A5_A6_A7
        AFIO_voidRemap(AFIO_SPI1_REMAP, 0);
        GPIO_voidSetPinMode(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_AFPP  ); /*SCK*/
        GPIO_voidSetPinMode(GPIOA, PIN6, INPUT_FLOATING           ); /*MISO*/
        GPIO_voidSetPinMode(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP  ); /*MOSI*/
    #elif SPI1_PINS == SPI_PINS_A15_B3_B4_B5
        AFIO_voidRemap(AFIO_SPI1_REMAP, 1);
        GPIO_voidSetPinMode(GPIOB, PIN3, OUTPUT_SPEED_10MHZ_AFPP  ); /*SCK*/
        GPIO_voidSetPinMode(GPIOB, PIN4, INPUT_FLOATING           ); /*MISO*/
        GPIO_voidSetPinMode(GPIOB, PIN5, OUTPUT_SPEED_10MHZ_AFPP  ); /*MOSI*/
    #endif
}

void SPI1_voidInitSlave(void)
{
    /* 
        Software slave management enabled
        SPI Enable
        Slave configuration
        Frame format: MSB First
        Clock polarity: CK to 1 when idle
        Clock phase: The second clock transition is the first data capture edge
    */
    SPI1->CR1 = 0x0343;

    SPI1_vidSetBaudRatePrescaler(SPI1_BAUDRATE_PRESCALER);

    #if SPI1_DATA_ORDER   == SPI_LSB_FIRST
        SET_BIT(SPI1->CR1, 7);
    #endif
    #if SPI1_CLK_PHASE    == SPI_FIRST_CLOCK_FIRST_CAPTURE
        CLR_BIT(SPI1->CR1, 0);
    #endif
    #if SPI1_CLK_POLARITY == SPI_CK_0_WHEN_IDLE
        CLR_BIT(SPI1->CR1, 1);
    #endif

    #if SPI1_PINS == SPI_PINS_A4_A5_A6_A7
        AFIO_voidRemap(AFIO_SPI1_REMAP, 0);
        GPIO_voidSetPinMode(GPIOA, PIN4, INPUT_FLOATING           ); /*NSS*/
        GPIO_voidSetPinMode(GPIOA, PIN5, INPUT_FLOATING           ); /*SCK*/
        GPIO_voidSetPinMode(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_AFPP  ); /*MISO*/
        GPIO_voidSetPinMode(GPIOA, PIN7, INPUT_FLOATING           ); /*MOSI*/
    #elif SPI1_PINS == SPI_PINS_A15_B3_B4_B5
        AFIO_voidRemap(AFIO_SPI1_REMAP, 1);
        GPIO_voidSetPinMode(GPIOA, PIN15, INPUT_FLOATING          ); /*NSS*/
        GPIO_voidSetPinMode(GPIOB, PIN3 , INPUT_FLOATING          ); /*SCK*/
        GPIO_voidSetPinMode(GPIOB, PIN4 , OUTPUT_SPEED_10MHZ_AFPP ); /*MISO*/
        GPIO_voidSetPinMode(GPIOB, PIN5 , INPUT_FLOATING          ); /*MOSI*/
    #endif
}

void SPI1_voidSendRecieveSynch16Bit(u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u16 Copy_u16DataToSend, u16 *Copy_u16DataToRecieve)
{
    while ((GET_BIT(SPI1->SR, 7)));         /* Wait for busy flag if another transision is processing   */
    CLR_BIT(SPI1->CR1, 6);                  /* Disable SPI                                              */
    SET_BIT(SPI1->CR1, 11);                 /* Set data size to 16 bits                                 */
    SET_BIT(SPI1->CR1, 6);                  /* Enable SPI                                               */

    /* Clear slave select pin to start sending */   
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, LOW_PIN); 

    SPI1 -> DR = Copy_u16DataToSend;        /* Write data                                               */
    while ((GET_BIT(SPI1->SR, 7)));         /* Wait for busy flag is cleared when finished              */
    *Copy_u16DataToRecieve = SPI1 -> DR;    /* Read recieved data                                       */

    /* Set slave select pin to finish sending */
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, HIGH_PIN);
}

void SPI1_voidSendRecieveSynch8Bit(u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u8 Copy_u8DataToSend, u8 *Copy_u8DataToRecieve)
{
    while ((GET_BIT(SPI1->SR, 7)));         /* Wait for busy flag if another transision is processing   */
    CLR_BIT(SPI1->CR1, 6);                  /* Disable SPI                                              */
    CLR_BIT(SPI1->CR1, 11);                 /* Set data size to 8 bits                                  */
    SET_BIT(SPI1->CR1, 6);                  /* Enable SPI                                               */

    /* Clear slave select pin to start sending */   
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, LOW_PIN); 

    SPI1 -> DR = Copy_u8DataToSend;         /* Write data                                               */
    while ((GET_BIT(SPI1->SR, 7)));         /* Wait for busy flag is cleared when finished              */
    *Copy_u8DataToRecieve = SPI1 -> DR;     /* Read recieved data                                       */

    /* Set slave select pin to finish sending */
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, HIGH_PIN);
}

void SPI1_voidSetBaudRatePrescaler(u8 Copy_u8Prescaler)
{
    SPI1 -> CR1 |= (Copy_u8Prescaler << 3);
}

u8 SPI1_u8GetBaudRatePrescalerFromMaxFreq(u32 Copy_u32MaxFreq)
{
    u32 local_u32FreqSPI = RCC_u32GetClockFrequency(RCC_APB2);
    u8  local_u8Result   = SPI_BAUDRATE_PRESCALER_256;
    u8  local_u8Counter;

    /* Trying to get the prescaler which have result less than max freq ( (freq / prescaler) < max_freq ) */
    for (local_u8Counter = 0; local_u8Counter < 8; local_u8Counter++) {
        if (local_u32FreqSPI / (1 << (local_u8Counter+1)) < Copy_u32MaxFreq) {
            local_u8Result = local_u8Counter;
        }
    }

    /* when no prescaler have result less than the max value, it's already assigned before with max prescaler (256)*/
    return local_u8Result;
}

void SPI2_voidEnableClock(void)
{
    RCC_voidEnableClock(RCC_APB1, SPI2EN);
}

void SPI2_voidInitMaster(void)
{
    /* 
        Software slave management enabled
        SPI Enable
        Master configuration
        Prescaller = CLK/2
        Frame format: MSB First
        Clock polarity: CK to 1 when idle
        Clock phase: The second clock transition is the first data capture edge
    */
    SPI2->CR1 = 0x0347;

    SPI2_vidSetBaudRatePrescaler(SPI2_BAUDRATE_PRESCALER);

    #if SPI2_DATA_ORDER   == SPI_LSB_FIRST
        SET_BIT(SPI2->CR1, 7);
    #endif
    #if SPI2_CLK_PHASE    == SPI_FIRST_CLOCK_FIRST_CAPTURE
        CLR_BIT(SPI2->CR1, 0);
    #endif
    #if SPI2_CLK_POLARITY == SPI_CK_0_WHEN_IDLE
        CLR_BIT(SPI2->CR1, 1);
    #endif

    GPIO_voidSetPinMode(GPIOB, PIN13, OUTPUT_SPEED_10MHZ_AFPP  ); /*SCK*/
    GPIO_voidSetPinMode(GPIOB, PIN14, INPUT_FLOATING           ); /*MISO*/
    GPIO_voidSetPinMode(GPIOB, PIN15, OUTPUT_SPEED_10MHZ_AFPP  ); /*MOSI*/

}

void SPI2_voidInitSlave(void)
{
        /* 
        Software slave management enabled
        SPI Enable
        Slave configuration
        Frame format: MSB First
        Clock polarity: CK to 1 when idle
        Clock phase: The second clock transition is the first data capture edge
    */
    SPI2->CR1 = 0x0343;

    SPI2_vidSetBaudRatePrescaler(SPI2_BAUDRATE_PRESCALER);

    #if SPI2_DATA_ORDER   == SPI_LSB_FIRST
        SET_BIT(SPI1->CR1, 7);
    #endif
    #if SPI2_CLK_PHASE    == SPI_FIRST_CLOCK_FIRST_CAPTURE
        CLR_BIT(SPI1->CR1, 0);
    #endif
    #if SPI2_CLK_POLARITY == SPI_CK_0_WHEN_IDLE
        CLR_BIT(SPI1->CR1, 1);
    #endif

    GPIO_voidSetPinMode(GPIOB, PIN12, INPUT_FLOATING           ); /*NSS*/
    GPIO_voidSetPinMode(GPIOB, PIN13, INPUT_FLOATING           ); /*SCK*/
    GPIO_voidSetPinMode(GPIOB, PIN14, OUTPUT_SPEED_10MHZ_AFPP  ); /*MISO*/
    GPIO_voidSetPinMode(GPIOB, PIN15, INPUT_FLOATING           ); /*MOSI*/
}

void SPI2_voidSendRecieveSynch16Bit(u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u16 Copy_u16DataToSend, u16 *Copy_u16DataToRecieve)
{
    while ((GET_BIT(SPI2->SR, 7)));         /* Wait for busy flag if another transision is processing   */
    CLR_BIT(SPI2->CR1, 6);                  /* Disable SPI                                              */
    SET_BIT(SPI2->CR1, 11);                 /* Set data size to 16 bits                                 */
    SET_BIT(SPI2->CR1, 6);                  /* Enable SPI                                               */

    /* Clear slave select pin to start sending */   
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, LOW_PIN); 

    SPI2 -> DR = Copy_u16DataToSend;        /* Write data                                               */
    while ((GET_BIT(SPI2->SR, 7)));         /* Wait for busy flag is cleared when finished              */
    *Copy_u16DataToRecieve = SPI2 -> DR;    /* Read recieved data                                       */

    /* Set slave select pin to finish sending */
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, HIGH_PIN);
}

void SPI2_voidSendRecieveSynch8Bit(u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u8 Copy_u8DataToSend, u8 *Copy_u8DataToRecieve)
{
    while ((GET_BIT(SPI2->SR, 7)));         /* Wait for busy flag if another transision is processing   */
    CLR_BIT(SPI2->CR1, 6);                  /* Disable SPI                                              */
    CLR_BIT(SPI2->CR1, 11);                 /* Set data size to 8 bits                                  */
    SET_BIT(SPI2->CR1, 6);                  /* Enable SPI                                               */

    /* Clear slave select pin to start sending */   
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, LOW_PIN); 

    SPI2 -> DR = Copy_u8DataToSend;         /* Write data                                               */
    while ((GET_BIT(SPI2->SR, 7)));         /* Wait for busy flag is cleared when finished              */
    *Copy_u8DataToRecieve = SPI2 -> DR;     /* Read recieved data                                       */

    /* Set slave select pin to finish sending */
    GPIO_vidSetPinValue(Copy_u8SlavePort, Copy_u8SlavePin, HIGH_PIN);
}

void SPI2_voidSetBaudRatePrescaler(u8 Copy_u8Prescaler)
{
    SPI2 -> CR1 |= (Copy_u8Prescaler << 3);
}

u8 SPI2_u8GetBaudRatePrescalerFromMaxFreq(u32 Copy_u32MaxFreq)
{
    u32 local_u32FreqSPI = RCC_u32GetClockFrequency(RCC_APB1);
    u8  local_u8Result   = SPI_BAUDRATE_PRESCALER_256;
    u8  local_u8Counter;

    /* Trying to get the prescaler which have result less than max freq ( (freq / prescaler) < max_freq ) */
    for (local_u8Counter = 0; local_u8Counter < 8; local_u8Counter++) {
        if (local_u32FreqSPI / (1 << (local_u8Counter+1)) < Copy_u32MaxFreq) {
            local_u8Result = local_u8Counter;
        }
    }

    /* when no prescaler have result less than the max value, it's already assigned before with max prescaler (256)*/
    return local_u8Result;
}