/*
 * OS_interface.h
 *
 *  Created on: July 20, 2023
 *      Author: Mohamed Tarek
 */

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidInit             (void);
void OS_voidStart            (void);
void OS_voidDispatchTasks    (void);
void OS_voidDeleteTask       (u8 Copy_u8Position);
u8   OS_u8CreateTask         (u16 Copy_u16Period, u16 Copy_u16Delay, void (*ptrFunction) (void));

/*
--> Interface

    void OS_vidInit(void)
        - takes no parameters, called first to initialize the OS Scheduler
        - returns void.

    u8 OS_u8CreateTask(u16 copy_u16Period, u16 copy_u16Delay, void (*ptrFunction) (void))
        - takes the task period (in ms) (0 if it is one shot task), the first delay (in ms) of the task, and the pointer the task function.
        - returns the task position to use for later deletion.

    void OS_vidStart(void)
        - takes no parameters, called after adding the tasks.
        - returns void.

    void OS_vidDeleteTask(u8 copy_u8Position)
        - takes the task position to delete.
        - returns void.

    void OS_vidDispatchTasks(void)
        - takes no parameters, calling this function in an infinite loop will let the OS Scheduler run.
        - returns void.


--> Configuration
    - OS_XTAL_FREQ The frequency of the oscillator must be defined in OS_config.h file.
    - OS_MAX_TASKS The maximum number of tasks must be defined in OS_config.h file.


--> Usage
    A simple example of using the OS Scheduler is implemented in main.c file.
*/


#endif
