/*
 * OS_private.h
 *
 *  Created on: July 20, 2023
 *      Author: Mohamed Tarek
 */
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define OS_TRUE    1
#define OS_FALSE   0

typedef struct data
{   
    u16 period;                     /* Interval (ms) between subsequent runs                    */
    u16 delay;                      /* Delay (ms) until the function will (next) be run         */
    u32 runMe;                      /* Incremented (by scheduler) when task is due to execute   */
    void (*taskFunction) (void);    /* Pointer to the task (must be a 'void (void)' function)   */
}sTask;

static void updateTasks (void);


#endif
