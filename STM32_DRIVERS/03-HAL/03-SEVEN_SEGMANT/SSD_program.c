/*
 * SSD_program.c
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"

#if SSD_TYPE == SSD_TYPE_COMMON_CATHODE
    #define SSD_LED_ON  GPIO_HIGH
    #define SSD_LED_OFF GPIO_LOW
#elif SSD_TYPE == SSD_TYPE_COMMON_ANODE
    #define SSD_LED_ON  GPIO_LOW
    #define SSD_LED_OFF GPIO_HIGH
#else
    #error "Invalid SSD Type"
#endif

void Ssd_voidInit (void)
{
    GPIO_voidSetPinMode(SSD_PIN_A  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_B  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_C  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_D  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_E  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_F  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_G  , OUTPUT_SPEED_10MHZ_PP);
    GPIO_voidSetPinMode(SSD_PIN_DOT, OUTPUT_SPEED_10MHZ_PP);
}

void Ssd_voidDisplayNumber (u8 number)
{
    switch (number)
    {
    case 0:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_OFF);
        break;
    case 1:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_OFF);
        break;
    case 2:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    case 3:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    case 4:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    case 5:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    case 6:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    case 7:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_OFF);
        break;
    case 8:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON);
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON);
        break;
    case 9:
        GPIO_voidSetPinValue(SSD_PIN_A, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_B, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_C, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_D, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_E, SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F, SSD_LED_ON );
        GPIO_voidSetPinValue(SSD_PIN_G, SSD_LED_ON );
        break;
    default:
        GPIO_voidSetPinValue(SSD_PIN_A  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_B  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_C  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_D  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_E  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_F  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_G  , SSD_LED_OFF);
        GPIO_voidSetPinValue(SSD_PIN_DOT, SSD_LED_OFF);
        break;
    }
}

void Ssd_voidSetDotOn(void)
{
    GPIO_voidSetPinValue(SSD_PIN_DOT, SSD_LED_ON);
}

void Ssd_voidSetDotOff(void)
{
    GPIO_voidSetPinValue(SSD_PIN_DOT, SSD_LED_OFF);
}