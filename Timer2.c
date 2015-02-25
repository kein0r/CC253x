/** @ingroup Timer2
 * @{
 */
/*
  Copyright (c) 2014 Jan Rüdiger.  All right reserved.

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
#include <Timer2.h>
#include <ioCC2530.h>
   
/*******************| Macros |*****************************************/

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function definition |****************************/

/** 
 * Initializes and starts timer 2. Timer 2 is always started synchronized
 * to 32kHz oscilator
 * Also sets overflow if passed value is no equal to 0x0000
*/
void Timer2_startSynchronous(uint16_t overflowValue)
{
  /* stop the timer2 in case its already running */
  T2CTRL &= ~T2CTRL_RUN;
  /* set period for timer 2 */
  if (overflowValue != 0x0000)
  {
    Timer2_t overflow;
    overflow.value = overflowValue;
    T2MSEL = T2MSEL_T2MSEL_T2_PERIOD;
    T2M0 = overflow.regs.T2M0;
    T2M1 = overflow.regs.T2M1;
    
  }
  T2CTRL |= T2CTRL_RUN | T2CTRL_SYNC_32kHz | T2CTRL_LATCHMODE_COMBINED;
  while (!(T2CTRL & T2CTRL_STATE_MASK)); /* Wait for next 32 kHz positive edge when timer 2 is started */
}

void Timer2_read(Timer2_t *timerPtr)
{
/* Timer 2 contains a 16-bit timer, which increments on each clock cycle. The counter value can be read
 * from registers T2M1:T2M0 with register T2MSEL.T2MSEL set to 000. Note that the register content in
 * T2M1 is latched when T2M0 is read, meaning that T2M0 must always be read first. */
  T2MSEL = T2MSEL_T2MSEL_T2TIMER;
  timerPtr->regs.T2M0 = T2M0;
  timerPtr->regs.T2M1 = T2M1;
}

/** @}*/