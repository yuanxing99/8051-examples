#include "task-switcher.h"

typedef void(*FunType)(void);

uint8_t task_id;
uint8_t __idata task_sp[MAX_TASKS];
uint8_t __idata task_stack[MAX_TASKS][MAX_TASK_DEEP];

void os_start(uint8_t tid)
{
  task_id = tid;
  SP = task_sp[tid];
}

void task_load(uint32_t fn, uint8_t tid)
{
  task_stack[tid][0] = fn & 0xFF;
  task_stack[tid][1] = fn >> 8;
  task_sp[tid] = (uint8_t)(task_stack[tid] + 1);
}

void task_switch(void)
{
  task_sp[task_id] = SP;
  if (++task_id == MAX_TASKS)
  {
    task_id = 0;
  }
  SP = task_sp[task_id];
}



