/*
 * NVIC_interface.h
 *
 *  Created on: June 15, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

void NVIC_voidInit            (      void     );
void NVIC_voidEnableInterrupt (u8 Copy_u8IntID);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntID);
void NVIC_voidSetPendingFlag  (u8 Copy_u8IntID);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntID);
void NVIC_voidSetPriority     (u8 Copy_u8PeripheralIndex, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
u8 NVIC_u8GetActiveFlag       (u8 Copy_u8IntID);

#endif