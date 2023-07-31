/*
 * STK_private.h
 *
 *  Created on: June 19, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _STK_PRIVATE_H_
#define _STK_PRIVATE_H_

#define STK_CTRL     *((volatile u32*)0xE000E010) /*Address for the Control Register          */
#define STK_LOAD     *((volatile u32*)0xE000E014) /*Address for the Load Register             */
#define STK_VAL      *((volatile u32*)0xE000E018) /*Address for the Value Register            */
#define STK_CALIB    *((volatile u32*)0xE000E01C) /*Address for the Calibration Value Register*/


#define     STK_SRC_AHB            0
#define     STK_SRC_AHB_8          1

#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1

#endif