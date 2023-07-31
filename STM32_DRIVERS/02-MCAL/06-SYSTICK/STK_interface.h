/*
 * STK_interface.h
 *
 *  Created on: June 19, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _STK_INTERFACE_H_
#define _STK_INTERFACE_H_

void STK_voidInit     (void);
void STK_voidStopTimer(void);

void STK_voidGetElapsedTime  (void);
void STK_voidGetRemainingTime(void);

void STK_voidSetBusyWait(u32 Copy_u32Ticks);

void STK_voidSetIntervalSingle  (u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));

#endif