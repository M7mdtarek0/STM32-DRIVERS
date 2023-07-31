/*
 * BUTTON_interface.h
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _BUTTON_INTERFACE_H_
#define _BUTTON_INTERFACE_H_

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "BUTTON_config.h"

typedef enum
{
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED
}Button_StateType;

void BUTTON_voidInit(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin);
Button_StateType Button_GetState(Gpio_PortType port, Gpio_PinType pin);

#endif