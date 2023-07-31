/*
 * SPI_interface.h
 *
 *  Created on: July 28, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

void SPI1_voidEnableClock   (void);
void SPI1_voidInitMaster    (void);
void SPI1_voidInitSlave     (void);
void SPI1_voidSendRecieveSynch16Bit         (u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u16 Copy_u16DataToSend, u16 *Copy_u16DataToRecieve);
void SPI1_voidSendRecieveSynch8Bit          (u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u8 Copy_u8DataToSend, u8 *Copy_u8DataToRecieve    );
void SPI1_voidSetBaudRatePrescaler          (u8 Copy_u8Prescaler);
u8   SPI1_u8GetBaudRatePrescalerFromMaxFreq (u32 Copy_u32MaxFreq);

void SPI2_voidEnableClock   (void);
void SPI2_voidInitMaster    (void);
void SPI2_voidInitSlave     (void);
void SPI2_voidSendRecieveSynch16Bit         (u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u16 Copy_u16DataToSend, u16 *Copy_u16DataToRecieve);
void SPI2_voidSendRecieveSynch8Bit          (u8 Copy_u8SlavePort, u8 Copy_u8SlavePin, u8 Copy_u8DataToSend, u8 *Copy_u8DataToRecieve    );
void SPI2_voidSetBaudRatePrescaler          (u8 Copy_u8Prescaler);
u8   SPI2_u8GetBaudRatePrescalerFromMaxFreq (u32 Copy_u32MaxFreq);


/*
--> Copy_u8Prescaler options:
    1- SPI_BAUDRATE_PRESCALER_2
    2- SPI_BAUDRATE_PRESCALER_4
    3- SPI_BAUDRATE_PRESCALER_8
    4- SPI_BAUDRATE_PRESCALER_16
    5- SPI_BAUDRATE_PRESCALER_32
    6- SPI_BAUDRATE_PRESCALER_64
    7- SPI_BAUDRATE_PRESCALER_128
    8- SPI_BAUDRATE_PRESCALER_256
*/

#define SPI_BAUDRATE_PRESCALER_2    0
#define SPI_BAUDRATE_PRESCALER_4    1
#define SPI_BAUDRATE_PRESCALER_8    2
#define SPI_BAUDRATE_PRESCALER_16   3
#define SPI_BAUDRATE_PRESCALER_32   4
#define SPI_BAUDRATE_PRESCALER_64   5
#define SPI_BAUDRATE_PRESCALER_128  6
#define SPI_BAUDRATE_PRESCALER_256  7

#endif