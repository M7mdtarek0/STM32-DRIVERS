/*
 * DMA_interface.h
 *
 *  Created on: July 25, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _DMA_INTERFACE_H_
#define _DMA_INTERFACE_H_

/*Options
--> Channel options:
    1- DMA_CHANNEL1
    2- DMA_CHANNEL2
    3- DMA_CHANNEL3
    4- DMA_CHANNEL4
    5- DMA_CHANNEL5
    6- DMA_CHANNEL6
    7- DMA_CHANNEL7

--> Priority options:
    1- DMA_PRIORITY_LOW
    2- DMA_PRIORITY_MEDIUM
    3- DMA_PRIORITY_HIGH
    4- DMA_PRIORITY_VERY_HIGH

--> Mode options:
    1- DMA_MODE_ENABLED
    2- DMA_MODE_DISABLED

--> Data transfer direction options:
    1- DMA_READ_FROM_MEMORY
    2- DMA_READ_FROM_PERIPHERAL

--> Interrupt options:
    1- DMA_TRANSFER_ERROR_INTERRUPT
    2- DMA_HALF_TRANSFER_INTERRUPT
    3- DMA_TRANSFER_COMPLETE_INTERRUPT
    4- DMA_GLOBAL_INTERRUPT (Allowed only to read or clear flag)

--> Size options:
    1- DMA_SIZE_8_BITS
    2- DMA_SIZE_16_BITS
    3- DMA_SIZE_32_BITS

*/




void DMA_voidEnableClock             (void);

void DMA_voidEnableChannel           (u8 Copy_u8Channel);
void DMA_voidDisableChannel          (u8 Copy_u8Channel);

void DMA_voidSetCallback             (u8 Copy_u8Channel, void (*ptr)(void)   );
 
void DMA_voidSetPriority             (u8 Copy_u8Channel,    u8 Copy_u8Priority  );
void DMA_voidSetMemoryToMemoryMode   (u8 Copy_u8Channel,    u8 Copy_u8Mode      );
void DMA_voidSetCircularMode         (u8 Copy_u8Channel,    u8 Copy_u8Mode      );
void DMA_voidDataTransferDirection   (u8 Copy_u8Channel,    u8 Copy_u8Direction );
void DMA_voidSetNumberOfData         (u8 Copy_u8Channel,    u16 Copy_u16Number  );
 
void DMA_voidEnableInterrupt         (u8 Copy_u8Channel,    u8 Copy_u8Interrupt );
void DMA_voidDisableInterrupt        (u8 Copy_u8Channel,    u8 Copy_u8Interrupt );
void DMA_voidClearInterruptFlag      (u8 Copy_u8Channel,    u8 Copy_u8Interrupt );
u8   DMA_u8ReadInterruptFlag         (u8 Copy_u8Channel,    u8 Copy_u8Interrupt );

void DMA_voidSetSize                 (u8 Copy_u8Channel, u8 Copy_u8MemorySize      ,  u8 Copy_u8PeripheralSize     );
void DMA_voidSetIncrementMode        (u8 Copy_u8Channel, u8 Copy_u8MemoryMode      ,  u8 Copy_u8PeripheralMode     );
void DMA_voidSetAddress              (u8 Copy_u8Channel, u32 *Copy_u32MemoryAddress, u32 *Copy_u32PeripheralAddress);

/*These values cannot be changed*/

#define DMA_CHANNEL1    0
#define DMA_CHANNEL2    1
#define DMA_CHANNEL3    2
#define DMA_CHANNEL4    3
#define DMA_CHANNEL5    4
#define DMA_CHANNEL6    5
#define DMA_CHANNEL7    6

#define DMA_SIZE_8_BITS  0b00
#define DMA_SIZE_16_BITS 0b01
#define DMA_SIZE_32_BITS 0b10

#define DMA_PRIORITY_LOW        0
#define DMA_PRIORITY_MEDIUM     1
#define DMA_PRIORITY_HIGH       2
#define DMA_PRIORITY_VERY_HIGH  3

#define DMA_MODE_DISABLED  0 
#define DMA_MODE_ENABLED   1

#define DMA_READ_FROM_PERIPHERAL 0
#define DMA_READ_FROM_MEMORY     1

#define DMA_GLOBAL_INTERRUPT            0
#define DMA_TRANSFER_COMPLETE_INTERRUPT 1
#define DMA_HALF_TRANSFER_INTERRUPT     2
#define DMA_TRANSFER_ERROR_INTERRUPT    3

#endif