#ifndef __TASK_SWITCHER_H__
#define __TASK_SWITCHER_H__

#include <stdint.h>
#include <mcs51/8051.h>
#include "config.h"

void os_start(uint8_t tid);
void task_load(uint32_t fn, uint8_t tid);
void task_switch(void);

#endif // __TASK_SWITCHER_H__
