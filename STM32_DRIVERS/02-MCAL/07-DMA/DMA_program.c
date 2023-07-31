/*
 * DMA_program.c
 *
 *  Created on: July 25, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

#include "RCC_interface.h"

/*callback function*/
static void (*DMA_callback[7])(void);

/*function to enable the clock*/
void DMA_voidEnableClock(void)
{
    RCC_voidEnableClock(RCC_AHB, DMA1EN);
}

/*function to enable the channel*/
void DMA_voidEnableChannel(u8 Copy_u8Channel)
{
    SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 0);
}

/*function to disable the channel*/
void DMA_voidDisableChannel(u8 Copy_u8Channel)
{
    CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 0);
}

/*function to set the callback function*/
void DMA_voidSetCallback(u8 Copy_u8Channel, void (*ptr)(void))
{
    DMA_callback[Copy_u8Channel] = ptr;
}

/*Function to set the priority*/
void DMA_voidSetPriority(u8 Copy_u8Channel, u8 Copy_u8Priority)
{
    switch (Copy_u8Channel)
    {
    case DMA_PRIORITY_LOW:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 12);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_MEDIUM:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 12);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_MEDIUM:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 12);
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_MEDIUM:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 12);
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 13);
        break;
    default:
        /*Return Error*/
        break;
    }
}

/*function to set transfering from memory to memory*/
void DMA_voidSetMemoryToMemoryMode(u8 Copy_u8Channel, u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 14);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 14);
        break;
    default:
        break;
    }
}

/*Function for repeating*/
void DMA_voidSetCircularMode(u8 Copy_u8Channel, u8 Copy_u8Mode)
{
     switch (Copy_u8Mode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 5);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 5);
        break;
    default:
        break;
    }
}

/*function to choose the transfet dirction of data*/
void DMA_voidDataTransferDirection(u8 Copy_u8Channel, u8 Copy_u8Direction)
{
    switch (Copy_u8Direction)
    {
    case DMA_READ_FROM_MEMORY:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 4);
        break;
    case DMA_READ_FROM_PERIPHERAL:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 4);
        break;
    default:
        break;
    }
}

/*function to set number of the data*/
void DMA_voidSetNumberOfData(u8 Copy_u8Channel, u16 Copy_u16Number)
{
    DMA -> channel[Copy_u8Channel].CNDTR = Copy_u16Number;
}
 
/*function to enable the interrupt*/
void DMA_voidEnableInterrupt(u8 Copy_u8Channel, u8 Copy_u8Interrupt ) 
{
    SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 0);
}

/*function to disable the interrupt*/
void DMA_voidDisableInterrupt(u8 Copy_u8Channel, u8 Copy_u8Interrupt )
{
    CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 0);
}

/*function to clear the interrupt flag*/
void DMA_voidClearInterruptFlag(u8 Copy_u8Channel, u8 Copy_u8Interrupt )
{
    u8 Local_u8PinNumber = Copy_u8Interrupt + 4*Copy_u8Channel;
    DMA -> IFCR = 1 << Local_u8PinNumber;
}

/*function to read the flag of the interrupt*/
u8 DMA_u8ReadInterruptFlag(u8 Copy_u8Channel, u8 Copy_u8Interrupt )
{
    u8 Local_u8Result;
    u8 Local_u8PinNumber = Copy_u8Interrupt + 4*Copy_u8Channel;
    Local_u8Result = GET_BIT ((DMA -> ISR), Local_u8PinNumber);
}

/*function to set the size of the memory and the peripheral*/
void DMA_voidSetSize(u8 Copy_u8Channel, u8 Copy_u8MemorySize, u8 Copy_u8PeripheralSize)
{
    switch (Copy_u8MemorySize)
    {
    case DMA_SIZE_8_BITS:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 10);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 11);
        break;
    case DMA_SIZE_16_BITS:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 10);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 11);
        break;
    case DMA_SIZE_32_BITS:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 10);
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 11);
        break;
    default:
        /*Return Error*/
        break;
    }
    switch (Copy_u8PeripheralSize)
    {
    case DMA_SIZE_8_BITS:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 8);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 9);
        break;
    case DMA_SIZE_16_BITS:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 8);
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 9);
        break;
    case DMA_SIZE_32_BITS:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 8);
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 9);
        break;
    default:
        /*Return Error*/
        break;
    }
}

/*function to set the increment mode*/
void DMA_voidSetIncrementMode(u8 Copy_u8Channel, u8 Copy_u8MemoryMode, u8 Copy_u8PeripheralMode)
{
    switch (Copy_u8MemoryMode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 7);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 7);
        break;
    default:
        /*Return Error*/
        break;
    }
    switch (Copy_u8PeripheralMode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[Copy_u8Channel].CCR), 6);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[Copy_u8Channel].CCR), 6);
        break;
    default:
        /*Return Error*/
        break;
    }
}

/*function to set the address*/
void DMA_voidSetAddress(u8 Copy_u8Channel, u32 *Copy_u32MemoryAddress, u32 *Copy_u32PeripheralAddress)
{
    DMA -> channel[Copy_u8Channel].CMAR = Copy_u32MemoryAddress;
    DMA -> channel[Copy_u8Channel].CPAR = Copy_u32PeripheralAddress;
}

/* IRQHandler Handlers */
void DMA1_Channel1_IRQHandler(void) {
    DMA_callback[0]();
    DMA -> IFCR = 0x0000000F; /* clear interrupt flags */
}
void DMA1_Channel2_IRQHandler(void) {
    DMA_callback[1]();
    DMA -> IFCR = 0x000000F0; /* clear interrupt flags */
}
void DMA1_Channel3_IRQHandler(void) {
    DMA_callback[2]();
    DMA -> IFCR = 0x00000F00; /* clear interrupt flags */
}
void DMA1_Channel4_IRQHandler(void) {
    DMA_callback[3]();
    DMA -> IFCR = 0x0000F000; /* clear interrupt flags */
}
void DMA1_Channel5_IRQHandler(void) {
    DMA_callback[4]();
    DMA -> IFCR = 0x000F0000; /* clear interrupt flags */
}
void DMA1_Channel6_IRQHandler(void) {
    DMA_callback[5]();
    DMA -> IFCR = 0x00F00000; /* clear interrupt flags */
}
void DMA1_Channel7_IRQHandler(void) {
    DMA_callback[6]();
    DMA -> IFCR = 0x0F000000; /* clear interrupt flags */
}