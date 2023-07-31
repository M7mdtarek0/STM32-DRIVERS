/*
 * TFT_program.c
 *
 *  Created on: July 30, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "delay.h"

void TFT_voidInit(void)
{
    /*Initialize Pins*/
    GPIO_voidSetPinMode(TFT_A0_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(TFT_RESET_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(TFT_CS_PIN, OUTPUT_SPEED_2MHZ_PP);

    /*Send Pulse to RESET pin*/
    GPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
    delayMS(1);
    GPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_LOW);
    delayMS(1);
    GPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
    delayMS(1);
    GPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_LOW);
    delayMS(1);
    GPIO_voidSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
    delayMS(150);

    /*Sleep Out Command*/
    voidWriteCommand(0x11);
    delayMS(150);

    /*Color Mode*/
    voidWriteCommand(0x3A);
    voidWriteData(0x05);

    /*TFT ON*/
    voidWriteCommand(0x29);
}

void TFT_voidDisplayImage(const u16* Copy_u16Image)
{
    u16 counter = 0;

    /*Set X address*/
    voidWriteCommand(0x2A);
    /*Start from Position 0 to 127*/
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);

    /*Set Y address*/
    voidWriteCommand(0x2B);
    /*Start from Position 0 to 159*/
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);

    /*Write to RAM means every wirte data will appear on display*/
    voidWriteCommand(0x2C);

    for(counter = 0; counter < 20480; counter++)
    {
        voidWriteData(Copy_u16Image[counter] >> 8); /*Write the High Byte for one Pixel*/
        voidWriteData(Copy_u16Image[counter] & 0x00FF); /*Write the Low Byte for one Pixel*/
    }
}

static void voidWriteCommand(u8 Copy_u8Command)
{
    u8 Local_u8Temp;
    /*Set A0 Pin to LOW*/
    GPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);

    /*Send Command over SPI*/
    SPI1_voidSendRecieveSynch8Bit(TFT_CS_PIN, Copy_u8Command, &Local_u8Temp);
}

static void voidWriteData(u8 Copy_u8Data)
{
    u8 Local_u8Temp;
    /*Set A0 Pin to HIGH*/
    GPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);

    /*Send Command over SPI*/
    SPI1_voidSendRecieveSynch8Bit(TFT_CS_PIN, Copy_u8Command, &Local_u8Temp);
}

void TFT_voidFillColor(u16 Copy_u16Color)
{
    u16 counter = 0;
    u8 Data;

    /*Set X address*/
    voidWriteCommand(0x2A);
    /*Start from Position 0 to 127*/
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);

    /*Set Y address*/
    voidWriteCommand(0x2B);
    /*Start from Position 0 to 159*/
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);

    /*Write to RAM means every wirte data will appear on display*/
    voidWriteCommand(0x2C);

    for(counter = 0; counter < 20480; counter++)
    {
        Data = Copy_u16Color >> 8;
        voidWriteData(Data); /*Write the High Byte for one Pixel*/

        Data = Copy_u16Color & 0x00FF
        voidWriteData(Data); /*Write the Low Byte for one Pixel*/
    }
}