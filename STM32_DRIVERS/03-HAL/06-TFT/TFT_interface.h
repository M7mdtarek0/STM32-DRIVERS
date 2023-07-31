/*
 * TFT_interface.h
 *
 *  Created on: July 30, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _TFT_INTERFACE_H_
#define _TFT_INTERFACE_H_

void TFT_voidInit(void);
void TFT_voidDisplayImage(const u16* Copy_u16Image);
void TFT_voidFillColor(u16 Copy_u16Color);

#endif