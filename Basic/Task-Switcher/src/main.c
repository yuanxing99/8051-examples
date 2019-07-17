#include <stdio.h>
#include <stdint.h>
#include <mcs51/8051.h>
#include "serial.h"
#include "task-switcher.h"

int putchar(int c)
{
	while(!(SCON & 0x02));
	SCON &= ~0x02;
	SBUF = (char)c;
  return c;
}

void task_1()
{
  while(1)
  {
    printf("task 1\n");
    task_switch();
  }
}

void task_2()
{
  while(1)
  {
    printf("task 2\n");
    task_switch();
  }
}

void main()
{
  serial_init();
  printf("os init\n");

  task_load((uint32_t)task_1, 0);
  task_load((uint32_t)task_2, 1);

  os_start(0);
}
