/*
 * DMA_private.h
 *
 *  Created on: July 25, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_


typedef struct
{   /*every channel here has a register*/
    volatile u32 CCR;
    volatile u32 CNDTR;
    volatile u32 CPAR;
    volatile u32 CMAR;
    volatile u32 RESERVED;
}DMA_CHANNEL;


typedef struct 
{
    volatile u32 ISR; /*For all channels*/
    volatile u32 IFCR; /*For all channels*/
    DMA_CHANNEL channel[7]; /*this is an array has 7 element because i have 7 channels*/
}DMA_t;

#define DMA     ((volatile DMA_t*)(0x40020000)) /*This is the base address*/

#endif