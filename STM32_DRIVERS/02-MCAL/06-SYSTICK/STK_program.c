/*
 * STK_program.c
 *
 *  Created on: June 19, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void(*STK_callBack)(void);

static u8 STK_u8ModeOfInterval;


/*Function to Apply Clock choice from configuration file
*Also Disable SYSTICK Interrupt
*And Disable SYSTICK*/
void STK_voidInit(void)
{
    #if STK_CLK_SRC == STK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
		STK_CTRL = 0x00000004;
    #else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
		STK_CTRL = 0;
    #endif
}

/*Synchronous Function: it will wait untill it returns the value you want
*it will count the number of Ticks*/
void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    /* Load ticks to load register */
	STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK_CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK_CTRL,16)) == 0);
	
	/* Stop Timer */
	CLR_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

/*Asynchronous Function: it won't wait it will do an interrupt when the value is ready
*Set Interval Single: means it will take time to count for just one time (Single Shoot)*/
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{	
	/* Disable Timer */
	CLR_BIT(STK_CTRL, 0);
	STK_VAL = 0;

    /* Load ticks to load register */
	STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK_CTRL, 0);
	
	/* Save CallBack */
	STK_callBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK_CTRL, 1);
}

/*Asynchronous Function: it won't wait it will do an interrupt when the value is ready
*Set Interval Periodic: means it will take time to count it Frequently 
*And when it finishes it will do an interrupt and do it again and again*/
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
    /* Load ticks to load register */
	STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK_CTRL, 0);
	
	/* Save CallBack */
	STK_callBack = Copy_ptr;
	
	/* Set Mode to Periodic */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK_CTRL, 1);
}

/*Function to stop the timer when i need to and can used with (interval single) or (periodic)*/
void STK_voidStopTimer(void)
{
    /* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);
	
	/* Stop Timer */
	CLR_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

/*Function to know what i already counted:  means the value in (Load Register - Value Register)*/
void STK_voidGetElapsedTime(void)
{
    u32 local_u32ElapsedTime;
	
	local_u32ElapsedTime = STK_LOAD - STK_VAL ;
	
	return local_u32ElapsedTime;
}

/*Function to read the value in the (Value Register) right now when i need to*/
void STK_voidGetRemainingTime(void)
{
    u32 local_u32RemainTime;
	
	local_u32RemainTime = STK_VAL;
	
	return local_u32RemainTime;
}

/*A Handler Function*/
void SysTick_Handler (void) {
	
	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL) {
		STK_voidStopTimer();
	}
	
	/* Callback notification */
	STK_callBack();
	
	/* Clear interrupt flag by reading it */
	(void) GET_BIT(STK_CTRL,16);
}
