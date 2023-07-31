/*
 * USART_interface.h
 *
 *  Created on: July 29, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

void USART1_voidInit        (void    )  ;
void USART_voidTransmit     (u8 arr[])  ;
u8   USART_u8Recieve        (void    )  ;
void USART_voidEnableClock  (void    )  ;

#endif