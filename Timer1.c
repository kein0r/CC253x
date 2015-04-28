/** @ingroup Timer1
 * @{
 */
/*
  Copyright (c) 2015 Jan Rüdiger.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Credits:
*/

/*******************| Inclusions |*************************************/
#include <Timer1.h>
#include <ioCC2530.h>
   
/*******************| Macros |*****************************************/

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function definition |****************************/

/** 
 * Initializes and starts timer 1. Timer 1 is always started synchronized
 * to 32kHz oscilator
 * Also sets overflow if passed value is no equal to 0x0000
 * @param overflowValue Overflow value for Timer1 if given value unequal to 0x0000
*/
void Timer1_startSynchronous(uint8_t mode, uint16_t overflowValue)
{
  /* stop the timer1 in case its already running */
  T1CTL &= ~T1CTL_MODE;
  T1CTL = mode & T1CTL_MASK;
  
  /* set module or up/down value for timer 1 */
  if (overflowValue != 0x0000)
  {
    Timer1_t overflow;
    overflow.value = overflowValue;
    T1CC0L = overflow.regs.T1CNTL;
    T1CC0H = overflow.regs.T1CNTH;
    
  }
  T2CTRL |= T2CTRL_RUN | T2CTRL_SYNC_32kHz | T2CTRL_LATCHMODE_COMBINED;
  while (!(T2CTRL & T2CTRL_STATE_MASK)); /* Wait for next 32 kHz positive edge when timer 2 is started */
}

void Timer1_captureCompareChannel0(uint8_t mode)
{
}

/**
 * Readout of timer1 value
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_read(Timer1_t *timerPtr)
{
  /* T1CNTH is latched when T1CNTL is read, meaning that T1CNTL must always be read first. */
  T2MSEL = T2MSEL_T2MSEL_T2TIMER;
  timerPtr->regs.T1CNTL = T1CNTL;
  timerPtr->regs.T1CNTH = T1CNTH;
}

/** @}*/