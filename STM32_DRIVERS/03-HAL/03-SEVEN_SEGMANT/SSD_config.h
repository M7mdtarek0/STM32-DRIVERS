/*
 * SSD_config.h
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */
#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#include "GPIO_interface.h"
#include "GPIO_private.h"

#define SSD_TYPE_COMMON_ANODE       1
#define SSD_TYPE_COMMON_CATHODE     2


#define SSD_TYPE        SSD_TYPE_COMMON_CATHODE

#define SSD_PIN_A       GPIOA,PIN0
#define SSD_PIN_B       GPIOA,PIN1
#define SSD_PIN_C       GPIOA,PIN2
#define SSD_PIN_D       GPIOA,PIN3
#define SSD_PIN_E       GPIOA,PIN4
#define SSD_PIN_F       GPIOA,PIN5
#define SSD_PIN_G       GPIOA,PIN6
#define SSD_PIN_DOT     GPIOA,PIN7

#endif