/*
 * TFT_config.h
 *
 *  Created on: July 30, 2023
 *      Author: Mohamed Tarek
 */
#ifndef _TFT_CONFIG_H_
#define _TFT_CONFIG_H_

/***********************************/
/*                                 */
/*                                 */
/*      TFT SCREEN (ST7735)        */
/*                                 */
/*                                 */
/*                                 */
/*                                 */
/*                                 */
/* VCC GND CS RESET A0 SDA SCK LED */
/***********************************/

#define TFT_A0_PIN      GPIOA, PIN2
#define TFT_CS_PIN      GPIOA, PIN0
#define TFT_RESET_PIN   GPIOA, PIN1

#endif