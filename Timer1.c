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
  /* stop the timer1 in case its already running. "If 00 is written to T1CTL.MODE, the counter 
   * halts at its present value."*/
  T1CTL &= ~T1CTL_MODE;
  
  /* set module or up/down value for timer 1 */
  if (overflowValue != 0x0000)
  {
    Timer1_t overflow;
    overflow.value = overflowValue;
    T1CC0L = overflow.regs.T1CNTL;
    T1CC0H = overflow.regs.T1CNTH;
    
  }

  /* Start timer1. "The counter is started when a value other than 00 is written to T1CTL.MODE."*/
  T1CTL = mode & T1CTL_MASK;
 }

/**
 * Set capture/compare mode for channel 0 of timer1.
 @param mode value for register T1CCTL0. One or more of T1CCTL0_XX values
 */
void Timer1_captureCompareChannel0(uint8_t mode)
{
  T1CCTL0 = mode;
}

/**
 * Readout of timer1 capture/compare value of channel0
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_readCaptureCompareChannel0(Timer1_t *timerPtr)
{
  /* T1CC0H is latched when T1CC0L is read, meaning that T1CC0L must always be read first. */
  timerPtr->regs.T1CNTL = T1CC0L;
  timerPtr->regs.T1CNTH = T1CC0H;
}
  
/**
 * Set capture/compare mode for channel 1 of timer1.
 @param mode value for register T1CCTL1. One or more of T1CCTL1_XX values
 */
void Timer1_captureCompareChannel1(uint8_t mode)
{
  T1CCTL1 = mode;
}

/**
 * Readout of timer1 capture/compare value of channel1
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_readCaptureCompareChannel1(Timer1_t *timerPtr)
{
  /* T1CC1H is latched when T1CC1L is read, meaning that T1CC1L must always be read first. */
  timerPtr->regs.T1CNTL = T1CC1L;
  timerPtr->regs.T1CNTH = T1CC1H;
}

/**
 * Set capture/compare mode for channel 2 of timer1.
 @param mode value for register T1CCTL2. One or more of T1CCTL2_XX values
 */
void Timer1_captureCompareChannel2(uint8_t mode)
{
  T1CCTL2 = mode;
}

/**
 * Readout of timer1 capture/compare value of channel2
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_readCaptureCompareChannel2(Timer1_t *timerPtr)
{
  /* T1CC2H is latched when T1CC2L is read, meaning that T1CC2L must always be read first. */
  timerPtr->regs.T1CNTL = T1CC2L;
  timerPtr->regs.T1CNTH = T1CC2H;
}

/**
 * Set capture/compare mode for channel 3 of timer1.
 @param mode value for register T1CCTL3. One or more of T1CCTL3_XX values
 */
void Timer1_captureCompareChannel3(uint8_t mode)
{
  T1CCTL3 = mode;
}

/**
 * Readout of timer1 capture/compare value of channel3
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_readCaptureCompareChannel3(Timer1_t *timerPtr)
{
  /* T1CC3H is latched when T1CC3L is read, meaning that T1CC3L must always be read first. */
  timerPtr->regs.T1CNTL = T1CC3L;
  timerPtr->regs.T1CNTH = T1CC3H;
}

/**
 * Set capture/compare mode for channel 4 of timer1.
 @param mode value for register T1CCTL4. One or more of T1CCTL4_XX values
 */
void Timer1_captureCompareChannel4(uint8_t mode)
{
  T1CCTL4 = mode;
}

/**
 * Readout of timer1 capture/compare value of channel4
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_readCaptureCompareChannel4(Timer1_t *timerPtr)
{
  /* T1CC4H is latched when T1CC4L is read, meaning that T1CC4L must always be read first. */
  timerPtr->regs.T1CNTL = T1CC4L;
  timerPtr->regs.T1CNTH = T1CC4H;
}

/**
 * Readout of timer1 value
 * @param timerPtr Pointer to Timer1_t where the counter value should be copied to
*/
inline void Timer1_read(Timer1_t *timerPtr)
{
  /* T1CNTH is latched when T1CNTL is read, meaning that T1CNTL must always be read first. */
  timerPtr->regs.T1CNTL = T1CNTL;
  timerPtr->regs.T1CNTH = T1CNTH;
}

/** @}*/