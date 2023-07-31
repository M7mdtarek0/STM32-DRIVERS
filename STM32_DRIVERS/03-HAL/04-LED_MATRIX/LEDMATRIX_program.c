/*
 * LEDMATRIX_program.c
 *
 *  Created on: June 23, 2023
 *      Author: Mohamed Tarek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "LEDMATRIX_config.h"



void LEDMATRIX_voidInit(void)
{
    /*Set Direction of all rows pins*/
    GPIO_voidSetPinMode(LEDMATRIX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);

    /*Set Direction of all cols pins*/
    GPIO_voidSetPinMode(LEDMATRIX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_voidSetPinMode(LEDMATRIX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP);
}

void LEDMATRIX_voidDisplay(u8* Copy_u8Data)
{
    while (1)
    {
    /*This for Column 0*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[0]); 
  
    /*Enable Column 0*/
    GPIO_u8GetPinValue(LEDMATRIX_COL0_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 1*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[1]); 
  
    /*Enable Column 1*/
    GPIO_u8GetPinValue(LEDMATRIX_COL1_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 2*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[2]); 
  
    /*Enable Column 2*/
    GPIO_u8GetPinValue(LEDMATRIX_COL2_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 3*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[3]); 
  
    /*Enable Column 3*/
    GPIO_u8GetPinValue(LEDMATRIX_COL3_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 4*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[4]); 
  
    /*Enable Column 4*/
    GPIO_u8GetPinValue(LEDMATRIX_COL4_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 5*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[5]); 
  
    /*Enable Column 5*/
    GPIO_u8GetPinValue(LEDMATRIX_COL5_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 6*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[6]); 
  
    /*Enable Column 6*/
    GPIO_u8GetPinValue(LEDMATRIX_COL6_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);

    /*This for Column 7*/
    /*Disable all Columns to be sure there is nothing enabled before i start*/
    DisableAllCols();

    /*Putting the values on the ROW i want*/
    SetRowValues(Copy_u8Data[7]); 
  
    /*Enable Column 7*/
    GPIO_u8GetPinValue(LEDMATRIX_COL7_PIN, GPIO_LOW);

    /*Using the SYSTICK Busy Wait Function to be a delay for 2500 Microseconds (to be open for 2.5 milliseconds)*/
    STK_voidSetBusyWait(2500);
    
    }
}

/*Function to disable all Columns*/
static void DisableAllCols(void)
{
    GPIO_u8SetPinValue(LEDMATRIX_COL0_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL1_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL2_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL3_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL4_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL5_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL6_PIN, GPIO_HIGH);
    GPIO_u8SetPinValue(LEDMATRIX_COL7_PIN, GPIO_HIGH);
}

/*Function to set All ROWS values*/
static void SetRowValues(u8 Copy_u8Value)
{
    u8 Local_u8BIT;
    
    /*Putting the values of the eight ROWS of all COLUMN*/
    Local_u8BIT = GET_BIT(Copy_u8Value, 0);
    GPIO_voidSetPinValue(LEDMATRIX_ROW0_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 1);
    GPIO_voidSetPinValue(LEDMATRIX_ROW1_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 2);
    GPIO_voidSetPinValue(LEDMATRIX_ROW2_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 3);
    GPIO_voidSetPinValue(LEDMATRIX_ROW3_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 4);
    GPIO_voidSetPinValue(LEDMATRIX_ROW4_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 5);
    GPIO_voidSetPinValue(LEDMATRIX_ROW5_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 6);
    GPIO_voidSetPinValue(LEDMATRIX_ROW6_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 7);
    GPIO_voidSetPinValue(LEDMATRIX_ROW7_PIN, Local_u8BIT);
}