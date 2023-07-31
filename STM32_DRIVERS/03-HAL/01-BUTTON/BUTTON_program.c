/*
 * BUTTON_program.c
 *
 *  Created on: June 10, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "BUTTON_interface.h"
#include "Button_config.h"

void BUTTON_voidInit(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin)
{
    #if (BUTTON_CONNECTION == INPUT_PULL_UP_DOWN)
    Dio_SetPinMode(Copy_u8Port, Copy_u8Pin, INPUT_PULL_UP_DOWN);
#elif (BUTTON_CONNECTION == BUTTON_PULLDOWN)
    Dio_SetPinMode(Copy_u8Port, Copy_u8Pin, INPUT_FLOATING);
    #warning "Input Pull Down not supported"
#else
    #error "Invalid Button Connection Type"
#endif
}

Button_StateType Button_GetState(Gpio_PortType port, Gpio_PinType pin)
{
    Button_StateType ret_value = BUTTON_NOT_PRESSED;
#if (BUTTON_CONNECTION == INPUT_PULL_UP_DOWN)
    if (Dio_ReadPinLevel(Copy_u8Port, Copy_u8Pin) == GPIO_LOW)
#elif (BUTTON_CONNECTION == INPUT_PULL_UP_DOWN)
    if (Dio_ReadPinLevel(Copy_u8Port, Copy_u8Pin) == GPIO_HIGH)
#else
    if (0)
#endif
    {
        ret_value = BUTTON_PRESSED;
    }
    else {
        ret_value = BUTTON_NOT_PRESSED;
    }
    return ret_value;
}
