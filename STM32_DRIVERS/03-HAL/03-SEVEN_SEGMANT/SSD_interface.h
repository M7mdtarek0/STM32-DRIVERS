/*
 * SSD_interface.h
 *
 *  Created on: June 12, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "SSD_config.h"

void Ssd_voidInit (void);
void Ssd_voidDisplayNumber (u8 number);
void Ssd_voidSetDotOn(void);
void Ssd_voidSetDotOff(void);

#endif