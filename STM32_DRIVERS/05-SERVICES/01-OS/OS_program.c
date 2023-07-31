/*
 * OS_program.c
 *
 *  Created on: July 20, 2023
 *      Author: Mohamed Tarek
 */


#include "STD_TYPES.h"
#include "STK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


sTask OS_tasks[OS_MAX_TASKS];

void OS_voidInit(void)
{
    /*Init all tasks with zero values*/
    u8 local_u8TaskCounter;
    for (local_u8TaskCounter = 0; local_u8TaskCounter < OS_MAX_TASKS; local_u8TaskCounter++) {
        OS_vidDeleteTask(local_u8TaskCounter);
    }
}

void OS_voidStart (void) 
{
    /*Init SysTick with 1 ms period*/
    STK_voidInit();
    STK_voidSetIntervalPeriodic((OS_XTAL_FREQ/1000), updateTasks);
}

u8 OS_u8CreateTask(u16 Copy_u16Period, u16 Copy_u16Delay, void (*ptrFunction) (void))
{
    u8 local_u8TaskCounter = 0;
    
    /*First find a gap in the array (if there is one)*/
    while ((OS_tasks[local_u8TaskCounter].taskFunction != 0) && (local_u8TaskCounter < OS_MAX_TASKS)) {
        local_u8TaskCounter++;
    }
    
    /*Have we reached the end of the list?*/
    if (local_u8TaskCounter == OS_MAX_TASKS) {
        /*Task list is full*/
        return OS_MAX_TASKS;
    }
    
    /*If we're here, there is a space in the task array*/
    OS_tasks[local_u8TaskCounter].period = Copy_u16Period;
    OS_tasks[local_u8TaskCounter].taskFunction = ptrFunction;
    OS_tasks[local_u8TaskCounter].delay = Copy_u16Delay;
    OS_tasks[local_u8TaskCounter].runMe = OS_FALSE;
    return local_u8TaskCounter; // return position of task (to allow later deletion)
}
void OS_voidDeleteTask(u8 Copy_u8Position) 
{
    if (Copy_u8Position < OS_MAX_TASKS) {
        OS_tasks[Copy_u8Position].taskFunction = 0;
        OS_tasks[Copy_u8Position].delay        = 0;
        OS_tasks[Copy_u8Position].period       = 0;
        OS_tasks[Copy_u8Position].runMe        = OS_FALSE;
    }
}


void OS_voidDispatchTasks(void) 
{
    u8 local_u8TaskCounter;
    for (local_u8TaskCounter = 0; local_u8TaskCounter < OS_MAX_TASKS; local_u8TaskCounter++) 
    {
        /*Run the task if the runMe flag is true*/
        if (OS_tasks[local_u8TaskCounter].runMe == OS_TRUE) {

            /*Run the task*/
            (OS_tasks[local_u8TaskCounter].taskFunction)(); 
            OS_tasks[local_u8TaskCounter].runMe = OS_FALSE;

            /*Periodic tasks will automatically run again*/
            /*if this is a 'one shot' task, remove it from the array*/
            if (OS_tasks[local_u8TaskCounter].period == 0) {
                OS_voidDeleteTask(local_u8TaskCounter);
            }
        }
    }
}



static void updateTasks (void) {
    u8 local_u8TaskCounter;
    for (local_u8TaskCounter = 0; local_u8TaskCounter < OS_MAX_TASKS; local_u8TaskCounter++) {

        /*Check if there is a task at this location*/
        if (OS_tasks[local_u8TaskCounter].taskFunction) {

            /*Check if the task is due to run*/
            if (OS_tasks[local_u8TaskCounter].delay == 0) 
            {
                /*Increment runMe flag*/
                OS_tasks[local_u8TaskCounter].runMe = OS_TRUE; 

                /*Schedule periodic tasks to run again*/
                OS_tasks[local_u8TaskCounter].delay = OS_tasks[local_u8TaskCounter].period;

            } else 
            {
                /*Not yet ready to run: just decrement the delay*/
                OS_tasks[local_u8TaskCounter].delay -= 1;
            }
        }

    }

}



