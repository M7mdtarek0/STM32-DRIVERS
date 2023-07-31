/*
 * LED_program.c
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "LED_config.h"
#include "LED_interface.h"

void Led_voidInit (Gpio_PortType port, Gpio_PinType pin) {
    GPIO_voidSetPinMode(port, pin, OUTPUT_SPEED_10MHZ_PP);
}

void Led_voidTurnOn (Gpio_PortType port, Gpio_PinType pin) {
    GPIO_voidSetPinValue(port, pin, GPIO_HIGH);
}

void Led_voidTurnOff (Gpio_PortType port, Gpio_PinType pin) {
    GPIO_voidSetPinValue(port, pin, GPIO_LOW);
}