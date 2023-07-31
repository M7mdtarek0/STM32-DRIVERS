/*
 * LED_interface.h
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "LED_config.h"

typedef enum {
    LED_OFF,
    LED_ON
} Led_StateType;

void Led_voidInit (Gpio_PortType port, Gpio_PinType pin);
void Led_voidTurnOn (Gpio_PortType port, Gpio_PinType pin);
void Led_voidTurnOff (Gpio_PortType port, Gpio_PinType pin);


#endif