/*
 * SPI_private.h
 *
 *  Created on: July 28, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_


typedef struct
{
    volatile u32 CR1    ;
    volatile u32 CR2    ;
    volatile u32 SR     ;
    volatile u32 DR     ;
    volatile u32 CRCPR  ;
    volatile u32 RXCRCR ;
    volatile u32 TXCRCR ;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR  ;
}SPI_registers;

#define SPI1    ((volatile SPI_registers*)(0x40013000))
#define SPI2    ((volatile SPI_registers*)(0x40003800))

#define SPI_MSB_FIRST                   0
#define SPI_LSB_FIRST                   1

#define SPI_FIRST_CLOCK_FIRST_CAPTURE   0
#define SPI_SECOND_CLOCK_FIRST_CAPTURE  1

#define SPI_CK_0_WHEN_IDLE              0
#define SPI_CK_1_WHEN_IDLE              1

#define SPI_PINS_A4_A5_A6_A7            0
#define SPI_PINS_A15_B3_B4_B5           1

#endif